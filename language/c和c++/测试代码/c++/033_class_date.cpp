
#include <unistd.h>
#include <iomanip>
#include <iostream>
using namespace std;

class Date {
 private:
  int year_;
  int month_;
  int day_;

 public:
  Date(int y = 2016) {  // 构造函数自动调用
    cout << "构造函数！" << endl;
    year_ = y;
    month_ = 1;
    day_ = 1;
  }

  void show() { cout << year_ << endl; }
};

int main() {
  Date date(2013);
  date.show();

  Date *p = new Date();
  p->show();

  Date datec();  // 编译器把这句话翻译成一个函数声明

  Date *p1 = new Date(2020);
  p1->show();

  return 0;
}

// 构造函数！
// 2013
// 构造函数！
// 2016
// 构造函数！
// 2020
