
// pthread_detach函数的使用
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *task(void *p) {
  int i = 1;
  printf("子线程：");
  while (i <= 20) {
    printf("%d ", i);
    i++;
    usleep(100000);
  }
  printf("\n");
}

int main(void) {
  // 创建一个线程
  pthread_t tid;
  pthread_create(&tid, NULL, task, NULL);

  // 分离
  pthread_detach(tid);

  // 等待
  pthread_join(tid, NULL);

  // 打印
  int i = 1;
  printf("主线程：");
  while (i <= 20) {
    printf("%d ", i);
    i++;
    usleep(100000);
  }
  printf("\n");

  return 0;
}
