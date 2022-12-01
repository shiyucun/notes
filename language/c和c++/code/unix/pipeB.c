
// 从管道文件中读取数据
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开管道文件
  int fd = open("b.pipe", O_RDONLY);
  if (-1 == fd) {
    perror("a.pipe"), exit(-1);
  }

  // 循环读取
  int buffer = 0;
  int i = 0;
  for (i = 0; i < 100; i++) {
    read(fd, &buffer, sizeof(int));
    printf("%d\n", buffer);
  }

  // 关闭文件
  close(fd);

  return 0;
}
