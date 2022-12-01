
#include <stdio.h>

int getmax(int x, int y);

int main() {
  printf("%d\n", getmax(1, 2));
  return 0;
}

int getmax(int x, int y) { return x > y ? x : y; }

// 2
