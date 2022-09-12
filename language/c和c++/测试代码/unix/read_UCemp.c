
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct employer {
  int num;
  char name[20];
  float salary;
} employer;

int main() {
  employer emp = {0};

  ssize_t fd = open("emp.dat", O_RDONLY);  // 只读
  if (-1 == fd) {
    perror("open"), exit(-1);
  }

  printf("emp.dat打开！\n");

  read(fd, &emp, sizeof(employer));

  printf("%d,%s,%.2f\n", emp.num, emp.name, emp.salary);

  close(fd);

  return 0;
}
