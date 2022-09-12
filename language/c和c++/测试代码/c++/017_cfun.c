
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

int getmax(int x, int y) {
  printf("getmax use the c language!\n");
  return x > y ? x : y;
}

#ifdef __cplusplus
}
#endif

