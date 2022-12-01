
#include <iostream>
using namespace std;

class Array {
 private:
  int* data;    // 指向数据存储区域
  int size;     // 已存储数据的个数
  int maxsize;  // 最大容量

 public:
  Array(int maxsize = 5);
  Array(const Array& buf);
  ~Array();

  void push_back(int d = 0);
  void expend();
  void show();
};

Array::Array(int maxsize) : size(0), maxsize(maxsize) {
  data = new int[maxsize];  // 申请内存
}

Array::Array(const Array& buf) {  // 拷贝构造函数
  cout << "Array( const Array& buf )" << endl;

  // 复制变量
  size = buf.size;
  maxsize = buf.maxsize;

  // 开辟空间
  data = new int[maxsize];
  for (int i = 0; i < size; i++) {
    data[i] = buf.data[i];
  }
}

Array::~Array() {
  delete[] data;  // 释放内存
}

void Array::push_back(int d) {  // 插入数据
  if (size == maxsize) {
    expend();  // 扩容
  }
  data[size++] = d;
}

void Array::expend() {  // 扩容
  maxsize = 2 * maxsize + 1;  // 重新定义最大容量

  int* p = new int[maxsize];  // 申请内存

  // 复制原内存
  for (int i = 0; i < size; i++) {
    p[i] = data[i];
  }

  // 释放原内存
  delete[] data;

  data = p;  // 指向新内存
}

void Array::show() {
  for (int i = 0; i < size; i++) {
    cout << data[i] << ' ';
  }
  cout << endl;
}

void foo() {
  Array arr(3);

  arr.push_back(9);
  arr.push_back(9);
  arr.show();

  arr.push_back(9);
  arr.push_back(9);
  arr.push_back(9);
  arr.show();

  Array arrb = arr;

  arrb.show();
}

int main() {
  foo();

  return 0;
}

// 9 9
// 9 9 9 9 9
// Array( const Array& buf )
// 9 9 9 9 9
