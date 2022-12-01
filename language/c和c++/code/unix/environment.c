
// 环境表的相关函数的使用
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("获取环境变量的值：%s\n", getenv("SHELL"));
  printf("PATH=%s\n", getenv("PATH"));

  setenv("SHELL", "123", 0);  //修改失败
  printf("PATH=%s\n", getenv("SHELL"));

  setenv("SHELL", "123", 1);  //修改成功
  printf("PATH=%s\n", getenv("SHELL"));

  return 0;
}
