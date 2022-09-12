
#include <iomanip>
#include <iostream>
using namespace std;

struct Date {
  int year;
  int month;
  int day;

  void show() {
    cout << setfill('0') << year << '-' << setw(2) << month << '-' << setw(2) << day << endl;
  }

  void operator++() {}
  void operator++(int) {}
};

int main() {
  Date date = {2015, 2, 3};
  date.show();

  ++date;
  date++;

  return 0;
}

// 2015-02-03
