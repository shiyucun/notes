
// 基于网络通信的客户端
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 创建 socket
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (-1 == sockfd) {
    perror("socket"), exit(-1);
  }

  // 准备通信地址
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8888);
  addr.sin_addr.s_addr = inet_addr("172.30.9.101");

  // 连接
  int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("bind"), exit(-1);
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
