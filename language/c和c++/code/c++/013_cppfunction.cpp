
#include <iostream>
using namespace std;

bool flag = false;
int testcpp();

int main() {
  flag = testcpp();

  if (flag) {
    cout << "success!" << endl;
  } else {
    cout << "fail!" << endl;
  }

  return 0;
}

int testcpp() {
  cout << "this is a function!" << endl;
  return true;
}

// this is a function!
// success!
