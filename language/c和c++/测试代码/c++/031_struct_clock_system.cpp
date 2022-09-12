
#include <time.h>
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
         << second_ << '\r' << flush;
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

  void getsystemtime() {
    time_t sys_time;
    tm *ptm;

    time(&sys_time); /* time是获取1970年到当前的秒数，localtime是把这个秒数转换成当前时间 */

    ptm = localtime(&sys_time);

    hour_ = ptm->tm_hour;
    minute_ = ptm->tm_min;
    second_ = ptm->tm_sec;
  }
};

int main() {
  Time time;

  time.getsystemtime();
  time.dida();

  return 0;
}
