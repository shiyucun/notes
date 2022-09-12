
#include <stdio.h>
#include <string.h>

// 打印环境表中的所有内容
void PrintEnvs() {
  // environ 存储的是环境表的首地址，不能更改，更改后系统不能再次找到环境表首地址
  extern char **environ;

  char **p = environ;

  while (*p) {
    printf("%s\n", *p++);
    // char *arr[20];
    // arr 指针数组中存储了所有环境变量的地址，它是一个一维数组，每个变量占用四个字节存储地址
    // 一个指针 p 指向 arr 时需要是一个二维指针，
    // 访问当前指向的指针数组的下一个元素时，是对这个二级指针进行+1操作则指向了下一个元素
    // p=&arr[0]; *p=arr[0];
  }
}

int main() {
  PrintEnvs();

  extern char **environ;
  char **p = environ;

  while (*p) {
    if (!strncmp(*p, "SHELL", 5)) {
      printf("%s\n", *p);
      break;
    }
    p++;
  }

  return 0;
}
