
#include <iostream>
using namespace std;

class A {
 public:
  void show() { cout << "void show()" << endl; }
  // 静态成员函数有没有对象都可以调用
  static void shows() { cout << "static void shows()" << endl; }
};

int main() {
  A::shows();

  A a;
  a.show();
  a.shows();

  return 0;
}

// static void shows()
// void show()
// static void shows()
