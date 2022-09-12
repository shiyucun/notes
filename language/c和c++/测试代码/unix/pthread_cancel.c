
// pthread_cancel函数的使用
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void *task(void *p) {
  // 线程默认是可以被取消的，下面这句话设置为不可以被取消
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

  while (1) {
    printf("I am stronger!\n");
    usleep(100000);
  }
}

void *task2(void *p) {
  printf("开始取消线程...\n");
  sleep(2);
  printf("取消线程！\n");
  pthread_cancel(*(pthread_t *)p);
}

int main(void) {
  // 创建一个线程
  pthread_t tid, tid2;

  pthread_create(&tid, NULL, task, NULL);
  pthread_create(&tid2, NULL, task2, &tid);

  pthread_join(tid, NULL);
  pthread_join(tid2, NULL);

  return 0;
}
