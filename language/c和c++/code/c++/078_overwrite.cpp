
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
  Fish fish("银龙", 20);
  fish.show();
  fish.run();
  cout << "------------------------------" << endl;

  Animal *pa = new Fish();
  pa->show();
  pa->run();
  cout << "------------------------------" << endl;

  Animal *pb = new Bird();
  pb->show();
  pb->run();

  return 0;
}

// This is a 银龙:20
// fish is in the water!
// ------------------------------
// :0
// fish is in the water!
// ------------------------------
// :0
// Bird fly in the sky!
