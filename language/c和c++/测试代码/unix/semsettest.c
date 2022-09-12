
// 创建10个进程模拟抢占资源的过程
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 获取key值，使用ftok函数
  key_t key = ftok(".", 100);
  if (-1 == key) {
    perror("ftok"), exit(-1);
  }
  printf("key = %d\n", key);

  // 获取信号量集的id
  int semid = semget(key, 0, 0);
  if (-1 == semid) {
    perror("semget"), exit(-1);
  }
  printf("semid = %d\n", semid);

  // 创建10个子进程模拟抢占资源的过程
  int i = 0;
  for (; i < 10; i++) {
    pid_t pid = fork();
    if (0 == pid)  // 子进程
    {
      // 准备结构体变量
      struct sembuf op;
      op.sem_num = 0;  // 下标
      op.sem_op = -1;  // 计数减1
      op.sem_flg = 0;
      // 操作信号量集
      semop(semid, &op, 1);

      printf("进程%d申请资源成功\n", getpid());
      sleep(20);
      printf("进程%d使用完毕！\n", getpid());

      op.sem_op = 1;
      semop(semid, &op, 1);
      exit(0);
    }
  }

  while (1) {
  }

  return 0;
}
