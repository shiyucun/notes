/* #pragma的使用 */

#include <stdio.h>

#pragma GCC dependency "line.c"

int main() {
  printf("查看依赖文件的效果\n");
  return 0;
}
