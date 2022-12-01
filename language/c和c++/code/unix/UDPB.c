
// 基于UDP协议的客户端
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

  // 通信
  char buf[100] = {};
  scanf("%s", buf);
  sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
  read(sockfd, buf, sizeof(buf));
  printf("数据是：%s\n", buf);

  // 关闭
  close(sockfd);

  return 0;
}
