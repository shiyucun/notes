
#include <iostream>
using namespace std;

#define GETMAX(x, y) (((x) > (y)) ? (x) : (y))

int getmax(int x, int y);

int main() {
  cout << GETMAX(2, 1) << endl;
  cout << getmax(2, 1) << endl;

  return 0;
}

int getmax(int x, int y) { return x > y ? x : y; }

// 2
// 2
