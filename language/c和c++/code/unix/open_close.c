
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  printf("O_RDONLY = %d\nO_WRONLY = %d\nO_RDWR = %d\nO_APPEND = %d\n"
         "O_CREAT = %d\nO_EXCL = %d\nO_TRUNC = %d\n",
         O_RDONLY, O_WRONLY, O_RDWR, O_APPEND, O_CREAT, O_EXCL, O_TRUNC);
  // 打开或创建文件,系统可能会自动的屏蔽某些权限，因此最后一个参数不一定按照预想的权限分配给指定的用户
  int fd = open("open_close.txt", O_CREAT |   // 创建
                                  // O_EXCL | // 存在则创建失败
                                  O_RDONLY |  // 只读
                                  O_TRUNC,    // 文件截断
                                  0666);      // 权限
  if (-1 == fd) {
    perror("open"), exit(-1);
  }
  printf("创建成功");

  //关闭文件
  close(fd);

  return 0;
}
