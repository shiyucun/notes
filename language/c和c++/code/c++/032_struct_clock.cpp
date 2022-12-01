
#include <unistd.h>
#include <iomanip>
#include <iostream>
using namespace std;

struct Time {
  int hour_;
  int minute_;
  int second_;

  void show() {
    cout << setfill('0') << setw(2) << hour_ << ':' << setw(2) << minute_ << ':' << setw(2)
         << second_ << '\r' << flush;  // 回车刷新，使时间显示在一行
  }

  void dida() {
    show();
    while (1) {
      sleep(1);
      second_++;
      if (second_ == 60) {
        second_ = 0;
        minute_++;
        if (minute_ == 60) {
          minute_ = 0;
          hour_++;
          if (hour_ == 24) {
            hour_ = 0;
          }
        }
      }
      show();
    }
  }
};

int main() {
  Time time = {23, 59, 58};

  time.dida();

  return 0;
}
