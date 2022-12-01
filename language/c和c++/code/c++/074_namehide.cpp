
#include <iostream>
using namespace std;

class A {
 public:
  static int sx;
  int x;

  A(int x = 0) : x(x) {}

  void show() { cout << "A:x = " << x << endl; }
};

int A::sx = 1;

class B : public A {
 public:
  static int sx;
  int x;

  B(int x = 0) : x(x) {}

  void show() { cout << "B:x = " << x << endl; }
};

int B::sx = 9;

int main() {
  cout << sizeof(B) << " " << B::sx << " " << A::sx << endl;
  B::sx = 0;
  cout << sizeof(B) << " " << B::sx << " " << A::sx << endl;

  B b(100);

  cout << b.x << endl;
  b.show();

  cout << b.A::x << endl;
  b.A::show();

  return 0;
}

// 8 9 1
// 8 0 1
// 100
// B:x = 100
// 0
// A:x = 0
