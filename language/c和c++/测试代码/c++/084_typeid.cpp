
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal {
 public:
  virtual void run() {}
};

class Dog : public Animal {
 public:
  virtual void run() {}
};

int main() {
  int x;
  cout << typeid(x).name() << endl;

  double *p;
  cout << typeid(*p).name() << endl;

  Animal *pa = new Dog();
  cout << typeid(pa).name() << endl;
  cout << typeid(*pa).name() << endl;

  if (typeid(*pa) == typeid(Dog)) {
    cout << "Yes!" << endl;
  }

  return 0;
}

// i
// d
// P6Animal
// 3Dog
// Yes!
