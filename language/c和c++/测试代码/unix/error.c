/* #error和#warning的使用 */

#include <stdio.h>

#define VERSION 3

#if (VERSION < 3)
#error "版本低"
#elif (VERSION > 3)
#warning "版本高"
#endif

int main() {
  printf("error 和 warning 的区别\n");
  return 0;
}
