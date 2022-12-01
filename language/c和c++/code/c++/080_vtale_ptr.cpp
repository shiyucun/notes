
#include <iostream>
using namespace std;

class A {
 private:
  int x;

 public:
  A(int x = 0) : x(x) {}

  virtual void run() {}
};

class B : public A {};

int main() {
  A a(101);

  int *pa = reinterpret_cast<int *>(&a);

  // pa 指向虚函数表首地址
  cout << *pa << endl;
  cout << *(pa + 1) << endl;

  A b(221);
  int *pb = reinterpret_cast<int *>(&b);

  // pb 指向虚函数表首地址
  cout << *pb << endl;
  cout << *(pb + 1) << endl;

  // 取得 B 类型的虚表地址
  B c;
  int *pc = reinterpret_cast<int *>(&c);
  cout << *pc << endl;

  return 0;
}

// 1685736792
// 21929
// 1685736792
// 21929
// 1685736768
