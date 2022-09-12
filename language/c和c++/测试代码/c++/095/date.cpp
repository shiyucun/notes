
#include "mydate.h"

#include <time.h>
#include <unistd.h>
#include <iomanip>
#include <iostream>

using namespace std;

bool fstop = 1;

void stop_task(int signo) {
  cout << "signo = " << signo << endl;
  fstop = 0;
}

void Displaytime() { cout << "TIME："; }

void DisplayDate() { cout << "DATE："; }

Date::Date(bool flag, int y, int mon, int d, int h, int min, int s) {
  if (flag) {
    GetDT();
  } else {
    year = y;
    month = mon;
    day = d;
    hour = h;
    minute = min;
    second = s;
  }
}

void Date::DisplayDate() {
  ::DisplayDate();
  cout << setfill('0') << year << '-' << setw(2) << month << '-' << setw(2) << day << endl;
}

void Date::SetDate(int y, int m, int d, bool flag) {
  if (flag) {
    time_t sys_time;
    tm *ptm;

    time(&sys_time);  // time是获取1970年到当前的秒数，localtime是把这个秒数转换成当前时间
    ptm = localtime(&sys_time);

    day = ptm->tm_mday;
    month = ptm->tm_mon + 1;
    year = ptm->tm_year + 1900;
  } else {
    day = d;
    month = m;
    year = y;
  }
}

void Date::DisplayTime() {
  ::Displaytime();
  cout << setfill('0') << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second
       << endl;
}

void Date::setTime(int h, int m, int s, bool flag) {
  if (flag) {
    time_t sys_time;
    tm *ptm;

    time(&sys_time);  // time是获取1970年到当前的秒数，localtime是把这个秒数转换成当前时间
    ptm = localtime(&sys_time);

    hour = ptm->tm_hour;
    minute = ptm->tm_min;
    second = ptm->tm_sec;
  } else {
    hour = h;
    minute = m;
    second = s;
  }
}

void Date::cal_time(bool flag) {
  if (flag) {
    setTime(0, 0, 0, 1);
  } else {
    setTime(0, 0, 0, 0);
  }
  while (1) {
    if (fstop == 0) {
      break;
    }

    cout << setfill('0') << setw(2) << hour << ':' << setw(2) << minute << ':' << setw(2) << second
         << '\r' << flush;
    sleep(1);
    second++;
    if (second == 60) {
      second = 0;
      minute++;
      if (minute == 60) {
        minute = 0;
        hour++;
        if (hour == 24) {
          hour = 0;
        }
      }
    }
  }
  fstop = 1;
}

void Date::GetDT() {
  time_t sys_time;
  tm *ptm;

  time(&sys_time);  // time是获取1970年到当前的秒数，localtime是把这个秒数转换成当前时间
  ptm = localtime(&sys_time);

  day = ptm->tm_mday;
  month = ptm->tm_mon + 1;
  year = ptm->tm_year + 1900;
  hour = ptm->tm_hour;
  minute = ptm->tm_min;
  second = ptm->tm_sec;
}
