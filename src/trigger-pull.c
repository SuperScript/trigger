#include <unistd.h>
#include "strerr.h"
#include "error.h"
#include "ndelay.h"
#include "exit.h"
#include "sig.h"
#include "open.h"

#define FATAL "trigger-pull: fatal: "

void usage() {
  strerr_die1x(100,"trigger-pull: usage: trigger-pull fifo");
}

int main(int argc,char * const *argv) {
  int r;
  int fd;
  const char *file;

  file = *++argv;
  if (!file) usage();

  fd = open_append(file);
  if (fd == -1)
    strerr_die4sys(111,FATAL,"cannot open ",file,": ");
  if (ndelay_on(fd) == -1)
    strerr_die4sys(111,FATAL,"cannot control ",file,": ");
  sig_ignore(sig_pipe);
  r = write(fd,"",1);
  if (r != -1) _exit(0);
  if (errno == error_again) _exit(0);
  if (errno == error_pipe) _exit(0);
  strerr_die4sys(111,FATAL,"cannot write ",file,": ");
}
