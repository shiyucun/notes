
#include <iostream>
using namespace std;

// 抽取共有部分到更高层的类中
class Product {
 private:
  double price;

 public:
  Product(double price = 0.0) : price(price) {}
  double getPrice() { return price; }
};

class Phone : virtual public Product {
  // 求大小时为12，其中继承的父类数据占8个，并且有一个指向这个数据的虚指针大小为4
 public:
  Phone(double price = 0) : Product(price) { cout << "Phone()" << endl; }
  ~Phone() { cout << "~Phone()" << endl; }

  void callto(string no) { cout << "call " << no << " !" << endl; }
};

class Camera : virtual public Product {
 public:
  Camera(double price = 0) : Product(price) { cout << "Camera()" << endl; }
  ~Camera() { cout << "~Camera()" << endl; }

  void camera() { cout << "拍视频!" << endl; }
};

class Mp3 : virtual public Product {
 public:
  Mp3(double price = 0) : Product(price) { cout << "Mp3()" << endl; }
  ~Mp3() { cout << "~Mp3()" << endl; }

  void listen(string name) { cout << "listen to the music:" << name << endl; }
};

class Iphone : virtual public Phone, virtual public Camera, virtual public Mp3 {
  // Iphone 虚继承了 Phone、Mp3、Camera 三个类
  // 因此在 Iphone 中存在三个虚指针维护父子类之间的关系
  // 因此 Iphone 大小是20
 public:
  Iphone(double p = 0.0, double c = 0.0, double m = 0.0) : Product(p + c + m) {}
};

int main() {
  Iphone iphone6(50.5, 12000, 1200);

  iphone6.callto("15912345672");
  iphone6.camera();
  iphone6.listen("traveling light");

  cout << iphone6.getPrice() << endl;
  cout << sizeof(Product) << " " << sizeof(Phone) << " " << sizeof(Iphone) << endl;

  return 0;
}

// Phone()
// Camera()
// Mp3()
// call 15912345672 !
// 拍视频!
// listen to the music:traveling light
// 13250.5
// 8 16 32
// ~Mp3()
// ~Camera()
// ~Phone()
