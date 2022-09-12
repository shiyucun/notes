
#include <iostream>
using namespace std;

class Base {
 private:
  int x;
  int y;

  void base_show1() { cout << x << " " << y << " " << x * y << endl; }

 protected:
  void SetXY(int SetX, int SetY) {
    x = SetX;
    y = SetY;
  }

  void base_show2() {
    base_show1();
    cout << x << " " << y << " " << x * y << endl;
  }

 public:
  Base(int x = 0, int y = 0) : x(x), y(y) { cout << "Base()" << endl; }
  ~Base() { cout << "~Base()" << endl; }

  void base_show3() { cout << x << " " << y << " " << x * y << endl; }

  int get_result() { return x * y; }
};

class create : public Base {
 private:
  int result;

 public:
  create(int result = 0) : result(result) { cout << "create()" << endl; }
  ~create() { cout << "~create()" << endl; }

  void create_show() {
    cout << "result = " << result << endl;
    base_show2();
  }

  void SetXYR(int SetX, int SetY, int Result) {
    SetXY(SetX, SetY);
    result = Result;
  }
};

int main() {
  create create_public;

  create_public.SetXYR(3, 4, 5);
  create_public.create_show();
  create_public.base_show3();

  return 0;
}

// Base()
// create()
// result = 5
// 3 4 12
// 3 4 12
// 3 4 12
// ~create()
// ~Base()
