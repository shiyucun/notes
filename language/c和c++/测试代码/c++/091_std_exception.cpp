
#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
  // int* pi = (int*)malloc(0xffffffff);
  // if (pi != NULL) {
  //   cout << "内存分配成功" << endl;
  // } else {
  //   cout << "内存分配失败" << endl;
  // }

  try {
    int* parr = new int[0xffffffff];
  } catch (bad_alloc& e) {
    cout << "内存分配问题:" << endl;
    cout << e.what() << endl;
  } catch (...) {
    cout << "有问题" << endl;
  }

  string abc("hello");

  cout << abc.at(4) << endl;
  cout << abc[4] << endl;

  try {
    cout << abc.at(10) << endl;
  } catch (out_of_range& e) {
    cout << e.what() << endl;
  }

  return 0;
}

// o
// o
// basic_string::at: __n (which is 10) >= this->size() (which is 5)
