
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  int fd = open("b.txt", O_CREAT | O_EXCL | O_RDWR, 0666);
  if (-1 == fd) {
    perror("open"), exit(-1);
  }
  // fd 和 fd2 对应同一个文件表，从而也就对应同一个文件
  int fd2 = dup(fd);
  printf("fd = %d, fd2 = %d\n", fd, fd2);

  // fd 和 fd2 互相影响文件里面的定位指针，fd 操作文件时改变了文件里的指针，
  // 这时指针的指向在用 fd2 操作时同样有效
  write(fd, "A\n", 2);
  write(fd2, "B\n", 2);

  close(fd);
  close(fd2);

  return 0;
}
