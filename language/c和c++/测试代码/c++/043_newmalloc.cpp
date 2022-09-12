
#include <cstdlib>
#include <iostream>
using namespace std;

struct Date {
  int year;
  int month;
  int day;

  Date() : year(2015), month(1), day(1) { cout << "Date()" << endl; }
};

class Emp {
 public:
  int id_;
  Date date_;
  double salary_;

 public:
  Emp() : id_(0), salary_(9) { cout << "Emp()" << endl; }
};

int main() {
  cout << "-----------------------" << endl;
  Emp emp;
  cout << "-----------------------" << endl;
  Emp *p1 = new Emp();
  cout << "-----------------------" << endl;
  Emp *p2 = new Emp;
  cout << "-----------------------" << endl;

  // 以下代码用 malloc 实现 new 的功能
  Emp *p3 = static_cast<Emp *>(malloc(sizeof(Emp)));

  Date date;
  p3->date_ = date;

  (p3->date_).year = 2015;
  (p3->date_).month = 1;
  (p3->date_).day = 1;

  p3->id_ = 0;
  p3->salary_ = 9;
  cout << "-----------------------" << endl;

  return 0;
}

// -----------------------
// Date()
// Emp()
// -----------------------
// Date()
// Emp()
// -----------------------
// Date()
// Emp()
// -----------------------
// Date()
// -----------------------
