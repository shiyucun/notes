
#include <iostream>
using namespace std;

class Date {
 public:
  int year_;
  int month_;
  int day_;

 public:
  Date();

  void show();

  Date addDay();
  Date* addday();
};

// 全局函数对一个日期变量进行显示
void ShowDate(Date* mythis);

Date::Date() {
  year_ = 1234;
  month_ = 5;
  day_ = 6;
}

void Date::show() { ShowDate(this); }

Date Date::addDay() {
  day_++;
  return *this;
}

Date* Date::addday() {
  day_++;
  return this;
}

int main() {
  Date date;

  date.show();
  date.addDay().addDay();
  date.show();

  (date.addday())->addDay();
  date.show();

  return 0;
}

void ShowDate(Date* mythis) {
  cout << mythis->year_ << "-" << mythis->month_ << "-" << mythis->day_ << endl;
}

// 1234-5-6
// 1234-5-7
// 1234-5-9
