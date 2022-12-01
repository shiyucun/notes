
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开/创建文件
  int fd = open("c.txt", O_CREAT | O_EXCL | O_RDWR, 0666);
  if (-1 == fd) {
    perror("open"), exit(-1);
  }

  // 操作
  // fd 和 fd2 对应同一个文件表，从而也就对应同一个文件
  int fd2 = dup(fd);
  printf("fd = %d, fd2 = %d\n", fd, fd2);

  // fd和fd2互相影响文件里面的定位指针，fd操作文件时改变了文件里的指针，这是指针的指向在用fd2操作时同样有效
  write(fd, "A\n", 2);
  write(fd2, "B\n", 2);

  int fd3 = open("c.txt", O_RDWR);
  if (-1 == fd3) {
    perror("open2"), exit(-1);
  }
  printf("fd3 = %d\n", fd3);

  // fd4 就是 fd3
  int fd4 = dup2(fd, fd3);
  // fd3 与 fd4 相等
  printf("fd3 = %d\n", fd3);
  printf("fd4 = %d\n", fd4);

  write(fd3, "1\n", 2);
  write(fd4, "2\n", 2);

  // 关闭文件
  close(fd);
  close(fd2);

  // 此时fd、fd2、fd3、fd4的值分别为3、4、5、5，当关闭了fd和fd2对b.txt的关联时，fd3、fd4的关联仍然存在，
  // 因为他们在文件表中存储的信息一样，从而后面写入3仍然可以访问
  // close(fd3);
  // close(fd4);

  write(fd3, "3\n", 2);

  return 0;
}
