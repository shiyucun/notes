
#include <iostream>
using namespace std;

class Date {
 private:
  int year_;
  int month_;
  int day_;

 public:
  Date(int y = 2015, int m = 2, int d = 4) {
    cout << "class Date" << endl;
    year_ = y;
    month_ = m;
    day_ = d;
  }

  void show() { cout << year_ << "-" << month_ << "-" << day_ << " "; }
};

class Emp {
 private:
  int id_;
  Date date_;
  double salary_;

 public:
  Emp(int i = 0, double s = 0) {
    cout << "class Emp" << endl;
    id_ = i;
    salary_ = s;
  }

  void show() {
    cout << id_ << " ";
    date_.show();
    cout << salary_ << endl;
  }
};

int main() {
  cout << sizeof(Emp) << endl;

  Emp emp;
  emp.show();

  return 0;
}

// 24
// class Date
// class Emp
// 0 2015-2-4 0
