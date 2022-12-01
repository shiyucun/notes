
// 共享库文件动态加载
#include <dlfcn.h>
#include <stdio.h>

int main() {
  // 1.打开共享库文件
  void *handle = dlopen("./libdl_so.so", RTLD_NOW);

  // 2.错误处理
  char *error = dlerror();
  if (error) {
    printf("打开共享库文件失败！\n");
    return -1;
  }

  // 3.获取共享库文件的函数地址
  int (*pf)(int, int) = dlsym(handle, "addint");

  // 4.错误处理
  error = dlerror();
  if (error) {
    printf("函数地址获取失败！\n");
    return -1;
  }

  // 5.使用函数地址进行调试
  printf("%d\n", pf(10, 50));

  // 6.关闭共享库文件
  dlclose(handle);

  return 0;
}
