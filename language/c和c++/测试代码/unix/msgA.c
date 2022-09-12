
// 向消息队列中存放消息
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <unistd.h>

// 定义数据类型
typedef struct Msg {
  long mtype;
  char buffer[256];
} Msg;

int main() {
  // 获取 key，使用 ftok 函数
  key_t key = ftok(".", 100);
  if (key == -1) {
    perror("ftok"), exit(-1);
  }
  printf("key = %d\n", key);

  // 创建消息队列，得到 msgid
  int msgid = msgget(key, IPC_CREAT | IPC_EXCL | 0666);
  if (msgid == -1) {
    perror("msgget"), exit(-1);
  }
  printf("msgid = %d\n", msgid);

  // 准备并发送消息
  Msg m1, m2;
  m1.mtype = 1;
  strcpy(m1.buffer, "hello1");
  m2.mtype = 2;
  strcpy(m2.buffer, "hello2");
  if (-1 == msgsnd(msgid, &m2, sizeof(m1.buffer), 0)) {
    perror("m2"), exit(-1);
  }

  if (-1 == msgsnd(msgid, &m1, sizeof(m1.buffer), 0)) {
    perror("m1"), exit(-1);
  }

  return 0;
}
