
#include <iostream>
using namespace std;

class Integer {
 private:
  int data;

 public:
  Integer(int data = 0) : data(data) {}

  friend ostream& operator<<(ostream& os, const Integer& out);
  friend istream& operator>>(istream& is, Integer& in);

  double operator/(const Integer& dat) { return (data * 1.0) / dat.data; }

  bool operator==(const Integer& dat) { return data == dat.data; }

  bool operator!() {  // 单参构造
    return !data;
  }

  Integer operator-() {  // 单参构造
    return (-1) * data;
  }

  Integer& operator--() {  // 前--运算符
    --data;
    return *this;
  }

  const Integer operator--(int) {  // 后--运算符，用哑元区分
    return data--;
  }
};

ostream& operator<<(ostream& os, const Integer& out) {
  cout << out.data;
  return os;
}

istream& operator>>(istream& is, Integer& in) {
  cin >> in.data;
  return is;
}

int main() {
  Integer mydata1(3);

  cout << mydata1 << endl;
  cin >> mydata1;
  cout << mydata1 << endl;

  Integer mydata2(4);

  cout << mydata2 << endl;
  cin >> mydata1 >> mydata2;
  cout << mydata1 << " " << mydata2 << endl;
  cout << mydata1 / mydata2 << endl;

  if (mydata1 == mydata2) {
    cout << "true!" << endl;
  } else {
    cout << "false!" << endl;
  }

  cout << !mydata1 << " " << !mydata2 << endl;
  cout << -(-mydata1) << endl;
  cout << --mydata1 << endl;
  cout << mydata1-- << endl;
  cout << mydata1 << endl;

  return 0;
}

// 3
// 1
// 1
// 4
// 2 2
// 2 2
// 1
// true!
// 0 0
// 2
// 1
// 1
// 0
