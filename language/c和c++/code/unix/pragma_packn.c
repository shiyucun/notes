/* #pragma pack(n)的使用 */

#include <stdio.h>

#pragma pack(1)

typedef struct s {
  char c1;
  int i;
  char c2;
} s;

int main() {
  printf("sizeof(s) = %d.\n", sizeof(s));
  return 0;
}
