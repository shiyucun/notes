
#ifndef MYTIME_H
#define MYTIME_H

extern int g_var;
void show();
class mytime {
 private:
  int hour;
  int minute;
  int second;

 public:
  mytime(int hour = 0, int minute = 0, int second = 0);
  void settime(int h = 0, int m = 0, int sec = 0);
  void run();

 private:
  void show();
  void dida();
};

#endif
