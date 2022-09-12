
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

  printf("请输入员工编号：");
  scanf("%d", &emp.num);

  printf("请输入员工姓名：");
  scanf("%s", emp.name);

  printf("请输入员工薪水：");
  scanf("%f", &emp.salary);

  ssize_t fd = open("emp.dat", O_CREAT |  // 创建
                               O_EXCL |   // 存在则创建失败
                               O_WRONLY,  // 只写
                               0666);
  if (-1 == fd) {
    perror("open"), exit(-1);
  }
  printf("emp.dat创建成功！\n");

  write(fd, &emp, sizeof(employer));

  close(fd);

  return 0;
}
