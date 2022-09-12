
#include "mydate.h"

#include <signal.h>

using namespace std;

int main() {
  signal(SIGQUIT, stop_task);
  Date date;
  date.DisplayDate();
  date.DisplayTime();

  date.SetDate(1970, 1, 1, 1);
  date.DisplayDate();
  date.SetDate(1970, 1, 1, 0);
  date.DisplayDate();

  date.setTime(0, 0, 0, 1);
  date.DisplayTime();
  date.setTime(2, 34, 56, 0);
  date.DisplayTime();

  date.cal_time(1);
  date.cal_time(0);

  return 0;
}

// DATE：2022-07-06
// TIME：02:08:05
// DATE：2022-07-06
// DATE：1970-01-01
// TIME：02:08:05
// TIME：02:34:56
// ^C:08:10
