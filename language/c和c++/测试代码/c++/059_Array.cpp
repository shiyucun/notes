
#include <iostream>
using namespace std;

class Array {
 private:
  int* data;
  int size;
  int len;

 public:
  Array(int len = 5) : len(len), size(0) { data = new int[len]; }

  ~Array() { delete[] data; }

  Array(const Array& arr) {  // 拷贝构造
    cout << "Array(const Array& arr)" << endl;
    size = arr.size;
    len = arr.len;
    data = new int[len];

    for (int i = 0; i < size; i++) {
      data[i] = arr.data[i];
    }
  }

  Array& operator=(const Array& arr) {  // 赋值运算符
    cout << "Array& operator=(const Array& arr)" << endl;
    if (this != &arr) {
      size = arr.size;
      len = arr.len;
      delete[] data;  // 释放原内存
      data = new int[len];  // 申请新内存
      for (int i = 0; i < size; i++) {  // 复制数据
        data[i] = arr.data[i];
      }
    }
    return *this;
  }

  void push_back(int d) {
    if (size >= len) {
      expend();  // 扩容
    }
    data[size++] = d;
  }

  void expend() {  // 扩容
    int* temp = data;

    len = 2 * len + 1;
    data = new int[len];

    for (int i = 0; i < size; i++) {
      data[i] = temp[i];
    }

    delete[] temp;
  }

  int operator[](int idx) {
    if (idx >= size) {
      throw "out of index";
    }
    return data[idx];
  }
};

void foo() {
  Array arra(5);
  Array arrb(10);
  Array arrc = arra;  // 调用拷贝构造
  arrb = arra;  // 调用赋值运算符
}

int main() {
  foo();

  Array arra(3);

  arra.push_back(9);
  arra.push_back(5);
  arra.push_back(2);
  arra.push_back(7);

  cout << arra[1] << endl;

  try {
    cout << arra[4] << endl;
  } catch (const char* e) {
    cout << e << endl;
  }

  string abc = "hello";

  cout << abc.at(2) << endl;
  cout << abc[4] << endl;
  cout << abc[10] << endl;

  try {
    cout << abc.at(10) << endl;
  } catch (...) {
    cout << "exception" << endl;
  }

  return 0;
}

// Array(const Array& arr)
// Array& operator=(const Array& arr)
// 5
// out of index
// l
// o
// �
// exception
