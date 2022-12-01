
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

int main() {
  cout << "IBM salary = $" << IBM::salary << endl;
  cout << "Oracle salary = ￥" << Oracle::salary << endl;

  IBM::show();
  Oracle::show();

  return 0;
}

// IBM salary = $8000
// Oracle salary = ￥7500
// this is IBM
// this is Oracle
