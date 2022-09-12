
// vfork 和 signal 函数的使用
#include <signal.h>
#include <stdio.h>

#include <sys/types.h>
#include <unistd.h>

void fa(int signo) { printf("捕捉到信号%d\n", signo); }

int main() {
  //设置信号处理的方式为自定义
  signal(SIGINT, fa);

  //设置对信号3进行默认处理
  signal(SIGQUIT, SIG_IGN);

  pid_t pid = vfork();

  if (pid == 0) {
    printf("child start! PID = %d.\n", getpid());
    //要用execl跳出去
    while (1) {
    }
  }

  printf("parent end! PID = %d.\n", getpid());

  return 0;
}
