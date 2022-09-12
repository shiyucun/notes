
// signal 函数的使用
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo) { printf("捕捉到信号%d\n", signo); }

int main() {
  // 设置信号处理的方式为忽略
  signal(2, fa);

  // 设置对信号3进行自定义处理
  signal(SIGQUIT, SIG_IGN);

  pid_t pid = fork();

  if (pid == 0) {
    printf("child start! PID = %d.\n", getpid());
    int i = 0;
    while (1) {
      i++;
      sleep(3);
      printf("%d\n", i);
    }
  }

  printf("parent end! PID = %d.\n", getpid());

  return 0;
}
