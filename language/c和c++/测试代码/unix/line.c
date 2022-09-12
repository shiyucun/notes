
// 预处理指令 #line 的使用
#include <stdio.h>

#line 200

int main() {
  double f = 100.1;
  printf("编译输出 warning %u\n", f);
  return 0;
}
