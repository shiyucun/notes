
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void foo() throw(int, double, const char*) {
  int r = rand() % 4;

  cout << "调用函数开始" << endl;

  if (0 == r) {
    cout << "程序正常" << endl;
  } else if (1 == r) {
    throw 1;
  } else if (2 == r) {
    throw 2.5;
  } else {
    throw "connect server failed";
  }

  cout << "函数调用结束" << endl;
}

int main() {
  srand(time(NULL));

  try {
    foo();
  } catch (int e) {
    cout << "int data=" << e << endl;
  } catch (double e) {
    cout << "double data=" << e << endl;
  } catch (const char* e) {
    cout << "const char* data=" << e << endl;
  }

  return 0;
}

// 090_exception.cpp:7:12: warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
//     7 | void foo() throw(int, double, const char*) {
//       |

// 调用函数开始
// double data=2.5
