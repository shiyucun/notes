
#include <iostream>
using namespace std;

class Date {
 private:
  int year_;
  int month_;
  int day_;

 public:
  Date();

  void show();
};

Date::Date() { cout << "this =  " << this << endl; }

void Date::show() { cout << "this =  " << this << endl; }

int main() {
  Date date;

  cout << "&date=  " << &date << endl;
  date.show();

  Date *pd = new Date();

  cout << "pd   =  " << pd << endl;
  pd->show();

  cout << "&pd  =  " << &pd << endl;

  return 0;
}

// this =  0x7fffa534843c
// &date=  0x7fffa534843c
// this =  0x7fffa534843c
// this =  0x555d1d1e12c0
// pd   =  0x555d1d1e12c0
// this =  0x555d1d1e12c0
// &pd  =  0x7fffa5348430
