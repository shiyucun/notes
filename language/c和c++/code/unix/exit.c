// exit函数的使用
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void fa(void) { printf("有钱任性!\n"); }

int main() {
  atexit(fa);

  printf("main start...\n");
  //_exit(0);
  //_Exit(0);
  exit(0);
  printf("main end!\n");

  return 0;
}
