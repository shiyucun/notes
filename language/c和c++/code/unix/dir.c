
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 打开目录
  DIR *dir = opendir(".");
  if (dir == NULL) {
    perror("opendir"), exit(-1);
  }

  // 循环读取目录中的内容
  struct dirent *ent = readdir(dir);
  while (ent) {
    printf("类型是:%d,名称是：%s\n", ent->d_type, ent->d_name);
    // 读取下一个内容
    ent = readdir(dir);
  }

  char buf[256] = {0};
  char *p = getcwd(buf, sizeof(buf));

  printf("当前路径是：%s, %s\n", buf, p);

  return 0;
}
