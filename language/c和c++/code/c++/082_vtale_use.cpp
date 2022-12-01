
#include <cstring>
#include <iostream>
using namespace std;

class Animal {
 private:
  int age;

 public:
  Animal(int age = 0) : age(age) {}

  virtual void show(int s) { cout << "Animal show:" << s << endl; }
  virtual void run(int speed) { cout << "Animal run speed:" << speed << endl; }
};

// 注意：底层函数原型的第一个参数都是包含该函数的类的指针
typedef void (*FUN)(Animal* t, int s);
typedef FUN* VTABLE;

int main() {
  Animal a;

  // 取得对象 a 的虚表
  VTABLE vt = *(VTABLE*)(&a);

  vt[0](&a, 2);
  vt[1](&a, 100);

  return 0;
}

// Animal show:2
// Animal run speed:100
