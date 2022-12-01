
#include <iostream>
using namespace std;

class Singleton {
 private:
  static Singleton sig;  // 静态成员变量只有一份

  Singleton() { cout << "对象构造成功！" << endl; }
  Singleton(const Singleton& s) { cout << "对象拷贝成功！" << endl; }

 public:
  static Singleton& Instance() { return sig; }
};

Singleton Singleton::sig;

int main() {
  cout << "-----------------------------" << endl;
  cout << sizeof(Singleton) << endl;

  Singleton& siga = Singleton::Instance();
  Singleton& sigb = Singleton::Instance();

  cout << &siga << endl << &sigb << endl;

  return 0;
}

// 对象构造成功！
// -----------------------------
// 1
// 0x55849d960151
// 0x55849d960151
