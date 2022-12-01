#include <iostream>
#include <list>

using namespace std;

struct Date {
  // 迭代器本质上是结构内存提供了一个内部类
  class iterator {};

  int year;
  int month;
  int day;
};

int main() {
  list<int> datas;

  datas.push_back(9);
  datas.push_back(5);
  datas.push_back(2);
  datas.push_back(7);

  // 指向第一个元素的迭代器
  list<int>::iterator it = datas.begin();
  // cout << *it << endl;
  // it++;
  // cout << *it << endl;
  // it++;
  // cout << *it << endl;
  // it++;
  // cout << *it << endl;
  while (it != datas.end()) {
    cout << *it << endl;
    it++;
  }

  list<Date> dates;

  Date datea = {2013, 10, 1};
  Date dateb = {2014, 10, 2};
  Date datec = {2015, 2, 8};

  dates.push_back(datea);
  dates.push_back(dateb);
  dates.push_back(datec);

  list<Date>::iterator it2 = dates.begin();
  while (it2 != dates.end()) {
    cout << it2->year << "/" << it2->month << "/" << it2->day << endl;
    it2++;
  }

  // 实例化内部类
  Date::iterator it3;
  return 0;
}

// 9
// 5
// 2
// 7
// 2013/10/1
// 2014/10/2
// 2015/2/8
