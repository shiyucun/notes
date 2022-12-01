
//建立和解除虚拟地址到文件的映射
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct Emp {
  int id;
  char name[20];
  double salary;
} Emp;

int main() {
  //创建一个保存员工信息的文件，给定文件的大小
  ssize_t fd = open("Emp.dat", O_CREAT | O_EXCL | O_RDWR | O_TRUNC, 0666);
  if (fd == -1) {
    perror("open"), exit(-1);
  }

  ftruncate(fd, sizeof(Emp) * 3);

  //建立虚拟地址到文件的映射
  void *p = mmap(NULL, sizeof(Emp) * 3, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (p == MAP_FAILED) {
    perror("mmap"), exit(-1);
  }

  //准备员工信息，通过虚拟地址操作文件
  Emp *pe = p;
  pe[0].id = 1001;
  strcpy(pe[0].name, "zhangfei");
  pe[0].salary = 3000;

  pe[1].id = 1002;
  strcpy(pe[1].name, "guanyu");
  pe[1].salary = 3500;

  pe[2].id = 1001;
  strcpy(pe[2].name, "liubei");
  pe[2].salary = 4000;

  //解除映射
  munmap(p, 3 * sizeof(Emp));

  //关闭文件
  close(fd);

  return 0;
}
