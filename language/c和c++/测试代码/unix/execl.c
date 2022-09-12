
// vfork和execl函数的搭配使用
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = vfork();
  if (-1 == pid) {
    perror("vfork"), exit(-1);
  }

  if (0 == pid) {
    printf("child process start! id = %d!\n", getpid());
    //子进程跳转执行ls命令
    execl( "/bin/ls", "ls", "-l", NULL );
    printf("child end!\n");  //跳转后这句话不再执行
  }

  printf("parent start! id = %d!\n", getpid());
  sleep(2);
  printf("parent end!\n");

  return 0;
}
