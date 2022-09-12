
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开/创建文件
  int fd = open("d.txt", O_RDONLY);  // 只读
  if (-1 == fd) {
    perror("open"), exit(-1);
  }
  printf("d.txt读取成功！\n");

  char buffer[20];
  ssize_t res = read(fd, buffer, 15);
  // 上面读取的时候，如果之前写入了'\0'，则没有问题；
  // 如果没有写入'\0'，则读取时候要加入'\0'，否则以字符串输出时会出现乱码。
  // 或者将接收缓冲区初始化，即令所有的值全部为0，这时0即为'\0'，则可以正常结束字符串输出。
  if (-1 == res) {
    perror("read"), exit(-1);
  }
  printf("读取成功！大小是：%d。\n内容是：%s\n", res, buffer);

  // 关闭文件
  close(fd);

  return 0;
}
