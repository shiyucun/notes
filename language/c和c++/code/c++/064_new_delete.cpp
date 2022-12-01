
#include <cstdlib>
#include <iostream>
using namespace std;

class A {
 private:
  int x;
  int y;

 public:
  A() { cout << "A()" << endl; }
  ~A() { cout << "~A()" << endl; }

  static void *operator new(size_t size) {
    cout << "operator new:" << size << endl;
    return malloc(size);
  }

  static void operator delete(void *ptr) {
    cout << "operator delete." << endl;
    free(ptr);
  }
};

void *operator new(size_t size) {
  cout << "operator new" << size << endl;
  return malloc(size);
}

void operator delete(void *ptr) {
  cout << "operator delete" << endl;
  free(ptr);
}

int main() {
  A *pa = new A();
  delete pa;

  return 0;
}

// operator new:8
// A()
// ~A()
// operator delete.
