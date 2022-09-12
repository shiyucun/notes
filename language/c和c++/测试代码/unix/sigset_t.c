
// 信号集操作函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("sigset_t = %d\n", sizeof(sigset_t));

  // 把结构体类型的 set 假设为 long int 进行输出
  sigset_t set;

  // 处理
  printf("set = %ld\n", set);

  sigemptyset(&set);
  printf("set = %ld\n", set);  // 0

  sigaddset(&set, 2);  // 2
  printf("set = %ld\n", set);

  sigaddset(&set, 3);  // 6
  printf("set = %ld\n", set);

  sigaddset(&set, 7);
  printf("set = %ld\n", set);  // 70

  sigdelset(&set, 3);
  printf("set = %ld\n", set);  // 66

  if (sigismember(&set, 3)) {
    printf("信号3存在\n");
  } else {
    printf("信号3不存在\n");
  }

  if (sigismember(&set, 7)) {
    printf("信号7存在\n");
  } else {
    printf("信号7不存在\n");
  }

  return 0;
}
