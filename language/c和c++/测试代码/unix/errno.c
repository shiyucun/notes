// error number(errno)的使用
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/etc/passwd1", "r");

  if (!fp) {
    printf("打开失败\n");
    printf("errno = %d\n", errno);
    printf("错误原因是:%s\n", strerror(errno));
    perror("错误原因是");
    printf("错误原因是:%m\n");
    return -1;
  }

  printf("打开成功\n");

  fclose(fp);
  fp = NULL;

  fp = fopen("/etc/passwd", "w");
  if (!fp) {
    printf("打开失败\n");
    printf("errno = %d\n", errno);
    printf("错误原因是:%s\n", strerror(errno));
    perror("错误原因是");
    printf("错误原因是:%m\n");
    return -1;
  }

  printf("打开成功\n");

  fclose(fp);
  fp = NULL;

  return 0;
}
