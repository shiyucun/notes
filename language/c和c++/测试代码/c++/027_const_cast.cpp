
#include <iostream>
using namespace std;

int main() {
  volatile const int data = 100;
  int *pi = const_cast<int *>(&data);

  *pi = 200;

  cout << *pi << "  " << data << endl;
  cout << pi << endl;
  cout << (int *)&data << endl;

  return 0;
}

// 200  200
// 0x7ffe5dfafa2c
// 0x7ffe5dfafa2c
