
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
  Date(int& py, int y = 2015, int m = 1, int d = 1)
      : century_(m), year_(2014), month_(5), day_(15), y_(py) {
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

  Date D(x, 2013, 2, 2);

  return 0;
}

// 2  2014-5-15 100
// 2  2013-2-2 100
