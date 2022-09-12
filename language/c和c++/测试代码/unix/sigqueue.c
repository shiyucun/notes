
// sigqueue 函数的使用
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void fa(int signo, siginfo_t *info, void *p) {
  printf("进程%d发送了信号%d，附加数据是：%d\n", info->si_pid, signo, info->si_value.sival_int);
}

int main() {
  // 准备结构体
  struct sigaction action = {};
  action.sa_sigaction = fa;
  action.sa_flags = SA_SIGINFO;

  sigaction(40, &action, NULL);

  pid_t pid = fork();

  if (0 == pid) {
    int i = 0;
    for (i = 0; i < 100; i++) {
      union sigval value;
      value.sival_int = i;
      sigqueue(getppid(), 40, value);
    }
    sleep(1);
    exit(0);
  }

  while (1) {
  }

  return 0;
}
