#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
  while (true) {
    cout << "pid:" << getpid() << endl;
    usleep(100000);
  }

  return 0;
}