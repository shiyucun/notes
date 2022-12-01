
// 从共享内存读取数据
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 使用ftok获取key
  key_t key = ftok(".", 100);
  if (-1 == key) {
    perror("ftok"), exit(-1);
  }
  printf("key = %#x\n", key);

  // 用key创建/获取共享内存id
  int shmid = shmget(key, 0, 0);
  if (-1 == shmid) {
    perror("shget"), exit(-1);
  }
  printf("shmid = %d\n", shmid);

  // 挂接共享内存
  void *p = shmat(shmid, NULL, 0);
  if (p == (void *)-1) {
    perror("shmat"), exit(-1);
  }

  // 使用共享内存
  int *pi = p;
  printf("*pi = %d\n", *pi);

  // 脱接共享内存
  if (-1 == shmdt(p)) {
    perror("shmdt"), exit(-1);
  }

  // 删除共享内存
  if (-1 == shmctl(shmid, IPC_RMID, NULL)) {
    perror("shmctl"), exit(-1);
  } else {
    printf("成功删除共享内存！\n");
  }

  return 0;
}
