
// 使用无名管道进行通信
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <unistd.h>

int main() {
  int fds[2];

  // 创建管道文件，返回读写描述符
  if (-1 == pipe(fds)) {
    perror("pipe"), exit(-1);
  }

  // 创建子进程，父子间进程通信
  pid_t pid = fork();
  if (0 == pid) {
    // 关闭写端
    close(fds[1]);
    int i = 0;
    for (i = 0; i < 100; i++) {
      int x = 0;
      read(fds[0], &x, sizeof(int));
      printf("%d ", x);
      fflush(stdout);
    }
    printf("\n");
    close(fds[0]);
    exit(0);
  }

  close(fds[0]);
  int i = 0;
  for (i = 0; i < 100; i++) {
    write(fds[1], &i, sizeof(int));
    usleep(10000);
  }
  close(fds[1]);

  return 0;
}
