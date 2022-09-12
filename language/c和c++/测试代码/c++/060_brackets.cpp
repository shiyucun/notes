
#include <iostream>
using namespace std;

class Product {
 private:
  int pcount;
  double price;

 public:
  Product(int pcount = 0, double price = 0.0) : pcount(pcount), price(price) {}

  operator int() {  // Product 变成 int 类型
    return pcount;
  }

  operator double() {  // Product 变成 double 类型
    return price;
  }

  double operator()(int c, double p) {  // 对象可以像函数一样使用
    return c * p;
  }
};

int main() {
  Product iphone6(50, 5188.85);

  int pcount = (int)iphone6;
  cout << pcount << endl;

  double price = (double)iphone6;
  cout << price << endl;

  Product apple;
  cout << apple(11, 7.8) << endl;

  return 0;
}

// 50
// 5188.85
// 85.8
