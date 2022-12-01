
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
 public:
  virtual void run() { cout << "animal run()" << endl; }
};

class Dog : public Animal {
 private:
  string name;

 public:
  void run() { cout << "Dog run()" << endl; }

  void dogfun() {
    cout << "dogfun()" << endl;
    cout << "name = " << name << endl;
  }
};

class Fish : public Animal {
 public:
  void run() { cout << "Fish run()" << endl; }

  void fishfun() { cout << "fishfun()" << endl; }
};

void testAnimal(Animal *pa) {
  // 展示共性接口，类型通用
  pa->run();

  // 恢复个性，则需要类型识别
  cout << typeid(*pa).name() << endl;

  if (typeid(*pa) == typeid(Dog)) {
    ((Dog *)pa)->dogfun();
  } else if (typeid(*pa) == typeid(Fish)) {
    ((Fish *)pa)->fishfun();
  }
}

int main() {
  Dog dog;
  testAnimal(&dog);

  Fish fish;
  testAnimal(&fish);

  return 0;
}

// Dog run()
// 3Dog
// dogfun()
// name =
// Fish run()
// 4Fish
// fishfun()
