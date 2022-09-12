
# C++ 新特性

- [C++ 新特性](#c-新特性)
  - [C++11](#c11)
    - [is\_integral](#is_integral)
    - [enable\_if](#enable_if)
    - [conditional](#conditional)
    - [explicit](#explicit)
    - [std::this\_thread::yield()](#stdthis_threadyield)
    - [std::numeric\_limits](#stdnumeric_limits)
    - [内存模型](#内存模型)
      - [relaxed](#relaxed)
      - [release-acquire](#release-acquire)
      - [seq\_cst](#seq_cst)
      - [consume](#consume)

## C++11

### is_integral

用于检查类型是否为整数类型。

提供成员变量 value，类型为整数类型时`value=true`，否则`value=false`。

访问方式：`is_integral<T>::value`。

`bool`、`long`、`long long`、`short`、`char`等均为整数类型。

```c++
#include <iostream>
#include <type_traits>

template <typename T>
void Print(T v) {
  std::cout << std::boolalpha;
  std::cout << std::is_integral<T>::value << std::endl;
}

int main(int argc, char const *argv[]) {

  Print<bool>(true);
  Print<int>(1);
  Print<long>(1);

  Print<float>(1.0);
  Print<double>(1.0);

  return 0;
}

// 输出：true true true false false
```

### enable_if

`enable_if`的作用主要用于模板的匹配，偏特化的一个过程。

编译器在类型推导的过程中，会尝试推导所有的重载函数。

在以上过程中，如果`enable_if`条件不满足，则会在候选函数集合中剔除此函数。

```c++
#include <iostream>
#include <type_traits>

template <class T>
typename std::enable_if<std::is_integral<T>::value, bool>::type is_odd(T i) {
  return bool(i % 2);
}

template <class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
bool is_even(T i) {
  return !bool(i % 2);
}

int main() {
  short int i = 1;

  std::cout << std::boolalpha;
  std::cout << "i is odd: " << is_odd(i) << std::endl;
  std::cout << "i is even: " << is_even(i) << std::endl;

  return 0;
}

// 输出：
// i is odd: true
// i is even: false
```

### conditional

原型：`std::conditional<condition, type1, type2>`

具体理解为：

- 如果 condition 为 true 则 conditional 提供的公有成员 `type = type1`
- 否则，提供的公有成员 `type = type2`。

```c++
#include <iostream>
#include <type_traits>

int main() {
  short int i = 1;

  typedef std::conditional<true, int, float>::type A;   // int
  typedef std::conditional<false, int, float>::type B;  // float
  typedef std::conditional<std::is_integral<A>::value, long, int>::type C;  // long
  typedef std::conditional<std::is_integral<B>::value, long, int>::type D;  // int

  std::cout << std::boolalpha;
  std::cout << "typedefs of int:" << std::endl;
  std::cout << "A: " << std::is_same<int, A>::value << std::endl;
  std::cout << "B: " << std::is_same<int, B>::value << std::endl;
  std::cout << "C: " << std::is_same<int, C>::value << std::endl;
  std::cout << "D: " << std::is_same<int, D>::value << std::endl;

  return 0;
}

// typedefs of int:
// A: true
// B: false
// C: false
// D: true
```

### explicit

explicit 是 C++11 中特意添加的一个关键字。

通常情况下用于构造函数前面，表示显式表示，禁止构造函数的隐式转换。

这种隐式转换往往是让人迷惑的，并且容易隐藏Bug，得到了一个不期望的类型转换。

所以对于单参数的构造函数是要求explicit声明。

### std::this_thread::yield()

`yield()`用于避免一个线程频繁与其他线程争抢CPU时间片，从而导致多线程处理性能下降。

`yield()`会让当前线程让出自己的CPU时间片给其他线程使用。

`std::this_thread::sleep_for()`会让当前线程休眠一段时间。

`sleep_for()`也可以起到`yield()`相似的作用。

但以上两者的使用目的是大不相同的:

- `yield()`是让线程让渡出自己的CPU时间片给其他线程使用
- `sleep_for()`是线程根据某种需要, 需要等待若干时间

### std::numeric_limits

定义于头文件`<limits>`，定义：`template< class T > class numeric_limits;`。

`numeric_limits`类模板提供查询各种算术类型属性的标准化方式。

如`int`类型的最大可能值是：`std::numeric_limits<int>::max())`。

通过 numeric_limits 模板的特化提供此信息。

标准库为所有算术类型制定可用的特化：

```c++
template<> class numeric_limits<bool>;
template<> class numeric_limits<char>;
template<> class numeric_limits<signed char>;
template<> class numeric_limits<unsigned char>;
template<> class numeric_limits<wchar_t>;
template<> class numeric_limits<char8_t>; (C++20 起)
template<> class numeric_limits<char16_t>; (C++11 起)
template<> class numeric_limits<char32_t>; (C++11 起)
template<> class numeric_limits<short>;
template<> class numeric_limits<unsigned short>;
template<> class numeric_limits<int>;
template<> class numeric_limits<unsigned int>;
template<> class numeric_limits<long>;
template<> class numeric_limits<unsigned long>;
template<> class numeric_limits<long long>; (C++11 起)
template<> class numeric_limits<unsigned long long>; (C++11 起)
template<> class numeric_limits<float>;
template<> class numeric_limits<double>;
template<> class numeric_limits<long double>;

// (公开静态成员常量)
is_specialized     // 用于鉴别 std::numeric_limits 是否为该类型特化
is_signed          // 用于鉴别有符号类型
is_integer         // 用于鉴别整数类型
is_exact           // 用于鉴别准确表示的类型
has_infinity       // 用于鉴别能表示特殊值“正无穷大”的浮点类型
has_quiet_NaN      // 用于鉴别能表示特殊值“安静的非数”（ NaN ）的浮点类型
has_signaling_NaN  // 用于鉴别能表示特殊值“发信的非数”（ NaN ）的浮点类型
has_denorm         // 用于鉴别浮点类型所用的非正规风格
has_denorm_loss    // 用于鉴别浮点类型是否检测精度损失为非正规损失，而非不准确结果
round_style        // 用于鉴别类型所用的舍入模式
is_iec559          // 用于鉴别 IEC 559/IEEE 754 浮点类型
is_bounded         // 用于鉴别表示有限值集合的类型
is_modulo          // 用于鉴别以模算术处理溢出的类型
digits             // 用于能无更改地表示的 radix 位数
digits10           // 用于能无更改地表示的十进制位数
max_digits10       // 用于C++11， 区别所有此类型值所需的十进制位数
radix              // 用于给定类型的表示所用的基或整数底
min_exponent       // 用于底的该数次幂是合法正规浮点值的最小负数加一
min_exponent10     // 用于10 的该数次幂是合法正规浮点值的最小负数
max_exponent       // 用于底的该数次幂是合法有限浮点值的最大整数加一
max_exponent10     // 用于10 的该数次幂是合法有限浮点值的最大整数
traps              // 用于鉴别可能导致算术运算出现陷阱的类型
tinyness_before    // 用于鉴别检测舍入前是否非正规的浮点类型

// (公开静态成员函数)
min            // 用于返回给定类型的最小有限值
lowest         // 用于C++11， 返回给定类型的最低有限值
max            // 用于返回给定类型的最大有限值
epsilon        // 用于返回 1.0 与给定类型的下个可表示值的差
round_error    // 用于返回给定浮点类型的最大舍入误差
infinity       // 用于返回给定类型的正无穷大值
quiet_NaN      // 用于返回给定浮点类型的安静 NaN 值
signaling_NaN  // 用于返回给定浮点类型的发信的 NaN
denorm_min     // 用于返回给定浮点类型的最小正非正规值
```

### 内存模型

乱序执行产生的原因：

1. 编译器出于优化的目的，在编译阶段将源码的顺序进行交换
2. 程序执行期间，指令流水被 cpu 乱序执行
3. inherent cache 的分层及刷新策略使得有时候某些写读操作的从效果上看，顺序被重排

在多线程中乱序制造了麻烦的原因：

1. 并发不能保证修改和访问共享变量的操作原子性，使得一些中间状态暴露了出去
2. 变量被修改后，该修改未必能被另一个线程及时观察到，因此需要**同步**

解决同步问题就需要确定内存模型，也就是需要确定线程间应该怎么通过共享内存来进行交互。

内存模型所要表达的内容主要是怎么描述一个内存操作的效果，在各个线程间的可见性的问题。

修改操作的效果不能及时被别的线程看见的原因有很多，其中组明显的一个：

- 对计算机来说，通常内存的写操作相对于读操作是昂贵很多很多的，因此对写操作的优化是提升性能的关键
- **写操作通常会在CPU内部的cache中缓存起来**
- 缓存导致在一个CPU执行写操作后，导致的内存变化不一定马上被另一个CPU看到，其实就是读写乱序了

```c++
// cpu1执行
a = 3;

// cpu2执行
load(a);
```

对如上代码：

- 假设a的初始值是0, 然后cpu1先执行，之后cpu2再执行
- 假设其中读写都是原子的，那么cpu2最后也可能读到`a=0`
- 以上在某个线程成功修改了全局变量，在另一个线程却看不到效果的后果是很严重的

**因此必须要有必要的手段对这种修改公共变量的行为进行同步**。

c++11中支持的[内存模型](https://en.cppreference.com/w/cpp/atomic/memory_order)：

```c++
enum memory_order {
    memory_order_relaxed,    // 自由序列
    memory_order_consume,    // 获取释放序列
    memory_order_acquire,    // 获取释放序列
    memory_order_release,    // 获取释放序列
    memory_order_acq_rel,    // 获取释放序列
    memory_order_seq_cst     // 排序一致序列，default
};
```

#### relaxed

`memory_order_relaxed`一种最宽松的内存操作约定，该约定其实就是不进行约定。

以这种方式修改内存时，不需要保证该修改会不会及时被其它线程看到，也不对乱序做任何要求。

因此当对公共变量以 relaxed 方式进行读写时，编译器、cpu等被允许按照它们认为合适的方式优化处理。

#### release-acquire

release 和 acquire 是相辅相承的，必须配合使用，分开使用完全没有意义。

具体到其中，release 用于进行写操作，acquire 用于进行读操作，它们结合起来表示这样一个约定：

1. 如果线程 A 对内存以 release 方式修改
2. 那么线程 A 中所有在 release 操作之前进行的内存操作
3. 在另一个线程 B 对内存以 acquire 方式读取之后变得可见

```c++
// 线程A执行
a.store(3);
b.store(4);
m.store(5, release);

// 线程B执行
e.load();
f.load();
m.load(acquire);
g.load();
h.load();
```

如上，**假设线程A先执行，线程B后执行**：

- 因为线程 A 中对 m 以 release 的方式进行修改
- 而线程 B 中以 acquire 的方式对 m 进行读取
- 所以当线程 B 执行完`m.load(acquire)`之后，线程 B 必须已经能看到`a==3`, `b == 4`

release 和 acquire 是相对两个线程来说的，它约定的是两个线程间的相对行为：

- 如果其中一个线程 A 以 release 的方式修改公共变量 m，另一个线程 B 以 acquire 的方式时读取该 m 时
- 以上约定了需要有什么样的后果
- 但它并不保证，此时如果还有另一个线程 C 以非 acquire 的方式来读取 m，会有什么后果

这在一定程度阻止了乱序的发生，因为要求 release 操作之前的所有操作都在另一个线程 acquire 之后可见，那么：

- release 操作之前的所有内存操作不允许被乱序到 release 之后
- acquire 操作之后的所有内存操作不允许被乱序到 acquire 之前

在对它们的使用上，有几点是特别需要注意和强调的：

- release 和 acquire 必须配合使用，分开单独使用是没有意义
- release 只对写操作(store)有效，对读(load)是没有意义的
- acquire 只对读操作有效，对写操作是没有意义的

现代的处理器通常都支持一些`read-modify-write`之类的指令。

对于这种指令，有时可能既想执行 release 又想执行 acquire，因此还定义了`memory_order_acq_rel`。

`memory_order_acq_rel`类型的操作就是 release 与 acquire 的结合，除以上作用，还有内存屏障的功能。

[memory barrier](https://preshing.com/20120710/memory-barriers-are-like-source-control-operations/)

#### seq_cst

`sequential consistency`相当于`release+acquire`之外，还有对该操作加上全局顺序的要求。

对所有以`memory_order_seq_cst`方式进行的内存操作：

- 不管它们是不是分散在不同的cpu中同时进行
- 这些操作所产生的效果最终都要求有一个全局的顺序
- 而且这个顺序在各个相关的线程看起来是一致的

```c++
// 线程A执行
a.store(3, seq_cst);

// 线程B执行
b.store(4, seq_cst);
```

如上，假设a和b的初始值都是0：

- 对a与b的修改分别放在两个线程里同时进行，这些动作是非原子的
- 因此这些操作的进行在全局上必须要有一个先后顺序：
  - 先修改a, 后修改b
  - 先修改b, 后修改a
- 这个顺序是固定的，必须在其它任意线程看起来都是一样
  - 因此`a == 0 && b == 4`与`a == 3 && b == 0`不允许同时成立。

#### [consume](https://blog.csdn.net/qls315/article/details/120721892)

`memory_order_consume`仅仅只用来补充该系列的完整性，在实际代码中不能使用该内存序。

在GCC中会自动将该内存序转换为`memory_order_acquire`。

[memory_order_consume的目的](https://blog.csdn.net/netyeaxi/article/details/80718781)

ARM 和 PowerPC 都是弱排序CPU，在多核系统上必须放置内存栅栏指令以保证获取语义。

PowerPC 中：

- GCC 使用了3个指令实现内存栅栏：`cmp;bne;isync`
- 单个指令`lwsync`也可以实现内存栅栏

ARMv7中`dmb ish`是最合适实现内存栅栏的指令。

原子操作就是通过内存栅栏实现的。
