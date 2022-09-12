
// fcntl 函数中 F_GETLK 的使用
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  ssize_t fd = open("a.txt", O_RDWR);
  if (fd == -1) {
    perror("open"), exit(-1);
  }

  struct flock lock;

  lock.l_type = F_RDLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 10;
  lock.l_pid = -1;

  int res = fcntl(fd, F_GETLK, &lock);

  if (res == -1) {
    perror("fcntl"), exit(-1);
  } else if (F_UNLCK == lock.l_type) {
    printf("文件无锁！\n");
  } else {
    printf("文件有锁!\n");
  }

  close(fd);

  return 0;
}
