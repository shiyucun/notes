
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

  int getyear() { return year; }

  int getday() { return day; }
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

  int (Date::*pmfun)();  // 成员函数指针
  pmfun = &Date::getyear;  // 没有 & 就是静态函数的地址，加上 & 就是普通函数的地址

  int y = (date.*pmfun)();
  cout << y << endl;

  Date *pmdate = new Date(2016, 8, 9);
  y = (pmdate->*pmfun)();
  cout << y << endl;

  return 0;
}

// 2070 : 0
// 2071 : 0
// 8 : 0x8
// 9 : 0x8
// 2070
// 2016
