
#include <iostream>
using namespace std;

class Animal {
 public:
  string name;
  int age;

 public:
  void show() { cout << "Animal " << name << " " << age << endl; }
};

class Dog : public Animal {
 public:
  int leges;
  void dogfun() { cout << "看家" << endl; }
};

class Cat : public Animal {
 public:
  string color;
  void catfun() { cout << "catch mouse!" << endl; }
};

int main() {
  cout << sizeof(Animal) << endl;
  cout << sizeof(Dog) << endl;
  cout << sizeof(Cat) << endl;

  Dog dog;

  dog.name = "lily";
  dog.age = 2;

  dog.show();
  dog.dogfun();

  return 0;
}

// x64, int 8字节对齐, string 大小为 32
// 40
// 40
// 72
// Animal lily 2
// 看家
