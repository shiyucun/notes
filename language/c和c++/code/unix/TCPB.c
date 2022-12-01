
// 基于 TCP 通信的客户端
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  // create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (-1 == sockfd) {
    perror("socket"), exit(-1);
  }

  // ready address
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8888);
  addr.sin_addr.s_addr = inet_addr("172.30.9.101");
  // connect
  int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("connect"), exit(-1);
  }
  printf("connect succeed!\n");

  // 通信
  char buf[100] = {};
  scanf("%s", buf);
  res = write(sockfd, buf, strlen(buf) + 1);
  if (res == -1) {
    perror("write"), exit(-1);
  }

  res = read(sockfd, buf, sizeof(buf));
  if (res == -1) {
    perror("read"), exit(-1);
  }
  printf("数据是：%s大小是：%d。\n", buf, res);

  // 关闭
  close(sockfd);

  return 0;
}
