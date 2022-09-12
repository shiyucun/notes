
// 多个线程同时访问共享资源的同步问题
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 准备共享资源
char *buf[5];  // 字符指针数组
int pos;       // 下标

// 定义互斥量
pthread_mutex_t lock;

void *task(void *p) {
  // 访问共享资源之前加锁
  pthread_mutex_lock(&lock);

  buf[pos] = p;
  pos++;

  // 使用完共享资源解锁
  pthread_mutex_unlock(&lock);
}

int main() {
  // 初始化互斥量
  pthread_mutex_init(&lock, 0);

  pthread_t tid, tid2;

  pthread_create(&tid, NULL, task, "zhangfei");
  pthread_create(&tid2, NULL, task, "guanyu");

  pthread_join(tid, NULL);
  pthread_join(tid2, NULL);

  int i = 0;
  for (i = 0; i < pos; i++) {
    printf("%s ", buf[i]);
  }
  printf("\n");

  // 销毁互斥量
  pthread_mutex_destroy(&lock);

  return 0;
}
