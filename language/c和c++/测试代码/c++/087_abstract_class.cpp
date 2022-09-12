
#include <iostream>
using namespace std;

class Animal {
  string name;
  int age;

 public:
  Animal(string name = "", int age = 0) : name(name), age(age) {}

  void show() {}
  virtual void run() = 0;
};

class Cat : public Animal {
 public:
  Cat() : Animal("noname", 0) {}

  void run() {}
};

int main() {
  // Animal  a;

  Cat cat;
  Animal *pa = new Cat();

  return 0;
}
