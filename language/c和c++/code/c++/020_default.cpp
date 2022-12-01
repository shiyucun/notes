
#include <iostream>
using namespace std;

int getmax(int x = 1, int y = 3);

int main() {
  cout << getmax() << endl;
  cout << getmax(2) << endl;
  cout << getmax(5, 8) << endl;
  cout << getmax(8, 5) << endl;

  return 0;
}

int getmax(int x, int y) { return x > y ? x : y; }

// 3
// 3
// 8
// 8
