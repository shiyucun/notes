
// umask 函数的使用
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 一般来说系统默认屏蔽 0002 权限
  mode_t old = umask(0055);
  printf("旧权限屏蔽字是(八进制)：%o\n", old);

  ssize_t fd = open("b.txt", O_CREAT | O_EXCL | O_RDWR, 0777);
  if (-1 == fd) {
    perror("open"), exit(-1);
  }

  //恢复系统默认的屏蔽字
  umask(old);

  //重新获取文件权限
  struct stat st;
  fstat(fd, &st);
  printf("获取的文件权限是：%o\n", st.st_mode & 0777);

  close(fd);

  return 0;
}
