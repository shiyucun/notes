
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

using namespace Oracle;
// using namespace IBM;

int main() {
  cout << age << endl;
  cout << salary << endl;

  show();
  IBM::show();

  return 0;
}

// 13
// 7500
// this is Oracle
// this is IBM
