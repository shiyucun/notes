
#ifndef MYDATE_H
#define MYDATE_H

void Displaytime();
void DisplayDate();
void stop_task(int signo);

class Date {
 private:
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;

 public:
  Date(bool flag = 1, int y = 1970, int mon = 1, int d = 1, int h = 0, int min = 0, int s = 0);

  void DisplayDate();
  void SetDate(int y = 1970, int m = 1, int d = 1, bool flag = 1);

  void DisplayTime();
  void setTime(int h = 0, int m = 0, int s = 0, bool flag = 1);
  void cal_time(bool flag = 1);

  void GetDT();
};

#endif
