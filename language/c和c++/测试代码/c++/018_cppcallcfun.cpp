
#include <iostream>
using namespace std;

#ifdef __cplusplus
extern "C" {
#endif 

int getmax(int x, int y);

#ifdef __cplusplus
}
#endif

extern "C" void *memcpy(void *dest, const void *src, size_t size);

int main() {
  cout << getmax(1, 2) << endl;

  int x = 0, y = 100;

  memcpy(&x, &y, 4);
  cout << "x=" << x << endl;

  return 0;
}

// g++ 017_cfun.c 018_cppcallcfun.cpp && ./a.out
// getmax use the c language!
// 2
// x=100
