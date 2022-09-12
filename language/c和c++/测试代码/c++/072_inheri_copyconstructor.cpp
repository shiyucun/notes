
#include <iostream>
using namespace std;

class A {
 private:
  int x;

 public:
  A(int x = 0) : x(x) {}
  A(const A& a) {
    cout << "A(const A&)" << endl;
    x = a.x;
  }
};

class B : public A {
 public:
  int y;

  B() {}
  B(const B& b) : A(b) {
    cout << "B(const B& b)" << endl;
    y = b.y;
  }
};

int main() {
  B b1;
  b1.y = 101;

  B b2 = b1;
  cout << b2.y << endl;

  return 0;
}

// A(const A&)
// B(const B& b)
// 101
