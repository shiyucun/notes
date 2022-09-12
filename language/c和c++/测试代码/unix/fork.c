
// fork 函数的使用
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("main函数开始执行...\n");
  printf("pid = %d\n", getpid());

  pid_t pid = fork();
  if (-1 == pid) {
    perror("fork"), exit(-1);
  }

  if (0 == pid) {
    printf("我是子进程：pid = %d, ppid = %d\n", getpid(), getppid());
  } else {
    printf("我是父进程：pid = %d，cpid = %d\n", getpid(), pid);
  }

  // printf( "main函数结束！pid=%d\n", pid );  // 父进程返回子进程pid，子进程返回0
  return 0;
}
