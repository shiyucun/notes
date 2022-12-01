
// 使用fork查看父子进程之间的关系
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();

  if (-1 == pid) {
    exit(-1);
  }

  if (0 == pid) {
    sleep(1);
    printf("child:%d,parent:%d\n", getpid(), getppid());
  } else {
    printf("parent:%d,child:%d\n", getpid(), pid);
  }

  return 0;
}
