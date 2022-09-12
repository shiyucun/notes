
#include <iostream>
using namespace std;

class A {
 private:
  int x;
  int y;

 public:
  A(int x = 1, int y = 1) : x(x), y(y) {}

  // 虚函数也会有一个指针进行管理，这个指针在类内占有四个字节
  // 无论有多少个虚函数，虚指针只会有一个
  virtual void show() {}
  virtual void funa() {}
};

int main() {
  cout << sizeof(A) << endl;
  return 0;
}

// 16
