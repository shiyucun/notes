
#include <iostream>
using namespace std;

class Integer {
  int data;

 public:
  Integer(int data = 0) : data(data) {}

  const Integer operator+(const Integer& ib) const { return data + ib.data; }

  friend ostream& operator<<(ostream& os, const Integer& i);
  friend istream& operator>>(istream& is, Integer& i);
  friend Integer& operator++(Integer& i);
  friend const Integer operator++(Integer& i, int);
};

int getInt() {
  int x = 100;
  return x;
}

const Integer getInteger() {
  Integer i(100);
  return i;
}

ostream& operator<<(ostream& os, const Integer& i) {  // 支持 Integer 输出
  return os << i.data;
}

istream& operator>>(istream& is, Integer& i) {  // 支持 Integer 输入
  return is >> i.data;
}

Integer& operator++(Integer& i) {  // 全局形式前 ++
  i.data++;
  return i;
}

const Integer operator++(Integer& i, int) {  // 全局形式后 ++
  return i.data++;
}

int main() {
  // getInt() = 101;

  const Integer ia(101);

  // getInteger() = ia;

  Integer ib(102);

  cout << (ia + ib) << endl;
  cout << ++ib << endl;
  cout << ib++ << endl;
  cout << ib << endl;

  Integer ic = 123;

  cout << ic << endl;

  return 0;
}

// 203
// 103
// 103
// 104
// 123
