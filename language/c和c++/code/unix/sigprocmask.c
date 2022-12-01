
// sigprocmask 函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo) { printf("捕捉到信号%d\n", signo); }

int main() {
  printf("PID = %d\n", getpid());

  signal(2, fa);
  signal(3, fa);
  signal(50, fa);

  int res = sleep(20);
  if (0 != res) {
    printf("没有信号屏蔽，睡眠被唤醒，睡眠时间：%dS\n", (20 - res));
  }

  printf("-----------------------------------------\n");
  printf("开始屏蔽信号\n");

  // 准备信号集
  sigset_t set, old;

  // 清空信号集
  sigemptyset(&set);
  sigemptyset(&old);

  // 屏蔽信号放入集合中
  sigaddset(&set, 2);
  sigaddset(&set, 50);
  sigaddset(&set, 3);

  // 调用函数进行屏蔽
  if (-1 == sigprocmask(SIG_SETMASK, &set, &old)) {
    perror("sigprocmask"), exit(-1);
  }

  printf("old = %ld\n", old);
  res = sleep(20);

  if (0 == res) {
    printf("屏蔽了，开始解除...\n");
  }

  // 恢复默认屏蔽方式
  // sigprocmask( SIG_SETMASK, &old, NULL );

  // 获取屏蔽期间到达过的信号
  sigset_t pend;
  sigpending(&pend);
  if (sigismember(&pend, 3)) {
    printf("信号3来过！\n");
  }

  sigprocmask(SIG_SETMASK, &old, NULL);

  return 0;
}
