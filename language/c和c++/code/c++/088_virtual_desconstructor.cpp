
#include <iostream>
using namespace std;

class A {
  int *data;

 public:
  A() {
    cout << "A()" << endl;
    data = new int[10];
  }

  virtual void run() {}

  virtual ~A() {
    cout << "~A()" << endl;
    delete[] data;
  }
};

class B : public A {
  double *d;

 public:
  B() {
    cout << "B()" << endl;
    d = new double[20];
  }

  ~B() {
    cout << "~B()" << endl;
    delete[] d;
  }
};

int main() {
  A *pa = new B();  // 8+40+160
  delete pa;

  return 0;
}

// A()
// B()
// ~B()
// ~A()
