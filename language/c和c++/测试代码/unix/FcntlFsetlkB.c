
// fcntl 函数中 F_SETLK 选项的使用
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // open a file
  int fd = open("a.txt", O_RDWR);
  if (-1 == fd) {
    perror("open a.txt"), exit(-1);
  }
  // printf("成功打开文件！\n");

  // ready a lock
  struct flock lock;
  lock.l_type = F_RDLCK;     // read lock
  lock.l_whence = SEEK_SET;  // at the begin of the file
  lock.l_start = 0;          // offset
  lock.l_len = 10;           // the number of lock bytes
  lock.l_pid = -1;
  // printf("锁已经准备好！\n");

  // put a lock on the file and use the file
  int res = fcntl(fd, F_SETLK, &lock);
  if (-1 == res) {
    perror("fcntl"), exit(-1);
  }
  // use
  printf("成功加锁！开始使用文件....\n");
  sleep(20);
  // printf("文件使用结束！\n");

  // close the file
  close(fd);

  return 0;
}
