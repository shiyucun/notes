
#include <iostream>
using namespace std;

// _Z6getmaxii这个函数是 int getmax(int, int) 在底层的实现
int getmax(int x, int y);

// _Z6getmaxid这个函数是 double getmax(int, double) 在底层的实现
double getmax(int x, double y);

int main() {
  getmax(1, 2);
  getmax(1, 2.0);

  return 0;
}

double getmax(int x, double y) { return x > y ? x : y; }

int getmax(int x, int y) { return x > y ? x : y; }

// g++ -c 016_cppfunction.cpp -o out.o
// objdump -t out.o
// 以上命令可以查看文件中函数底层实现的函数名，输出如下：
// out.o:     file format elf64-x86-64
// SYMBOL TABLE:
// 0000000000000000 l    df *ABS*	0000000000000000 016_cppfunction.cpp
// 0000000000000000 l    d  .text	0000000000000000 .text
// 0000000000000000 l    d  .data	0000000000000000 .data
// 0000000000000000 l    d  .bss	0000000000000000 .bss
// 0000000000000000 l    d  .rodata	0000000000000000 .rodata
// 0000000000000000 l     O .rodata	0000000000000001 _ZStL19piecewise_construct
// 0000000000000000 l     O .bss	0000000000000001 _ZStL8__ioinit
// 000000000000007e l     F .text	000000000000004d _Z41__static_initialization_and_destruction_0ii
// 00000000000000cb l     F .text	0000000000000019 _GLOBAL__sub_I_main
// 0000000000000000 l    d  .init_array	0000000000000000 .init_array
// 0000000000000000 l    d  .note.GNU-stack	0000000000000000 .note.GNU-stack
// 0000000000000000 l    d  .note.gnu.property	0000000000000000 .note.gnu.property
// 0000000000000000 l    d  .eh_frame	0000000000000000 .eh_frame
// 0000000000000000 l    d  .comment	0000000000000000 .comment
// 0000000000000000 g     F .text	0000000000000034 main
// 000000000000005e g     F .text	0000000000000020 _Z6getmaxii
// 0000000000000034 g     F .text	000000000000002a _Z6getmaxid
// 0000000000000000         *UND*	0000000000000000 _GLOBAL_OFFSET_TABLE_
// 0000000000000000         *UND*	0000000000000000 _ZNSt8ios_base4InitC1Ev
// 0000000000000000         *UND*	0000000000000000 .hidden __dso_handle
// 0000000000000000         *UND*	0000000000000000 _ZNSt8ios_base4InitD1Ev
// 0000000000000000         *UND*	0000000000000000 __cxa_atexit

// 工具：c++filt
// linux 下提供以上工具，可以将底层实现函数转换为编码时的格式
// 终端中执行 c++filt
// 依次输入：_Z6getmaxii 和 _Z6getmaxid
// 可依次看到输出：getmax(int, int) 和 getmax(int, double)
