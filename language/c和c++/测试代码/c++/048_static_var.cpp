
#include <iostream>
using namespace std;

class Person {
 private:
  string name;  // 标准编译器只占4个字节，其它编译器测试看
  int age;
  static int pcount;  // 不属于某个对象，属于这个类型

 public:
  Person(string name, int age) : age(age), name(name) {
    cout << "hello! I'm " << name << ". I'm " << age << " years old!" << endl;
    pcount++;
    cout << "人数：" << pcount << endl;
  }

  ~Person() {
    pcount--;
    cout << "欢送：" << name << "。人数：" << pcount << endl;
  }

  void show() { cout << name << ":" << age << ":" << pcount << endl; }
};

int Person::pcount = 0;  // 静态成员变量必须在类外初始化

void foo() {
  Person pa("abc", 55);
  Person po("def", 45);
  Person px("ghi", 60);
}

int main() {
  cout << sizeof(string) << endl;  // 32
  cout << sizeof(int) << endl;     // 4
  cout << sizeof(Person) << endl;  // 40

  foo();

  return 0;
}

// 32
// 4    (64位系统上，int 8字节对齐)
// 40
// hello! I'm abc. I'm 55 years old!
// 人数：1
// hello! I'm def. I'm 45 years old!
// 人数：2
// hello! I'm ghi. I'm 60 years old!
// 人数：3
// 欢送：ghi。人数：2
// 欢送：def。人数：1
// 欢送：abc。人数：0
