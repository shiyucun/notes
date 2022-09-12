
// 多个线程同时访问共享资源的同步问题
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 准备共享资源
char *buf[5];  // 字符指针数组
int pos;       // 下标

// 定义信号量
sem_t sem;

void *task(void *p) {
  // 获取一个信号量(信号量-1)
  sem_wait(&sem);

  buf[pos] = p;
  pos++;

  // 释放一个信号量
  sem_post(&sem);
}

int main() {
  // 初始化信号量
  sem_init(&sem, 0,  // 控制线程数
                 1); // 信号量的初始值

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

  // 销毁信号量
  sem_destroy(&sem);

  return 0;
}
