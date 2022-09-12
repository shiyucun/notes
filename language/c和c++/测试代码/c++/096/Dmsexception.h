
#ifndef DMSEXCEPTION_H
#define DMSEXCEPTION_H

#include <string>
using namespace std;

class DmsException {
 private:
  string msg;  //存储错误消息
 public:
  DmsException(string msg = "") : msg(msg) {}
  const char* what() const throw() { return msg.c_str(); }
};

class DmsInitNetWorkExecption : public DmsException {
 public:
  DmsInitNetWorkExecption(string msg = "") : DmsException(msg) {}
};

class DmsSendDataExecption : public DmsException {
 public:
  DmsSendDataExecption(string msg = "") : DmsException(msg) {}
};

#endif
