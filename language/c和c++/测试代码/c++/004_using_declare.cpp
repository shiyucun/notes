
#include <iostream>
using namespace std;

namespace IBM {
double salary = 8000;
void show() { cout << "this is IBM" << endl; }
}  // namespace IBM

namespace Oracle {
double salary = 7500;
int age = 13;
void show();
}  // namespace Oracle

namespace Oracle {
void show() { cout << "this is Oracle" << endl; }
}  // namespace Oracle

using IBM::salary;
using Oracle::show;

int main() {
  cout << salary << endl;
  cout << Oracle::salary << endl;

  show();
  IBM::show();

  return 0;
}

// 8000
// 7500
// this is Oracle
// this is IBM
