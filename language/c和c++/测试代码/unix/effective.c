
// 用标 C 函数实现将 0~100 万的整数写入文件中

#include <stdio.h>
#include <stdlib.h>

int main() {
  // 打开/创建文件
  FILE *fp = fopen("num.dat", "wb+");
  if (NULL == fp) {
    perror("fopen"), exit(-1);
  }

  // 写入数据
  int i = 0;
  while (i <= 1000000) {
    fwrite(&i, sizeof(int), 1, fp);
    i++;
  }

  // 关闭文件
  fclose(fp);
  fp = NULL;

  return 0;
}
