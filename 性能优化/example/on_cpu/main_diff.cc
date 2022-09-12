#include <iostream>

using namespace std;

int add1(int a, int b) {
  int sum = 0;

  for (int i = 0; i < 0xffffff; i++) {
    sum += a + b;
  }

  cout << sum << endl;

  return a + b;
}

int main() {
  add1(1, 1);
  add1(2, 2);
  return 0;
}
