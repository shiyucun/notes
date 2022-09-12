
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fa(int signo) { printf("捕获到信号%d\n", signo); }

int main() {
  printf("PID = %d.\n", getpid());
  //设 置信号2的处理方式为自定义
  signal(SIGINT, fa);

  int res = sleep(10);

  printf("res = %d\n", res);

  raise(2);

  while (1)
    ;

  return 0;
}
