
#include <iostream>
using namespace std;

class Fraction {
 public:
  int x;
  int y;

 public:
  Fraction(int x = 1, int y = 1) : x(x), y(y) {}

  void show() { cout << x << '/' << y << endl; }

  Fraction operator+(const Fraction& b) {
    cout << "mem operator+" << endl;
    return Fraction(x * b.y + y * b.x, y * b.y);
  }
};

void Fractionadd1(Fraction& a, Fraction& b, Fraction& c) {
  c.x = a.x * b.y + a.y * b.x;
  c.y = a.y * b.y;
}

Fraction Fractionadd2(const Fraction& a, const Fraction& b) {
  return Fraction(a.x * b.y + a.y * b.x, a.y * b.y);
}

Fraction operator+(const Fraction& a, const Fraction& b) {
  return Fraction(a.x * b.y + a.y * b.x, a.y * b.y);
}

int main() {
  Fraction vara(1, 2);
  vara.show();

  Fraction varb(1, 3);
  varb.show();

  Fraction varc;
  Fractionadd1(vara, varb, varc);
  varc.show();

  Fraction vard = Fractionadd2(vara, varb);
  vard.show();

  Fraction vare = vara + varb;
  vare.show();

  return 0;
}

// 1/2
// 1/3
// 5/6
// 5/6
// mem operator+
// 5/6
