
// brk 函数的使用

#include <stdio.h>
#include <unistd.h>

int main() {
  void *p = sbrk(0);  // 获取当前指针位置
  printf("%p\n", p);

  brk(p + 4);  // 申请四个字节
  void *cur = sbrk(0);  // 再次获取当前指针位置
  printf("%p\n", cur);

  brk(p + 8);  // 申请四个字节
  cur = sbrk(0);  // 再次获取当前指针位置
  printf("%p\n", cur);

  brk(p + 4);  // 释放四个字节
  cur = sbrk(0);  // 再次获取当前指针位置
  printf("%p\n", cur);

  int *pi = p;
  *pi = 250;
  printf("*pi = %d\n", *pi);

  brk(p);
  p = NULL;

  cur = sbrk(0);  // 再次获取当前指针位置
  printf("%p\n", cur);

  return 0;
}
