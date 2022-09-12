
// pthread_exit函数的使用
#include <pthread.h>
#include <stdio.h>

void *task(void *p) {
  int i = 1;
  while (i < 100) {
    printf("%d\n", i);
    i++;
    // i=10退出
    if (i == 10) {
      // bread;
      pthread_exit((void *)i);
    }
  }
}

int main() {
  // typedef unsigned long int pthread_t;
  pthread_t tid;

  // 创建子线程
  pthread_create(&tid, NULL, task, NULL);

  // 等待子线程结束
  int p = 0;
  pthread_join(tid, (void **)&p);

  printf("i的值是%d\n", p);

  return 0;
}
