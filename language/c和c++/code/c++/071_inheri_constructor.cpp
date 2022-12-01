
#include <iostream>
using namespace std;

class A {
 private:
  int x;
  int y;

 public:
  A() { cout << "A()" << endl; }
  A(int x, int y) : x(x), y(y) { cout << "A(int x, int y) : x(x), y(y)" << endl; }
  ~A() { cout << "~A()" << endl; }

  void show() { cout << "showA" << endl; }
};

class B : public A {
 private:
  int x;

 public:
  B() : A(100, 200) { cout << "B()" << endl; }
  B(int x) : A(100, 200), x(x) { cout << "B(int x) : A(100, 200), x(x)" << endl; }
  ~B() { cout << "~B()" << endl; }

  void show() { cout << "showB" << endl; }
};

class C : public B {
 public:
  C() { cout << "C()" << endl; }
  ~C() { cout << "~C()" << endl; }
};

int main() {
  C c;
  c.show();

  return 0;
}

// A(int x, int y) : x(x), y(y)
// B()
// C()
// showB
// ~C()
// ~B()
// ~A()
