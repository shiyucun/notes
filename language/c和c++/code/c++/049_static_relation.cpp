
#include <iostream>
using namespace std;

class A {
 public:
  int x;
  static int c;

 public:
  A(int value = 0) : x(value) { cout << "对象构造成功，x初始化为" << value << endl; }

  ~A() { cout << "对象销毁成功！" << endl; }

  static void show(A& a) { cout << a.x << endl; }

  // 普通函数第一个参数传 this 指针，静态函数不会传 this 指针
  void show2() {
    cout << this->x << endl;
    cout << this->c << endl;
  }

  static void show3(A* mythis) {
    cout << mythis->x << endl;
    cout << mythis->c << endl;
  }
};

int A::c = 0;

int main() {
  A a(5);

  A::show(a);
  a.show2();
  A::show3(&a);

  return 0;
}

// 对象构造成功，x初始化为5
// 5
// 5
// 0
// 5
// 0
// 对象销毁成功！
