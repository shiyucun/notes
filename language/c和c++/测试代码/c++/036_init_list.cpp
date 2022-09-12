
#include <iostream>
using namespace std;

class Date {
 private:
  const int century_;
  int year_;
  int month_;
  int day_;
  int& y_;

 public:
  Date(int y = 2015, int m = 1, int d = 1, int x = 101)
      : century_(x), year_(2014), month_(5), day_(15), y_(*(new int(x))) {
    cout << "---" << endl;
    show();
    year_ = y;
    month_ = m;
    day_ = d;
    show();
  }

  void show() {
    cout << century_ << "  " << year_ << "-" << month_ << "-" << day_ << " " << y_ << endl;
  }
};

int main() {
  int x = 100;

  Date A;
  Date B(2013);
  Date C(2013, 2);
  Date D(2013, 2, 3);
  Date E(2013, 2, 3, 4);

  return 0;
}

// ---
// 101  2014-5-15 101
// 101  2015-1-1 101
// ---
// 101  2014-5-15 101
// 101  2013-1-1 101
// ---
// 101  2014-5-15 101
// 101  2013-2-1 101
// ---
// 101  2014-5-15 101
// 101  2013-2-3 101
// ---
// 4  2014-5-15 4
// 4  2013-2-3 4
