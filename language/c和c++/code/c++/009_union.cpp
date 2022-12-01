
#include <arpa/inet.h>
#include <iostream>
using namespace std;

int main() {
  // 大端系统和小端系统的验证
  int y = 1;
  printf("0x%x, 0x%x\n", y, htonl(y));

  union {
    int x;
    char datas[4];
  };

  x = 0x31323334;
  for (int i = 0; i < sizeof(int); i++) {
    printf("0x%x(%c)  ", datas[i], datas[i]);
  }
  cout << endl;

  return 0;
}

// htonl() 用于将主机数序转换成无符号长整型的网络字节顺序
//         网络字节序为大端序
// 小端序低字节存在低地址，大端序低字节存在高地址
// 小端序从低字节开始存储，大端序从高字节开始存储

// 0x1, 0x1000000
// 0x34(4)  0x33(3)  0x32(2)  0x31(1)
