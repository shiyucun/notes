
#include <iostream>
#include <memory>
using namespace std;

class A {
 public:
  A() { cout << "A()" << endl; }
  ~A() { cout << "~A()" << endl; }

  void show() { cout << "show()" << endl; }
};

class myauto_ptr {
 private:
  A *data;

 public:
  myauto_ptr(A *data = NULL) : data(data){};
  ~myauto_ptr() { data = NULL; }

  A *operator->() { return data; }
  A &operator*() { return *data; }
};

void foo() {
  // 在新版本的 c++中，auto_ptr 已被加入以下标记，编译时会提醒 auto_ptr 被弃用
  // _GLIBCXX_DEPRECATED
  // # define _GLIBCXX_DEPRECATED __attribute__ ((__deprecated__))
  A *pa = new A();
  auto_ptr<A> myptr1(pa);
  myptr1->show();

  A *pb = new A();
  myauto_ptr myptr2(pb);
  myptr2->show();
  myptr2.operator->()->show();  // 编译器会把代码还原成上面的样子
  (*myptr2).show();
}

int main() {
  foo();
  return 0;
}

// A()
// show()
// A()
// show()
// show()
// show()
// ~A()
