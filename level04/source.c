#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>
#include <sys/prctl.h>
#include <sys/types.h>

int main(void) {
  int stat_loc;
  char str[128];
  int var;
  int var2;
  int var3;
  pid_t pid;

  pid = fork();
  memset(str, 0, 128);
  var3 = 0;
  stat_loc = 0;
  if (pid){
    do{
      wait(&stat_loc);
      var = stat_loc;
      if ((stat_loc & 0x7f) == 0 || (var2 = stat_loc, (char)((stat_loc & 0x7f) + 1) >> 1 > 0))
      {
        puts("child is exiting...");
        return (0);
      }
      var3 = ptrace(PTRACE_PEEKUSER, pid, 44, 0);
    }
    while ( var3 != 11);
    puts("no exec() for you");
    kill(pid, 9);
  }
  else{
    prctl(1, 1);
    ptrace(PTRACE_TRACEME, 0, 0, 0);
    puts("Give me some shellcode, k");
    gets(str);
  }
  return (0);
}
