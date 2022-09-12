
// malloc 可能额外申请 12 个字节，储存申请的空间信息，这 12 个字节不能更改，否则段错误
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *p1 = (int *)malloc(4);
  int *p2 = (int *)malloc(4);
  int *p3 = (int *)malloc(4);
  int *p4 = (int *)malloc(4);

  printf("%p\n", p1);
  printf("%p\n", p2);
  printf("%p\n", p3);
  printf("%p\n", p4);

  printf("-----------------------------------------\n");

  *p1 = 1;
  //*(p1+1) = 2;
  //*(p1+2) = 3;
  //*(p1+3) = 4;
  *(p1 + 4) = 5;  // 指向 p2

  printf("%d %d\n", *p1, *p2);

  free(p1);
  p1 = NULL;

  return 0;
}
