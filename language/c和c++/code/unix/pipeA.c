
// 向管道文件中写入数据
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开管道文件
  int fd = open("b.pipe", O_WRONLY);
  if (-1 == fd) {
    perror("a.pipe"), exit(-1);
  }

  // 循环写入管道文件
  int i = 0;
  for (i = 0; i < 100; i++) {
    write(fd, &i, sizeof(int));
    usleep(100000);
  }

  // 关闭文件
  close(fd);

  return 0;
}
