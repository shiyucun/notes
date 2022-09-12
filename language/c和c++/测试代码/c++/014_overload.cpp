
#include <iostream>
using namespace std;

int getmax(int x, int y);
double getmax(double x, int y);
double getmax(int x, double y);
double getmax(double x, double y);

int main() {
  cout << getmax(1, 2) << endl;
  cout << getmax(1, 2.5) << endl;
  cout << getmax(1.5, 7) << endl;
  cout << getmax(1.5, 7.0) << endl;

  double (*p)(double x, int y) = getmax;  // 函数指针
  cout << p(1.2, 7) << endl;

  return 0;
}

int getmax(int x, int y) {
  cout << "getmax(int,int) = ";
  return x > y ? x : y;
}

double getmax(double x, int y) {
  cout << "getmax(double,int) = ";
  return x > y ? x : y;
}

double getmax(int x, double y) {
  cout << "getmax(int,double) = ";
  return x > y ? x : y;
}

double getmax(double x, double y) {
  cout << "getmax(double,double) = ";
  return x > y ? x : y;
}

// getmax(int,int) = 2
// getmax(int,double) = 2.5
// getmax(double,int) = 7
// getmax(double,double) = 7
// getmax(double,int) = 7
