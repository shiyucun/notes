
// pthread_create函数的使用
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *task(void *p) {
  int i = 1, sum = 0;
  int *pi = p;
  while (i <= (*pi)) {
    sum += i;
    i++;
  }

  int *psum = (int *)malloc(sizeof(int));
  *psum = sum;

  return psum;
}

int main() {
  // 定义变量对子线程传递参数
  int num = 0;
  printf("请输入一个整数：");
  fflush(stdout);
  scanf("%d", &num);

  // typedef unsigned long int pthread_t;
  pthread_t tid;

  // 创建子线程
  pthread_create(&tid, NULL, task, &num);

  int *p = NULL;
  // 等待子线程终止
  pthread_join(tid, (void **)&p);

  printf("1到整数%d之间的和是:%d\n", num, *p);

  return 0;
}
