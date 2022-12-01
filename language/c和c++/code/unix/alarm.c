
// alarm 函数的使用

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fa(int signo) { printf("catch the signal %d\n", signo); }

int main() {
  // 设置 SIGALRM 信号自定义处理
  signal(SIGALRM, fa);

  // 5s 之后发送 alarm 信号
  int res = alarm(5);
  printf("res = %d\n", res);

  sleep(2);

  res = alarm(10);
  printf("res = %d\n", res);

  sleep(2);

  res = alarm(0);
  printf("res = %d\n", res);

  sleep(2);

  res = alarm(0);
  printf("res = %d\n", res);

  while (1) {
  }

  return 0;
}
