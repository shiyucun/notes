
// 基于 TCP 通信的服务器端
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
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

  // 解决被占用的问题
  int reuseaddr = 1;
  setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

  // bind
  int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
  if (-1 == res) {
    perror("bind"), exit(-1);
  }
  printf("bind succeed!\n");

  // listen
  res = listen(sockfd, 100);
  if (-1 == res) {
    perror("listen"), exit(-1);
  }
  printf("listen succeed!\n");

  // 响应
  struct sockaddr_in rcvAddr;
  socklen_t len = sizeof(rcvAddr);
  int fd = accept(sockfd, (struct sockaddr *)&rcvAddr, (socklen_t *)&len);
  if (-1 == fd) {
    perror("accept"), exit(-1);
  }
  // 将客户端ip打印出来
  char *ip = inet_ntoa(rcvAddr.sin_addr);
  printf("客户端%s连接成功！\n", ip);

  // 通信
  char buf[100] = {};
  res = read(fd, buf, sizeof(buf));
  if (res == -1) {
    perror("read"), exit(-1);
  }
  printf("数据是：%s大小是：%d\n", buf, res);

  res = write(fd, "I received!", 12);
  if (res == -1) {
    perror("write"), exit(-1);
  }

  // 关闭
  close(sockfd);

  return 0;
}
