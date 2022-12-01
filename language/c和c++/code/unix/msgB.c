
// 接收消息队列中存放的消息
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

  // 获取消息队列，得到 msgid
  int msgid = msgget(key, 0);
  if (msgid == -1) {
    perror("msgget"), exit(-1);
  }
  printf("msgid = %d\n", msgid);

  // 读取消息
  Msg m = {};
  // if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), 0, 0)) {
  //   perror("read"), exit(-1);
  // }
  // printf("0消息为：%s\n", m.buffer);

  // if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), 1, 0)) {
  //   perror("read"), exit(-1);
  // }
  // printf("1消息为：%s\n", m.buffer);

  if (-1 == msgrcv(msgid, &m, sizeof(m.buffer), -2, 0)) {
    perror("read"), exit(-1);
  }
  printf("-2消息为：%s\n", m.buffer);

  // 删除消息队列
  if (-1 == msgctl(msgid, IPC_RMID, NULL)) {
    perror("msgctl"), exit(-1);
  }

  return 0;
}
