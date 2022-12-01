
// sigaction 函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo, siginfo_t *info, void *p) {
  printf("进程%d,发送了信号%d\n", info->si_pid, signo);
  printf("信号处理完毕\n");
}

int main() {
  printf("PID = %d\n", getpid());

  // 准备结构体（函数参数）
  struct sigaction action = {};

  // 选择第2个函数指针处理信号
  action.sa_sigaction = fa;

  // 设置信号处理标志
  action.sa_flags = SA_SIGINFO;

  // 使用 sigaction 函数设置对信号的处理
  sigaction(2, &action, NULL);

  while (1) {
  }

  return 0;
}
