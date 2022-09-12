
#include <iostream>
using namespace std;

void display(const int *arr, int size = 1, char c = ',');

int main() {
  int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

  display(arr);
  display(arr, 4);
  display(arr, 6, ' ');

  return 0;
}

void display(const int *arr, int size, char c) {
  int i = 0;

  for (i = 0; i < size - 1; i++) {
    cout << arr[i] << c;
  }

  cout << arr[i] << endl;
}

// 9
// 9,8,7,6
// 9 8 7 6 5 4
