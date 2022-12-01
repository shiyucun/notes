
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开/创建文件
  int fd = open("d.txt", O_CREAT |  // 创建
                         O_EXCL |   // 存在则创建失败
                         O_WRONLY,  // 只读
                         0666);
  if (-1 == fd) {
    perror("open"), exit(-1);
  }
  printf("d.txt创建成功！");

  char *buffer = "我爱学习！";
  ssize_t res = write(fd, buffer, 15);
  // 上面写入的时候如果buffer直接是一个字符串，当写入的大小是字符长度+1或更长时，最后一个写入'\0'；
  // 否则不写入'\0'，不写入时读取的时候要加入'\0'，
  // 读取并且以字符串的方式输出的时候才能正常结束，
  // 要不然会出现乱码(可以将接收缓冲区初始化，因为'\0'字符对应0)。

  if (-1 == res) {
    perror("write"), exit(-1);
  }
  printf("写入成功！大小是：%d\n", res);

  // 关闭文件
  close(fd);

  return 0;
}
