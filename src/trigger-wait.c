#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "strerr.h"
#include "open.h"
#include "exit.h"
#include "ndelay.h"
#include "fifo.h"
#include "iopause.h"
#include "sig.h"
#include "taia.h"
#include "sgetopt.h"
#include "scan.h"
#include "wait.h"
#include "pathexec.h"

#define FATAL "trigger-wait: fatal: "
#define WARNING "trigger-wait: warning: "

int fdr;
int fdw;
unsigned int timeout = ~0;
int waiting = 0;
int flagwait = 1;
int flagdelete = 1;

void usage() {
  strerr_die1x(100,"trigger-wait: usage: trigger-wait [ -wWdD -t timeout ] fifo [ prog ]");
}

int main(int argc,char * const *argv) {
  int opt;
  const char *path;
  mode_t m;
  iopause_fd x;
  struct taia deadline;
  struct taia stamp;
  int pid = 0;
  char ch;
  int wstat;

  while ((opt = getopt(argc,argv,"wWdDt:")) != opteof)
    switch(opt) {
      case 't': scan_uint(optarg,&timeout); break;
      case 'w': flagwait = 1; break;
      case 'W': flagwait = 0; break;
      case 'd': flagdelete = 1; break;
      case 'D': flagdelete = 0; break;
      default: usage();
    }

  argv += optind;
  path = *argv++;
  if (!path) usage();

  if (flagdelete) {
    m = umask(0);
    unlink(path);
    fifo_make(path,0666);
    umask(m);
  }

  fdr = open_read(path);
  if (fdr == -1)
    strerr_die4sys(111,FATAL,"cannot read ",path,": ");
  ndelay_on(fdr);

  fdw = open_write(path);
  if (fdw == -1)
    strerr_die4sys(111,FATAL,"cannot write ",path,": ");

  if (*argv) {
    pid = fork();
    switch (pid) {
      case 0:
	close(fdr); close(fdw);
	pathexec(argv);
	strerr_die4sys(111,FATAL,"cannot run ",*argv,": ");
      case -1:
	strerr_die4sys(111,FATAL,"cannot fork ",*argv,": ");
	break;
      default:
	break;
    }
  }
  else
    flagwait = 0;

  x.fd = fdr;
  x.events = IOPAUSE_READ;
  taia_now(&stamp);
  taia_uint(&deadline,timeout);
  taia_add(&deadline,&stamp,&deadline);

  for (;;) {
    taia_now(&stamp);
    iopause(&x,1,&deadline,&stamp);
    if (x.revents) {
      waiting = 0;
      break;
    }
    if (taia_less(&deadline,&stamp)) {
      waiting = 99;
      break;
    }
  }

  if (!waiting)
    if (read(fdr,&ch,1) != 1)
      waiting = 0;

  if (flagwait)
    if (wait_pid(&wstat,pid) != pid)
      strerr_die2x(111,FATAL,"cannot reap child process");

  _exit(waiting);
}
