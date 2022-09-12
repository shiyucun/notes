
#include <iostream>
using namespace std;

class A {
 public:
  A() { cout << "A()" << endl; }
  A(const A& a) { cout << "A(const A& a)" << endl; }
};

// 做函数参数时候拷贝
void setA(A a) {}

// 做返回值时拷贝
A setB(A& a) { return a; }

// 由于编译器优化，注释部分只有函数返回时构造一个对象，不拷贝
A setC() {
  // A d;
  // return d;
  return A();  // 返回一个匿名对象
}

int main() {
  A a;

  // 拷贝三次
  A b = a;
  setA(a);
  A c = setB(a);

  setC();

  return 0;
}

// A()
// A(const A& a)
// A(const A& a)
// A(const A& a)
// A()
