
#include <iostream>
using namespace std;

int getmax(int x, int y);
int& getmax1(int& x, int& y);

int main() {
  int x = 1;
  int y = 123;
  int z = getmax(x, y);

  cout << "z=" << z << endl;

  z = getmax1(x, y);
  cout << "z=" << z << endl;

  getmax1(x, y) = 100;
  cout << "y=" << y << endl;
}

int getmax(int x, int y) {
  if (x > y)
    return x;
  else
    return y;
}

int& getmax1(int& x, int& y) {
  if (x > y)
    return x;
  else
    return y;
}

// z=123
// z=123
// y=100
