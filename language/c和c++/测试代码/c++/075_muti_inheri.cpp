
#include <iostream>
using namespace std;

class Phone {
 private:
  double price;

 public:
  Phone(double price = 0) : price(price) { cout << "Phone()" << endl; }
  ~Phone() { cout << "~Phone()" << endl; }

  double getPrice() { return price; }
  void callto(string no) { cout << "call " << no << " !" << endl; }
};

class Camera {
 private:
  double price;

 public:
  Camera(double price = 0) : price(price) { cout << "Camera()" << endl; }
  ~Camera() { cout << "~Camera()" << endl; }

  double getPrice() { return price; }
  void camera() { cout << "拍视频!" << endl; }
};

class Mp3 {
 private:
  double price;

 public:
  Mp3(double price = 0) : price(price) { cout << "Mp3()" << endl; }
  ~Mp3() { cout << "~Mp3()" << endl; }

  double getPrice() { return price; }
  void listen(string name) { cout << "listen to the music:" << name << endl; }
};

class Iphone : public Phone, public Camera, public Mp3 {
 public:
  Iphone(double m = 0.0, double c = 0.0, double p = 0.0) : Mp3(m), Camera(c), Phone(p) {}

  // name hide
  double getPrice() { return Mp3::getPrice() + Camera::getPrice() + Phone::getPrice(); }
};

int main() {
  Iphone iphone6(50.5, 12000, 1200);

  iphone6.callto("15912345672");
  iphone6.camera();
  iphone6.listen("traveling light");

  cout << iphone6.Mp3::getPrice() << endl;
  cout << iphone6.Camera::getPrice() << endl;
  cout << iphone6.Phone::getPrice() << endl;

  cout << iphone6.getPrice() << endl;

  cout << sizeof(Iphone) << endl;

  return 0;
}

// Phone()
// Camera()
// Mp3()
// call 15912345672 !
// 拍视频!
// listen to the music:traveling light
// 50.5
// 12000
// 1200
// 13250.5
// 24
// ~Mp3()
// ~Camera()
// ~Phone()
