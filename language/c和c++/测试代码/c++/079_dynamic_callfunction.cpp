
#include <iostream>
using namespace std;

class Animal {
 private:
  string name;
  int age;

 public:
  Animal(string name = "", int age = 0) : name(name), age(age) {}

  void show() { cout << name << ":" << age << endl; }
  virtual void run() { cout << "Animal is running!" << endl; }
};

class Fish : public Animal {
 private:
 public:
  Fish(string name = "", int age = 0) : Animal(name, age) {}

  // namehide
  void show() {
    cout << "This is a ";
    Animal::show();
  }

  // overwrite
  void run() { cout << "fish is in the water!" << endl; }
};

class Bird : public Animal {
 private:
 public:
  Bird(string name = "", int age = 0) : Animal(name, age) {}

  // namehide
  void show() { cout << "This is a bird!" << endl; }

  // overwrite
  void run() { cout << "Bird fly in the sky!" << endl; }
};

int main() {
  // 编译时可以确定调用 Fish 中的函数
  Fish fish("银龙", 20);
  fish.show();
  fish.run();

  // 编译时可以确定调用Animal中的show和run函数
  Animal a = fish;
  a.show();
  a.run();

  Animal *pa;
  int f;
  cin >> f;

  if (0 == f) {
    pa = new Fish();
  } else {
    pa = new Bird();
  }

  // 调用Animal中的show函数
  pa->show();

  // 根据f的值确定调用哪个run函数
  pa->run();

  return 0;
}

// This is a 银龙:20
// fish is in the water!
// 银龙:20
// Animal is running!
// 2
// :0
// Bird fly in the sky!
