
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

  Fraction operator*(const Fraction& b) {
    cout << "mem operator*" << endl;
    return Fraction(x * b.x, y * b.y);
  }

  Fraction operator*=(const Fraction& b) {
    cout << "mem operator*=" << endl;
    x *= b.x;
    y *= b.y;
    return *this;
  }

  friend ostream& operator<<(ostream& os, const Fraction& f);
  friend istream& operator>>(istream& is, Fraction& f);
};

ostream& operator<<(ostream& os, const Fraction& f) {
  os << f.x << '/' << f.y;
  return os;
}

istream& operator>>(istream& is, Fraction& f) {
  is >> f.x;
  is >> f.y;
  return is;
}

int main() {
  Fraction vara(1, 2);
  vara.show();

  Fraction varb(1, 3);
  varb.show();

  Fraction varc = vara + varb;
  varc.show();

  Fraction vard = vara * varb;
  vard.show();

  vara *= varb;
  vara.show();

  cout << vard << endl;
  cin >> vard >> varc;
  cout << vard << endl << varc << endl;

  return 0;
}

// 1/2
// 1/3
// mem operator+
// 5/6
// mem operator*
// 1/6
// mem operator*=
// 1/6
// 1/6
// 2 3
// 5 6
// 2/3
// 5/6
