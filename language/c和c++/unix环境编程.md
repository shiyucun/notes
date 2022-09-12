
# unix 环境编程

- [unix 环境编程](#unix-环境编程)
  - [网络常识](#网络常识)
  - [socket 通信模型](#socket-通信模型)
    - [一对一的通信模型](#一对一的通信模型)
      - [socket 相关函数](#socket-相关函数)
      - [通讯地址](#通讯地址)
      - [示例-本地通信](#示例-本地通信)
      - [示例-网络通信](#示例-网络通信)
    - [基于TCP协议的通信模型](#基于tcp协议的通信模型)
      - [tcp 相关函数](#tcp-相关函数)
      - [示例-基于TCP通信](#示例-基于tcp通信)
    - [基于UDP协议的通信模型](#基于udp协议的通信模型)
      - [udp 相关函数](#udp-相关函数)
      - [示例-基于UDP通信](#示例-基于udp通信)
  - [进程和多进程](#进程和多进程)
    - [进程相关命令](#进程相关命令)
    - [进程相关函数](#进程相关函数)
    - [终止进程](#终止进程)
    - [等待进程](#等待进程)
    - [进程中内存管理](#进程中内存管理)
      - [进程中内存区域的划分](#进程中内存区域的划分)
      - [虚拟地址和物理地址](#虚拟地址和物理地址)
      - [相关函数](#相关函数)
  - [进程间通信](#进程间通信)
    - [共享内存](#共享内存)
    - [管道](#管道)
    - [信号和信号集](#信号和信号集)
      - [信号](#信号)
      - [信号集](#信号集)
    - [消息队列](#消息队列)
  - [多线程](#多线程)
    - [解释](#解释)
    - [线程相关函数](#线程相关函数)
  - [线程同步](#线程同步)
    - [互斥锁](#互斥锁)
    - [信号量](#信号量)
  - [信号量集](#信号量集)
  - [计时器(SIGALRM)](#计时器sigalrm)
    - [计时器相关函数](#计时器相关函数)
    - [计时器的使用](#计时器的使用)
  - [目录](#目录)
  - [文件](#文件)
    - [C语言中文件相关函数](#c语言中文件相关函数)
    - [Unix C中文件相关函数](#unix-c中文件相关函数)
    - [文件描述符](#文件描述符)
    - [C和UC文件操作函数的区别](#c和uc文件操作函数的区别)
    - [文件锁](#文件锁)

---

## 网络常识

**ISO从逻辑上将网络划分成七层**：

- 应用层：主要用于与应用软件进行通讯
- 表示层：主要用于将数据封装成统一的规则
- 会话层：主要用于控制会话的开始和结束
- 传输层：主要用于控制数据的传输，体现逻辑概念
- 网络层：主要用于控制数据的传输和交换，体现物理概念
- 数据链路层：主要用于数据的转换
- 物理层：主要指路由器和交换机等设备

**相关的协议**：

- TCP：传输控制协议，面向连接的协议
- UDP：用户数据报协议，非面向连接的协议
- IP：互联网协议，上述两种协议的底层协议

**IP 地址**：

IP 地址是互联网中的唯一地址标识。

本质上 IP 地址就是一个整数，在 IPV4 中是32位，在 IPV6 中是128位。

网络编程中需要提供 IP 地址。

点分十进制表示法是描述 IP 地址的主要方式：每个字节转换为十进制数，中间用 '.' 隔开。

IP地址主要分为两部分：网络号和主机号。主要分为以下四类：

- A类：0 + 7位网络地址 + 24位主机地址
- B类：10 + 14位网络地址 + 16位主机地址
- C类：110 + 21位网络地址 + 8位主机地址
- D类：1110 + 28位多播地址

**子网掩码**：

主要用于和 IP 地址搭配使用，标识 IP 地址中网络号和主机号。

- `IP地址 & 子网掩码`：可以得到网络号
- `IP地址 & (~ 子网掩码)`：可以得到主机号

**MAC 地址(物理地址)**：

本质就是网卡设备的地址，MAC 地址绑定可以限制用户上网。

**端口号**：

IP 地址可以定位某一台主机，端口号主要用于定位主机上的某个进程。

端口号是`unsigned short`类型的，范围是`0~65535`，其中`0~1024`的端口号一般由系统占用。

网络编程中需要提供端口号。

**字节序**：

计算机存储整数，可以从高字节到低字节顺序存放，反之也可，因此提出了字节序的概念。

网络字节序(NBO network byte)：表示数据在网络中的存放次序(大端系统)。

主机字节序(HBO hostwork byte)：表示数据在本地存放的次序。

小端系统：表示低位数据存放在低位地址中。

大端系统：表示低位数据存放在高位地址中。

[大小端判断](../../嵌入式/体系结构/ARM/ARM工作模式和寄存器.md)

---

## socket 通信模型

### 一对一的通信模型

- 服务器端
  1. 创建socket，使用socket函数
  2. 准备一个通讯地址(结构体变量)
  3. 进行socket和通讯地址之间的绑定，使用bind函数
  4. 进行通信，使用read/write函数
  5. 关闭socket，使用close函数
- 客户端
  1. 创建socket，使用socket函数
  2. 准备一个通讯地址(结构体变量)
  3. 进行socket和通讯地址之间的连接，使用connect函数
  4. 进行通信，使用read/write函数
  5. 关闭socket，使用close函数

#### socket 相关函数

```c
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
    // 第一个参数：域，主要决定本地通信还是网络通信
    //              AF_UNIX/AF_LOCAL 本地通信
    //              AF_INET 基于IPV4的网络通信
    //              AF_INET6 基于IPV6的网络通信
    // 第二个参数：通讯的协议和方式
    //              SOCK_STREAM 数据流的通信，基于TCP协议
    //              SOCK_DGRAM 数据报的通信，基于UDP协议
    // 第三个参数：使用一些特殊的协议，一般给0即可
    // 返回值：成功返回一个socket的描述符，失败返回-1
    // 函数功能：创建一个socket作为通信载体

#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    // 第一个参数：socket描述符，即socket函数的返回值
    // 第二个参数：结构体指针，表示通信地址
    // 第三个参数：通信地址的大小（sizeof()）
    // 返回值：成功返回0，失败返回-1
    // 函数功能：主要用于绑定socket和通信地址

#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
    // 第一个参数：socket描述符，即socket函数的返回值
    // 第二个参数：结构体指针，表示通信地址
    // 第三个参数：通信地址的大小（sizeof()）
    // 返回值：成功返回0，失败返回-1
    // 函数功能：主要用于连接socket和通信地址

#include <arpa/inet.h>
uint32_t htonl(uint32_t hostlong);
uint16_t htons(uint16_t hostshort);
    // 函数功能：字节序转换函数，主机字节序转换为网络字节序
uint32_t ntohl(uint32_t netlong);
uint16_t ntohs(uint16_t netshort);
    // 函数功能：字节序转换函数，网络字节序转换为主机字节序

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
in_addr_t inet_addr(const char *cp);
    // 函数功能：转换参数中指定的地址的类型
char *inet_ntoa(struct in_addr in);
    // 函数功能：IP地址转换，将结构体类型的IP地址转换为字符串
```

#### 通讯地址

通用的通信地址，一般作为函数参数：

```c
struct sockaddr {
    sa_family_t sa_family;  // 域/协议簇
    char sa_data[14];       //表示一个地址
}
```

**本地通信**的结构体类型：

```c
#include <sys/un.h>
struct sockaddr_un {
    sa_family_t sun_family;  // 和socket第一参数保持一致
    char sun_path[];         // socket文件的路径
}
```

**网络通信**的结构体类型：

```c
#include <netinet/in.h>

// IPV4
struct sockaddr_in {
    sa_family_t sin_family;   // AF_INET,网络通信
    in_port_t sin_port;       // 端口号
    struct in_addr sin_addr;  // IP地址
}

struct in_addr {
    in_addr_t s_addr;  // IP地址
}

// IPV6
struct sockaddr_in6 {
    sa_family_t sin6_family;    // AF_INET6,网络通信
    in_port_t sin6_port;        // 端口号
    uint32_t sin6_flowinfo;     // traffic class and 信息流
    struct in6_addr sin6_addr;  // IP地址
    uint32_t sin6_scope_id;     // scope的接口
}

struct in6_addr {
    uint8_t s6_addr[16];  // IP地址
}
```

#### 示例-本地通信

```c
// 服务器端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_un addr;  // 准备通信地址
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "a.sock");

    int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 绑定
    if(-1 == res) {
        perror("bind");
        exit(-1);
    }

    char buf[100] = {};
    res = read(sockfd, buf, sizeof(buf));  // 读取数据
    if(-1 == res) {
        perror("write");
        exit(-1);
    }
    printf("数据是：%s，大小是：%d.\n", buf, res);

    close(sockfd);  // 关闭

    return 0;
}
```

```c
// 客户端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/un.h>
#include <sys/types.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_UNIX, SOCK_DGRAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror( "socket" );
        exit(-1);
    }

    struct sockaddr_un addr;  // 准备通信地址
    addr.sun_family = AF_UNIX;
    strcpy(addr.sun_path, "a.sock");

    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 连接
    if (-1 == res) {
        perror("connect");
        exit(-1);
    }

    char buf[100] = {};
    scanf("%s", buf);

    res = write(sockfd, buf, strlen(buf));  // 发送数据
    if (-1 == res) {
        perror("write");
        exit(-1);
    }

    close(sockfd);  // 关闭

    return 0;
}
```

#### 示例-网络通信

```c
// 服务器端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("172.30.9.101");

    int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 绑定
    if (-1 == res) {
        perror("bind");
        exit(-1);
    }

    char buf[100] = {};
    res = read(sockfd, buf, sizeof(buf));  // 读取数据
    if (-1 == res) {
        perror("read");
        exit(-1);
    }
    printf( "数据是：%s大小是：%d。\n", buf, res );

    close(sockfd);  // 关闭

    return 0;
}
```

```c
// 客户端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("172.30.9.101");

    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 连接
    if (-1 == res) {
        perror("bind");
        exit(-1);
    }

    char buf[100] = {};
    scanf("%s", buf);
    res = write(sockfd, buf, strlen(buf));  // 发送数据
    if (-1 == res) {
        perror("write");
        exit(-1);
    }

    close( sockfd );  // 关闭

    return 0;
}
```

### 基于TCP协议的通信模型

- 服务器端
  1. 创建socket，使用socket函数
  2. 准备通信地址，使用结构体变量：```struct sockaddr_in{}```
  3. 绑定socket和通信地址，使用bind函数
  4. 进行监听，使用listen函数
  5. 等待并且响应客户端的连接请求，使用accept函数
  6. 进行通信，使用read/write函数
  7. 关闭socket，使用close函数
- 客户端
  1. 创建socket，使用socket函数
  2. 准备通信地址，使用结构体变量
  3. 连接通信地址和socket，使用connect函数
  4. 进行通信，使用read/write函数
  5. 关闭socket，使用close函数

#### tcp 相关函数

```c
#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
int listen(int sockfd, int backlog);
    // 第一个参数：socket描述符，socket函数的返回值
    // 第二个参数：等待服务器响应的最大连接数
    // 函数功能：监听指定的socket上的连接请求
    // 返回值：成功0，失败-1

#include <sys/types.h> /* See NOTES */
#include <sys/socket.h>
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    // 第一个参数：socket描述符，socket函数的返回值
    // 第二个参数：存放客户端的地址信息
    // 第三个参数：存放客户端地址的大小
    // 返回值：成功返回进行通信的描述符，失败返回-1
    // 函数功能：等待客户端的连接请求，并且响应，如果没有客户端则连接阻塞
    // 注意：socket函数的返回值主要用于监听，accept函数的返回值主要用于通信
```

#### 示例-基于TCP通信

```c
// 服务器端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("172.30.9.101");

    int reuseaddr = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));  // 解决通信地址被占用的问题

    int res = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 绑定docket与通信地址
    if (-1 == res) {
        perror("bind");
        exit(-1);
    }

    res = listen(sockfd, 100);  // 监听
    if (-1 == res) {
        perror("listen");
        exit(-1);
    }

    struct sockaddr_in rcvAddr;
    socklen_t len = sizeof(rcvAddr);
    int fd = accept(sockfd, (struct sockaddr *)&rcvAddr, (socklen_t *)&len);
    if (-1 == fd) {
        perror("accept");
        exit(-1);
    }

    char *ip = inet_ntoa(rcvAddr.sin_addr);  // 打印客户端ip地址
    printf("客户端%s连接成功！\n", ip);

    char buf[100] = {};
    res = read(fd, buf, sizeof(buf));  // 读取数据
    if (res == -1) {
        perror("read");
        exit(-1);
    }
    printf("数据是：%s大小是：%d\n", buf, res);

    res = write(fd, "I received!", 12);  // 发送数据
    if (res == -1) {
        perror("write");
        exit(-1);
    }

    close(sockfd);  // 关闭

    return 0;
}
```

```c
// 客户端
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  // 创建socket
    if (-1 == sockfd) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("172.30.9.101");

    int res = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));  // 连接服务器
    if (-1 == res) {
        perror("connect");
        exit(-1);
    }

    char buf[100] = {};
    scanf("%s", buf);
    res = write(sockfd, buf, strlen(buf)+1);  // 向服务端发送数据
    if (res == -1) {
        perror("write");
        exit(-1);
    }

    res = read(sockfd, buf, sizeof(buf));  // 读取数据
    if (res == -1) {
        perror("read");
        exit(-1);
    }
    printf("数据是：%s大小是：%d。\n", buf, res);

    close(sockfd);  // 关闭

    return 0;
}
```

### 基于UDP协议的通信模型

TCP 协议：传输控制协议，面向连接的协议，在通信过程中一直保持连接。

优点：重发一切错误数据，保证数据的完整性和准确性。

缺点：服务器压力比较大，资源占用率比较高。

UDP 协议：用户数据报协议，非面向连接的协议，只有在发送数据的时候去连接。

优点：服务器压力比较小，效率比较高，资源占用率比较低。

缺点：不保证数据的完整性和准确性。

- 服务器端
  1. 创建socket，使用socket函数
  2. 准备通信地址，使用结构体变量
  3. 进行绑定，使用bind函数
  4. 进行通信，使用recvfrom/sendto函数
  5. 关闭socket，使用close函数

- 客户端
  1. 创建socket，使用socket函数
  2. 准备通信地址，使用结构体变量
  3. 进行通信，使用recvfrom/sendto函数
  4. 关闭socket，使用socket函数

#### udp 相关函数

```c
#include <sys/types.h>
#include <sys/socket.h>
ssize_t sendto(int sockfd, const void *buf, size_t len,
    int flags, const struct sockaddr *dest_addr, socklen_t addrlen);
    // 第一个参数：socket描述符，socket函数的返回值
    // 第二个参数：被发送的数据的首地址
    // 第三个参数：发送数据的大小
    // 第四个参数：发送标志，给0即可
    // 第五个参数：接收数据的通信地址
    // 第六个参数：接收方通信地址的大小
    // 返回值：成功返回发送的字节数，失败返回-1
    // 函数功能：向指定的目的地发送指定的数据

#include <sys/types.h>
#include <sys/socket.h>
ssize_t recvfrom(int sockfd, void *buf, size_t len,
    int flags, struct sockaddr *src_addr, socklen_t *addrlen);
    // 第一个参数：socket描述符，socket函数返回值
    // 第二个参数：存放数据的首地址
    // 第三个参数：接收数据的大小
    // 第四个参数：接收标志，给0即可
    // 第五个参数：保存发送方的地址信息
    // 第六个参数：发送方地址的大小
    // 返回值：成功返回接收到的数据的大小，失败返回-1
    // 函数功能：接收消息，并且存储发送方地址信息
```

#### 示例-基于UDP通信

```c
// 服务器端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // 创建socket
    if (sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int res = bind(sockfd, (struct sockaddr*)&addr, sizeof(addr));  //绑定
    if (-1 == res) {
        perror("bind");
        exit(-1);
    }

    char buf[100] = {};
    struct sockaddr_in rcvAddr;
    socklen_t len = sizeof(rcvAddr);

    recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&rcvAddr, &len);  // 接收数据
    printf("数据是：%s\n", buf);

    sendto(sockfd, "I received!", 12, 0, (struct sockaddr *)&rcvAddr, sizeof(rcvAddr)); // 发送数据

    close(sockfd);  // 关闭

    return 0;
}
```

```c
// 客户端
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);  // 创建socket
    if (sockfd == -1) {
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in addr;  // 准备通信地址
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    char buf[100] = {};
    scanf("%s", buf);

    sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));  // 发送数据

    // read(sockfd, buf, sizeof(buf));
    struct sockaddr_in rcvAddr;
    socklen_t len = sizeof(rcvAddr);
    recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&rcvAddr, &len);  // 接收数据

    printf("数据是：%s\n", buf);

    close(sockfd);  // 关闭

    return 0;
}
```

---

## 进程和多进程

如果进程A启动了进程B，则将A称为B的父进程，B称为A的子进程。

一般来说，操作系统中进程0是系统内部的进程，负责启动进程1(init)和进程2。

其他所有进程都是由进程1和进程2直接或者间接启动的。

进程号是进程的唯一标识。进程号可以延迟重用。

### 进程相关命令

|命令|作用|说明|
|---|---|---|
|ps|查看进程|PID(进程号)<br>TTY(终端号)<br>TIME(消耗的CPU时间)|
|ps -aux|显示所有进程<br>(其他使用者的进程也会显示)|USER(进程属主)<br>PID(进程号)|
|ps -aux \| more|分屏显示||
|ps -ef|全格式显示所有进程|PPID(父进程的ID)|
|ps -ef \| more|分屏显示||
|Kill -9 进程号|杀死指定的进程||

### 进程相关函数

获取进程信息：

```c
getpid()     // 获取当前进程号
getppid()    // 获取父进程号
getuid()     // 获取用户id
getgid()     // 获取用户组id
```

创建子进程：

```c
#include <unistd.h>
pid_t fork(void);
    // 函数功能：
    //     复制当前正在运行的进程的方式去创建一个新的进程
    //     新进程作为子进程，正在运行的进程作为父进程
    // 返回值：
    //     失败父进程返回-1，子进程无返回值
    //     成功父进程返回子进程pid，子进程返回0

    // 一般的执行原则：
    //     a：fork之前的代码，父进程执行一次
    //     b：fork之后的代码，父子进程各自执行一次
    //     c：fork函数的返回值有两个，父子进程各自返回
    // 注意：父子进程之间的执行次序是不固定的，取决于操作系统

    // 父子进程之间的内存区域关系：
    //     当创建子进程时，子进程会复制父进程中除了代码区以外的其他内存区域，代码区和父进程共用

    // 父子进程之间的关系：
    //     a.父进程启动子进程，父子进程各自独立运行
    //     b.如果子进程先结束，会给父进程发送信号，由父进程帮助回收子进程的相关资源
    //     c.如果父进程先结束，子进程会变成孤儿进程，子进程会变更父进程(一般为init进程)
    //     d.如果子进程结束但父进程没有收到信号，则子进程资源无法及时回收，变更为僵尸进程
    
    // 父进程创建两个子进程:
    //     fork();
    //     if (0 != pid) {
    //         fork();
    //     }
```

其它函数：

```c
#include <sys/types.h>
#include <unistd.h>
pid_t vfork(void);
    // 函数功能：与fork函数类似，不复制父进程的内存空间，而是直接使用父进程的内存空间
    // 注意：使用vfork创建的子进程先于父进程执行

#include <unistd.h>
extern char **environ;
int execl(const char *path, const char *arg, ...);
int execlp(const char *file, const char *arg, ...);
int execle(const char *path, const char *arg, ..., char * const envp[]);
int execv(const char *path, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],char *const envp[]);
    // 第一个参数：可执行文件的路径
    // 第二个参数：可执行文件名/选项
    // 第三个参数：可变长参数，可以有很多参数，最后使用一个空指针NULL终止
    // 返回值：只有出错才有返回值，值为-1
    // 函数功能：按照参数的要求进行跳转执行
    // 如：
    //     whereis ls → 查看ls所在的位置
    //     execl("/bin/ls", "ls", "-l", NULL);
    // 注意：vfork函数本身没有太大作用，一般与exec系列函数搭配使用

#include <stdlib.h>
int system(const char *command);
    // 函数功能：执行参数指定的shell命令行
```

`fork`和`vfork`子进程对信号处理方式的比较

- fork创建的子进程，完全照搬父进程对信号的处理方式
  1. 父进程忽略处理，子进程也忽略
  2. 父进程默认处理，子进程也默认处理
  3. 父进程自定义处理，子进程也自定义处理
- vfork创建的子进程
  1. 父进程自定义处理，子进程默认处理
  2. 父进程忽略处理，子进程忽略处理
  3. 父进程默认处理，子进程默认处理

### 终止进程

分为：正常终止和非正常终止：

- 正常终止：
  1. main 函数中执行了`return 0`
  2. 使用`exit()`函数
  3. 调用`_exit()`/`_Exit()`函数
  4. 最后一个线程返回
  5. 最后一个线程调用了`pthread_exit()`函数
- 非正常终止：
  1. 使用信号终止
  2. 最后一个线程被其他线程取消

```c
#include <unistd.h>
void _exit(int status);  // UC函数

#include <stdlib.h>
void _Exit(int status);  // C函数
    // 参数：表示进程的退出状态/退出码
    // 函数功能：立即终止运行的进程

#include <stdlib.h>
void exit(int status);
    // 函数功能：退出过程中会调用 atexit() 和 on_exit() 注册的函数

#include <stdlib.h>
int atexit(void (*function)(void));
    // 函数功能：注册参数指定的函数，等待 exit() 函数的调用
```

### 等待进程

1. 调用`wait()`/`waitpid()`函数，父进程开始等待子进程的状态改变，父进程进入阻塞状态
2. 如果没有子进程，父进程立即返回
3. 如果没有子进程结束，父进程保持阻塞状态，直到有一个符合的子进程状态发生改变
4. 如果有子进程结束，父进程获取子进程的退出状态(`return`/`exit()`的返回值)并返回

```c
#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *status);
    // 函数功能：
    //     表示挂起正在执行的进程，直到子进程的状态发生改变(子进程结束只是状态改变中的一种)
    //     通过参数将退出码返回
    // 返回值：
    //     成功返回所等待进程(子进程)的PID，失败返回-1
    // status 可用于：
    //     WIFEXITED(status)：判断等待的进程是否正常结束
    //     WEXITSTATUS(status)：获取所等待进程的退出状态信息/退出码

pid_t waitpid(pid_t pid, int *status, int options);
    // 第一个参数：进程号
    //     <-1：表示等待进程组 id 为 pid 绝对值的任何一个子进程
    //     =-1：表示等待任何一个子进程
    //     =0：表示等待与调用的子进程在同一个进程组的任何子进程
    //     >0：表示等待进程号为 pid 的子进程
    // 第二个参数：获取退出状态信息
    // 第三个参数：等待的模式，一般默认给 0 即可
    // 返回值：成功返回等待的进程号，失败返回-1
    // 函数功能：等待进程号为pid的子进程状态发生改变

// 注意：wait(&status) = waitpid(-1, &status, 0)
```

### 进程中内存管理

#### 进程中内存区域的划分

进程中内存地址从小到大依次是：代码区、只读常量区、全局区、BSS段、堆区、栈区。

堆区的地址是从小到大进行分配，栈区的地址是从大到小分配，以免避免堆区和栈区重叠。

全局区存储的全局变量默认初始化为0。

堆区、栈区存储的局部变量初始值随机。

- 代码区：主要存放程序的代码
- 只读常量区：主要存放常量字符串和const修饰的全局变量
- 全局区：保存初始化的全局变量和静态局部变量
- BSS段：主要存放未初始化的全局变量和静态局部变量，main执行前自动清零
- 堆区：new/malloc分配的内存，程序员手动申请和释放
- 栈区：局部变量(包括函数参数)、块变量(由{}括起来的变量)，栈内存自动管理

对于指向只读常量区字符串的指针来说，指向可以改变，指针指向的内容不可以改变。

对于使用常量字符串赋值的数组来说，指向不可以改变，数组内容可以改变。

对于指向堆区的指针来说，指向和内容都可以改变。

#### 虚拟地址和物理地址

unix/linux系统采用虚拟内存管理技术对内存地址进行管理：

- 每个进程都有 0~4G 的内存地址空间(虚拟的，不是真实的内存)
- 由操作系统负责映射建立(虚拟内存地址与真实物理内存或文件的映射关系)

0~4G的地址空间分为用户空间和内核空间：

- 用户空间 0~3G，内核空间 3~4G(可以改变大小)
- 用户程序通常都是运行在用户空间
- 内核空间系统内核可以访问，用户程序不能直接进行访问
- 内核提供一些具体的系统函数来访问内核空间

内存地址的基本单位为字节，内存映射的基本单位为内存页，目前主流操作系统内存页大小为4K。

**段错误**：

1. 虚拟内存地址没有映射到物理内存就去使用，可能会引发段错误
2. 使用到野指针/空指针可能引发段错误
3. 内存分配和释放

**内存分配须知**：

使用malloc分配内存，除了分配指定的内存大小之外，还可能额外申请12个字节。

额外申请的内存用于存储一些管理当前内存的信息，如内存的大小等等。

不同的操作系统额外申请的字节数可能不一样。

malloc使用链表来维护分配的内存空间。

注意：不要对malloc分配的内存空间进行越界访问，以免出现内存非法访问的段错误。

**内存分配原则**：

1. 当使用malloc申请比较小的内存空间时，系统默认分配33个内存页
2. 当申请比较大的内存空间时，系统可能分配34个内存页
3. 如果申请的内存超过或者等于34个内存页时，系统会再次分配33个内存页
4. 使用free进行释放时，释放多少则减去多少
5. 当所有内存都释放完毕时，可能会保留33个内存页不释放

**内存的释放**：

使用malloc申请，使用free函数释放，回收内存。

#### 相关函数

```c
#include <unistd.h>

size_t getpagesize(void);
    // 功能：获取内存页的大小，一般为 4K。

void *sbrk(intptr_t increment);
    // 功能：申请参数指定大小的内存空间，申请方便，释放不方便
    // 参数： 申请的内存大小(字节)。参数为0获取当前内存位置，参数为负数释放空间。
    // 返回值：
    //     成功返回增加内存空间之前的内存地址(其实就是分配的内存空间的首地址)
    //     失败返回(void*)-1

int brk(void *addr);
    // 功能：按照参数指定的位置进行内存区域分配
    // 注意：sbrk申请内存比较方便，brk释放内存比较方便，
    //      所以两个函数一般搭配使用，sbrk用来申请，brk用来释放

#include <sys/mman.h>

void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
    // 功能：用来建立文件/内存到地址空间的映射，返回地址
    // 参数：
    //     addr：建立映射的起始地址，使用NULL表示由内核指定(最好)
    //     length：所建立映射的大小
    //     prot：映射的权限，PROT_READ可读，PROT_WRITE可写
    //     flags：标志，决定映射是否对其他进程可见
    //            MAP_SHARED 共享的
    //            MAP_PRIVATE 私有的
    //            MAP_ANONYMOUS 默认映射文件，加上这个选项映射物理内存
    //     fd：文件描述符，给0即可
    //     offset：文件偏移量，给0即可

int munmap(void *addr, size_t length);
    // 功能：按照参数指定的位置和大小解除映射
```

## 进程间通信

进程间通讯方式有：

- 网络通信(套接字)
- 信号量和信号量集
- 文件
- 共享内存
- 管道
- 信号和信号集
- 消息队列

网络通信(套接字)在前面已经介绍。

信号量和信号量集在后续线程同步中介绍。

文件相关的操作在文件操作中介绍。

### 共享内存

共享内存本质上是系统内核维护的一块内存作为通信媒介，是最快的IPC通信方式。

**使用流程**：

1. 获取key值，使用`ftok`函数
2. 根据key值得到共享内存的id，使用`shmget`函数
3. 挂接共享内存，使用`shmat`函数
4. 使用共享内存
5. 脱接共享内存，使用`shmdt`函数
6. 如果所有进程不再使用，删除共享内存，使用`shmctl`函数

**相关的命令**：

```shell
ipcs -m                 # 查看当前操作系统中的共享内存段
ipcs -m 共享内存的id号    # 删除指定共享内存
```

**相关函数**：

```c
#include <sys/types.h>
#include <sys/ipc.h>
key_t ftok(const char *pathname, int proj_id);
    // 功能：根据有效路径和项目编号得到一个key值
    // 参数：
    //      pathname：有效的路径 (要求：文件存在，并且可以访问)
    //      proj_id：项目id (要求：非0，取的是低八位)
    // 返回值：
    //     失败返回-1
    //     成功返回key值 (系统级的共享内存的标识)
    // 注意：如果路径和项目id相同，则生成的key也相同

#include <sys/ipc.h>
#include <sys/shm.h>
int shmget(key_t key, size_t size, int shmflg);
    // 功能：根据key值创建/获取共享内存编号
    // 参数：
    //     key：ftok函数的返回值
    //     size：共享内存的大小
    //     shmflg：共享内存的操作标志
    //             IPC_CREAT → 创建
    //             IPC_EXCL → 与IPC_CREAT搭配使用，如果存在则创建失败
    // 返回值：成功返回共享内存编号id (进程级的标识)，失败返回-1
    // 注意：当创建新的共享内存时，需要指定权限，如：0666

#include <sys/types.h>
#include <sys/shm.h>
void *shmat(int shmid, const void *shmaddr, int shmflg);
    // 功能：将共享内存和进程地址空间挂接起来
    // 参数：
    //     shmid：共享内存的编号，shmget函数的返回值
    //     shmaddr：共享内存的地址 (为NULL时，由系统选择)
    //     shmflg：标志，一般给0即可
    // 返回值：成功返回一个void *类型的地址，失败返回(void *)-1；

#include <sys/types.h>
#include <sys/shm.h>
int shmdt(const void *shmaddr);
    // 功能：表示根据参数指定的地址进行脱接
    // 返回值：成功返回0，失败返回-1

#include <sys/ipc.h>
#include <sys/shm.h>
int shmctl(int shmid, int cmd, struct shmid_ds *buf);
    // 功能：按照指定的操作命令操作共享内存
    // 参数：
    //     shmid：共享内存的id，shmget函数的返回值
    //     cmd：操作命令(IPC_RMID删除共享内存, buf传参NULL)
    //     buf：结构体指针
    // 返回值：成功返回0，失败返回-1

struct shmid_ds {
    struct ipc_perm shm_perm;  // Ownership and permissions
    size_t shm_segsz;          // Size of segment (bytes)
    time_t shm_atime;          // Last attach time
    time_t shm_dtime;          // Last detach time
    time_t shm_ctime;          // Last change time
    pid_t shm_cpid;            // PID of creator
    pid_t shm_lpid;            // PID of last shmat(2)/shmdt(2)
    shmatt_t shm_nattch;       // No. of current attaches
    ...
};

struct ipc_perm {
    key_t __key;           // Key supplied to shmget(2)
    uid_t uid;             // Effective UID of owner
    gid_t gid;             // Effective GID of owner
    uid_t cuid;            // Effective UID of creator
    gid_t cgid;            // Effective GID of creator
    unsigned short mode;   // Permissions + SHM_DEST and SHM_LOCKED flags
    unsigned short __seq;  // Sequence number
};
```

**示例**：

```c
// 建立共享内存存放数据

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 100);  // 使用ftok获取key
    if (-1 == key) {
        perror("ftok");
        exit(-1);
    }
    printf("key = %#x\n", key);

    int shmid = shmget(key, 4, IPC_CREAT | IPC_EXCL | 0666);  // 用key创建/获取共享内存id
    if (-1 == shmid) {
        perror("shmget");
        exit(-1);
    }
    printf("shmid = %d\n", shmid);

    void *p = shmat(shmid, NULL, 0);  // 挂接共享内存
    if (p == (void *)-1) {
        perror("shmat");
        exit(-1);
    }

    int *pi = p;  // 使用共享内存
    *pi = 200;

    if (-1 == shmdt(p)) {  // 脱接共享内存
        perror("shmdt");
        exit(-1);
    }

    return 0;
}
```

```c
// 从共享内存读取数据

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main() {
    key_t key = ftok(".", 100);  // 使用ftok获取key
    if (-1 == key) {
        perror("ftok");
        exit(-1);
    }
    printf("key = %#x\n", key);

    int shmid = shmget(key, 0, 0);  // 用key创建/获取共享内存id
    if (-1 == shmid) {
        perror("shget");
        exit(-1);
    }
    printf("shmid = %d\n", shmid);

    void *p = shmat(shmid, NULL, 0);  //挂接共享内存
    if (p == (void *)-1) {
        perror("shmat");
        exit(-1);
    }

    int *pi = p;  // 使用共享内存
    printf("*pi = %d\n", *pi);

    if (-1 == shmdt(p)) {  // 脱接共享内存
        perror("shmdt");
        exit(-1);
    }

    if (-1 == shmctl(shmid, IPC_RMID, NULL)) {  // 删除共享内存
        perror("shmctl");
        exit(-1);
    } else {
        printf("成功删除共享内存.\n");
    }

    return 0;
}
```

### 管道

管道本质上讲是一种特殊的文件，采用此文件作为通信的媒介，实现进程间的通信。

管道分为两种：有名管道、无名管道。

有名管道主要用于任意两个进程间通信。

无名管道主要用于父子间的通信。

**注意**：管道文件比较特殊，本身不能存储数据，只负责连通两个进程。

**有名管道进程间通信**：

1. 使用命令 `mkfifo pipefilename.pipe` 创建管道文件
2. 一个进程向管道文件写入数据，另一个进程从管道文件读出数据

**无名管道进程间通信**：

```c
#include <unistd.h>
int pipe(int pipefd[2]);
    // 功能：创建进程间通信的管道，参数中pipefd[0]代表读端，pipefd[1]代表写端
    // 返回值：成功返回0，失败返回-1
```

**示例**：

```c
//向管道文件中写入数据

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = open("b.pipe", O_WRONLY);  // 打开管道文件
    if (-1 == fd) {
        perror("b.pipe");
        exit(-1);
    }

    for (int i = 0; i < 100; i++) {  // 循环写入数据
        write(fd, &i, sizeof(int));
        usleep(100000);
    }

    close(fd);  // 关闭文件

    return 0;
}
```

```c
//从管道文件中读取数据

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = open("b.pipe", O_RDONLY);  // 打开管道文件
    if (-1 == fd) {
        perror("b.pipe");
        exit(-1);
    }

    int buffer = 0;
    for (int i = 0; i < 100; i++) {  // 循环读取
        read(fd, &buffer, sizeof(int));
        printf("%d\n", buffer);
    }

    close(fd);  // 关闭文件

    return 0;
}
```

### 信号和信号集

#### 信号

信号就是软中断，既可以作为进程间的一种通信方式，也可以中断一个正在执行的程序。

信号更多的用来处理意外情况。

**特点**：

- 信号是异步的
- 进程既可以处理信号，也可以发送信号给指定的进程
- 每个信号都有一个名字，这些信号以`SIG`开头，如：`ctrl+c` → `SIGINT` → `2`

**相关命令**：

- `kill -l`：查看当前系统中的所有信号
- `ctrl+c`：`SIGINT`，信号2，默认处理是终止进程
- `ctrl+\`：`SIGQUIT`，信号3，默认处理是终止进程
- `kill -9`：`SIGKILL`，信号9，不允许被捕捉，终止进程

一般linux系统中有信号 1 ~ 64，不保证连续。

unix系统的信号和linux系统可能有所不同，unix中一般是 1 ~ 48。

**信号分类**(以linux系统为例)：

- 1~31：**不可靠信号**，信号可能丢失，不支持排队，又叫做**非实时信号**
- 34~64：**可靠信号**，信号不会丢失，支持排队，又叫做**实时信号**

**信号处理方式**：

- 默认处理，绝大多数都是终止进程
- 忽略信号
- 自定义处理信号，通过自己定义函数进行处理

**注意**：

1. 信号9只能进行默认处理，不能忽略，也不能进行自定义处理
2. 信号的发送受到用户的限制，一般来说，每个用户只能给自己的进程发送信号
3. root用户可以给所有进程发送信号

**信号处理函数**：

```c
#include <signal.h>
sighandler_t signal(int signum, sighandler_t handler);

→ void (*)(int) signal(int signum, void (*)(int) handler);

→ void (*)(int) signal(int signum, void (*handler)(int));

→ void (*signal(int signum, void (*handler)(int)))(int);

    // 函数功能：设置指定信号的处理方式
    // 参数：
    //     第一个参数是int类型
    //     第二个参数是函数指针类型
    // 返回值：函数指针，函数指针指向一个参数为int，返回值为void的函数
    // 使用：
    //     第一个参数：信号值/信号名称
    //     第二个参数：对信号的处理方式
    //                 可以取值SIG_IGN(忽略)、SIG_DFL(默认处理) 或 自定义的处理函数
    
    // 自定义处理函数函数指针：
    // (对)typedef void (*sighandler_t)(int);  // 给函数指针起别名，别名放在里面
    // (错)typedef void (*)(int) sighandler;   // 正常的起别名的顺序，不符合c语言规则
```

**示例**：

```c
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

void fa(int signo) {
    printf("捕捉到信号%d\n", signo);
    signal(3, SIG_DFL);   // 对信号3设置为默认处理
}

int main() {
    signal(2, SIG_IGN);   // 设置信号处理的方式为忽略
    signal(SIGQUIT, fa);  // 设置对信号3进行自定义处理
    signal(SIGKILL, fa);  // 设置对信号9进行自定义处理

    printf("PID = %d\n", getpid());

    while (1) {}

    return 0;
}
```

**信号发送方式**：

- 键盘发送方式(部分特殊信号可以)
  - ctrl+c → 信号2 SIGINT
  - ctrl+\ → 信号3 SIGQUIT
  - …
- 程序出错(只能发送部分特殊信号)
  - 段错误 → 信号11 SIGSEGV
  - 总线错误 → 信号7 SIGBUS
  - …
- `kill 信号值 进程号` (可以发送全部信号)
- 采用系统函数发送信号

**系统函数**：

```c
#include <signal.h>
int raise(int sig);
    // 函数功能：向正在执行的进程/线程发送参数指定的信号
    // 参数：信号值
    // 返回值：成功返回0，失败返回非0

#include <unistd.h>
unsigned int sleep(unsigned int seconds);
    // 函数功能：让进程/线程按照参数指定的时间进行睡眠
    // 返回值：正常结束返回0；如果被不能忽略的 signal 打断，返回剩余的秒数

#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);
    // 第一个参数：进程号
    //     pid > 0 给指定的进程发送信号
    //     pid = 0 给正在运行的进程同组的所有进程发送信号
    //     pid = -1 表示把信号发送到每一个可以被发送信号的进程中(除了进程1)
    //     pid < -1 发送信号给进程组为 -pid 的每一个进程
    // 第二个参数：信号
    //     sig = 0 时表示检查指定的进程/进程组的存在性
    // 返回值：成功返回0，失败返回-1
    // 函数功能：给指定的进程发送指定的信号

#include <unistd.h>
unsigned int alarm(unsigned int seconds);
    // 函数功能：
    //     表示经过参数指定的秒数后发送 SIGALARM 信号
    // 返回值：
    //     之前设定了闹钟则返回闹钟剩余的秒数，之前没有设定闹钟则返回0
    // 注意：
    //     参数为0时，不会设置新的闹钟，而是取消之前的闹钟
    //     一个进程只有一个闹钟，每次调用 alarm 都会重新设定闹钟时间

#include <signal.h>
union sigval {
    int sival_int;
    void *sival_ptr;
};
int sigqueue(pid_t pid, int sig, const union sigval value);
    // 函数功能：向指定的进程发送指定的信号，并附带数据信号的操作
    // 参数：
    //     第一个参数：进程号
    //     第二个参数：信号
    //     第三个参数：附加数据
    // 返回值：成功返回0，失败返回-1

#include <signal.h>
siginfo_t {
    pid_t si_pid;       // Sending process ID，发送方进程号
    sigval_t si_value;  // Signal value，发送时的附加数据
    ...
};
struct sigaction {
    void (*sa_handler)(int);
        // 函数指针，用于自定义处理信号，用函数地址初始化
    void (*sa_sigaction)(int, siginfo_t *, void *);
        // 函数指针，用于自定义处理信号，用函数地址初始化
    sigset_t sa_mask;
        // 设置信号屏蔽字，屏蔽处理信号期间需要屏蔽的信号
        // 自动屏蔽与正在处理的信号相同的信号，除非flag=SA_NODEFER
    int sa_flags;
        // 标志 → 处理方式
        // 为SA_SIGINFO时，采用第二个函数指针处理
        // 为SA_NODEFER时，不进行自动屏蔽
        // 为SA_RESETHAND时，调用信号处理函数后恢复默认处理(
        //         只要调用了立马恢复默认处理，不会等待函数执行结束)
    void (*sa_restorer)(void);
        // 保留不使用
};

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
    // 函数功能：设置对指定信号的处理方式
    // 参数：
    //     第一个参数：信号
    //     第二个参数：主要用于设置新的信号处理方式
    //     第三个参数：获取旧的信号处理方式
    // 返回值：0成功，-1失败

#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
    // 函数功能：用于设置新的信号屏蔽字，带出之前的信号屏蔽字
    // 参数：
    //     第一个参数：处理方式
    //         SIG_BLOCK → 屏蔽已经屏蔽的信号也屏蔽参数set指定的信号(旧+新)
    //         SIG_UNBLOCK → 把参数set指定的信号从屏蔽信号的集合中移除
    //         SIG_SETMASK → 用set指定的信号集合替换之前的屏蔽信号的集合
    //     第二个参数：设置新的信号屏蔽字
    //     第三个参数：带出旧的信号屏蔽字
    // 返回值：成功0，失败-1
    // 注意：信号屏蔽并不是删除信号，而只是把信号暂时存起来，等信号屏蔽解除之后还可以处理
    //       一般使用原则是：先设置新的信号屏蔽字，屏蔽工作完成后再恢复旧的
    //       屏蔽的可靠信号在屏蔽期间可以排队，收到信号多少次处理多少次

#include <signal.h>
int sigpending(sigset_t *set);
    // 函数功能：获取在信号屏蔽期间来过的信号
    // 注意：当解除信号后，来过的信号被处理掉，则不能检查是否来过(
    //         这个函数是获得队列中排队的信号)
```

#### 信号集

信号集是信号的集合。

信号集的数据类型：`sigset_t`。

linux系统表示信号的范围1~64，如果让每一个二进制位来表示一个信号，则8个字节足够。

实际上`sigset_t`占用128个字节，然后采用每一个二进制位表示一个信号。

相关函数：

```c
typedef struct {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;

sigemptyset()  // 清空信号集(位置0)
sigfillset()   // 填满信号集(位置1)
sigaddset()    // 增加一个信号(将一个位置1)
sigdelset()    // 删除一个信号(将一个位置0)
sigismember()  // 查找是否存在某个信号

#include <signal.h>

int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signum);
int sigdelset(sigset_t *set, int signum);
    // 返回值：成功返回0，失败返回-1

int sigismember(const sigset_t *set, int signum);
    // 返回值：存在返回1，不存在返回0，失败返回-1
```

### 消息队列

将要通信的数据存放到一个消息中，将消息存放到队列中，通过队列中消息的存取来进行通信。

**通信流程**：

1. 获取key值，使用ftok函数
2. 创建/获取消息队列的msgid，使用msgget函数
3. 发送/接收消息，使用msgsnd和msgrcv函数
4. 如果确定没有进程再使用，删除消息队列，使用msgctl函数

**相关指令**：

- ipcrm -q msqid 删除
- ipcs -q 查看

**相关函数**：

```c
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgget(key_t key, int msgflg);
    // 函数功能：根据key值创建/获取消息队列，返回id
    // 参数：
    //     key：ftok函数的返回值
    //     msgflg：消息队列的操作标志
    //             IPC_CREAT → 创建
    //             IPC_EXCL → 与IPC_CREAT搭配使用，如果存在则创建失败
    // 返回值：成功返回消息队列编号id，失败返回-1
    // 注意：当创建新的消息队列时，需要指定权限，如：0666

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf {
    long mtype;
        // message type, must be > 0，通过类型辨识自己要找到的消息
    char mtext[1];
        // message data，消息的内容，决定msgsnd函数第三个参数的大小，不包括消息的类型
};

int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
    // 函数功能：向指定的消息队列中发送指定的消息
    // 参数：
    //     msqid：msgget函数的返回值
    //     msgp：要发送的消息的首地址，消息类型为 struct msgbuf
    //     msgsz：消息的大小(消息结构体中内容的大小，不包括消息的类型)
    //     msgflg：发送的标志，给0即可
    // 返回值：成功返回0，失败返回-1

ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
    // 函数功能：从指定的消息队列中接收指定类型的信息
    // 参数：
    //     msqid：消息队列id，msgget函数的返回值
    //     msgp：存放消息的首地址，消息类型为 struct msgbuf
    //     msgsz：接收的消息大小
    //     msgtyp：接收的消息类型
    //             0 → 读取消息队列中的第一个消息
    //             > 0 → 读取消息队列中第一个类型为msgtyp的消息
    //             < 0 → 读取第一个小于或者等于msgtp绝对值的消息，优先读取类型最小的消息
    //     msgflg：接收标志，给0即可
    // 返回值：成功接收返回接收数据的大小，失败返回-1

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int msgctl(int msqid, int cmd, struct msqid_ds *buf);
    // 函数功能：对消息队列的各种操作
    // 参数：
    //     msqid：消息队列的id
    //     cmd：操作命令 IPC_RMID(删除，不需要第三个参数，置为NULL)
    //     buf：结构体指针
    // 函数返回值：成功返回0，失败返回-1
```

**示例**：

```c
//向消息队列中存放消息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct Msg {  // 定义数据类型
    long mtype;
    char buffer[256];
} Msg;

int main() {
    key_t key = ftok(".", 100);  //获取key，使用ftok函数
    if (key == -1) {
        perror("ftok");
        exit(-1);
    }
    printf("key = %d\n", key);

    int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);  // 创建消息队列，得到msgid
    if (msgid == -1) {
        perror("msgget");
        exit(-1);
    }
    printf("msgid = %d\n", msgid);

    Msg m1, m2;  // 准备并发送消息
    
    m1.mtype = 1;
    strcpy(m1.buffer, "hello1");

    m2.mtype = 2;
    strcpy(m2.buffer, "hello2");

    if (-1 == msgsnd(msgid, &m2, sizeof(m1.buffer), 0)) {  // 发送m2
        perror("m2");
        exit(-1);
    }

    if (-1 == msgsnd(msgid, &m1, sizeof(m1.buffer), 0)) {  // 发送m1
        perror("m1");
        exit(-1);
    }

    return 0;
}
```

```c
//接收消息队列中存放的消息
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

typedef struct Msg {  // 定义数据类型
    long mtype;
    char buffer[256];
} Msg;

int main() {
    key_t key = ftok(".", 100);  // 获取key，使用ftok函数
    if (key == -1) {
        perror("ftok");
        exit(-1);
    }
    printf( "key = %d\n", key );

    int msgid = msgget(key, 0);  //获取消息队列，得到msgid
    if (msgid == -1) {
        perror("msgget");
        exit(-1);
    }
    printf("msgid = %d\n", msgid);

    Msg m = {};
    
    // if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), 0, 0)) {
    //    perror("read");
    //    exit(-1);
    // }
    // printf("0消息为：%s\n", m.buffer);

    // if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), 1, 0)) {
    //     perror("read");
    //     exit(-1);
    // }
    // printf("1消息为：%s\n", m.buffer);

    if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), -2, 0)) {  // 接收数据
        perror("read");
        exit(-1);
    }
    printf("-2消息为：%s\n", m.buffer);

    if (-1 == msgctl(msgid, IPC_RMID, NULL)) {  // 删除消息队列
        perror("msgctl");
        exit(-1);
    }

    return 0;
}
```

## 多线程

### 解释

线程隶属于进程，是进程中的程序流。

操作系统支持多进程，而每一个进程中又支持多线程，多线程可以并行执行。

进程是重量级的，每个进程都需要独立的内存空间等，新建进程对于资源的消耗比较大。

线程是轻量级的，线程共享所在进程的内存资源等，但是每个线程都拥有一个独立的栈区。

进程中可以有很多的线程，但是必须有一个主线程(main函数)。

一般来说，由于CPU不可再分，所以本质就是宏观并行，微观串行，通常采用时间片轮转法。

### 线程相关函数

```c
#include <pthread.h>
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                   void *(*start_routine) (void *), void *arg);
    // 第一个参数：存储线程ID
    // 第二个参数：线程属性，给NULL表示使用默认属性
    // 第三个参数：函数指针，线程执行的函数
    // 第四个参数：函数指针的参数
    // 返回值：成功返回0，失败返回错误编号
    // 函数功能：启动一个新的线程
    // 注意：编译时需要链接pthread库(-lpthread)

#include <pthread.h>
pthread_t pthread_self(void);
    // 函数功能：获取当前线程的ID
    // 注意：编译时需要链接pthread库(-lpthread)

#include <pthread.h>
int pthread_join(pthread_t thread, void **retval);
    // 第一个参数：目标线程的ID
    // 第二个参数：二级指针，主要用于存储终止线程的返回值和退出码
    // 函数功能：等待指定的线程终止，并且接受终止时的退出码
    // 注意：编译时需要链接pthread库(-lpthread)

#include <pthread.h>
void pthread_exit(void *retval);
    // 函数功能：用于终止正在运行的线程，将退出码/返回值通过参数带出去，
    //         由调用pthread_join函数的线程接收处理
    // 注意：编译时需要链接pthread库(-lpthread)
    //       exit() → 终止整个进程，终止所有线程
    //       pthread_exit() → 终止一个线程

#include <pthread.h>
int pthread_detach(pthread_t thread);
    // 函数功能：将参数指定的线程设置为分离状态，该线程结束时资源由系统自动回收，
    //         而非分离状态的线程终止时由join此线程的线程回收
    // 注意：编译时需要链接pthread库(-lpthread)

#include <pthread.h>
int pthread_cancel(pthread_t thread);
    // 函数功能：发送终止信号给thread线程，发送成功并不意味着thread会立刻终止
    // 返回值：成功返回0，否则为非0值
    // 注意：编译时需要链接pthread库(-lpthread)

#include <pthread.h>
int pthread_setcancelstate(int state, int *oldstate);
    // PTHREAD_CANCEL_ENABLE 可以被取消
    // PTHREAD_CANCEL_DISABLE 不可以被取消
    // 函数功能：设置取消状态，并带出旧的状态值
int pthread_setcanceltype(int type, int *oldtype);
    // PTHREAD_CANCEL_DEFERRED 延迟取消
    // PTHREAD_CANCEL_ASYNCHRONOUS 立即取消
    // 函数功能：设置取消类型，并带出旧的类型值
```

## 线程同步

线程间共享进程资源，多线程同时访问共享资源时需要互相协调和通信，防止数据不一致和不完整。

线程之间的对共享资源访问的协调和通信叫做线程的同步。

**解决思想**：当多个线程访问共享资源时，不能并行而是串行。

**解决方案**：在多线程中，提供互斥量(互斥锁)和信号量实现线程的同步。

### 互斥锁

**使用步骤**：

1. 定义互斥量：`pthread_mutex_t lock`
2. 初始化互斥量：`pthread_mutex_init(&lock, 0)`
3. 对共享资源加锁：`pthread_mutex_lock(&lock)`
4. 使用共享资源
5. 对共享资源解锁：`pthread_mutex_unlock(&lock)`
6. 销毁互斥量：`pthread_mutex_destroy(&lock)`

**相关函数**：

```c
#include <pthread.h>

int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *mutexattr);
int pthread_mutex_lock(pthread_mutex_t *mutex);
int pthread_mutex_trylock(pthread_mutex_t *mutex);
int pthread_mutex_unlock(pthread_mutex_t *mutex);
int pthread_mutex_destroy(pthread_mutex_t *mutex);
```

### 信号量

信号量本质就是一个计数器，主要用于控制同时访问共享资源的进程数/线程数。

信号量的值为1时效果等同于互斥量。

**使用步骤**：

1. 定义信号量：`sem_t sem`
2. 初始化信号量：`sem_init(&sem, 0 /*控制线程数*/, 最大值 /*信号量的初始值*/)`
3. 获取一个信号量(信号量-1)：`sem_wait(&sem)`
4. 使用共享资源
5. 释放一个信号量：`sem_post(&sem)`
6. 销毁信号量：`sem_destroy(&sem)`

**相关函数**：

```c
#include <semaphore.h>

int sem_init(sem_t *sem, int pshared, unsigned int value);
    // 第一个参数：定义的信号量的地址
    // 第二个参数：为0时表示控制一个进程中的多个线程，非0时表示控制多个进程
    // 第三个参数：信号量的初始值
    // 函数功能：初始化信号量
    // 注意：Link with -lrt or -pthread

int sem_wait(sem_t *sem);
    // 函数功能：获取一个信号量(-1)

int sem_post(sem_t *sem);
    // 函数功能：释放一个信号量(+1)

int sem_destroy(sem_t *sem);
    // 函数功能：销毁信号量
```

## 信号量集

信号量集是信号量的集合，提供多个计数器，来控制多种共享资源的访问量。

**工作方式**：

1. 计数器初始化为最大值
2. 如果有进程申请资源，计数器-1
3. 计数器为0时，终止进程对资源的申请，申请资源的进程进入阻塞状态
4. 有进程释放资源，计数器+1
5. 当计数器的值大于0时，阻塞的进程就可以拿到资源，拿不到的继续阻塞

**使用信号量集进行进程间通信的流程**：

1. 使用ftok函数获取key值
2. 创建/获取信号量集，使用semget函数
3. 初始化信号量集，给指定的信号量初始化，使用semctl函数
4. 操作信号量集，对指定的信号量进行加减操作，使用semop函数
5. 如果不再使用，删除使用semctl函数

相关函数：

```c
#include <sys/types.h>
#include <sys/ipc.h>

key_t ftok(const char *pathname, int proj_id);
    // 功能：根据有效路径和项目编号得到一个key值
    // 参数：
    //     pathname：有效的路径(要求：文件存在，并且可以访问)
    //     proj_id：项目id(要求：非0，取的是低八位)
    // 返回值：失败返回-1；成功返回key值(系统级的共享内存的标识)
    // 注意：如果路径和项目id相同，则生成的key也相同

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semget(key_t key, int nsems, int semflg);
    // 函数功能：获取信号量集的id号
    // 参数：
    //     key：ftok函数的返回值
    //     nsems：信号量的个数，也就是信号量集的大小
    //     semflg：信号量集的操作标志
    //             IPC_CREAT → 创建
    //             IPC_EXCL → 与IPC_CREAT搭配使用，如果存在则创建失败
    // 返回值：成功返回信号量集的id(非负数)，失败返回-1
    // 注意：当创建一个新的信号量集时候需要指定一个8进制权限

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int semctl(int semid, int semnum, int cmd, ...);
    // 函数功能：对指定信号量集进行操作和处理
    // 参数：
    //     semid：semget函数的返回值，即信号量集的id
    //     semnum：信号量集的下标(从0开始)
    //     cmd：具体的操作命令
    //          IPC_RMID → 删除信号量集，不需要第四个参数
    //          SETVAL → 对信号量集中第semnum个信号量初始化，初始值由第四个参数指定
    //     ...：可变长参数
    // 返回值：成功返回0，失败返回-1

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

struct sembuf {
    unsigned short sem_num;  // semaphore number 信号量下标
    short em_op;             // semaphore operation 正数增加，负数减小
    short sem_flg;           // operation flags 默认给0即可
}

int semop(int semid, struct sembuf *sops, unsigned nsops);
    // 函数功能：对指定的信号量进行处理
    // 参数：
    //     semid：信号量集的id，semget函数的返回值
    //     sops：结构体指针
    //     nsops：信号量集合的大小，信号量个数
    // 返回值：成功返回0，失败返回-1
```

相关指令：

- ipcs -s 查看系统中的信号量集
- ipcrm -s 信号量集id 表示删除指定的信号量集
- ipcs -a 查看系统中所有的IPC结构

## 计时器(SIGALRM)

unix/linux系统中为每一个进程维护3种计时器，分别为：真实、虚拟、实用三种。

一般采用真实计时器。

真实计时器主要反应程序的运行时间，通过发送SIGALRM信号来工作。

### 计时器相关函数

```c
#include <sys/time.h>
int getitimer(int which, struct itimerval *curr_value);
int setitimer(int which, const struct itimerval *new_value, struct itimerval *old_value);
    // 第一个参数：计时器的类型
    //     ITIMER_REAL → 真是计时器，通过SIGALRM信号工作
    //     ITIMER_VIRTUAL → 虚拟计时器，通过SIGVTALRM信号工作
    //     ITIMER_PROF → 实用计时器，通过SIGPROF信号工作
    // 第二个参数：结构体指针，存放计时器的信息
    // 第三个参数：获取之前的计时器信息。
    // 返回值：成功返回0，失败返回-1。
    // 函数功能：获取/设置计时器信息。

struct itimerval {
    struct timeval it_interval;  // next value间隔时间
    struct timeval it_value;  // current value起始时间
};

struct timeval {
    long tv_sec;  // seconds秒
    long tv_usec;  // microseconds微秒(值在1s内)
};
```

### 计时器的使用

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <signal.h>

void fa(int signo) {
    printf( "捕获到信号%d\n", signo );
}

int main() {
    signal(SIGALRM, fa);

    struct itimerval timer;
    
    timer.it_interval.tv_sec = 1;
    timer.it_interval.tv_usec = 500000;

    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;

    if (-1 == setitimer(ITIMER_REAL, &timer, NULL)) {  //启动定时器，每隔1.5秒发送一次SIGALRM信号
        perror("setitimer");
        exit(-1);
    }

    while (1) {}

    return 0;
}
```

## 目录

**相关函数**：

```c
#include <sys/types.h>
#include <dirent.h>

DIR *opendir(const char *name);
DIR *fdopendir(int fd);
    // 函数功能：打开参数指定的目录
    // 返回值：成功返回目录入口地址，失败返回NULL

#include <dirent.h>
struct dirent *readdir(DIR *dirp);
    // 函数功能：读取指定目录下的内容
    // 返回值：成功返回读取的信息的结构体，失败返回空

struct dirent {
    ino_t d_ino;              // 节点编号
    off_t d_off;              // 偏移量
    unsigned short d_reclen;  // 记录的大小
    unsigned char d_type;     // 文件类型，并不是所有文件系统都支持
    char d_name[256];         // 文件名
};

#include <unistd.h>
char *getcwd(char *buf, size_t size);
    // 函数功能：获取当前工作目录的绝对路径放入buf中
    // 返回值：成功返回路径，失败返回NULL

mkdir() - 创建目录

rmdir() - 删除目录

chdir() - 切换目录
```

## 文件

linux系统中，几乎所有的一切都可以看作文件。

因此对文件的操作几乎可以适用于各种输入输出设备等等，目录也是文件。

```c
/dev/null               // 空设备

echo hello > /dev/null  // 将 "hello" 丢入空设备
cat /dev/null > a.txt   // 将空设备的数据输入到文件a.txt，即清空文件
cat a.txt > /dev/null   // 将输出内容丢入到空设备

/dev/tty                // 输入输出设备

echo hello > /dev/tty   // 将 "hello" 重定向到tty设备中，能在tty设备中输出
cat /dev/tty            // 从输入输出设备中读取信息
```

### C语言中文件相关函数

```c
fopen() / fclose() / fread() / fwrite() / fseek()
```

### Unix C中文件相关函数

**文件打开和关闭**：

```c
#include <sys/types.h>  //数据类型头文件
#include <sys/stat.h>   //状态信息头文件
#include <fcntl.h>      //控制和操作头文件

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
int creat(const char *pathname, mode_t mode);
    // 函数功能：主要用于打开和创建文件
    // pathname：文件的路径和文件名
    // flags：操作标志
    //     O_RDONLY - 只读
    //     O_WRONLY - 只写
    //     O_RDWR - 可读可写
    //     O_APPEND - 追加
    //     O_CREAT - 文件不存在则创建
    //     O_EXCL - 与O_CREAT搭配使用，不存在则创建，存在则创建失败
    //     O_TRUNC - 文件存在则清空；如果是FIFO或者terminal设备则忽略此标志
    // mode：文件的权限，当有新文件创建时需要指定第三个参数来指定文件的权限，一般用法(0666)，表示属主等用户都有读写权限
    // 返回值：成功返回文件描述符(非负数)，失败返回-1

#include <unistd.h>

int close(int fd);
    // 函数功能：关闭参数指定的文件
    // 返回值：成功返回0，失败返回-1
```

**文件读写**：

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
    // 函数功能：从指定文件fd中读取count个字节放到buf中
    // fd：文件描述符，open函数的返回值
    // buf：缓冲区首地址(读取出来的数据的存储地址)
    // count：要读取的数据有多少个字节
    // 返回值：成功返回读取到的字节数，失败返回-1，0表示文件末尾

#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
    // 函数功能：向指定文件fd中写入buf中存储的count个字节
    // fd：文件描述符，open函数的返回值
    // buf：缓冲区首地址(要写入的数据的存储地址)
    // count：要写入的数据有多少个字节
    // 返回值：成功返回写入的字节数，失败返回-1，0表示什么也没写
```

**文件定位**：

```c
#include <sys/types.h>
#include <unistd.h>
off_t lseek(int fd, off_t offset, int whence);
    // 函数功能：改变文件的读写位置
    // fd：文件描述符
    // offset：偏移量(字节数)
    // whence：开始偏移的位置
    //     SEEK_SET - 0，文件开头位置
    //     SEEK_CUR - 1，文件当前位置
    //     SEEK_END - 2，文件末尾位置
    //     (文件末尾位置是指最后一个字符前的位置，vi默认在文件最后加'\n'，用open函数创建的文件最后有noeol[no end of line])
    // 返回值：成功返回当前位置到文件开头的偏移量，失败返回-1
```

### 文件描述符

文件描述符本质上就是一个整数，可以代表一个打开的文件。

但是文件的信息并不是存储在文件描述符中，而是存储在文件表中。

使用open函数打开文件时，会将文件信息放入文件表中。

出于安全等因素考虑，不直接操作文件，给文件表中的文件指定一个编号，使用编号操作文件。

这个编号就是文件描述符。

**文件描述符** -> **文件表指针** -> **文件表** -> **文件**

文件描述符是一个最小的没有被使用的非负数(从0开始)，一般最大到255。

其中 0、1、2被系统占用，代表标准输入、标准输出、标准错误，一般从3开始可以使用。

### C和UC文件操作函数的区别

标C函数要比UC函数效率更高。

标C函数都有输入/输出缓冲区，会积累一定数量之后再进行读写，因此效率比较高。

UC的函数虽然在内核层也有小型的缓冲区，但是和标C相比，读写效率比较低。

使用time命令可查看程序的运行时间。

自定义缓冲区可以提高UC函数效率，可能比标C函数效率更高，但并不是缓冲区越大效率越高。

### 文件锁

当有多个进程访问同一个文件时，可能引发数据的混乱。

如果所有进程都是读操作，则可以同时进行；但只要有一个进程进行写操作，则所有操作就应该串行。

linux中借助文件锁实现上述功能。

文件锁就是读写锁，也就是一把读锁和一把写锁。

其中读锁是一把共享锁，允许其他进程加读锁，不允许加写锁。

其中写锁是一把互斥锁，不允许其他进程加读锁及其写锁。

使用文件锁时，fcntl函数需要第三个参数，而第三个参数就是`struct flock`类型的指针。

如下：

```c
struct flock {
    ...
    short l_type;    // Type of lock，F_RDLCK(读), F_WRLCK(写), F_UNLCK(解锁)
    short l_whence;  // How to interpret l_start: SEEK_SET, SEEK_CUR, SEEK_END
    off_t l_start;   // Starting offset for lock (起始位置偏移量)
    off_t l_len;     // Number of bytes to lock (锁定多少字节)
    pid_t l_pid;     // PID of process blocking our lock (锁定文件的进程) (F_GETLK only) (只有这个cmd需要使用进程号，否则默认给-1)
    ...
};
```

文件的非读写函数：

```c
#include <unistd.h>

int dup(int oldfd);
int dup2(int oldfd, int newfd);
    // 函数功能：创建参数oldfd的副本
    //     dup2可以指定新的文件描述符，如果指定的文件描述符已经被占用，则关闭之前的文件再使用
    // 返回值：成功时返回文件描述符，失败返回-1

#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, ... /* arg */ );
    // 函数功能：复制文件描述符、获取/设置文件的标志、实现文件锁的功能
    // fd：文件描述符
    // cmd：具体的操作命令cmd(决定是否需要第三个参数)
    // ...：可变长参数

    // 1. 复制文件描述符：
    //     cmd = F_DUPFD，表示复制文件描述符，需要第三个参数指定新的文件描述符，
    //         如果被占用，不会强制关闭，而是使用一个大于arg的值进行设定使用，
    //         即使用一个大于或等于arg的有效的文件描述符
    // 2. F_GETFD/F_SETFD 获取和设置文件描述符
    //    F_GETFL/F_SETFL 获取和设置文件状态标志
    // 3. 实现文件锁功能：F_GETLK、F_SETLK、F_SETLKW 请求、释放、测试锁是否存在

    // fcntl函数的使用：
    // 1. F_SETLK 加锁和释放锁的功能
    // 2. 释放锁的操作主要有两种形式
    //    (1) 进程结束时自动释放所有锁
    //    (2) 将锁的类型改为F_UNLCK，重新使用fcntl设置
    // 3. F_SETLKW 加锁如果加不上则等待，直到加上锁为止
    // 4. F_GETLK 主要用于测试是否可以加锁。
    //         如果用于测试的锁能加，并不去加锁，而将测试的锁的类型改为F_UNLCK；
    //         如果不能，则把测试的锁替换为正在锁定文件的锁
    //             (也就是把当前正在使用的锁信息通过lock参数带出来)，
    //         并且l_pid会被改为加锁的进程号

    // 总结：
    // 加完读锁之后，还是可以向文件中写入数据的，
    // 也就是说锁是独立于文件的，并没有真正控制文件的读写操作，
    // 也就是说锁只能锁定其它的锁，
    // 也就是说如果加了一个锁，会导致第二次加锁失败(两个读锁除外)，
    // 因此：在读写操作之前先进行加锁操作，据加锁是否成功来决定是否进行读写操作

    // 返回值：
    // C语言中大部分的函数返回值为0表示函数调用成功，为-1表示调用失败，
    // 但并不能根据他们来确定函数的执行结果；
    // 有的函数返回值为0或-1可以表示执行结果；
    // 有的函数因为参数不同可能会有以上两种情况。
    // man fcntl可以看到函数在不同参数条件下的返回值，
    // 其中cmd = F_GETLK时，返回值为0表示调用正常，-1表示调用出错，
    // 至于执行结果需要访问第三个参数的成员值来确定。

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int stat(const char *path, struct stat *buf);
int fstat(int fd, struct stat *buf);
int lstat(const char *path, struct stat *buf);
    // 第一个参数：文件的路径/描述符
    // 第二个参数：结构体指针
    // 返回值：成功返回0，失败返回-1
    // 函数功能：获取指定文件的状态信息，如文件大小等，man 2 stat可以查看帮助信息

struct stat {
    dev_t st_dev;          // ID of device containing file 设备id
    ino_t st_ino;          // inode number 节点编号
    mode_t st_mode;        // protection 文件类型和权限
    nlink_t st_nlink;      // number of hard links 硬链接数
    uid_t st_uid;          // user ID of owner 属主用户id
    gid_t st_gid;          // group ID of owner 属组用户id
    dev_t st_rdev;         // device ID (if special file) 特殊设备id
    off_t st_size;         // total size, in bytes 文件大小
    blksize_t st_blksize;  // blocksize for file system I/O 块大小
    blkcnt_t st_blocks;    // number of 512B blocks allocated 块数量
    time_t st_atime;       // time of last access 最后访问时间
    time_t st_mtime;       // time of last modification 最后修改时间
    time_t st_ctime;       // time of last status change
};

#include <time.h>

char *ctime(const time_t *timep);
    // 函数功能：将参数传进来的整数类型时间转换为字符串类型的时间。
struct tm *localtime(const time_t *timep);
    // 函数功能：将参数传进来的整数类型时间转换为结构体类型的时间。

struct tm {
    int tm_sec;   // seconds
    int tm_min;   // minutes
    int tm_hour;  // hours
    int tm_mday;  // day of the month
    int tm_mon;   // month 定义的范围0到11
    int tm_year;  // year 值是1900年到现在的年数
    int tm_wday;  // day of the week 定义在0到6
    int tm_yday;  // day in the year 定义在0到365
    int tm_isdst; // daylight saving time 夏令时
};

#include <unistd.h>

int access(const char *pathname, int mode);
    // 第一个参数：文件的路径
    // 第二个参数：操作模式，R_OK可读、W_OK可写、X_OK可执行、F_OK文件是否存在
    // 函数功能：检查用户对文件的权限

#include <sys/stat.h>

int chmod(const char *path, mode_t mode);
int fchmod(int fd, mode_t mode);
    // 函数功能：修改第一个参数指定的文件的权限为第二个参数指定的值，第二参数采用八进制表示即可

#include <unistd.h>
#include <sys/types.h>

int truncate(const char *path, off_t length);
int ftruncate(int fd, off_t length);
    // 函数功能：截断第一个参数指定的文件调整到第二个参数指定的大小

#include <sys/types.h>
#include <sys/stat.h>

mode_t umask(mode_t mask);
    // 函数功能：设置新的权限屏蔽字
    //     权限屏蔽字只在文件创建时起作用，并不改变已经创建的文件的权限
    //     创建文件时设置文件权限，权限屏蔽字屏蔽的权限无法设置
    // 返回值：旧的权限屏蔽字。

// mmap 和 munmap 函数用于建立虚拟地址和文件映射

link()    // 创建链接的函数
unlink()  // 删除链接的函数
rename()  // 重命名的函数
remove()  // 删除的函数
```
