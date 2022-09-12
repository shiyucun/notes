
// pthread_create函数的使用
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define pi 3.1415926

void *task(void *p) {
  float *r = p;
  printf("周长：%.2f;面积：%.2f。\n", 2 * pi * (*r), pi * (*r) * (*r));
}

int main() {
  // 定义变量对子线程传递参数
  float r = 0;
  printf("请输入半径：");
  fflush(stdout);
  scanf("%f", &r);

  // typedef unsigned long int pthread_t;
  pthread_t tid;

  // 创建子线程
  pthread_create(&tid, NULL, task, &r);

  // 等待子线程终止
  pthread_join(tid, NULL);

  return 0;
}
