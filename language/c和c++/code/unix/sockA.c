
// 基于本地通信的服务器端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <unistd.h>

int main() {
  // 创建 socket
  int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);
  if (-1 == sockfd) {
    perror("socket"), exit(-1);
  }

  // 准备通信地址
  struct sockaddr_un addr;
  addr.sun_family = AF_UNIX;
  strcpy(addr.sun_path, "a.sock");

  // 绑定
  int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("bind"), exit(-1);
  }
  printf("bind succeed!\n");

  // 通信
  char buf[100] = {};
  res = read(sockfd, buf, sizeof(buf));
  if (-1 == res) {
    perror("write"), exit(-1);
  }
  printf("数据是：%s，大小是：%d。\n", buf, res);

  // 关闭
  close(sockfd);

  return 0;
}
