
#include <iostream>
using namespace std;

class Fraction {
 private:
  int x;
  int y;

 public:
  Fraction(int x = 0, int y = 1) : x(x), y(y) {}

  void show() { cout << x << '/' << y << endl; }

  friend Fraction operator*(const Fraction fa, const Fraction fb);
};

// 声明为友元函数可以访问类中私有成员
Fraction operator*(const Fraction fa, const Fraction fb) {
  return Fraction(fa.x * fb.x, fa.y * fb.y);
}

int main() {
  Fraction fa(1, 2);
  Fraction fb(1, 3);

  Fraction fc = fa * fb;

  fc.show();

  return 0;
}

// 1/6
