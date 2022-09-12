
#include <iostream>
using namespace std;

class Emp {
 private:
  int id;
  string name;
  double salary;

 public:
  Emp(int id = 0, string name = "abc", double salary = 0) : id(id), name(name), salary(salary) {
    cout << "Emp()" << endl;
  }

  void show() { cout << id << ' ' << name << ' ' << salary << endl; }
};

int main() {
  Emp emp1(1, "xq", 8000);
  emp1.show();

  Emp emp2 = emp1;
  emp2.show();

  return 0;
}

// Emp()
// 1 xq 8000
// 1 xq 8000
