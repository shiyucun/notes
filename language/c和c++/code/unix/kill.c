
// kill函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void fa(int signo) { printf("catch signal %d!\n", signo); }

int main() {
  pid_t pid = fork();
  if (pid == -1) {
    perror("fork"), exit(-1);
  }

  if (0 == pid) {
    // 自定义处理信号50
    signal(50, fa);
    while (1) {}
  }

  sleep(1);
  if (0 == kill(pid, 0)) {
    printf("parent %d send the signal of 50 to child %d!\n", getpid(), pid);
    kill(pid, 50);
  }
  return 0;
}
