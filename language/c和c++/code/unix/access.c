
#include <stdio.h>
#include <unistd.h>

int main() {
  if (0 == access("../access.c", F_OK)) {
    printf("文件存在！\n");
  }

  if (0 == access("../access.c", R_OK)) {
    printf("文件可读！\n");
  }

  if (0 == access("../access.c", W_OK)) {
    printf("文件可写！\n");
  }

  if (0 == access("../access.c", X_OK)) {
    printf("文件可以执行！\n");
  }

  return 0;
}
