
// 创建信号量集并初始化
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

int semid;

void destroy() {
  if (-1 == semctl(semid, 0, IPC_RMID)) {
    perror("semctl"), exit(-1);
  }
}

void fa(signo) { exit(0); }

int main() {
  // 自定义信号处理函数
  atexit(destroy);
  signal(SIGQUIT, fa);

  // 获取key值，使用ftok函数
  key_t key = ftok(".", 100);
  if (-1 == key) {
    perror("key"), exit(-1);
  }
  printf("key = %d\n", key);

  // 创建/获取信号量集的id
  semid = semget(key, 1, IPC_CREAT | IPC_EXCL | 0666);
  if (-1 == semid) {
    perror("semget"), exit(-1);
  }
  printf("semid = %d\n", semid);

  // 初始化信号量集
  if (semctl(semid, 0, SETVAL, 5) == -1) {
    perror("semctl"), exit(-1);
  }

  printf("信号量集合初始化成功，使用ctrl+\\删除信号量集合\n");

  while (1) {}

  return 0;
}
