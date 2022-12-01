
#include <iostream>
using namespace std;

int x = 1;  // 属于无名命名空间

namespace { // 匿名空间，防止跨文件访问
int y = 100;
};

int main() {
  cout << x << endl;
  cout << ::x << endl;

  cout << y << endl;
  cout << ::y << endl;

  return 0;
}

// 1
// 1
// 100
// 100
