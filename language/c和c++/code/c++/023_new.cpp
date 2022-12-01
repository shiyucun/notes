
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

struct Date {
  int year;
  int month;
  int day;

  void show() {
    cout << setfill('0') << year << '-' << setw(2) << month << '-' << setw(2) << day << endl;
  }
};

void create_memory();
void create_struct_memory();

int main() {
  create_memory();
  create_struct_memory();

  int *parr = new int[5];

  parr[0] = 9;
  *(parr + 1) = 8;
  *(parr + 2) = 7;
  *(parr + 3) = 6;
  *(parr + 4) = 5;

  for (int i = 0; i < 5; i++) {
    cout << *(parr + i) << endl;
  }

  delete[] parr;

  char data[100];
  int *pi = new (data) int[25];

  printf("%p\n%p\n", data, pi);

  cout << pi << endl;
  cout << &data << endl;

  return 0;
}

void create_memory() {
  int *pi = new int;

  *pi = 101;
  cout << *pi << endl;

  delete pi;

  double *pd = new double(12.88);

  cout << *pd << endl;
  *pd = 12.87;
  cout << *pd << endl;

  delete pd;
}

void create_struct_memory() {
  Date *pd = new Date[3];
  Date *pd_temp = pd;

  pd_temp->year = 1991;
  pd_temp->month = 3;
  pd_temp->day = 10;

  pd_temp++;
  pd_temp->year = 1965;
  pd_temp->month = 10;
  pd_temp->day = 3;

  pd_temp++;
  pd_temp->year = 1968;
  pd_temp->month = 12;
  pd_temp->day = 20;

  pd_temp = pd;

  for (int i = 0; i < 3; i++) {
    pd_temp[i].show();
  }

  delete pd;
}

// 101
// 12.88
// 12.87
// 1991-03-10
// 1965-10-03
// 1968-12-20
// 9
// 8
// 7
// 6
// 5
// 0x7ffca4fef5b0
// 0x7ffca4fef5b0
// 0x7ffca4fef5b0
// 0x7ffca4fef5b0
