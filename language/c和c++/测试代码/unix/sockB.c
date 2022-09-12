
// 基于本地通信的客户端
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

  // 连接
  int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("connect"), exit(-1);
  }
  printf("connect succeed!\n");

  // 通信
  char buf[100] = {};
  scanf("%s", buf);
  res = write(sockfd, buf, strlen(buf));
  if (-1 == res) {
    perror("write"), exit(-1);
  }

  // 关闭
  close(sockfd);

  return 0;
}
