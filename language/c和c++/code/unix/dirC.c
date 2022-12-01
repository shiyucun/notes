
//递归目录中的内容

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void print(char *path) {
  // 打开指定的目录
  DIR *dir = opendir(path);
  if (NULL == dir) {
    return;
  }

  // 循环读取目录中的内容
  struct dirent *ent;
  while ((ent = readdir(dir)) != NULL) {
    // 如果是目录，先打印，排除特殊目录 . 和 ..，再进行递归打印
    if (4 == ent->d_type) {
      printf("[%s]:%d\n", ent->d_name, ent->d_type);

      if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")) {
        continue;
      }

      // 拼接新的路径
      char buf[512] = {0};
      sprintf(buf, "%s/%s", path, ent->d_name);

      print(buf);
    }

    if (8 == ent->d_type) {
      printf("%s:%d\n", ent->d_name, ent->d_type);
    }
  }
}

int main() {
  print(".");
  return 0;
}
