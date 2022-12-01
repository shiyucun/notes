
// 使用 UC 函数实现 0~100 万存储到文件中
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  ssize_t fd = open("store.dat", O_CREAT | O_EXCL | O_WRONLY, 0666);
  if (fd == -1) {
    perror("open"), exit(-1);
  }

  int i = 0;
  while (i <= 1000000) {
    write(fd, &i, sizeof(int));
    i++;
  }

  close(fd);

  return 0;
}
