
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
  struct stat st;

  stat("a.txt", &st);
  printf("权限: %o, 大小: %ld\n", st.st_mode&0777, st.st_size);

  chmod("a.txt", 0774);
  truncate("a.txt", 20);

  stat("a.txt", &st);
  printf("权限: %o, 大小: %ld\n", st.st_mode&0777, st.st_size);

  return 0;
}
