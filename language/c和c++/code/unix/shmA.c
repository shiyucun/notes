
// 建立共享内存存放数据
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 使用 ftok 获取 key
  key_t key = ftok(".", 100);
  if (-1 == key) {
    perror("ftok"), exit(-1);
  }
  printf("key = %#x\n", key);

  // 用 key 创建/获取共享内存 id
  int shmid = shmget(key, 4, IPC_CREAT | IPC_EXCL | 0666);
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
  *pi = 200;

  // 脱接共享内存
  if (-1 == shmdt(p)) {
    perror("shmdt"), exit(-1);
  }

  // 删除共享内存

  return 0;
}
