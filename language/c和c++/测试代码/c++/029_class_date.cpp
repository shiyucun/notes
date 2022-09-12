
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
  void show() {
    cout << setfill('0') << setw(4) << year_ << '-' << setw(2) << month_ << '-' << setw(2) << day_
         << endl;
  }

  void setDate(int year = 2015, int month = 2, int day = 4) {
    year_ = year;
    month_ = month;
    day_ = day;
  }
};

int main() {
  Date date;

  date.setDate();
  date.show();

  date.setDate(2014, 2, 25);
  date.show();

  date.setDate(2012, 9, 15);
  date.show();

  return 0;
}

// 2015-02-04
// 2014-02-25
// 2012-09-15
