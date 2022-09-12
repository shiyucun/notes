
// vfork 函数的使用
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
  int i = 0;
  printf("i = %d\n", i);

  pid_t pid = vfork();
  if (-1 == pid) {
    perror("vfork"), exit(-1);
  }

  if (0 == pid) {
    i = 3;
    printf("I am the child, id = %d\n", getpid());
    sleep(10);
    printf("end! Realse the resource!\n");
    // 如果没有下面这一句，打印结果不可预知
    exit(0);
  }

  printf("child is over, id = %d! parent start, id = %d!\n", pid, getpid());
  printf("i = %d\n", i);
  printf("end!\n");

  return 0;
}
