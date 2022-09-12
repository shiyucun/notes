
#include <iostream>
using namespace std;

class A {
 private:
  int x_;
  int y_;
  mutable int z_;

 public:
  A() {}

  void testA() {}

  void show() const {  // _ZNK1A4showEv 底层函数名
    cout << "show() const" << endl;
    cout << x_ << " " << y_ << " " << z_ << endl;
    // testA();  // const 函数只能调用类内 const 函数
    // x_ = 100;  // const 函数只能读，不能写
    z_ = 100;  // mutable 修饰 z_，因此可以修改
    cout << x_ << " " << y_ << " " << z_ << endl;
  }

  void show() {  // _ZN1A4showEv 底层函数名
    cout << "show()" << endl;
  }
};

int main() {
  const A a;
  a.show();

  A b;
  b.show();

  return 0;
}

// 0 0 -1769152256
// 0 0 100
// show()
