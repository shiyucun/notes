
// waitpid 函数的使用
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid1, pid2;

  pid1 = fork();
  if (-1 == pid1) {
    perror("fork1"), exit(-1);
  }
  if (pid1 != 0) {
    pid2 = fork();
    if (-1 == pid2) {
      perror("fork2"), exit(-1);
    }
  }

  if (0 == pid1) {
    printf("child process 1 start! pid = %d\n", getpid());
    sleep(5);
    printf("chile process 1 end !\n");
    exit(100);
  }

  if (0 == pid2) {
    printf("child process 2 start! pid = %d\n", getpid());
    sleep(2);
    printf("child process 2 end !\n");
    exit(200);
  }

  printf("parent wait! pid = %d\n", getpid());

  int status = 0;
  // int res = waitpid( -1, &status, 0 );
  int res = waitpid(pid1, &status, 0);

  if (WIFEXITED(status)) {
    printf("wait end! the terminal process is %d! exit code is %d!\n", res, WEXITSTATUS(status));
  } else {
    printf("wait end! the terminal process is error!");
  }

  return 0;
}
