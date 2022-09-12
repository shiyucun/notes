
#include <iostream>
using namespace std;

class Person {
 private:
  int age;

 public:
  Person(int age = 0) : age(age) {}
  Person(const Person& p) {
    cout << "Person(const Person& p)" << endl;
    age = p.age;
  }

  void show() { cout << "age = " << age << endl; }
};

class Emp : public Person {
 private:
  int* data;
  int c;

 public:
  Emp(int age = 0, int c = 1) : Person(age), c(c) { data = new int[c]; }

  ~Emp() { delete[] data; }

  Emp(const Emp& e) : Person(e) {
    c = e.c;
    data = new int[c];
    for (int i = 0; i < c; i++) {
      data[i] = e.data[i];
    }
  }

  Emp& operator=(const Emp& e) {
    Person::operator=(e);
    if (this != &e) {
      delete[] data;

      c = e.c;
      data = new int[c];

      for (int i = 0; i < c; i++) {
        data[i] = e.data[i];
      }
    }
    return *this;
  }
};

int main() {
  Emp a(40);
  Emp b(30);
  Emp c = a;  //调用拷贝构造

  c.show();
  b.show();

  b = a;  //调用赋值运算符,如果没有人工重载赋值运算符，这句话会重复释放内存
  b.show();

  return 0;
}

// Person(const Person& p)
// age = 40
// age = 30
// age = 40
