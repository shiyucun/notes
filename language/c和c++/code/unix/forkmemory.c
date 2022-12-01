
// fork 函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

int i1 = 1;  // 全局

int main() {
  int i2 = 1;  // 栈区

  char *pc = (char *)malloc(10);  // 堆区
  strncpy(pc, "hello", 5);

  pid_t pid = fork();
  if (-1 == pid) {
    perror("fork"), exit(-1);
  }

  if (pid == 0) {
    i1 = 2;
    i2 = 2;
    pc[0] = '1';
    int i3 = 2;  // 栈区，父进程不能使用
    printf("child, i1 = %d, i2 = %d, i3 = %d, pc = %s\n", i1, i2, i3, pc);
    exit(0);
  }

  sleep(1);
  printf("i1 = %d, i2 = %d, pc = %s\n", i1, i2, pc);

  return 0;
}
