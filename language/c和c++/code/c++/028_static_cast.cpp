
#include <iostream>
using namespace std;

int main() {
  int *pi = new int(100);
  void *vp = pi;
  int *pi2 = static_cast<int *>(vp);

  cout << *pi2 << endl;

  return 0;
}

// 100
