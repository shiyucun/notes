
#include <iostream>
using namespace std;

class Array {
 private:
  int *data;    // 指向存储数据的区域
  int size;     // 记录已经加入数据的个数
  int maxsize;  // 存储数据的最大容量

 public:
  Array(int maxsize = 5);
  ~Array();

  void push_back(int d = 0);
  void expend();
  void show();
};

Array::Array(int maxsize) : size(0), maxsize(maxsize) {
  data = new int[maxsize];  // 申请动态内存
}

Array::~Array() {
  delete[] data;  // 析构函数释放内存
}

void Array::push_back(int d) {  // 插入数据
  if (size == maxsize) {
    expend();  // 扩容
  }
  data[size++] = d;
}

void Array::expend() {  // 扩充
  maxsize = 2 * maxsize + 1;  // 重新定义最大容量

  int *p = new int[maxsize];  // 申请内存

  for (int i = 0; i < size; i++) {  // 复制原内存存储的值
    p[i] = data[i];
  }

  delete[] data;  // 释放原内存

  data = p;  // 让 data 指向新开辟的内存
}

void Array::show() {  // 显示输出
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
}

int main() {
  foo();
  return 0;
}

// 9 9
// 9 9 9 9 9
