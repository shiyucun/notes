
#include <iostream>
using namespace std;

class Radio {
 private:
  string name;
  double price;

 public:
  void radiofun() { cout << "收听广播！" << endl; }
};

class Car {
 private:
  string color;
  Radio radio;

 public:
  void carfun() { cout << "代步！" << endl; }
};

int main() {
  cout << sizeof(Radio) << " " << sizeof(Car) << endl;
  return 0;
}

// 40 72
