
// signal 函数的使用
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo) {
  printf("捕捉到信号%d\n", signo);
  // 对信号3设置为默认处理
  signal(3, SIG_DFL);
}

int main() {
  // 设置信号处理的方式为忽略
  signal(2, SIG_IGN);
  // 设置对信号3进行自定义处理
  signal(SIGQUIT, fa);
  // 设置对信号9进行自定义处理
  signal(SIGKILL, fa);

  printf("PID = %d\n", getpid());
  while (1) {
  }

  return 0;
}
