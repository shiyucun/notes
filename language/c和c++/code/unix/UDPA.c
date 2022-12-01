
// 基于 UDP 协议的服务器端
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // 创建
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket"), exit(-1);
  }

  // 准备通信地址
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8888);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // 绑定
  int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("bind"), exit(-1);
  }
  printf("bind succeed!\n");

  // 通信
  char buf[100] = {};

  // read( sockfd, buf, sizeof(buf) );

  struct sockaddr_in rcvAddr;
  socklen_t len = sizeof(rcvAddr);
  recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&rcvAddr, &len);
  printf("数据是：%s\n", buf);

  sendto(sockfd, "I received!", 12, 0, (struct sockaddr *)&rcvAddr, sizeof(rcvAddr));

  // 关闭
  close(sockfd);

  return 0;
}
