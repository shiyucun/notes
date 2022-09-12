
#include <iostream>
using namespace std;

int main() {
  bool flag;

  flag = "abc";
  cout << flag << endl;

  flag = false;
  cout << flag << endl;

  flag = true;
  int mdays = 28;
  mdays += flag;
  cout << mdays << endl;

  if (not flag) {
    cout << "条件真！" << endl;
  } else {
    cout << "条件假！" << endl;
  }

  return 0;
}

// 1
// 0
// 29
// 条件假！
