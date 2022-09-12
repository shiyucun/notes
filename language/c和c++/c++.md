
# C++

- [C++](#c)
  - [命名空间(namespace)](#命名空间namespace)
  - [结构体、联合体 和 枚举](#结构体联合体-和-枚举)
  - [布尔类型](#布尔类型)
  - [c++ 函数和 c 函数的不同点](#c-函数和-c-函数的不同点)
  - [函数重载 (overload)](#函数重载-overload)
  - [哑元](#哑元)
  - [参数默认值](#参数默认值)
  - [内联函数](#内联函数)
  - [引用(reference)](#引用reference)
  - [对象](#对象)
  - [构造函数](#构造函数)
  - [this指针](#this指针)
  - [const 对象和 const 函数](#const-对象和-const-函数)
  - [析构函数](#析构函数)
  - [new 与 malloc](#new-与-malloc)
  - [拷贝构造函数](#拷贝构造函数)
  - [类中与内存相关的函数](#类中与内存相关的函数)
  - [静态数据](#静态数据)
  - [成员指针](#成员指针)
  - [突破访问权限](#突破访问权限)
  - [运算符重载](#运算符重载)
  - [指针和引用的联系和区别](#指针和引用的联系和区别)
  - [面向对象的三大特征](#面向对象的三大特征)
  - [封装](#封装)
  - [继承](#继承)
  - [多继承](#多继承)
  - [虚函数](#虚函数)
  - [重载、隐藏、覆盖](#重载隐藏覆盖)
  - [多态](#多态)
  - [多态中的类型识别](#多态中的类型识别)
  - [抽象类](#抽象类)
  - [虚析构函数](#虚析构函数)
  - [异常](#异常)
  - [IO](#io)
  - [c++ 内存分配](#c-内存分配)

## 命名空间(namespace)

命名空间是一种描述逻辑分组的机制。

如果一些声明按照某种准则在逻辑上属于同一部分，就可以将它们放入同一个命名空间。

防止命名冲突也是一个很重要的原因。

一个人写的程序放到一个名字空间中也是一种可取的做法。

作用：

- 逻辑上划分模块
- 防止命名冲突

语法：

```c++
namespace 空间名{
    // 类型定义 变量定义 函数定义 函数声明
}

namespace A
{
    // 类型定义
    namespace B {
        // 类型定义
    }
}
```

- 如果使用命名空间，则在数据前加`命名空间::`
- 使用using声明空间中的数据后(`using 空间名::数据名`)，声明的数据可以直接使用
- 使用命名空间后(`using namespace 空间名`)，空间中所有的数据都可以直接使用

如果一个数据没有定义在任何命名空间中，则这个数据属于匿名空间。

```c++
namespace {
    /* 匿名空间 */
}
```

注意：

1. 局部变量不属于任何命名空间
2. 全局变量可以显式或隐式放在匿名空间，显式不能被其他文件调用
3. 使用匿名空间中的函数或者变量需要在前面加上`::`

当发生命名空间的嵌套时：

1. 调用一个其它命名空间的函数，会**从当前命名空间一层层向上依次去查找对应命名空间**
2. 如果命名空间中没有该可调用对象则在编译时会报错，所以需要注意指定正确的命名空间

如下：

```c++
namespace A {
    namespace B {
        void func1() {}
    }
    
    namespace C {
        void func2 { B::func1(); }  // 调用的是 A::B::func1()
    }
}

namespace B {
    void func1() {}  // 在 namespace C 中调用，则需要在 func2 中调用 ::B::func1()
}
```

## 结构体、联合体 和 枚举

结构体定义语法和C语言完全相同。

- c++ 定义结构体变量时可以省略 struct
- c++ 中结构体中可以定义函数
- 结构体中没有定义任何成员变量，c++ 中结构体大小是1，c 语言中是0

联合体定义语法和C语言完全相同。

- c++ 定义联合体变量时可以省略union
- c++ 中可以定义匿名联合

枚举定义语法和C语言完全相同。

- c++ 定义枚举变量时可以省略 enum
- c++ 中枚举看成一种特定的类型，不能把一个整数赋值给枚举变量(c++ 类型检查更加严格)

## 布尔类型

c++ 不用像 c 语言一样需要导入头文件：`#include<stdbool.h>`。

c++ 中 bool 类型取值有两个(true、false)

c++ 中 bool 类型可以赋值任何值，其中只有四个代表假值(0、NULL、false、'\0')。

bool变量和整数运算时，真处理为1，假处理为0。

## c++ 函数和 c 函数的不同点

- c++ 无参函数代表没有任何参数，参数列表严格匹配，但 void 型参数依然可用
- c++ 函数不再支持隐式声明，函数调用前要么先声明，要么先定义
- c++ 函数返回值类型不能省略

## 函数重载 (overload)

在同一作用域中，函数名相同，参数列表不同的函数可以存在若干个，返回值任意。

参数列表不同是指参数类型不同、参数个数不同、参数顺序不同。

对于重载函数使用函数指针显得有些问题：给函数指针赋值时，指针类型代表具体的函数。

函数重载是基于编译时函数名改变实现的。

重载函数跨越编译器或由其它语言调用时，编译时编译器不能修改函数名，否则无法调用。

`extern "C"` 可以告诉编译器，像C语言那样进行编译处理。

## 哑元

如果一个函数的参数只有类型而没有形参名则这个参数称之为哑元。

作用：

- 让参数列表匹配更加严格，但 c++ 本身对无参参数列表严格
- 保证函数的向前兼容
- 区分函数(运算符重载函数)

## 参数默认值

函数参数可以指定默认值，调用时，如果不传入值，则使用默认值，否则会替代掉默认值。

注意：

- 参数的默认值要遵循靠右原则：指定默认值参数右侧的所有参数都必须指定默认值
- 参数传递时遵循靠左原则：按形参顺序从左到右依次赋值
- 参数的默认值不能和重载形成冲突
- 函数声明和实现分离时，默认值要设置在函数声明部分

## 内联函数

宏是在预处理阶段进行的简单替换，内联函数是在编译阶段进行编译的。

注意：

- 内联只是个请求，可能成功(复制代码过去)，也可能失败(当成普通调用)
- 小函数、频繁调用的函数适合内联
- 大函数、调用频率比较低的函数不适合内联
- 递归函数无法实现内联
- 类中的成员函数默认是内联的

## 引用(reference)

引用就是起别名。如下：

```c++
int x = 1;
int& rx = x;
```

注意：

- 引用初始化后在生命周期内一直绑定该变量或对象，不可更改
- 引用原变量地址相同，指向同一片内存
- 常引用：`const int& rtemp = 100`
- 不能有空引用，必须确保引用和一块合法的内存关联
- 尽量使用引用传递参数
- 尽量使用引用代替指针
- 不能返回对局部变量的引用，除非局部变量是：
  - 静态局部变量
  - 动态内存中分配的局部变量

引用底层是用指针实现的。

```c++
int x = 100;
const int *px = &x;  // px 指向可以改变，但不能通过 px 修改值

int y = 200;
int *const py = &y;  // py 指向不能改变，但 py 指向的变量 y 的值可以改变
```

## 对象

对象是一个类型的变量，类型是抽象的，对象是具体的。

- 一切皆对象
- 程序就是由一组对象组成的，并且通过发消息相互通知做什么(消息即函数)
- 每一个对象都有它自己的由其他对象构成的存储区，最终对象是由基本类型进行表达的
- 基本类型就是编译器所支撑的类型
- 每一个对象都有一个类型
- 一个特定类型的所有对象都能接收和发送相同的消息

对现实进行抽象时：

- 公共特征抽象为成员变量
- 公共行为抽象为成员函数

类是用户定义的数据类型，在类中声明的变量和函数称为类的成员：

- 变量称为数据成员(也叫成员变量)
- 函数称为成员函数(有时称为方法)

可用类来声明变量(也称为实例)。

每个实例是类的一个对象，定义类实例称为类的实例化。

注意：

1. struct 中的成员默认的访问权限为 public
2. class 中的成员默认的访问权限为 private
3. protected 也是访问权限的一种，在类内或者子类内可以访问

## 构造函数

构建一个对象时，被自动调用一次，用于初始化对象。

注意：

- 构造函数没有返回值，构造函数和类型名同名
- 如果不给一个类提供构造函数，编译器会自动提供一个无参的构造函数
- 如果提供了构造函数，编译器不再提供无参构造函数

构造函数也是函数，拥有重载和参数默认值等特性。

重载的构造函数在构造对象时根据参数自动选择构造函数。

可以用参数默认值减少构造函数的个数。

一个对象创建的过程：

1. 根据对象所对应的类型分配内存空间
2. 对成员变量进行处理
   - 成员是基本类型，则什么都不做
   - 成员是类类型，则构建这个成员
3. 调用构造函数初始化

注意：

1. 类嵌套时要传递参数给外层的类的构造函数，再传递给内层类 public 设置函数
2. 构造函数初始化列表可以让构造函数在函数体执行之前进行初始化工作
   - 如果类的成员变量是const或引用类型，必须使用初始化列表进行初始化
3. 解决引用类型的问题时：
   - 可以将一个引用变量放在构造函数最左边并且不进行设置默认值
   - 可以使用new开辟动态空间然后为这个空间起别名
4. 初始化列表可以解决参数名和成员变量的重名问题
5. 初始化列表在构造函数参数列表之后实现体之前，以冒号开头，初始化多个成员使用`,`分隔

## this指针

this 指针是指向当前对象的指针。

- 构造函数中 this 代表正在被构建的对象的地址
- 成员函数中 this 代表调用函数的对象的地址

this指针的应用：

- this 作为函数的参数或参数相关
- this 作为函数的返回值或返回值相关

## const 对象和 const 函数

const 修饰的变量叫做 const 对象(需要初始化)；const 修饰的成员函数为 const 函数。

```c++
#include <iostream>

class Date {
 public:
  Date(int y, int m, int d): year_(y), month_(m), day_(d) {}

  void show() const {
    std::cout << year_ << "-" << month_ << "-" << day_ << std::endl;
  }

 private:
  int year_;
  int month_;
  int day_;
};

int main() {
  Date date(2022, 7, 3);
  const Date const_date = date;

  const_date.show();

  return 0;
}
```

注意：

- 定义一个无参构造函数 const 对象可以不用初始化
- const 和非 const 类型的函数可以同时定义，是一种特殊的重载

const 对象和非 const 对象对函数的调用规则：

- const 对象只能调用 const 函数
- 非 const 对象优先调用非 const 函数，如果没有非 const 函数可以调用 const 函数

const 函数对成员的访问：

- const 函数只能对成员进行读操作，不能进行写操作
  - 如果非要进行写操作，可以使用 mutable 修饰成员变量
- const 函数只能调用 const 函数，不能调用非 const 函数

## 析构函数

析构函数在一个对象销毁之前会被自动调用一次。

析构函数也可以手动调用，但是一般由系统调用。

手动调用析构函数以后，系统还会再次调用一次。

析构函数和类型名相同，并且在类型名前面加一个~，即：`~类型名`。

析构函数没有返回值类型、没有参数，所以析构函数只有一个。

在对象销毁之前，要处理一些资源时可以使用自定义析构函数。如关闭文件、关闭数据库连接、释放动态内存等。

## new 与 malloc

new 比 malloc 多做了三件事：

- 类的成员变量是其它类，则自动创建该类型的成员变量
- 自动调用构造函数
- 自动类型转换

## 拷贝构造函数

拷贝构造函数是用复制的形式来创建新对象的函数。

形式：`类名(const 类名& 对象) {}`

如果不给一个类型提供拷贝构造函数，编译器会默认提供一个。

默认的拷贝构造函数采用逐字节拷贝的形式复制对象。

默认是浅拷贝，自定义可以深拷贝。

使用时机：

- 使用同类型的对象创建一个对象时
- 把一个对象传入一个值类型的参数中
- 把一个对象通过函数返回值返回时

## 类中与内存相关的函数

- 构造函数：动态内存的申请
- 析构函数：释放动态内存
- 拷贝构造函数：处理内存独立性

## 静态数据

静态成员函数：不使用对象就可以直接调用的成员函数。

静态成员函数的调用方法：

- 类名::函数名
- 对象名.函数名

注意：

- 一般采用第一种方法
- 静态成员函数没有 this 指针

静态成员变量：不使用对象就可以直接使用的成员变量(数据在对象之间共享)

静态成员变量不属于任何一个对象，它属于这个类。

**在计算含有静态成员变量的类的大小时不包含静态成员变量的大小**。

**静态成员变量必须在类外初始化**，方法：

```c++
静态成员变量类型 类名::静态变量名 [= 值];
```

静态成员函数和成员变量的访问关系：

- 静态成员函数只能直接访问静态成员，不能直接访问非静态成员
  - 因为普通成员函数中，编译器会隐式传递对象 this 指针，静态函数没有 this 指针
- 如果想要访问非静态成员，可以通过引用或者指针来传递参数给静态函数

## 成员指针

指向成员变量的指针，本质上是记录这个成员变量与首地址的偏移量。

定义成员指针：`成员变量类型 类名::*指针名;`

给成员指针赋值：`指针名 = &类名::成员名;`

访问成员指针指向的变量：`对象名.*指针名;`

使用指针访问成员指针指向的变量：`对象指针名->*指针名;`

```c++
#include <iostream>

class Date {
 public:
  Date(int year, int month, int day): year_(year), month_(month), day_(day) {}

  void show() {
    printf("addr century_ = 0x%p\n", &century_);
    printf("addr year_ = 0x%p\n", &year_);
    printf("addr month_ = 0x%p\n", &month_);
    printf("addr day_ = 0x%p\n", &day_);
  }

 private:
  int year_;
  int month_;
  int day_;
  static int century_;
};

int Date::century_ = 21;

int main() {
  Date date(2022, 7, 3);

  date.show();

  return 0;
}

// 输出了成员变量在内存中的地址，如下：
// addr century_ = 0x0x55e3683f8010
// addr year_ = 0x0x7fff4dbde27c
// addr month_ = 0x0x7fff4dbde280
// addr day_ = 0x0x7fff4dbde284
```

```c++
// 编译器：g++

#include <iostream>

class Date {
 public:
  Date(int year, int month, int day): year_(year), month_(month), day_(day) {}

 public:
  int year_;
  int month_;
  int day_;
  static int century_;
};

int Date::century_ = 21;

int main() {
  printf("addr century_ = %p\n", &Date::century_);
  printf("addr year_ = %p\n", &Date::year_);
  printf("addr month_ = %p\n", &Date::month_);
  printf("addr day_ = %p\n", &Date::day_);

  // 输出：
  // static 成员直接输出内存地址
  // addr century_ = 0x55dbbc5b7010
  // 非 static 成员输出与首地址的偏移量，针对 year_ 的偏移量为 0
  // addr year_ = (nil)
  // addr month_ = 0x4
  // addr day_ = 0x8

  int Date::* p = nullptr;
  std::cout << (p == &Date::year_) << std::endl;
  // 输出：0 (第一个成员变量首地址并非空指针)

  p = &Date::year_;

  Date date(2015,10,1);
  std::cout << date.*p << std::endl;
  // 输出：2015

  Date *pdate = new Date(2016,8,9);
  std::cout << pdate->*p << std::endl;
  // 输出：2016

  return 0;
}
```

指向成员函数的指针，本质上是代码区中的一个地址。

```c++
#include <iostream>

struct Date {
  Date(int year, int month, int day): year_(year), month_(month), day_(day) {}

  int getyear(){
      return year_;
  }

  int getday(){
      return day_;
  }

  int year_;
  int month_;
  int day_;
};

int main() {
  int (Date::*pmfun)();      // 定义成员函数指针
  pmfun = &Date::getyear;    // 没有'&'就是静态函数的地址，加上'&'就是函数的地址

  Date date(2014, 10, 15);
  std::cout << (date.*pmfun)() << std::endl;    // 使用对象调用
  // 输出：2014

  Date *pdate = new Date(2016, 8, 9);
  std::cout << (pdate->*pmfun)() << std::endl;    // 使用对象指针调用
  // 输出：2016
}
```

## 突破访问权限

1. 公开访问接口
2. 使用友元函数(在函数声明前面加friend，并且应用到类里面)

|  | 成员函数 | 静态成员函数 | 友元函数 |
| --- | --- | --- | --- |
| 能访问私有成员 | Y | Y | Y |
| 受访问权限和作用域控制 | Y | Y | N |
| 必须使用对象来调用 | Y | N | N |

## 运算符重载

**二元运算符**(`L#R，L左操作数，R右操作数`)翻译规则：

1. 去L对应的类型中找一个成员函数：`operator#(R)`
2. 如果找不到就去全局找一个全局函数：`operator#(L,R)`
3. 如果都存在则综合判断选择最好的

例：

1. `cout << 对象` 被编译器解释为：`cout.operator << (对象)` 或 `operator<<(cout, 对象)`
2. `cin >> 对象` 被编译器解释为：`cin.operator >> (对象)` 或 `operator>>(cin, 对象)`

注意：

- 运算符重载函数能写成成员形式就写成成员形式
- `<<`(ostream)、`>>`(istream) 是特殊的运算符，是流类型对象，不能被复制，也不能加 const
- `>>`是流类型输入运算符，因为要输入，所以重载时对要输入到的对象不能加 const

语法：

- 声明为全局：`返回值类型 operator 运算符(参数列表){}`
- 声明为成员：`返回值类型 operator 运算符(参数列表){}`

**一元运算符**翻译规则：

- `#O`
  - 首先去O对象对应的类型中找一个成员函数`operator#()`
  - 如果找不到就去全局找一个函数`operator#(O)`
- `O#`
  - 首先去O对象对应的类型中找一个成员函数`operator#(int)`
  - 如果找不到就去全局找一个函数`operator#(O,int)`

**运算符重载就是函数设计**：

- 返回值不拷贝就使用引用(不能引用临时局部变量)
- 参数不拷贝就使用引用
- 函数内部不修改参数就加 const

**运算符重载的限制**：

1. 不是所有的运算符都能重载
   - :: 作用域运算符
   - . 成员访问运算符
   - .* 成员指针解引用
   - sizeof 求类型或者对象大小的运算符
   - ?： 三目运算符
   - typeid 获取类型
2. 不能发明运算符进行重载
3. 不能对基本类型进行重载：运算符重载中至少有一个对象是类类型
4. 不应该改变运算符运算特性

**只能成员形式重载的运算符**：

1. `=`：
   - 如果不给一个类型提供赋值运算符则编译器会自动提供一个赋值运算符
   - 默认的赋值运算符完成的是逐字节拷贝即浅拷贝
   - 一定要要处理泄露、内存重复释放、防止自赋值这些问题
2. `()`：
    - 如果要把当前对象转换成某个类型：`operator 转换成的类型 () { return 值; }`
    - 把某个类型转换成当前对象类型可以使用单参构造机制，explicit关键字放在构造函数之前防止单参转换规则
    - 可以完成函数对象机制：可以像函数一样使用的对象(c语言中使用的是qsort函数传送规则)
3. `->`和`*`：可以把一个不是指针的类型当作指针类型来操作
4. `new`和`delete`

```c++
void* operator new (size_t size)
// 返回值：void*
// 函数名：operator new
// 参数：(size_t size)

void operator delete (void *ptr)
// 返回值：void
// 函数名：operator delete
// 参数：(void *ptr)
```

## 指针和引用的联系和区别

联系：

- 引用的底层是用指针实现的，所以很多指针的效果可以用引用来实现
- 函数的参数问题：指针类型的参数可以使用引用替换
- 函数的返回值问题：指针类型的返回值可以使用引用替换

区别：

- 引用定义时必须初始化，指针不是必须的但一般初始化
- 引用是一个别名所以不占内存，指针是一个实体变量大小是4
- 引用一旦初始化在生命周期内不能改变引用的对象，指针指向是可以改变的
- 没有引用的引用，有指针的指针(二级指针)
- 没用引用的指针，有指针的引用 int*& //相当于二级指针
- 没有引用的数组(但是有数组的引用)，有指针的数组

```c++
int* data[5] = {&a, &b, &c};

int& data[5] = { a, b, c };  //错误，没有引用的数组

int data[5];
int (&rdata)[5];  //数组的引用
```

## 面向对象的三大特征

- 封装
- 继承
- 多态

## 封装

给外界公开访问接口，隐藏具体实现。

该公开的数据设置为public，该隐藏细节的数据就设置为private。

划分模块、防止不必要的扩展。

## 继承

继承是一种软件复用方式，通过继承可以吸收现有类的数据和行为来创建新类，并增添新功能。

父类(基类)：被传承的类。

子类(派生类)：传承数据的类。

语法：

```c++
class Animal {
  public:
    void show() {}

  private:
    string name_;
    int age_;
};

class Dog: public Animal {};
```

**继承方式**：

- 公开继承：`public`
- 保护继承：`protected`
- 私有继承：`private`(可省略)

public 继承(`父类中的数据继承后访问权限不变`)：

- public成员在派生类为public可以直接由任何成员函数、友元函数和非成员函数访问
- protected成员在派生类中为protected可以直接由任何成员函数、友元函数访问
- private成员在派生类中隐藏可以通过基类的public或protected成员函数由成员函数和友元函数访问

protected 继承(`父类中的数据继承后除了private全部为protected`)：

- public成员在派生类中为protected可以直接由成员函数、友元函数访问
- protected成员在派生类中为protected可以直接由任何成员函数、友元函数访问
- private成员在派生类中隐藏可以通过基类的public或protected成员函数由成员函数和友元函数访问

private 继承(`父类中的数据继承后权限全部变为私有`)：

- public成员在派生类中为private可以直接由成员函数、友元函数访问
- protected成员在派生类中为private可以直接由任何成员函数、友元函数访问
- private成员在派生类中隐藏可以通过基类的public或protected成员函数由成员函数和友元函数访问

注意：

1. 可以说派生类是基类，但不可以说基类是派生类，因此派生类可以给基类赋值，相反则不能
2. 以 public 方式继承时：
   - public 和 protected 成员相当于子类的 public 和 protected 成员
   - 父类 private 成员对子类不可见
   - 父类中的 public 成员派生类对象可以直接访问
   - 父类中的 protected 成员：
     - 需要派生类中的 public 成员(或友元函数)调用
     - 再由派生类对象调用
   - 父类中的 private 成员：
     - 需要父类中的 protected 或 public 成员调用
     - 再由派生类成员调用
     - 再由派生类对象调用
3. 以 protected 方式继承时：
   - 父类 public 和 protected 成员在子类中全部是 protected 成员
   - 父类 private 成员对子类不可见
4. 以 private 方式继承时：
   - 父类 public 和 protected 成员在子类中全部是 private 成员
   - 父类 private 成员对子类不可见
5. 继承中构造和析构函数不会被继承：
    - 子类先调用父类构造函数
    - 子类默认调用父类无参构造函数
    - 在子类的构造函数中，可以通过初始化列表来指定调用父类的构造函数
    - 析构函数的调用数序和构造函数相反
6. 继承中拷贝构造和赋值运算符不会被继承
    - 子类没有提供拷贝构造函数，子类对象触发拷贝构造函数时会默认调用父类拷贝构造函数
    - 子类提供拷贝构造函数，则不再默认调用父类拷贝构造函数，需要指定调用(通过初始化列表指定)
    - 子类对象没有提供赋值运算符函数并且触发了赋值运算符调用，默认调用父类的赋值运算符函数
    - 子类提供赋值运算符函数，不再默认调用父类赋值运算符函数，需要指定调用调用(通过初始化列表来指定)：
      - `父类名::operator=()`
7. 名字隐藏机制：
   - 当子类提供了和父类同名的成员时，子类的数据会隐藏掉父类的数据
   - 当想要使用已经隐藏的父类成员时要使用作用域运算符`::`
     - `父类名::成员名`

## 多继承

多继承是指一个类有多个直接父类。

一个类继承多个父类之后，构造的调用顺序和继承顺序一致，与其他无关。

一个类继承多个父类之后，具备所有父类的功能，当然也可能会产生冲突。

解决多继承冲突问题：

1. 使用名字隐藏机制，通过`类名::成员`访问冲突成员
2. 共有数据抽取 + 虚继承(也称为菱形继承或者钻石继承)
    - 抽取多个父类中共有的数据部分到更高层的类中
    - 采用虚继承的方式继承更高层的类

注意：虚继承在子类中会存在一个虚指针以维持父子类之间的虚继承关系。

## 虚函数

虚函数就是增加`virtual`修饰的成员函数。

类中提供了虚函数，编译器会自动为这个类增加一个指针类型的成员变量，用以维护数据。

## 重载、隐藏、覆盖

函数重载(overload)：在同一个作用域中，函数名相同，参数列表不同的函数构成重载关系。

名字隐藏(namehide)：子类提供一个和父类同名的数据，子类的实现会把父类的实现隐藏掉。

函数重写(overwrite)：子类提供一个和父类同名的数据，子类的实现会把父类的实现覆盖掉。

## 多态

父类指针(或引用)指向子类对象调用虚函数时，子类重写了虚函数调用表现为子类，否则表现为父类。

注意：

1. 继承是构成多态的基础
2. 虚函数是构成多态的关键
3. 函数重写是必备条件

多态的底层实现：

1. 静态绑定和动态绑定
    - 静态绑定：编译时确定函数调用地址
    - 动态绑定：运行时确定函数调用地址
2. 底层实现：
   - 虚指针，虚函数表指针
   - 只要给一个类型提供虚函数则编译器会自动为这个类型提供一个指针类型的成员
   - 该指针指向虚函数表(在代码区)的首地址，存储在类的前四个字节
   - 同类型的对象共享虚函数表

```c++
#include <iostream>
using namespace std;

class A {
  public:
    A(int x=0): x(x) {}
    virtual void run() {}

  private:
    int x;
};

class B: public A {};

int main()
{
    A a(101);
    int *pa = reinterpret_cast<int*>(&a);  // *pa是虚函数表的首地址
    printf("0x%x\n", *pa);
    printf("0x%x\n", *(pa+1));

    A b(221);
    int *pb = reinterpret_cast<int*>(&b);  // *pb是虚函数表的首地址的值
    printf("0x%x\n", *pb);
    printf("0x%x\n", *(pb+1));

    B c;
    int *pc = reinterpret_cast<int*>(&c);  // 取得B类型的虚表地址
    printf("0x%x\n", *pc);

    B d;
    int *pd = reinterpret_cast<int*>(&d);  // 取得B类型的虚表地址
    printf("0x%x\n", *pd);

    return 0;
}

// 输出：
// 0x22b69d68
// 0x556e
// 0x22b69d68
// 0x556e
// 0x22b69d50
// 0x22b69d50
```

当父类指针指向子类对象调用虚函数时：

1. 并没有立即调用这个函数，而是根据对象得到虚函数表的地址
2. 根据虚函数表中函数对应的地址做出相应的调用
3. 虚函数表中放置哪个实现就调用那个函数

```c++
#include <iostream>
#include <cstring>
using namespace std;

class Animal {
  public:
    Animal( int age = 0 ):age( age ) { }

    void show() {
      cout << "Animal show()" << endl;
    }

    virtual void fun() {
        cout << "Animal fun()" << endl;
    }

    virtual void run() {
        cout << "Animal run()" << endl;
    }
    
  private:
    int age;
};


class Dog:public Animal {
  public:
    virtual void fun() {
        cout << "watch dog" << endl;
    }

    void show() {
        cout << "Dog show()" << endl;
    }
};

class Cat:public Animal {
  public:
    virtual void fun() {
        cout << "Catch the mouses!" << endl;
    }
    
    virtual void run() {
        cout << "A run cat!" << endl;
    }

    void show() {
        cout << "Cat show()" << endl;
    }
};

int main() {
    Dog dog;
    Cat cat;

    memcpy(&dog, &cat, 4);

    Animal *pa = &dog;

    pa->fun();
    pa->show();

    return 0;
}

// 输出：
// Catch the mouses!
// Animal show()
```

注意：有参和无参成员函数底层原型的第一个参数都是该类型的指针，即 this 指针。

## 多态中的类型识别

1. `typeid`获取类或者对象的类型信息(头文件`typeinfo`)，返回`type_info`对象，包含：
    - `name()`：类型名字
    - `==`：两个 type_info 对象相等代表类型相同
    - `!=`：两个 type_info 对象是否不相等
2. 动态类型转换，语法：`dynamic_cast<类型>(对象)`
   - 适用于具有多态性的父子类之间
   - 转换成功就返回非NULL，转换失败返回NULL

## 抽象类

不能被实例化的类就是抽象类，除了这一点和普通类没有任何区别。

实现：只要在这个类型中出现一个纯虚函数,则这个类自动成为抽象类。

`virtual void run() = 0`。

注意：

子类继承抽象类，如果不实现纯虚函数则子类也自动成为抽象类。

## 虚析构函数

父类型指针指向子类对象时，delete 该对象只会调用父类析构函数，子类析构函数不会调用。

解决以上问题：把父类的析构函数设置成虚析构函数。

子类析构函数的调用会引起父类析构函数调用。

```c++
class A {
  public:
    A() {}
    virtual ~A() {}  // 虚析构函数
}

class B: public A {
    B() {}
    ~B() {}
}
```

## 异常

异常是一种错误表达形式。

抛出异常：`throw 数据;` (数据可以是基本类型也可以是类类型)

异常处理：

- 默认的处理是调用 terminate 函数终止进程
- 可以对异常进行捕获处理，从而不终止进程

```c++
try {
    // 可能会出现异常的代码
} catch (异常的类型 e) {
    ......
} catch (异常的类型 e) {
    ......
}
```

函数的异常说明：

```c++
void foo();                     // 可能会抛出所有异常
void foo() throw();             // 不抛出任何异常，在这样写的情况下如果函数还抛出异常则这些异常不能被捕获
void foo() throw(int);          // 可能会抛出int异常
void foo() throw(int, double);  // 可能会抛出int或者double的异常
```

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void foo() throw(int, double, const char*) {
    int r=rand()%4;

    cout << "调用函数开始" << endl;

    if (0 == r) {
        cout << "程序正常" << endl;
    } else if (1 == r){
        throw 1;
    } else if (2 == r){
        throw 2.5;
    }else{
        throw "connect server failed";
    }

    cout << "函数调用结束" << endl;
}

int main() {
    srand(time(NULL));

    try {
        foo();
    } catch (int e) {
        cout << "int data = " << e << endl;
    } catch (double e) {
        cout << "double data = " << e << endl;
    } catch (const char* e) {
        cout << "const char* data = " << e << endl;
    }
    
    return 0;
}
```

系统异常：

```c++
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

int main(){
    try {
        int *parr=new int[0xffffffff];
    } catch (bad_alloc& e) {
        cout << "内存分配问题:" << endl;
        cout << e.what() << endl;
    } catch (...) {
        cout << "有问题" << endl;
    }

    string abc("hello");
    cout << abc.at(4) << endl;
    cout << abc[4] << endl;
    
    try {
        cout << abc.at(10) << endl;
    } catch(out_of_range& e) {
        cout << e.what() << endl;
    }
    
    return 0;
}
```

系统异常包含(继承自`std::exception`)：

- `std::bad_alloc`
- `std::bad_cast`
- `std::bad_typeid`
- `std::bad_exception`
- `std::logic_error`
- `std::runtime_error`

`std::logic_error`中包含：

- `std::domain_error`
- `std::invalid_argument`
- `std::length_error`
- `std::out_of_range`

`std::runtime_error`中包含：

- `std::overflow_error`
- `std::range_error`
- `std::underflow_error`

自定义异常：通过继承`std::exception`实现。

```c++
#include <iostream>
#include <exception>
#include <string>

using namespace std;

class MyException: public exception {
  public:
    MyException(): message("Error."){}
    MyException(string str): message("Error: " + str) {}

    ~MyException() throw () {}

    virtual const char* what() const throw () {
        return message.c_str();
    }

  private:
    string message;
};

int main() {
    try {
        throw MyException();
    } catch(MyException& e) {
        std::cout << e.what() << std::flush;
    } catch(std::exception& e) {
        //其他的错误
    }
}
```

## IO

对比 C 和 C++ 的 IO：C 语言就是一堆全局函数，C++ 使用类的方式来组织。

控制台相关的类：istream、ostream --> `#include <iostream>`

文件操作相关的类：ifstream、ofstream、fstream --> `#include <fstream>`

字符串操作相关的类：istringstream、ostringstream --> `#include <sstream>`

格式化IO和非格式化IO：

- 格式化数据是有类型的
- 非格式化只有字符的概念

C++ 中的 IO `cin >>`、`cout <<` 自动识别格式。

C++中也有非格式化函数：

```c++
#include <fstream>

int get();
istream& get(char& ch);
ostream& get(char& ch);
```

## c++ 内存分配

**new / delete**：

```c++
int* p2 = new int;//不保证是零
int* p3 = new int(100);
int* p4 = new int[5];
delete p2;
delete p3;
delete[] p4;
```

**定位分配**：

```c++
char buf[100] = {};
new(buf) int[25];
```

注意：不存在定位分配所对应的 delete 运算，一旦 buf 释放，new 所分配的空间也随即释放。

**malloc / free**：

new在分配空间后会比malloc多做三件事：

- 如果对象成员又是对象，自动构造此对象
- 自动调用构造函数
- 自动处理类型转换

**delete 和 free 的区别**：

delete在释放对象之前会调用析构函数。
