
// wait 函数的使用
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>

int main() {
  pid_t pid = fork();
  if (-1 == pid) {
    perror("fork"), exit(-1);
  }

  if (0 == pid) {
    printf("子进程%d开始运行，将睡眠5s\n", getpid());
    sleep(5);
    printf("子进程结束！\n");
    exit(-1);
  }

  printf("父进程%d开始运行，等待子进程结束\n", getpid());

  //挂起父进程，等待子进程结束，存储退出码
  int status = 0;
  int res = wait(&status);

  printf("等待结束，res = %d, status = %d\n", res, status);

  if (WIFEXITED(status)) {
    // WEXITSTATUS( status )只是取出低八位作为退出码
    printf("子进程正常结束，退出码是:%d\n", WEXITSTATUS(status));
  }

  return 0;
}
