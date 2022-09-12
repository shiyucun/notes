
#include <cstring>
#include <iostream>
using namespace std;

class Animal {
 private:
  int age;

 public:
  Animal(int age = 0) : age(age) {}

  void show() { cout << "Animal show()" << endl; }
  virtual void fun() { cout << "Animal fun()" << endl; }
  virtual void run() { cout << "Animal run()" << endl; }
};

class Dog : public Animal {
 public:
  virtual void fun() { cout << "watch dog" << endl; }
  void show() { cout << "Dog show()" << endl; }
};

class Cat : public Animal {
 public:
  virtual void fun() { cout << "Catch the mouses!" << endl; }
  virtual void run() { cout << "A run cat!" << endl; }
  void show() { cout << "Cat show()" << endl; }
};

int main() {
  Dog dog;
  Cat cat;

  memcpy(&dog, &cat, 4);

  Animal *pa = &dog;
  pa->fun();
  pa->show();

  return 0;
}

// Catch the mouses!
// Animal show()
