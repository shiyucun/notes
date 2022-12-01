
// sigaction 函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo) {
  printf("捕获到信号%d\n", signo);
  sleep(5);
  printf("信号处理完毕\n");
}

int main() {
  printf("PID = %d\n", getpid());

  // 准备结构体（函数参数）
  struct sigaction action = {};

  // 选择第一个函数指针处理信号
  action.sa_handler = fa;

  // 准备信号屏蔽字
  sigemptyset(&action.sa_mask);
  sigaddset(&action.sa_mask, 3);  // 信号处理期间屏蔽信号3，默认屏蔽相同信号

  // 设置信号处理标志
  action.sa_flags = SA_NODEFER;

  // 使用sigaction函数设置对信号的处理
  sigaction(2, &action, NULL);

  while (1) {}

  return 0;
}
