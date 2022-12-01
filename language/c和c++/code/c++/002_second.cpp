
#include <cstdio>
#include <iostream>
using namespace std;

int main() {
  int age = 0;

  cout << "c++ interface" << endl;
  cout << "请输入一个年龄:" << endl;
  cin >> age;
  cout << "输入的年龄是" << age << endl;

  printf("c interface\n");
  printf("请输入一个年龄:\n");
  scanf("%d", &age);
  printf("输入的年龄是%d\n", age);

  return 0;
}
