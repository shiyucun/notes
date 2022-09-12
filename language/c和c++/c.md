
# C

- [C](#c)
  - [宏运算符](#宏运算符)
  - [条件编译](#条件编译)
  - [typedef 与 define](#typedef-与-define)
  - [指针和数组的差异](#指针和数组的差异)
  - [结构体的对齐与补齐](#结构体的对齐与补齐)
  - [结构体位域/位段](#结构体位域位段)
  - [大小端测试](#大小端测试)
  - [可变长参数](#可变长参数)
  - [输入输出缓冲区](#输入输出缓冲区)
  - [文件操作](#文件操作)
  - [主函数的原型](#主函数的原型)
  - [字符串](#字符串)
  - [C程序错误处理](#c程序错误处理)

## 宏运算符

`#`用于将宏中的参数转换为字面值常量。

注意：只能出现在带参数的宏的替换列表中。

```c
#include <stdio.h>

#define PRINT(n) printf(#n"=%d\n",n);

int main() {
    int abc = 10;
    int def = 20;
    
    PRINT(abc);
    PRINT(def);

    return 0;
}

// 输出：
// abc=10
// def=20
```

字符串特性：

- "adc""de"="adcde"
- #n="n"

`##`用于将两个标识符粘合在一起形成一个标识符。

```c
#define MAX(type) type max_##type()
MAX(int) = int max_int()
```

## 条件编译

根据预处理器的执行结果来包含或者排除某一段程序。

1. `#if`和`#endif`：预处理器遇到#if会判断后面的宏目前的数值
   - 值为0就把`#if`和`#endif`之间的代码从程序中排除
   - 值非0就保留
2. `defined`：判断宏是否存在(`#ifdef` = `#if defined`)
3. `#ifdef`：判断标识符是否被定义为宏
4. `#elif`和`#else`：`#if`的分支
5. `#undef`：取消宏定义(一般定义不取消)
6. `#error`：产生一个错误，停止执行
7. `#warning`：产生一个警告，不停止执行
8. `#pragma`：额外提供一些功能
9. `#line line_num`：从下一行起修改行号为`line_num`

```c
#define Debug
#if defined Debug
...
#endif

#if ...
    代码1
#elif ...
    代码2
#else
    代码3
#endif

// 关联文件名和当前文件的时间，当前文件新则没有问题，否则产生警告
#pragma GCC dependency 文件名

// 禁止使用这个单词，否则产生错误
// 当把禁止的单词定义为其他宏时，则可使用单词(需要放在 poison 之前)
#pragma GCC poison 单词

// 以 n 的倍数作为结构体对齐和补齐的字节数，n>4，按4计算，n=1时，对齐补齐不工作
// 对齐和补齐会提升效率，但浪费空间，如果不想浪费空间，可以用 pack(1) 解决
#pragma pack(n)
```

编写多种硬件环境或多操作系统上运行的可移植程序：

```c
#if linux
// 代码：专用于linux
#elif windows
// 代码：专用与windows
#endif

#if x86
// 代码：专用于x86
#elif arm
// 代码：专用于arm
#endif
```

编写用于不同编译器的程序：

```c
#if __STDC__
// 函数..
#else
// 函数..
#endif
```

产品的调试与发布：

```c
//define DEBUG
#ifdef DEBUG
//printf(".... ....");
#endif
```

为宏提供定义：

```c
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 20000
#endif
```

定义头文件(防止头文件重复引用)：

```c
#ifndef __XXX_H__
#define __XXX_H__
//头文件内容
#endif
```

## typedef 与 define

`typedef`是语言编译过程的一部分，不实际分配内存空间。

`#define`为宏定义语句，在预处理过程中就已经完成了处理。

```c
typedef int INT;
typedef int ARRAY[10];
typedef (int*) pINT;

#define INT int
#define TRUE 1
#define Add(a,b) ((a)+(b));
#define Loop_10 for (int i=0; i<10; i++)
```

**区别**：

- `typedef`在语言编译过程中处理；`#define`在预处理过程中完成处理
- `#define`宏定义只是简单的字符串替换
- `typedef`不是原地扩展，新名字具有一定的封装性，新命名的标识符具有更易定义变量的功能

```c
typedef (int*) pINT;
#define pINT2 int*
pINT a,b;   // 定义了两个整型指针变量a、b
pINT2 c,d;  // 定义了一个整型指针变量c和整型变量d
```

## 指针和数组的差异

- 指针可以被赋值，数组名称不可以
- 对指针进行sizeof运算结果是4，对数组名称进行sizeof运算结果是数组中包含字节的个数
- 对数组名称取地址结果是二维数组，对指针取地址结果是指针本身存储区的地址

const 声明指针：

```c
const int* p_num = NULL;  // 指针指向地址中的值不可修改，但可以修改指针的指向
int* const p_num = NULL； // 指针指向不可修改，只能在初始化时实现赋值
```

## 结构体的对齐与补齐

对齐：

- 内存分配将结构体中的成员分配到内存的边界上，方便访问
- 每个成员都是从自身长度的整数倍开始存放，本身长度大于4，则以4计算

补齐：整个的结构体长度必须保持为内部最长成员的整数倍(大于4以4计算)，如果不够，补齐。

## 结构体位域/位段

结构体指定每一个成员的大小，节约内存，大小是指成员占用多少个二进制位。

```c
struct Bits{
    int i:3;  // 指定i在内存中占用三个二进制位
    int b:1;  // 指定b在内存中占用一个二进制位
};
```

## 大小端测试

大端存储：数据的低位存储在高地址处。

小端存储：数据的低位存储在低地址处。

union需要区分大端存储和小端存储，可以写一段代码进行测试。

```c
#include <stdio.h>

int main(){
    union {
        int i;
        char c;
    } u;

    u.i = 1;
    printf("当前计算机: %s\n"，u.c == 1 ? "小端" : "大端");

    return 0;
}
```

## 可变长参数

变长参数是指函数可以输入任意多个参数。

在 C 语言中需要包含头文件 ```#include<stdarg.h>```。

**编程步骤**：

1. `va_list v`：定义一个可变长参数的列表
2. `va_start(v, 第一个参数的名字)`：将可变长参数列表定位到第二个参数的位置
3. `变量 = va_arg(v, 数据类型)`
4. `va_end(v)`：释放可变长参数列表

```c
#include<stdio.h>
#include<stdarg.h>

int max(int cnt, ...);

int main() {
    printf("%d\n", max(3, 15, 24, 18));
    printf("%d\n", max(5, 15, 24, 18, 23, 16));
    printf("%d\n", max(11, 15, 24, 18, 34, 34, 56, 78, 123, 234, 1, 255 ));
    
    return 0;
}

int max(int cnt, ...) {
    va_list v;
    va_start(v, cnt);

    int maxvalue = va_arg(v, int);

    for (int i = 1; i < cnt; i++) {
        int data = va_arg(v, int);
        if (data > maxvalue) {
            maxvalue = data;
        }
    }

    va_end(v);

    return maxvalue;
}
```

## 输入输出缓冲区

输入输出缓冲区有这样的一个特点：只有当其中的数据读走时，才会清除这个数据。

**输入缓冲区**：键盘->键盘缓冲区->输入缓冲区->程序。

`scanf(数据类型)`和缓冲区中数据类型**不一致**时，便无法读走数据，可能会导致死循环。

解决办法：

```c
scanf("%*[^\n]");  // *忽略读到的内容
                   // [^\n]任何非\n的字符
                   // 将\n之前的所有字符读走
scanf("%*c");      // 能够读取换行符，并将其忽略，scanf不会读取换行符
```

`scanf`调用失败主要是因为类型不匹配，返回值为0，因此我们可以将代码改变为:

```c
int i = 0;
if (scanf( "%d", &i ) == 0) {
    scanf( "%*[^\n]" );  // 读走\n之前的所有字符
    scanf( "%*c" );      // 读走\n
}
```

**输出缓冲区**：程序->输出缓冲区->屏幕。

程序的输出可以到达屏幕的条件：

- 遇到`\n`
- 程序结束
- 输出缓冲区满4kb
- 人工刷新(fflush)；

满足以上条件之一时，输出缓冲区的内容才可以刷新到屏幕上，fflush很少用。

```c
#include<stdio.h>

int main() {
    printf("welcome!");
    //fflush(stdout);

    while(1);

    return 0;
}
```

## 文件操作

每一个打开的文件在内存里都会有一个结构体来保存文件的信息：大小、位置、权限等。

这个结构体是系统定义：`FILE`。

```c
typedef struct {
    ......
} FILE;
```

文件指针就是指向 FILE 结构体的指针，`FILE *fp;`。

**文件的打开与关闭**：

```c
FILE *fopen(const char *path, const char *mode);
    // path：代表文件名的字符串(可以包含路径)
    // mode：访问文件的方式：
    //     文本文件：
    //         "r"只读
    //         "w"只写(可以不存在，存在会覆盖)
    //         "a"追加(可以不存在，文件末尾增加新的数据)
    //         "r+"读和写(文件头部开始)
    //         "w+"读写(覆盖)
    //         "a+"读写(追加)
    //     二进制文件：
    //         "rb"只读
    //         "wb"只写
    //         "ab"追加
    //         "rb+" "r+b" 读和写(文件头开始)
    //         "wb+" "w+b" 读写(覆盖)
    //         "ab+" "a+b" 读写(追加)
    //
    // 返回值:
    //     <1>成功：返回一个指向打开文件的文件指针
    //     <2>失败：返回NULL

int fclose(FILE *fp);
    // fp：文件指针
    // 返回值：
    //     0：成功
    //     -1(EOF)：失败。

FILE *fp = NULL;
if ((fp = fopen(.....)) == NULL) {
    //打开失败
}
// 读写文件

fclose(fp);
```

**文件读写**：

`fputc()`将一个字符写到文件中：

- 原型：`int fputc(int c, FILE *fp)`
- 返回值：成功返回c对应的整数值，失败返回EOF(-1)

`fgetc()`从文件中读一个字符出来：

- 原型：`int fgetc( FILE *stream )`
- 返回值：返回读到的字符

```c
#include<stdio.h>

int main (int argc, const char *argv[]) {
    if (argc < 2 || argc > 2) {
        printf("命令格式不对\n");
        printf("Useage:command filename\n");
        return 0;
    }

    FILE *fp = NULL;
    if ((fp = fopen(argv[1], "r")) == NULL) {
        printf("文件打开失败:%m\n");
        return -1;
    }

    char c;
    while (1) {
        c = fgetc(fp);
    
        if (c == EOF) {
            break;
        } else {
            printf("%c",c);
        }
    }

    fclose(fp);
    fp = NULL;

    return 0;
}
```

操作多文件时，如果其中一个打开失败，在程序退出前，应将成功打开的其它文件关闭。

`fread`和`fwrite`函数原型：

```c
size_t fread(buffer, size, count, fp)    // 返回读取的数据的个数
size_t fwrite(buffer, size, count, fp)
    // buffer：类型void*，缓冲区，对fread来说buffer保存了读出来的数据，对fwrite来说是即将写入的数据
    // size：读写一次的字节数
    // count：进行多少次读写
    // fp：文件指针
```

```c
// 使用这两个函数向文件写入两个整数并读出
#include <stdio.h>

int main() {
    int i = 15, j = 63;

    FILE *fp = NULL;
    if ((fp = fopen("c.txt","w")) == NULL) {
        printf("fail to open the file: %m.\n");  // %m 转换会打印与errno中的错误代码相对应的字符串
        return -1;
    }

    printf("success to open the file.\n");

    fwrite( &i, sizeof(i), 1, fp );
    fwrite( &j, sizeof(j), 1, fp );

    fclose(fp);
    fp = NULL;

    return 0;
}

#include <stdio.h>

int main() {
    int i = 0, j = 0;

    FILE *fp = NULL;
    if ((fp = fopen("c.txt","r")) == NULL) {
        printf("fail to open the file: %m.\n");
        return 0;
    }

    printf("success to open the file.\n");

    if (fread(&i, sizeof(i), 1, fp) != 1) {
        printf("读取失败\n");
    }

    if (fread(&j, sizeof(j), 1, fp) != 1) {
        printf("读取失败\n");
    }

    printf("i = %d, j = %d\n", i, j);

    fclose(fp);
    fp = NULL;

    return 0;
}
```

文件中都有一个位置指针，指向当前读写的位置。

顺序读写一个文件时，操作完当前的元素后，位置指针自动指向下一个元素的位置。

`rewind`函数，使位置指针回到文件的开头，原型：`void rewind(FILE *fp);`。

`fseek`函数原型：

```c
int fseek(FILE *stream, long offset, int whence)
    // stream：文件指针
    // offset：位移量
    // whence：起始点
    //         文件开头 0 SEEK_SET
    //         当前位置 1 SEEK_CUR
    //         文件末尾 2 SEEK_END
```

`fgets()`、`fputs()`函数，用于从指定的文件中读取或者写入一个字符串：

```c
fgets(str, n, fp)
    // n 为指定读取字符的个数，但fp只能读出(n-1)个字符，最后加'\0'
    // 如果在读入n-1个字符前遇到EOF，则读入结束并返回str的首地址
fputs("china", fp)
    // 成功返回非负数，失败返回EOF
```

`fprintf()`、`fscanf()`函数，针对文件的格式化读写，效率低，少量数据可以使用：

```c
fprintf(文件指针, 格式字符串, 输入列表)
fscanf(文件指针, 格式字符串, 输出列表)
```

`ftell()`函数，用于测试当前位置距离文件的开始有多少个字节。

## 主函数的原型

```c
int main( int argc, char *argv[], char **env )
    // argc – 参数个数
    // argv – 参数的地址
    // env - 环境表的首地址，从中可以读出环境变量
```

## 字符串

字符串字面值(`char *p = "abcdef";`)，不可以修改，因为存储在代码段中。

字符数组字符串，只有包含`\0`的字符数组才可以当作字符串使用。

用字符串字面值对字符数组初始化时，字符数组字符串可以修改。

字符串操作函数：(头文件`string.h`)

- strlen()：计算有效字符个数
- strcat()：合并字符串，返回值表示合并后的字符串，会修改数组内容，有可能会超过数组范围
- strncat()：与strcat类似，多一个整数类型的参数，表示字符数组中有多少个空位置
- strcmp()：比较两个字符串的大小关系，1前一个大，-1后一个大，0相等
- strncmp()：与strcmp类似，多一个整数类型的参数，比较前n个字符
- strcpy()：把一个字符串里的所有字符copy到另一个字符串数组里
- strncpy()：与strcpy类似，多一个整数类型的参数，表示copy前n个字符
- fgets(数组名称，数组中存储区的个数，用stdin表示键盘)：从键盘读取字符串填入数组缓冲区

对于`fgets()`函数，数组存满后，多余内容会残留在输入缓冲区，所以输入完成后要清空缓冲区。

清空缓冲区是有条件的：

- 数组大小不能全部存下输入的字符，即有效字符个数满足了最大值减1
- 最后一个有效字符不是回车换行键

fgets可以用来从键盘读取字符串，如果输入字符个数不能装满数组，则`\n`会被读入，不可避免。

## C程序错误处理

错误处理是软件的一部分，C程序员都要写错误处理的代码。

后期的语言都是使用异常机制(Exception)处理错误，而C语言没有使用异常机制。

C程序员用函数的返回值代表是否出错，错误处理的代码需要编写。

错误处理的方式：

1. 返回值是int，返回数据不可能是负数，可用-1代表出错，其他正常
2. 返回值是int，返回数据可能是负数，可用-1代表出错，0代表正确，数据用指针带回
3. 返回值是指针，返回NULL代表出错
4. 不可能出错或不需考虑出错的情况，数据正常返回即可

以上四种只是C程序员的常规处理方案。

C语言提供了出错处理的三个函数和一个变量：

1. `errno`：外部全局变量，记录错误的编号
   - errno是整数类型
   - 使用需要包含头文件`<errno.h>`
2. 出错处理函数：

```c
#include <string.h>

char *strerror(int errnum);  // 把错误编号转换成错误信息

perror()
    // 参数为NULL时，打印errno对应的最后一个错误信息
    // 参数不为NULL时，打印errno对应的最后一个错误信息，追加":"，显示参数指定显示的错误信息，换行

printf("%m")  // 打印errno对应的错误信息
```

调用系统函数时，如果发生错误，系统会把错误编号记录在errno中。

出错会改变errno值，不出错不会还原原来的值。因此不能用errno判断是否出错。

不是所有函数都使用了errno，如线程相关的函数就没有使用errno。
