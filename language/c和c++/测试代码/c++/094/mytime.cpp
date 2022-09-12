
#include "mytime.h"

#include <unistd.h>
#include <iomanip>
#include <iostream>

using namespace std;

void show() {
  cout << "This is a global show()!" << endl;
  cout << g_var << endl;
}

mytime::mytime(int hour, int minute, int second) : hour(hour), minute(minute), second(second) {}

void mytime::settime(int h, int m, int sec) {
  hour = h;
  minute = m;
  second = sec;
}

void mytime::run() { dida(); }

void mytime::show() {
  ::show();  // 无名命名空间

  cout << hour << ":" << minute << ":" << second << endl;
}
void mytime::dida() {
  while (1) {
    show();
    sleep(1);
    if (60 == ++second) {
      second = 0;
      if (60 == ++minute) {
        minute = 0;
        if (24 == ++hour) {
          hour = 0;
        }
      }
    }
  }
}
