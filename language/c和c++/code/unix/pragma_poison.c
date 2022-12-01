/* #pragma GCC poison 标识符 */

#include <stdio.h>

// #pragma GCC poison goto

int main() {
  goto ok;
  printf("main函数结束了\n");
ok:
  printf("goto到这里了\n");
  return 0;
}
