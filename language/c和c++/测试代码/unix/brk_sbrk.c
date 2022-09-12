
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
  void *p = sbrk(0);

  int *p_int = (int *)sbrk(sizeof(int));
  *p_int = 66;

  double *p_double = (double *)sbrk(sizeof(double));
  *p_double = 3.14;

  char *p_char = (char *)sbrk(10 * sizeof(char));
  p_char = "hello";

  printf(" %p\n %p\n %p\n %p\n", p, p_int, p_double, p_char);
  // p 和 p_int 的值相同，因为申请空间时返回的为申请的空间的首地址，
  // 因此不必额外读取申请之前的地址，即可在后面释放，但是在整个过程中指针的指向不能改变

  printf(" %d\n %lf\n %s\n", *p_int, *p_double, p_char);

  brk(p);
  p = NULL;

  return 0;
}
