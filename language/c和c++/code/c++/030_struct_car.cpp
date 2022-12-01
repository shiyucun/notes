
#include <iostream>
using namespace std;

struct Car {
  string name_;
  string No_;
  double price_;
  double speed_;
  string color_;

  void show() {
    cout << name_ << ' ' << No_ << ' ' << price_ << "万 " << speed_ << "km/h" << ' ' << color_
         << endl;
  }

  void start() { cout << "start..." << endl; }

  void run(double s) { cout << "speed：" << s << "km/h" << endl; }

  void stop() { cout << "arrived! stop!" << endl; }
};

int main() {
  Car car = {"RANGE ROVER", "京J999F", 349, 340, "BLACK"};

  car.show();

  car.start();
  car.run(110);
  car.stop();

  return 0;
}

// RANGE ROVER 京J999F 349万 340km/h BLACK
// start...
// speed：110km/h
// arrived! stop!
