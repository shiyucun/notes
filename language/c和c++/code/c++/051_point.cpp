
#include <iostream>
using namespace std;

struct Date {
  int year;
  int month;
  int day;

  Date(int year = 1970, int month = 1, int day = 1) {
    this->year = year;
    this->month = month;
    this->day = day;
  }
};

int main() {
  Date date(2070, 10, 8);
  Date date1(2071, 11, 9);

  union {
    int Date::*pm;
    int *p;
  };

  pm = &Date::year;
  cout << date.*pm << " : " << p << endl;
  cout << date1.*pm << " : " << p << endl;

  pm = &Date::day;
  cout << date.*pm << " : " << p << endl;
  cout << date1.*pm << " : " << p << endl;

  return 0;
}

// 2070 : 0
// 2071 : 0
// 8 : 0x8
// 9 : 0x8

// 指向成员变量的指针，本质上是记录这个成员变量与首地址的偏移量
