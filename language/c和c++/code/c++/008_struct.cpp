
#include <iomanip>
#include <iostream>
using namespace std;

struct Date {
  int year;
  int month;
  int day;

  void show();
};

void Date::show() {
  cout << setfill('0') << year << "-" << setw(2) << month << "-" << setw(2) << day << endl;
}

// 显示日期数据的函数
void display(const Date *date) {
  cout << (*date).year << "-" << (*date).month << "-" << (*date).day << endl;
}

int main() {
  cout << sizeof(Date) << endl;

  Date date = {2015, 2, 2};  // 省略struct定义变量
  cout << sizeof date << endl;  // sizeof，+变量时可以省略()，+变量类型时不可以省略()

  date.month = 12;

  display(&date);

  date.show();

  return 0;
}

// 12
// 12
// 2015-12-2
// 2015-12-02
