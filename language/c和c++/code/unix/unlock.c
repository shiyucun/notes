
// 解锁
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // open
  int fd = open("b.txt", O_RDWR);
  if (-1 == fd) {
    perror("a.txt"), exit(-1);
  }

  // 准备一把锁
  struct flock lock;
  lock.l_type = F_RDLCK;
  lock.l_whence = SEEK_SET;
  lock.l_start = 0;
  lock.l_len = 10;
  lock.l_pid = -1;

  // 加锁
  int flag = fcntl(fd, F_SETLK, &lock);

  // write
  if (flag == -1) {
    perror("fcntl"), exit(-1);
  }

  printf("加锁成功！开始使用...\n");

  sleep(10);

  printf("使用结束，开始释放锁...\n");

  lock.l_type = F_UNLCK;

  flag = fcntl(fd, F_SETLK, &lock);

  if (-1 == flag) {
    perror("fcntl2"), exit(-1);
  }

  printf("成功释放！\n");

  sleep(10);

  printf("等待完毕程序结束\n");

  // close
  close(fd);

  return 0;
}
