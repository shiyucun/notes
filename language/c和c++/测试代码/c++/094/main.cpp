
#include "mytime.h"
using namespace std;

int g_var;

int main() {
  mytime time;
  show();
  time.run();

  return 0;
}

// This is a global show()!
// 0
// This is a global show()!
// 0
// 0:0:0
// This is a global show()!
// 0
// 0:0:1
// This is a global show()!
// 0
// 0:0:2
// This is a global show()!
// 0
// 0:0:3
// ^C
