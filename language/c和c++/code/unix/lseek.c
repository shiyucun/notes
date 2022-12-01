
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开文件
  int fd = open("a.txt", O_RDWR);
  if (-1 == fd) {
    perror("open");
    return -1;
  }
  printf("成功打开文件a.txt！\n");
  // a.txt 中存储 abcdefghijklmn：vi 中默认在文件末尾加一个'\n'

  // 操作文件
  char ch;
  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // a

  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // b

  lseek(fd, 3, SEEK_CUR);
  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // f

  lseek(fd, 0, SEEK_SET);
  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // a

  // "B" 表示字符串，函数中需要指针时放进去表示地址；'B'，表示字符，不能够当作地址使用
  write(fd, "B", sizeof(char));

  // 文件中读写使用的是同一个定位指针，写完成后如果不是指在要操作的位置需要重新定位
  lseek(fd, -1, SEEK_CUR);
  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // B

  // 文件末尾指的是最后一个字符的后面，这个位置没有有效字符，而且vi编辑器在文件末尾自动加一个'\n'
  lseek(fd, -2, SEEK_END);
  read(fd, &ch, sizeof(char));
  printf("%c\n", ch);  // n

  close(fd);

  return 0;
}
