
#include <iostream>
using namespace std;

void swap1(int& xr, int& yr);
void swap2(int* xp, int* yp);
void display(const double& d);

int main() {
  int x = 100, y = 20;
  cout << x << endl << y << endl;

  swap1(x, y);
  cout << x << endl << y << endl;

  swap2(&x, &y);
  cout << x << endl << y << endl;

  double d = 1.23456;
  display(d);
  display(2.34567);

  return 0;
}

void swap1(int& xr, int& yr) {
  int temp;

  // 交换 x y
  temp = xr;
  xr = yr;
  yr = temp;
}

void swap2(int* xp, int* yp) {
  int temp;

  temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void display(const double& d) { cout << d << endl; }

// 100
// 20
// 20
// 100
// 100
// 20
// 1.23456
// 2.34567
