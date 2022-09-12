
// 文件描述符的概念
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开文件
  ssize_t fd = open("a.txt", O_CREAT | O_RDWR, 0666);

  if (fd == -1) {
    perror("open"), exit(-1);
  }

  printf("文件打开成功，fd = %d\n", fd);

  // 关闭文件
  close(fd);

  return 0;
}
