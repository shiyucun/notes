
#include <iostream>
using namespace std;

class A {
 public:
  A() {}

  void show() const {  // _ZNK1A4showEv 底层函数名
    cout << "show() const" << endl;
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

// show() const
// show()
