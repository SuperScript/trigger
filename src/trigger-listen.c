#include <sys/types.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <unistd.h>
#include "str.h"
#include "byte.h"
#include "fmt.h"
#include "scan.h"
#include "exit.h"
#include "prot.h"
#include "open.h"
#include "wait.h"
#include "stralloc.h"
#include "alloc.h"
#include "buffer.h"
#include "error.h"
#include "strerr.h"
#include "sgetopt.h"
#include "pathexec.h"
#include "sig.h"
#include "iopause.h"
#include "env.h"
#include "fifo.h"
#include "ndelay.h"

int verbosity = 1;

char strnum[FMT_ULONG];
char strnum2[FMT_ULONG];


/* ---------------------------- child */

#define WARNING "trigger-listen: warning: "

int flagdelete = 1;
int selfpipe[2];
int flag1 = 0;
int flagqueue = 0;
int fdr;
int fdw;


/* ---------------------------- parent */

#define FATAL "trigger-listen: fatal: "

void usage()
{
  strerr_warn1("\
trigger-listen: usage: trigger-listen \
[ -UdDqQv1 ] \
[ -c limit ] \
[ -t timeout ] \
[ -i interval ] \
[ -g gid ] \
[ -u uid ] \
path program",0);
  _exit(100);
}

unsigned long limit = 1;
unsigned int timeout = ~0;
unsigned int maxtimeout = ~0;
unsigned int interval = 0;
unsigned long numchildren = 0;

unsigned long uid = 0;
unsigned long gid = 0;

void printstatus(void) {
  if (verbosity < 2) return;
  strnum[fmt_ulong(strnum,numchildren)] = 0;
  strnum2[fmt_ulong(strnum2,limit)] = 0;
  strerr_warn4("trigger-listen: status: ",strnum,"/",strnum2,0);
}

void doit(char * const *argv) {
  ++numchildren; printstatus();

  switch(fork()) {
    case 0:
      close(fdr); close(fdw);
      close(selfpipe[0]); close(selfpipe[1]);
      if (verbosity >= 2) {
	strnum[fmt_ulong(strnum,getpid())] = 0;
	strerr_warn2("trigger-listen: pid ",strnum,0);
      }
      sig_uncatch(sig_child);
      sig_unblock(sig_child);
      sig_uncatch(sig_term);
      sig_uncatch(sig_pipe);
      pathexec(argv);
      strerr_die4sys(111,WARNING,"unable to run ",*argv,": ");
    case -1:
      strerr_warn2(WARNING,"unable to fork: ",&strerr_sys);
      --numchildren; printstatus();
  }
}



void sigterm() {
  _exit(0);
}

void sigchld() {
  int wstat;
  int pid;
 
  while ((pid = wait_nohang(&wstat)) > 0) {
    if (verbosity >= 2) {
      strnum[fmt_ulong(strnum,pid)] = 0;
      strnum2[fmt_ulong(strnum2,wstat)] = 0;
      strerr_warn4("trigger-listen: end ",strnum," status ",strnum2,0);
    }
    if (numchildren) --numchildren; printstatus();
  }
  write(selfpipe[1],"",1);
}


int main(int argc,char * const *argv) {
  const char *path;
  int opt;
  const char *tmp;
  mode_t m;
  iopause_fd x[2];
  struct taia deadline;
  struct taia stamp;
  struct taia resume;
  char ch;

  while ((opt = getopt(argc,argv,"1vqQdDUu:g:c:t:i:")) != opteof)
    switch(opt) {
      case '1': flag1 = 1; break;
      case 'c': scan_ulong(optarg,&limit); break;
      case 't': scan_uint(optarg,&timeout); break;
      case 'i': scan_uint(optarg,&interval); break;
      case 'v': verbosity = 2; break;
      case 'q': verbosity = 0; break;
      case 'Q': verbosity = 1; break;
      case 'd': flagdelete = 1; break;
      case 'D': flagdelete = 0; break;
      case 'U': tmp = env_get("UID"); if (tmp) scan_ulong(tmp,&uid);
		tmp = env_get("GID"); if (tmp) scan_ulong(tmp,&gid); break;
      case 'u': scan_ulong(optarg,&uid); break;
      case 'g': scan_ulong(optarg,&gid); break;
      default: usage();
    }
  argc -= optind;
  argv += optind;

  if (!verbosity)
    buffer_2->fd = -1;
 
  path = *argv++;
  if (!path) usage();
  if (str_equal(path,"")) usage();

  if (!*argv) usage();

  sig_block(sig_child);
  sig_catch(sig_child,sigchld);
  sig_catch(sig_term,sigterm);
  sig_ignore(sig_pipe);

  if (flagdelete) {
    m = umask(0);
    unlink(path);
    fifo_make(path,0666);
    umask(m);
  }

  fdr = open_read(path);
  if (fdr == -1)
    strerr_die4sys(111,FATAL,"unable to read ",path,": ");
  ndelay_on(fdr);

  fdw = open_write(path);
  if (fdw == -1)
    strerr_die4sys(111,FATAL,"unable to write ",path,": ");
  ndelay_on(fdw);

  if (pipe(selfpipe) == -1)
    strerr_die2sys(111,FATAL,"cannot create pipe: ");
  ndelay_on(selfpipe[0]);
  ndelay_on(selfpipe[1]);

  if (gid) if (prot_gid(gid) == -1)
    strerr_die2sys(111,FATAL,"unable to set gid: ");
  if (uid) if (prot_uid(uid) == -1)
    strerr_die2sys(111,FATAL,"unable to set uid: ");

  printstatus();
  flagqueue = 0;
  taia_now(&resume);
  if (flag1) {
    doit(argv);
    taia_uint(&deadline,interval);
    taia_add(&resume,&resume,&deadline);
  }

  for (;;) {
    sig_unblock(sig_child);
    
    x[0].fd = selfpipe[0];
    x[0].events = IOPAUSE_READ;
    x[1].fd = fdr;
    x[1].events = IOPAUSE_READ;

    taia_now(&stamp);
    taia_uint(&deadline,timeout);
    taia_add(&deadline,&stamp,&deadline);
    if (flagqueue && taia_less(&resume,&deadline)) {
      taia_sub(&deadline,&deadline,&deadline);
      taia_add(&deadline,&deadline,&resume);
    }

    for (;;) {
      taia_now(&stamp);
      if (taia_less(&deadline,&stamp)) {
	flagqueue = 1;
	if (numchildren < limit) break;
	taia_uint(&deadline,maxtimeout);
	taia_add(&deadline,&deadline,&stamp);
      }
      iopause(x,2,&deadline,&stamp);
      if (x[1].revents || x[0].revents) {
	break;
      }
    }

    sig_block(sig_child);

    while (read(selfpipe[0],&ch,1) == 1)
      ;

    while (read(fdr,&ch,1) == 1)
      flagqueue = 1;

    if (!flagqueue) continue;
    if (numchildren >= limit) continue;
    taia_now(&stamp);
    if (taia_less(&stamp,&resume)) continue;

    doit(argv);
    flagqueue = 0;
    taia_now(&resume);
    taia_uint(&deadline,interval);
    taia_add(&resume,&resume,&deadline);
  }
  _exit(0);
}
