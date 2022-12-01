
// pthread_create函数的使用
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *task(void *p) {
  int *pi = p;
  *pi = 200;
}

int main() {
  // 定义变量对子线程传递参数
  int num = 100;

  // typedef unsigned long int pthread_t;
  pthread_t tid;

  // 创建子线程
  pthread_create(&tid, NULL, task, &num);

  sleep(1);
  // 多个线程共享进程中的内存资源
  printf("num = %d\n", num);

  return 0;
}
