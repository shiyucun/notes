
// pthread_join函数的使用
#include <pthread.h>
#include <stdio.h>

void *task(void *p) {
  // 不能返回局部变量的地址
  // char str[] = "abcd";

  // 只读常量区
  char *ps = "abcd";
  return ps;  // 返回字符串地址
}

int main(void) {
  pthread_t tid;
  pthread_create(&tid, NULL, task, NULL);

  char *pc = NULL;
  pthread_join(tid, (void **)&pc);
  printf("pc = %s\n", pc);

  return 0;
}
