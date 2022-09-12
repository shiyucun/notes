
#include <iostream>
using namespace std;

class A {
 private:
  int fd_;

 public:
  A() { cout << "A()" << endl; }
  ~A() { cout << "~A()" << endl; }
};

A *foo() {
  A a;
  // a.~A();

  A *pa = new A();
  delete pa;

  pa = new A[3]();
  return pa;
}

int main() {
  A *pa = foo();
  delete[] pa;

  return 0;
}

// A()
// A()
// ~A()
// A()
// A()
// A()
// ~A()
// ~A()
// ~A()
// ~A()
