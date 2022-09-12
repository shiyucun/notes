
#include <iostream>
using namespace std;

int main() {
  int x = 1;
  int& rx = x;

  cout << &x << endl;
  cout << &rx << endl;
  cout << x << endl << rx << endl;

  rx = 2;
  cout << x << endl << rx << endl;

  const int& rtemp = 100;
  cout << rtemp << endl;

  return 0;
}

// 0x7ffc0157e6f0
// 0x7ffc0157e6f0
// 1
// 1
// 2
// 2
// 100
