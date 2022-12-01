
#include <iostream>
using namespace std;

// 命名空间的嵌套
namespace ns1 {
int x = 1;
namespace ns2 {
int x = 100;
void show() { cout << x << endl; }
namespace ns3 {
void show() { cout << "this is ns3" << endl; }
}  // namespace ns3
}  // namespace ns2
};  // namespace ns1

// 命名空间重命名
namespace ns4 = ns1::ns2::ns3;

int main() {
  cout << ns1::x << endl;
  cout << ns1::ns2::x << endl;

  ns1::ns2::show();
  ns4::show();

  return 0;
}

// 1
// 100
// 100
// this is ns3
