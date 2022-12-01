
#include <iostream>
using namespace std;

class Animal {
 public:
  virtual void run() {}
};

class Dog : public Animal {};

class Cat : public Animal {};

int main() {
  Animal *pa = new Dog();
  if (dynamic_cast<Cat *>(pa)) {
    cout << "这是一只猫" << endl;
  } else if (dynamic_cast<Dog *>(pa)) {
    cout << "这是一条狗" << endl;
  }
}

// 这是一条狗
