
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

int main() {
  struct stat st;

  int res = stat("../stat.c", &st);
  if (res == -1) {
    perror("stat"), exit(-1);
  }

  printf("类型和权限：%o\n", st.st_mode);
  printf("大小：%ld\n", st.st_size);
  printf("最后修改时间：%ld\n", st.st_mtime);
  printf("%s", ctime(&st.st_mtime));

  struct tm *pt = localtime(&st.st_mtime);
  printf("%d:%d:%d--%d:%d:%d\n",
          pt->tm_year + 1900, pt->tm_mon + 1,
          pt->tm_mday, pt->tm_hour,
          pt->tm_min, pt->tm_sec);

  return 0;
}
