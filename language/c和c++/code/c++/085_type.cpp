
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
 public:
  virtual void run() { cout << "this is animal run" << endl; }
};

class Dog : public Animal {
  string name;

 public:
  void run() { cout << "狗在陆地上狂奔" << endl; }

  void dogfun() {
    cout << "看家" << endl;
    cout << "name=" << name << endl;
    cout << "----------" << endl;
  }
};

class Fish : public Animal {
 public:
  void run() { cout << "鱼在水中游" << endl; }
  void fishfun() { cout << "鱼用来观赏" << endl; }
};

void testAnimal(Animal *pa) {
  // 类型通用 可以展示共性接口
  pa->run();
  // 恢复个性 类型识别
  // ((Dog*)pa)->dogfun();
  // if (typeid(*pa) == typeid(Dog)) {
  //   ((Dog *)pa)->dogfun();
  // }

  // if (typeid(*pa) == typeid(Fish)) {
  //   ((Fish *)pa)->fishfun();
  // }

  if (dynamic_cast<Dog *>(pa)) {
    ((Dog *)pa)->dogfun();
  } else if (dynamic_cast<Fish *>(pa)) {
    ((Fish *)pa)->fishfun();
  }
}

int main() {
  Dog dog;
  testAnimal(&dog);

  Fish fish;
  testAnimal(&fish);
}

// 狗在陆地上狂奔
// 看家
// name=
// ----------
// 鱼在水中游
// 鱼用来观赏
