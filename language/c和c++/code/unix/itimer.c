
// 计时器的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

void fa(int signo) { printf("捕获到信号%d\n", signo); }

int main() {
  signal(SIGALRM, fa);

  // 准备结构体
  struct itimerval timer;

  // 设置间隔时间
  timer.it_interval.tv_sec = 1;        // 秒数
  timer.it_interval.tv_usec = 230000;  // 微秒

  // 设置开始时间
  timer.it_value.tv_sec = 5;
  timer.it_value.tv_usec = 0;

  // 启动定时器
  if (-1 == setitimer(ITIMER_REAL, &timer, NULL)) {
    perror("setitimer"), exit(-1);
  }

  while (1)
    ;
  return 0;
}
