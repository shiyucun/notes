#include <iostream>

using namespace std;

int add(int a, int b) {
  int sum = 0;

  for (int i = 0; i < 0xffffff; i++) {
    sum += a + b;
  }

  cout << sum << endl;

  return a + b;
}

int main() {
  add(1, 1);
  add(2, 2);
  return 0;
}
