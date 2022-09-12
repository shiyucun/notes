
#include <iostream>
using namespace std;

enum Direction { UP, DOWN, LEFT, RIGHT };

int main() {
  Direction dir = LEFT;
  cout << dir << endl;

  int d = dir;
  cout << dir << endl;

  d = 3;
  // dir = d;  // 不能把一个大范围变化的整数赋值给emum变量
  if (3 == d) {
    dir = RIGHT;
  }
  cout << dir << endl;

  return 0;
}

// 2
// 2
// 3
