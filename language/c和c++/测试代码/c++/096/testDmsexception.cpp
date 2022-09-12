
#include "Dmsexception.h"

#include <cstdlib>
#include <iostream>

using namespace std;

void InitNetWork() throw(DmsInitNetWorkExecption) {
  int ra = rand() % 2;
  if (0 == ra) {
    cout << "Init success!" << endl;
  } else {
    throw DmsInitNetWorkExecption("connect to the server failed!");
  }
}

void SendData() throw(DmsInitNetWorkExecption, DmsSendDataExecption) {
  try {
    InitNetWork();
  } catch (DmsInitNetWorkExecption& e) {
    throw e;  //原样转发(也可以用[throw e;])
  }

  int rb = rand() % 2;
  if (0 == rb) {
    cout << "Send data success" << endl;
  } else {
    throw DmsSendDataExecption("Send to the server failed!");
  }
}

int main() {
  srand(time(NULL));
  try {
    SendData();
  } catch (DmsInitNetWorkExecption& e) {
    cout << e.what() << endl;
    cout << "connect to other server!" << endl;
  } catch (DmsSendDataExecption& e) {
    cout << e.what() << endl;
    cout << "Send again" << endl;
  }
  return 0;
}

// testDmsexception.cpp:9:20: warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
//     9 | void InitNetWork() throw(DmsInitNetWorkExecption) {
//       |                    ^~~~~
// testDmsexception.cpp:18:17: warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
//    18 | void SendData() throw(DmsInitNetWorkExecption, DmsSendDataExecption) {
//       |                 ^~~~~

// Init success!
// Send data success
