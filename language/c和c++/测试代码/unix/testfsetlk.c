
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // open
  int fd = open("a.txt", O_RDWR);
  if (-1 == fd) {
    perror("a.txt"), exit(-1);
  }

  // 准备一把锁
  struct flock lock;
  lock.l_type = F_WRLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 10;
  lock.l_pid = -1;

  // 加锁
  int flag = fcntl(fd, F_SETLK, &lock);

  // write
  if (flag == -1) {
    printf("加锁失败！不允许写操作！\n");
  } else {
    printf("加锁成功！\n");
    write(fd, "hello", 5);
  }

  // close
  close(fd);

  return 0;
}
