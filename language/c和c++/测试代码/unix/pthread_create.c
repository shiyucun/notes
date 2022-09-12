
// pthread_create函数的使用
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *task(void *p) {
  int i = 0;
  while (i < 101) {
    printf("我是子线程%d！\n", i);
    i++;
  }
}

int main() {
  // typedef unsigned long int pthread_t;
  pthread_t tid;
  // 创建子线程
  pthread_create(&tid, NULL, task, NULL);

  // int i = 0;
  // while (i < 101) {
  //   printf("我是主线程%d！\n", i);
  //   i++;
  // }

  pthread_t tidmain = pthread_self();
  printf("tid = %lu, tid2 = %lu\n", tid, tidmain);

  return 0;
}
