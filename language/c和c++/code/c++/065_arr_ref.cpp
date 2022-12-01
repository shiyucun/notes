
#include <iostream>
using namespace std;

void display(int (&rdata)[5]) {
  for (int i = 0; i < 5; i++) {
    cout << rdata[i] << " ";
  }
  cout << endl;
}

template <typename T>
void printArr(T& data) {
  for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
    cout << data[i] << " ";
  }
  cout << endl;
}

int main() {
  int dataa[5] = {9, 5, 2, 7, 8};
  display(dataa);

  int datab[3] = {3, 0, 8};
  printArr(datab);

  return 0;
}

// 9 5 2 7 8
// 3 0 8
