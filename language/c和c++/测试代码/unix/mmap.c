
// mmap和munmap的使用
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int main() {
  //使用mmap建立映射
  void *p = mmap(NULL,                         // 内核指定
                 4,                            // 指定映射大小
                 PROT_READ | PROT_WRITE,       //访问权限可读可写
                 MAP_PRIVATE | MAP_ANONYMOUS,  //映射物理内存、私有、匿名映射
                 0,                            // 文件描述符
                 0);                           // 文件偏移量
  if (p == MAP_FAILED) {  // (void *)-1
    perror("mmap"), exit(-1);
  }

  //使用映射空间
  int *pi = (int *)p;  // void* -> int* 的强制类型转换
  *pi = 100;
  printf("%d\n", *pi);

  //解除映射
  munmap(p, 4);

  return 0;
}
