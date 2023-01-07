
# Rust

- [Rust](#rust)
  - [相关文档](#相关文档)
  - [linux开发环境搭建](#linux开发环境搭建)
  - [cargo的使用](#cargo的使用)
  - [变量](#变量)
    - [变量命名](#变量命名)
    - [变量绑定](#变量绑定)
    - [变量可变性](#变量可变性)
    - [使用下划线开头忽略未使用的变量](#使用下划线开头忽略未使用的变量)
    - [变量解构与赋值](#变量解构与赋值)
    - [变量和常量之间的差异](#变量和常量之间的差异)
    - [变量遮蔽(shadowing)](#变量遮蔽shadowing)
  - [基本数据类型](#基本数据类型)
    - [类型推导与标注](#类型推导与标注)
    - [数值类型](#数值类型)
      - [整数类型](#整数类型)
      - [浮点类型](#浮点类型)
    - [数值运算](#数值运算)
    - [位运算](#位运算)
    - [序列](#序列)
    - [有理数和复数](#有理数和复数)
    - [字符类型](#字符类型)
    - [布尔](#布尔)
    - [单元类型](#单元类型)
  - [语句和表达式](#语句和表达式)
  - [函数](#函数)
  - [所有权](#所有权)
    - [堆与栈](#堆与栈)
    - [所有权原则](#所有权原则)
    - [变量作用域](#变量作用域)
    - [转移所有权](#转移所有权)
    - [克隆(深拷贝)](#克隆深拷贝)
    - [拷贝(浅拷贝)](#拷贝浅拷贝)
    - [函数传值与返回](#函数传值与返回)
  - [引用与借用](#引用与借用)
    - [引用与解引用](#引用与解引用)
    - [不可变引用](#不可变引用)
    - [可变引用](#可变引用)
    - [可变引用与不可变引用不能同时存在](#可变引用与不可变引用不能同时存在)
    - [悬垂引用](#悬垂引用)
  - [复合类型](#复合类型)
  - [字符串](#字符串)
    - [切片(slice)](#切片slice)
    - [其它切片](#其它切片)
    - [字符串字面量是切片](#字符串字面量是切片)
    - [rust字符串](#rust字符串)
    - [String 与 \&str 的转换](#string-与-str-的转换)
    - [字符串索引](#字符串索引)
    - [操作字符串](#操作字符串)
      - [追加(push)](#追加push)
      - [插入(insert)](#插入insert)
      - [替换(replace)](#替换replace)
      - [删除(delete)](#删除delete)
      - [连接(catenate)](#连接catenate)
    - [字符串转义](#字符串转义)
    - [操作UTF-8字符串](#操作utf-8字符串)
    - [获取子串](#获取子串)
  - [元组](#元组)
    - [使用模式匹配解构元组](#使用模式匹配解构元组)
    - [用`.`来访问元组](#用来访问元组)
  - [结构体](#结构体)
    - [结构体语法](#结构体语法)
    - [元组结构体](#元组结构体)
    - [单元结构体](#单元结构体)
  - [枚举](#枚举)
    - [枚举类型](#枚举类型)
    - [枚举值](#枚举值)
    - [用Option枚举处理空值](#用option枚举处理空值)
  - [数组](#数组)
    - [创建数组](#创建数组)
    - [访问数组元素](#访问数组元素)
    - [越界访问](#越界访问)
    - [数组切片](#数组切片)
  - [分支控制](#分支控制)
    - [使用if语句做分支控制](#使用if语句做分支控制)
    - [多重条件分支](#多重条件分支)
  - [循环控制](#循环控制)
    - [for循环](#for循环)
    - [`continue`](#continue)
    - [`break`](#break)
    - [while循环](#while循环)
    - [loop循环](#loop循环)
  - [模式匹配](#模式匹配)
    - [match匹配](#match匹配)
    - [模式绑定](#模式绑定)
    - [if let匹配](#if-let匹配)
    - [matches!宏](#matches宏)
    - [变量覆盖](#变量覆盖)
    - [解构Option](#解构option)
  - [模式适用场景](#模式适用场景)
    - [match分支](#match分支)
    - [if let分支](#if-let分支)
    - [while let条件循环](#while-let条件循环)
    - [for循环](#for循环-1)
    - [let语句](#let语句)
    - [函数参数](#函数参数)
    - [if和if let](#if和if-let)
  - [全模式列表](#全模式列表)
    - [匹配字面值](#匹配字面值)
    - [匹配命名变量](#匹配命名变量)
    - [单分支多模式](#单分支多模式)
    - [匹配范围](#匹配范围)
    - [解构结构体](#解构结构体)
    - [解构枚举](#解构枚举)
    - [解构嵌套的结构体和枚举](#解构嵌套的结构体和枚举)
    - [解构结构体和元组](#解构结构体和元组)
    - [忽略模式中的值](#忽略模式中的值)
      - [使用`_`忽略整个值](#使用_忽略整个值)
      - [使用嵌套的`_`忽略部分值](#使用嵌套的_忽略部分值)
      - [下划线开头忽略未使用的变量](#下划线开头忽略未使用的变量)
      - [用`..`忽略剩余值](#用忽略剩余值)
    - [匹配守卫提供的额外条件](#匹配守卫提供的额外条件)
    - [@绑定](#绑定)
      - [@前绑定后解构(rust-1.56新增)](#前绑定后解构rust-156新增)
      - [@新特性(rust-1.53新增)](#新特性rust-153新增)
  - [方法](#方法)
  - [定义方法](#定义方法)
    - [self](#self)
      - [方法名跟结构体字段名相同](#方法名跟结构体字段名相同)
  - [带有多个参数的方法](#带有多个参数的方法)
  - [关联函数](#关联函数)
  - [多个 impl 定义](#多个-impl-定义)
  - [为枚举实现方法](#为枚举实现方法)
  - [代码的组织管理](#代码的组织管理)
    - [相关概念](#相关概念)
  - [附录](#附录)
    - [关键字](#关键字)
    - [命名规范](#命名规范)
    - [运算符](#运算符)
    - [编译器属性标记](#编译器属性标记)

## 相关文档

[官方网站](https://rustwiki.org/)
[rust官方文档](https://rustwiki.org/zh-CN/)
[rust官方书籍](https://github.com/rust-lang/book)
[rust标准库](https://rustwiki.org/zh-CN/std/)
[rust语言中文社区](https://rustcc.cn/)
[rust语言圣经](https://course.rs/basic/intro.html)

## linux开发环境搭建

[参照文档](../../linux/ubuntu-20.04开发环境搭建.md#rust)。

## cargo的使用

命令 | 作用
--- | ---
`cargo --version` | 打印版本
`cargo new project_name` | 创建项目
`cargo build` | 构建项目
`cargo run` | 运行项目
`cargo test` | 测试
`cargo check` | 检测代码语法
`cargo clean` | 清理，添加模块后如果build有报错，可以尝试先clean

```shell
# 创建二进制类型的项目
cargo new notes_rust_code

# 目录结构
tree
# .
# ├── Cargo.toml
# └── src
#     └── main.rs

# 1 directory, 2 files

# 创建库类型的项目
cargo new notes_rust_lib --lib

# 目录结构
tree
# .
# ├── Cargo.toml
# └── src
#     └── lib.rs

# 1 directory, 2 files
```

编译和运行项目：

```shell
cd notes_rust_code
cargo build
cargo run
```

在以上生成的`main.rx`中，有代码打印`hello world`，该文件用于编译。

此外，我们可以自己新建文件`main.rs`，文件中输入以下代码：

```shell
fn main() {
    println!("Hello, world!");
}
```

执行`rustc main.rs`进行编译可以得到可执行程序`main`。

`rustc`是编译rust程序的编译器，该程序的帮助信息：`rustc --help`。

## 变量

### 变量命名

在命名方面，rust与其它语言没有区别，但给变量命名时需要遵循附录中命名规范。

rust语言中有一些**关键字**，与其他语言一样，这些关键字需要保留给rust语言使用，不能用作变量或函数的名称。

附录中可找到关键字列表。

### 变量绑定

其它语言中，可以使用`=`给变量赋值，即把等式右边的值赋值给等号左边的变量。

在rust中，可以这样写：`let a = 1`，同时给这个过程起了另一个名字：**变量绑定**。

为何不用赋值而用绑定呢？

其实也可以称之为赋值，但是绑定的含义更清晰准确。

因为这里涉及到rust最核心的原则：**所有权**。

即：

- 任何内存对象都是有主人的，且一般情况下完全属于它的主人
- 绑定就是把这个对象绑定给一个变量，让这个变量成为它的主人
  - 这种情况下，该对象之前的主人就会丧失对该对象的所有权

### 变量可变性

rust变量默认情况下是**不可变的**。

为了**灵活性与安全性**，rust中需要使用`mut`关键字**手动设置变量的可变性**。

无需改变的变量声明为不可变在运行期会避免一些多余的运行时检查，这意味着运行性能的提升。

如果变量声明为不可变，那么一旦为它绑定值，就不能再修改变量的值，使用命令`cargo new variables`新建工程。

修改文件`src/main.rs`中的代码：

```rust
fn main() {
    let mut x: i32 = 5;
    x = x + 1;

    let y: i32 = 6;
    // y = y + 1;
    // 以上这行代码取消注释后，会报如下错误:
    //   cannot assign twice to immutable variable

    println!("The value of x is: {} {}", x, y);
}
```

修改后使用`cargo run`运行可以得到结果：

```console
   Compiling variables v0.1.0 (/notes/language/rust/code/variables)
    Finished dev [unoptimized + debuginfo] target(s) in 2.74s
     Running `target/debug/variables`
The value of x is: 6 6
```

取消注释掉的报错的代码，使用`cargo run`运行：

```console
   Compiling variables v0.1.0 (/notes/language/rust/code/variables)
error[E0384]: cannot assign twice to immutable variable `y`
 --> src/main.rs:6:3
  |
5 |   let y: i32 = 6;
  |       -
  |       |
  |       first assignment to `y`
  |       help: consider making this binding mutable: `mut y`
6 |   y = y + 1;
  |   ^^^^^^^^^ cannot assign twice to immutable variable

For more information about this error, try `rustc --explain E0384`.
error: could not compile `variables` due to previous error
```

具体的错误原因是`cannot assign twice to immutable variable y`，无法对不可变的变量进行重复赋值。

以上rust编译还给出了错误修复提示，后续写代码的过程中编译有错误或者警告时，可以详细阅读并依照进行修复。

变量默认声明为不可变更，让代码变得非常清晰，只有想让变量改变时才能去改变。

在rust中，在变量名前加上关键字`mut`即可声明为可变变量，这种方式可以显式告诉代码阅读者变量在后面的代码中将会发生改变。

### 使用下划线开头忽略未使用的变量

当创建了一个变量却不在任何地方使用时，rust通常会给出警告，因为这可能会是个bug。

当我们希望rust不要警告未使用的变量时，可以使用下划线作为变量名的开头。

### 变量解构与赋值

`let` 表达式不仅仅用于变量的绑定，还能进行复杂变量的解构：从一个相对复杂的变量中，匹配出该变量的一部分内容：

使用`let`进行解构赋值：

```rust
fn main() {
    let (a, mut b): (bool, bool) = (true, false);
    // a = true, 不可变
    // b = false, 可变

    println!("a = {:?}, b = {:?}", a, b);

    b = true;
    assert_eq!(a, b);
}
```

元组、切片、结构体的解构赋值：

```rust
struct Struct {
    e: i32,
}

fn main() {
    let (a, b, c, d, e);

    (a, b) = (1, 2);
    [c, .., d, _] = [1, 2, 3, 4, 5];
    // 以上:
    //   .. 用于省略剩余值，后面会进行详细说明
    //   _  类似于python中的_，代表匹配一个值

    Struct { e, .. } = Struct { e: 5 };

    assert_eq!([1, 2, 1, 4, 5], [a, b, c, d, e]);
}
```

元组、切片、结构体的解构赋值与`let` 保持了一致性，但`let`会重新绑定，而这里仅仅是对之前绑定的变量进行再赋值。

### 变量和常量之间的差异

与不可变变量一样，常量也是绑定到一个常量名，且不允许更改常量值，但常量和变量之间存在一些差异：

- 常量不允许使用`mut`
  - 常量默认且自始至终不可更改，因为常量在编译完成后它的值就已经确定
- 常量的声明使用`const`关键字，且值的类型必须标注(数据类型后续将会有说明)

如下定义一个`u32`类型的常量：

```rust
const MAX_POINTS: u32 = 100_000;  // _用于分割数据提升可读性
```

### 变量遮蔽(shadowing)

rust允许声明相同的变量名，在后面声明的变量会遮蔽掉前面声明的变量，如下所示：

```rust
fn main() {
    let x = 5;
    let x = x + 1;

    println!("The value of x is: {}", x);

    {
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    println!("The value of x is: {}", x);
}

// 编译运行会输出以下内容:
// The value of x is: 6
// The value of x in the inner scope is: 12
// The value of x is: 6
```

前面介绍变量默认是不可变的，这里`let x = x + 1;`实际上生成了新的变量，是内存对象的再分配。

`mut`声明变量后，是修改同一个内存地址上的值，并不会发生内存对象的再分配，性能要更好。

变量遮蔽用于在某个作用域内无需再使用之前的变量时可以重复的使用变量名字，而不用绞尽脑汁去想更多的名字。

## 基本数据类型

rust每个数据都是基本类型或复合类型。

基本类型是一个最小化的原子类型，一般无法解构为其它类型，由以下组成：

- 数值类型：
  - 有符号整数(`i8`, `i16`, `i32`, `i64`, `isize`)
  - 无符号整数(`u8`, `u16`, `u32`, `u64`, `usize`)
  - 浮点数(`f32`, `f64`)
  - 有理数
  - 复数
- 字符串：
  - 字符串字面量
  - 字符串切片 `&str`
- 布尔类型：`true`、`false`
- 字符类型：表示单个Unicode字符，存储为4个字节
- 单元类型：即`()`，其唯一的值也是`()`

### 类型推导与标注

rust是一门静态类型语言，编译器必须在编译期知道所有变量的类型。

rust编译器可以根据变量的值和上下文中的使用方式来自动推导出变量的类型。

在某些情况下，编译器无法推导出变量的类型时，就需要手动给予一个类型标注。

```rust
let guess = "42".parse().expect("Not a number!");
```

以上代码是解析字符串`"42"`，编译器在这里无法推导出我们想要的类型，因此编译时会报错：

```text
error[E0282]: type annotations needed
```

此时我们需要显式标注变量`guess`的数据类型：

- `let guess: i32 = ...`
- `"42".parse::<i32>()`

### 数值类型

创建整数(`1`，`2`，...)和浮点数(`1.0`，`1.1`，...)，与其他语言一致。

整数、浮点数的运算和其它语言也一致，都是通过常见的运算符来完成。

rust数值类型及运算与其他语言较为相似，但实际上除了语法上的不同之外，还存在一些差异：

1. rust有很多种数值类型
    - 需要熟悉类型所占用的字节数，这样就知道该类型：
      - 允许的大小范围
      - 是否能表达负数
2. 必须显式进行类型转换
    - rust不会偷偷进行类型转换
3. 数值可以使用方法
    - 如对`13.14`取整可以写为`13.14_f32.round()`
      - `f32`是类型后缀，因为编译器需要知道`13.14`的具体类型

#### 整数类型

整数是没有小数部分的数字。

之前使用的`i32`类型，表示有符号32位整数，`i`是integer的首字母，与之相反的是`u`，代表无符号`unsigned`。

| 长度       | 有符号类型 | 无符号类型 |
| ---------- | ---------- | ---------- |
| 8 位       | `i8`       | `u8`       |
| 16 位      | `i16`      | `u16`      |
| 32 位      | `i32`      | `u32`      |
| 64 位      | `i64`      | `u64`      |
| 128-位     | `i128`     | `u128`     |
| 视架构而定 | `isize`    | `usize`    |

类型定义的形式统一为：`有无符号+类型大小(位数)`。

- 无符号数表示数字只能取正数
  - 取值范围：0 ~ 2<sup>n</sup> - 1，n为数据类型的位数
- 有符号表示数字即可以取正数又可以取负数
  - 取值范围：-(2<sup>n - 1</sup>) ~ 2<sup>n - 1</sup> - 1，n为数据类型的位数

有符号数字以补码形式存储。

`isize`和`usize`所占位数取决于程序运行的CPU类型：CPU为32位，则这两个类型为32位，CPU为64位，那它们为64位。

整形字面量可以用下表的形式书写：

| 数字字面量         | 示例          |
| ------------------ | ------------- |
| 十进制             | `98_222`      |
| 十六进制           | `0xff`        |
| 八进制             | `0o77`        |
| 二进制             | `0b1111_0000` |
| 字节 (仅限于 `u8`) | `b'A'`        |

注：以上书写形式中的`_`用于分割数字，以提升可读写。

rust中整形默认使用`i32`，如`let i = 1`，那`i`就是`i32`类型。

`isize`和`usize`主要用作集合的索引。

当一个变量修改为其能够表示的范围以外的值时，会发生整型溢出：

- debug模式下构建，发生整型溢出时，程序编译时会**panic**(崩溃，表示程序因错误而退出)
- release模式下构建，rust不检测溢出，大于类型最大值的数值会被补码转换成该类型能够支持的对应数字的最小值
  - 这种依赖默认行为的代码被认为是错误的代码

要显式处理可能的溢出，可以使用标准库针对原始数字类型提供的这些方法：

- `wrapping_*`：在所有模式下都按照补码循环溢出规则处理，如：`wrapping_add`
- `checked_*`：发生溢出，则返回`None`值
- `overflowing_*`：返回该值和一个指示是否溢出的布尔值
- `saturating_*`：使值达到最小值或最大值

#### 浮点类型

rust中浮点类型数字有两种基本类型：`f32`和`f64`，分别为32位和64位大小。

默认浮点类型是`f64`，现代CPU中它的速度与`f32`几乎相同，但精度更高。

`f32`为单精度浮点数类型，`f64`为双精度浮点数类型。

浮点数陷阱：

> 1. **浮点数往往是数字的近似表达**：
>     - 浮点数类型是基于二进制实现的，但是我们想要计算的数字往往是基于十进制
>     - 在十进制上存在的浮点数，在二进制上可能并不存在精确的表达形式，这种不匹配性会导致一定的歧义性
>     - 有时虽然浮点数能代表真实数值，但由于底层格式问题，可能只有使用无限精度的浮点数才能表达真实数字
> 2. **浮点数在某些特性上是反直觉的**：
>     - rust中`f32`和`f64`的比较运算实现的是`std::cmp::PartialEq`，没有实现`std::cmp::Eq`

因此，应该：

- 避免在浮点数上测试相等性
- 当结果在数学上可能存在未定义时，需要格外的小心

举例：

```rust
fn main() {
    let abc: (f32, f32, f32) = (0.1, 0.2, 0.3);
    let xyz: (f64, f64, f64) = (0.1, 0.2, 0.3);

    println!("abc (f32)");
    println!("   0.1 + 0.2: {:x}", (abc.0 + abc.1).to_bits());
    println!("         0.3: {:x}", (abc.2).to_bits());
    println!();

    println!("xyz (f64)");
    println!("   0.1 + 0.2: {:x}", (xyz.0 + xyz.1).to_bits());
    println!("         0.3: {:x}", (xyz.2).to_bits());
    println!();

    assert!(abc.0 + abc.1 == abc.2);
    assert!(xyz.0 + xyz.1 == xyz.2);
}

// 程序运行输出:

// abc (f32)
//    0.1 + 0.2: 3e99999a
//          0.3: 3e99999a

// xyz (f64)
//    0.1 + 0.2: 3fd3333333333334
//          0.3: 3fd3333333333333

// thread 'main' panicked at 'assertion failed: xyz.0 + xyz.1 == xyz.2', example.rs:16:5
// note: run with `RUST_BACKTRACE=1` environment variable to display a backtrace
```

以上：

1. `f32`类型做加法时，`0.1 + 0.2`结果为`3e99999a`，`0.3`也为`3e99999a`
    - 因此`f32`下的`0.1 + 0.2 == 0.3`通过测试
2. `f64`类型做加法时，因为`f64`精度高很多，因此在小数点后面发生了一点微小的变化
    - `0.1 + 0.2`以`4`结尾，但`0.3` 以`3`结尾，这个细微区别导致`f64`下测试失败并抛出异常
3. 最后一行代码修改为`assert!((xyz.0 + xyz.1 - xyz.2).abs() < 0.0000001);`，则测试通过
    - 对于浮点数的判等需要使用差值来判断，差值小于多少取决于对精度的需求

**NaN**：

NaN(not a number)表示数学上未定义的结果。

> 1. 所有与`NaN`交互的操作，都会返回一个`NaN`
> 2. `NaN`不能用于比较，会导致崩溃
> 3. 出于防御性编程的考虑，可以使用`is_nan()`判断一个数值是否是`NaN`

### 数值运算

rust支持所有数字类型的基本数学运算：加减乘除和取模。

```rust
fn main() {
    // 编译器会进行自动推导，给予twenty i32类型
    let twenty = 20;

    // 类型标注
    let twenty_one: i32 = 21;

    // 通过类型后缀的方式进行类型标注：twenty_two和twenty_three都是i32类型
    let twenty_two = 22i32;
    let twenty_three = 23_i32;

    // 只有同样类型，才能运算
    let addition = twenty + twenty_one + twenty_two + twenty_three;
    println!("{} + {} + {} + {} = {}", twenty, twenty_one, twenty_two, twenty_three, addition);

    // 对于较长的数字，可以使用 _ 进行分割，提升可读性
    let one_million: i64 = 1_000_000;
    println!("{}", one_million.pow(2));

    // 定义一个f32数组，其中42.0会自动被推导为f32类型
    let forty_twos = [42.0, 42f32, 42.0_f32];

    // 打印数组中第一个值，并控制小数位为2位
    println!("{:.2}", forty_twos[0]);
}

// 程序输出：
// 20 + 21 + 22 + 23 = 86
// 1000000000000
// 42.00
```

### 位运算

rust位运算基本上和其他语言一样：

| 运算符  | 说明                                   |
| ------- | -------------------------------------- |
| & 位与  | 相同位置均为1时则为1，否则为0            |
| \| 位或 | 相同位置只要有1时则为1，否则为0        |
| ^ 异或  | 相同位置不相同则为1，相同则为0         |
| ! 位非  | 把位中的0和1相互取反，即0置为1，1置为0 |
| << 左移 | 所有位向左移动指定位数，右位补零       |
| >> 右移 | 所有位向右移动指定位数，左位补零       |

```rust
fn main() {
    // 二进制为00000010
    let a: i32 = 2;

    // 二进制为00000011
    let b: i32 = 3;

    println!("(a & b) value is {}", a & b);
    println!("(a | b) value is {}", a | b);
    println!("(a ^ b) value is {}", a ^ b);
    println!("(!b) value is {} ", !b);
    println!("(a << b) value is {}", a << b);
    println!("(a >> b) value is {}", a >> b);

    let mut a = a;
    a <<= b; // 位运算符除!外都可以加上=进行赋值(!=用于判断不等)
    println!("(a << b) value is {}", a);
}

// 程序输出：
// (a & b) value is 2
// (a | b) value is 3
// (a ^ b) value is 1
// (!b) value is -4
// (a << b) value is 16
// (a >> b) value is 0
// (a << b) value is 16
```

### 序列

序列只允许用于数字或字符类型，原因是：它们可以连续。

编译器在编译期可以检查该序列是否为空，字符和数字值是rust中仅有的可以用于判断是否为空的类型。

1. `a..b`：
    - 生成`[a, b)`区间的值，生成的序列值不包括b
2. `a..=b`：
    - 生成`[a, b]`区间的值，生成的序列值包括b

```rust
fn main() {
    for i in 1..5 { // 输出1~4
        println!("{}", i);
    }

    for i in 1..=5 { // 输出1~5
        println!("{}", i);
    }

    for i in 'a'..='z' { // 输出a~z
        println!("{}", i);
    }
}
```

### 有理数和复数

rust标准库相比其它语言准入门槛较高，因此有理数和复数并未包含在标准库中：

- 有理数和复数
- 任意大小的整数和任意精度的浮点数
- 固定精度的十进制小数，常用于货币相关的场景

社区rust数值库：[num](https://crates.io/crates/num)。

可以按照以下步骤来引入 `num` 库：

1. 创建新工程`cargo new complex-num && cd complex-num`
2. 在`Cargo.toml`中的`[dependencies]`下添加一行`num = "0.4.0"`
3. 将`src/main.rs`文件中的`main`函数替换为下面的代码
4. 运行 `cargo run`，过程中会自动下载依赖的数值库

```rust
use num::complex::Complex;

fn main() {
    let a = Complex { re: 2.1, im: -1.2 };
    let b = Complex::new(11.1, 22.2);

    let result = a + b;
    println!("{} + {}i", result.re, result.im)
}
```

### 字符类型

rust语言中所有`Unicode`值都可以作为rust字符。

`Unicode`值包括单个中文、日文、韩文、emoji表情符号等，这些都是合法的字符类型。

`Unicode`值的范围从`U+0000 ~ U+D7FF`和`U+E000 ~ U+10FFFF`。

由于`Unicode`都是4个字节编码，因此字符类型也是占用4个字节。

```rust
fn main() {
    let c = 'z';
    let z = 'ℤ';
    let g = '国';
    let heart_eyed_cat = '😻';

    println!("字符{}占用{}字节", c, std::mem::size_of_val(&c));
    println!("字符{}占用{}字节", z, std::mem::size_of_val(&z));
    println!("字符{}占用{}字节", g, std::mem::size_of_val(&g));
    println!("字符{}占用{}字节", heart_eyed_cat, std::mem::size_of_val(&heart_eyed_cat));
}

// 程序输出：
// 字符z占用4字节
// 字符ℤ占用4字节
// 字符国占用4字节
// 字符😻占用4字节
```

注意：rust中字符只能用`''`来表示，`""`用于表示字符串。

### 布尔

rust中布尔类型有两个可能的值：`true`和`false`，布尔值占用内存的大小为`1`个字节。

```rust
fn main() {
    let _t = false;
    let f: bool = true; // 使用类型标注,显式指定f的类型

    if f {
        println!("仅仅是为了打印"); // 字符串将会打印到终端
    }
}
```

### 单元类型

单元类型就是`()` ，唯一的值也是 `()`。

`main`函数就返回这个单元类型`()`。

没有返回值的函数在rust中定义为`发散函数(diverge function)`，即无法收敛的函数。

## 语句和表达式

rust函数体由一系列语句组成：

```rust
fn add_with_extra(x: i32, y: i32) -> i32 {
    let x = x + 1; // 语句
    let y = y + 5; // 语句
    x + y // 表达式
}
```

- 语句会执行一些操作但不会返回一个值，因此语句不能赋值给其它值
- 表达式会在求值后返回一个值

基于表达式是函数式语言的重要特征，**表达式总要返回值**。

表达式包括：

- 语句的一部分，如`let x = 5+6`，`5+6`是表达式
- 调用一个函数是表达式
- 调用宏是表达式
- 花括弧包括的语句块最终返回一个值是表达式

表达式不能以`;`结尾，以`;`结尾的是语句。

## 函数

```rust
fn add(i: i32, j: i32) -> i32 {
   i + j
}
```

如上：

声明函数的关键字是`fn`，函数名`add()`，参数`i`和`j`，参数类型和返回值类型都是`i32`。

<img alt="" src="https://pic2.zhimg.com/80/v2-54b3a6d435d2482243edc4be9ab98153_1440w.png" class="center"/>

**函数要点**：

- 函数名和变量名使用**蛇形命名法**
- 函数**定义位置随意**，rust不关心在什么位置定义函数，只要有定义即可
- 每个函数**参数都需要标注类型**
- 函数体最后一条表达式可以作为返回值，也可以使用`return`提前返回
- 函数没有指明返回值类型时会返回一个单元类型`()`(语句也会返回一个单元类型)
- `!`作为函数返回类型时，表示该函数永不返回(发散函数)，往往用于会导致程序崩溃的函数

```rust
use std::fmt::Debug;
fn report<T: Debug>(item: T) { // 隐式返回一个单元类型
    println!("{:?}", item);
}

fn clear(text: &mut String) -> () { // 显式返回一个单元类型
    *text = String::from("");
}

fn add(x:u32,y:u32) -> u32 { // 声明u32类型的返回值
    x + y; // 语句作为最后一行代码，则会报错
}

fn dead_end() -> ! { // 函数会导致程序崩溃，永不返回
    panic!("你已经到了穷途末路，崩溃吧！");
}

fn forever() -> ! { // 函数体是死循环，永不返回
    loop {
        //...
    };
}
```

## 所有权

各种语言中内存的申请和释放大概有以下三种：

> 1. **垃圾回收机制(GC)**：程序运行时不断寻找不再使用的内存，如Java、Go、Python
> 2. **手动管理内存的分配和释放**：程序运行时通过函数调用的方式来申请和释放内存，如C/C++
> 3. **通过所有权来管理内存**：编译器在编译时会根据一系列规则进行检查

rust使用了第3种，这种**检查只发生在编译期**，对于程序运行期不会有任何性能上的损失。

### 堆与栈

栈和堆是编程语言最核心的数据结构，值是位于栈上还是堆上会影响程序的行为和性能。

栈和堆的核心目标是为程序提供运行时可供使用的内存。

在堆上存取数据时，需要向操作系统申请内存，会返回一个表示该位置地址的**指针**, 此过程称为**在堆上分配内存**。

堆上分配内存返回的指针会被推入栈中，后续可通过该指针访问堆上内存。

**入栈比在堆上分配内存要快**，因为入栈时操作系统无需分配新的空间，只需将新数据放入栈顶。

得益于CPU高速缓存，处理器可以减少对内存的访问，高速缓存和内存的访问速度差异在10倍以上。

栈数据往往可以直接存储在CPU高速缓存中，而堆数据只能存储在内存中。

**访问堆上的数据比访问栈上的数据慢**，因为必须先访问栈再通过栈上的指针来访问内存。

### 所有权原则

> 1. rust中每个值都被一个变量拥有(变量是值的所有者)
> 2. 一个值在一个时刻只能被一个变量拥有
> 3. 当所有者离开作用域范围时，其值将被丢弃

### 变量作用域

rust变量作用域与其它语言没有区别。

### 转移所有权

变量所占用的内存可以从栈上或堆上分配，在堆上分配的内存的地址需要记录在栈上。

rust基本数据类型，是固定大小的简单值。

栈上的基本数据类型间的赋值是通过自动拷贝的方式来完成的，拷贝后存储在栈上，不需要在堆上分配内存。

有些数据类型不是基本类型，而且数据存储在堆上，此时不能自动拷贝，于是就有了**深拷贝**和**浅拷贝**。

深拷贝栈上和堆上的数据都会进行拷贝，拷贝后栈堆内存地址都与拷贝前的变量不一样。

浅拷贝只拷贝栈上的数据，拷贝后栈上所指向的堆内存地址一致。

当变量离开作用域后，rust会自动调用`drop`函数清理变量的堆内存。

假设两个变量指向同一块堆内存，当两个变量离开作用域后，两个变量都会尝试释放同一块内存，此时会产生**二次释放**。

二次释放会导致**内存污染**，可能会导致潜在的安全漏洞。

在rust中解决二次释放问题：**浅拷贝，使用一个变量给另一个变量赋值时，所有权会直接转移给新的变量，原变量失效**。

其实，此处的**浅拷贝称之为移动更能说明实际的意义**，也**更能呼应前面所说的变量绑定**。

### 克隆(深拷贝)

**rust不会自动深拷贝**，即任何**自动的复制都不是深拷贝**。

当需要复制堆上的数据时，可以使用`clone()`。

```rust
let s1 = String::from("hello");
let s2 = s1.clone();

println!("s1 = {}, s2 = {}", s1, s2);
```

代码性能无关紧要时可以使用`clone()`简化编程。

对于执行较为频繁的代码使用`clone()`会极大的降低程序性能，小心使用。

### 拷贝(浅拷贝)

浅拷贝只发生在栈上，因此性能很高。

rust中有个概念`Copy`特征，可以用于类似整型这样的在栈中存储的类型。

如果一个类型拥有`Copy`特征，一个旧的变量在被赋值给其他变量后仍然可用。

通用的规则： **任何基本类型的组合可以`Copy` ，不需要分配内存或某种形式资源的类型是可以`Copy` 的**。

- 所有整数类型，如：`u32`
- 布尔类型
- 所有浮点数类型，如：`f64`
- 字符类型
- 元组，当且仅当其包含的类型也都是可`Copy`时，如：`(i32, i32)`
- 不可变引用`&T`

### 函数传值与返回

将值传递给函数也会发生所有权转移和数据复制：

```rust
fn main() {
    let s = String::from("hello");  // s进入作用域

    takes_ownership(s);             // s的所有权转移到函数中，s不再有效

    let x = 5;                      // x进入作用域

    makes_copy(x);                  // x应该移动函数里，但x类型为i32，是可Copy的，因此之后x仍有效
} // 执行完成后x先移出作用域，s值已被移走，因此不会对s做特殊操作

fn takes_ownership(some_string: String) { // some_string进入作用域
    println!("{}", some_string);
} // some_string移出作用域，然后调用drop()方法释放内存

fn makes_copy(some_integer: i32) { // some_integer进入作用域
    println!("{}", some_integer);
} // some_integer移出作用域，栈上数据没有特殊操作
```

同样的，函数返回值也会发生所有权转移。

## 引用与借用

前面提到所有权转移，变量所有权转移到调用的函数后，该变量就失效了。

在实际编程中可能并不想让变量失效，此时就需要使用借用。

**获取变量的引用，称之为借用(borrowing)**。

### 引用与解引用

常规引用是一个指针类型，指向了对象存储的内存地址。

如下代码：

```rust
fn main() {
    let x = 5;
    let y = &x; // y是x的一个引用，&用于取x的引用

    assert_eq!(5, x);
    assert_eq!(5, *y); // *用于对y解引用
}
```

引用是一种类型，不能直接与原变量进行比较，必须解引用。

### 不可变引用

下面的代码，我们用`s1`的引用作为参数传递给`calculate_length`函数，而不是把`s1`的所有权转移给该函数：

```rust
fn main() {
    let s1 = String::from("hello");
    let len = calculate_length(&s1);

    println!("The length of '{}' is {}.", s1, len);
    // The length of 'hello' is 5.
}

fn calculate_length(s: &String) -> usize { // s是对String的引用
    s.len()
}
```

以上`&`符号即是引用，允许使用值，但不获取所有权。

### 可变引用

可变引用需要使用关键字`mut`，如：

```rust
fn main() {
    let mut s = String::from("hello"); // s为可变类型

    change(&mut s); // 创建可变引用

    println!("{}", s);
}

fn change(some_string: &mut String) { // 函数参数为可变引用
    some_string.push_str(", world");
}
```

**同一作用域，特定数据只能有一个可变引用**。

```rust
fn main() {
    let mut s = String::from("hello");

    let r1 = &mut s;
    let r2 = &mut s;

    println!("{}, {}", r1, r2);
}
```

以上代码会报错：

```console
error[E0499]: cannot borrow `s` as mutable more than once at a time
 --> example.rs:5:14
  |
4 |     let r1 = &mut s;
  |              ------ first mutable borrow occurs here
5 |     let r2 = &mut s;
  |              ^^^^^^ second mutable borrow occurs here
6 |
7 |     println!("{}, {}", r1, r2);
  |                        -- first borrow later used here

error: aborting due to previous error

For more information about this error, try `rustc --explain E0499`.
```

以上可变引用`r1`必须要持续到最后一次使用的位置，在最后一次使用之前，不能创建第二个可变引用。

这种限制使rust在编译期就能避免数据竞争。

数据竞争可由以下行为造成：

- 两个或更多的指针同时访问同一数据
- 至少有一个指针被用来写入数据
- 没有同步数据访问的机制

数据竞争会导致未定义行为，这种行为很可能超出预期，难以在运行时追踪，并且难以诊断和修复。

rust为了避免未定义行为就不编译存在数据竞争的代码。

### 可变引用与不可变引用不能同时存在

下面的代码会导致一个错误：

```rust
fn main() {
    let mut s = String::from("hello");

    let r1 = &s;
    let r2 = &s;
    let r3 = &mut s;

    println!("{}, {}, and {}", r1, r2, r3);
}
```

错误如下：

```console
error[E0502]: cannot borrow `s` as mutable because it is also borrowed as immutable
 --> example.rs:6:12
  |
4 |   let r1 = &s;
  |            -- immutable borrow occurs here
5 |   let r2 = &s;
6 |   let r3 = &mut s;
  |            ^^^^^^ mutable borrow occurs here
7 |
8 |   println!("{}, {}, and {}", r1, r2, r3);
  |                              -- immutable borrow later used here

error: aborting due to previous error

For more information about this error, try `rustc --explain E0502`.
```

> 引用的作用域是从创建开始，持续到最后一次使用的地方
> 变量的作用域是从创建持续到某一个花括号

### 悬垂引用

悬垂引用也叫做悬垂指针，意思为指针指向某个值后，这个值被释放掉了，而指针仍然存在。

悬垂引用指向的内存可能不存在任何值或已被其它变量重新使用。

在rust中编译器可以确保引用永远也不会变成悬垂状态：

**当拥有一些数据的引用时，编译器可以确保数据不会在其引用之前被释放，要想释放数据，必须先停止引用的使用**。

```rust
fn main() {
    let reference_to_nothing = dangle();
}

fn dangle() -> &String { // 返回字符串的引用
    let s = String::from("hello");

    &s // 返回局部变量的引用
} // 函数执行完成s的内存会被释放
```

这里会报错：

```text
error[E0106]: missing lifetime specifier
 --> example.rs:5:16
  |
5 | fn dangle() -> &String { // 返回局部变量的引用
  |                ^ expected named lifetime parameter
  |
  = help: this function's return type contains a borrowed value, but there is no value for it to be borrowed from
help: consider using the `'static` lifetime
  |
5 | fn dangle() -> &'static String { // 返回局部变量的引用
  |                ~~~~~~~~

error: aborting due to previous error

For more information about this error, try `rustc --explain E0106`.
```

其实，这里可以直接返回`String`类型，将所有权转移给调用者。

## 复合类型

复合类型是由其它类型组合而成的，如结构体`struct`和枚举`enum`。

如平面上的一个点`point(x, y)`，它由两个数值类型的值`x`和`y`组合而成。

```rust
#![allow(unused_variables)] // 忽略未使用的变量，不要抛出warning，是编译器属性标记
type File = String;

fn open(f: &mut File) -> bool {
    true
}
fn close(f: &mut File) -> bool {
    true
}

#[allow(dead_code)]
fn read(f: &mut File, save_to: &mut Vec<u8>) -> ! {
    unimplemented!() // 告诉编译器该函数尚未实现，类似todo!()，代码执行到未实现的地方时会直接报错
}

fn main() {
    let mut f1 = File::from("f1.txt");
    open(&mut f1);
    //read(&mut f1, &mut vec![]);
    close(&mut f1);
}
```

以上从代码设计角度看：

1. 关于文件操作的类型和函数比较分散，难以管理和使用
2. 通过`open(&mut f1)`进行调用，没有使用`f1.open()`调用好

可以看出只使用基本类型无法从更高的抽象层次去简化代码。

## 字符串

### 切片(slice)

切片就是对`String`类型中某一部分的引用。

```rust
let s = String::from("hello world");

let hello = &s[0..5]; // 创建切片，范围：[0, 5)，也可以写成[..5]
let world = &s[6..11]; // 创建切片，范围：[6, 11)，也可以写成[6..]
let hello_world = &s[..]; // 截取完整的String切片
```

注意：**切片的索引必须落在字符之间的边界位置，即UTF-8字符的边界**。

字符串切片的类型标识是`&str`，因此可以这样声明一个函数：

```rust
fn first_word(s: &String) -> &str // 输入String类型，返回切片
```

有了切片就可以写出这样的安全代码：

```rust
fn main() {
    let mut s = String::from("hello world");

    let word = first_word(&s); // 产生不可变引用

    s.clear(); // 产生可变引用

    println!("the first word is: {}", word); // 使用不可变引用
}

fn first_word(s: &String) -> &str {
    &s[..1]
}
```

编译器报错如下：

```console
error[E0502]: cannot borrow `s` as mutable because it is also borrowed as immutable
 --> example.rs:6:5
  |
4 |     let word = first_word(&s);
  |                           -- immutable borrow occurs here
5 |
6 |     s.clear();
  |     ^^^^^^^^^ mutable borrow occurs here
7 |
8 |     println!("the first word is: {}", word);
  |                                       ---- immutable borrow later used here

error: aborting due to previous error

For more information about this error, try `rustc --explain E0502`.
```

### 其它切片

因为切片是对集合的部分引用，因此不仅仅字符串有切片，其它集合类型也有，如数组：

```rust
let a = [1, 2, 3, 4, 5];

let slice = &a[1..3];

assert_eq!(slice, &[2, 3]);
```

该数组切片的类型是 `&[i32]`，数组切片和字符串切片的工作方式是一样的，例如持有一个引用指向原始数组的某个元素和长度。

### 字符串字面量是切片

```rust
let s1 = "Hello, world!";
let s2: &str = "Hello, world!";
```

以上s1和s2类型均为`&str`，为字符串字面量，是切片。

以上切片指向了程序可执行文件中的某个点，也说明字符串字面量是不可变的，`&str`是一个不可变引用。

### rust字符串

rust中字符是Unicode类型，因此每个字符大小为4个字节。

rust字符串是UTF-8编码，每个字符占1~4个字节，有助于大幅降低字符串所占用的内存空间。

rust在语言级别只有`str`一种字符串类型，通常以引用类型出现`&str`，即上文提到的字符串切片。

在标准库中还有多种不同用途的字符串类型，其中使用最广的即是`String`类型。

- `str`类型：
  1. 硬编码进可执行文件
  2. 无法被修改
  3. UTF-8编码
- `String`类型：
  1. 可增长、可改变、具有所有权
  2. UTF-8编码

### String 与 &str 的转换

`&str`转换为`String`：

1. `String::from("string")`
2. `"string".to_string()`

`&str`转换为`String`取引用即可，如：

```rust
fn main() {
    let s = String::from("hello,world!");
    say_hello(&s);
    say_hello(&s[..]);
    say_hello(s.as_str());
}

fn say_hello(s: &str) {
    println!("{}", s);
}
```

### 字符串索引

**字符串是不能索引的**。

在其它语言中，使用索引的方式访问字符串的某个字符或者子串是很正常的行为，但在rust中会报错:

```rust
fn main() {
    let s1 = String::from("hello");
    let h = s1[0];
}
```

以上代码会产生如下错误：

```console
error[E0277]: the type `String` cannot be indexed by `{integer}`
 --> example.rs:3:13
  |
3 |     let h = s1[0];
  |             ^^^^^ `String` cannot be indexed by `{integer}`
  |
  = help: the trait `Index<{integer}>` is not implemented for `String`
  = help: the following other types implement trait `Index<Idx>`:
            <String as Index<RangeFrom<usize>>>
            <String as Index<RangeFull>>
            <String as Index<RangeInclusive<usize>>>
            <String as Index<RangeTo<usize>>>
            <String as Index<RangeToInclusive<usize>>>
            <String as Index<std::ops::Range<usize>>>
            <str as Index<I>>

error: aborting due to previous error

For more information about this error, try `rustc --explain E0277`.
```

字符串底层的数据存储格式本质上是一个字节数组。

字符串采用UTF-8编码，每个字符占1~4个字节，占用多个字节时通过索引只返回其中一个字节是无法解析的。

### 操作字符串

#### 追加(push)

在字符串尾部可以：

- 使用`push()`方法追加字符`char`
- 使用`push_str()`方法追加字符串字面量

**以上两个方法都是在原有的字符串上追加，并不会返回新的字符串**。

追加操作会修改原字符串，则原字符串必须是可变的，即**字符串变量必须由`mut`关键字修饰**。

```rust
fn main() {
    let mut s = String::from("Hello ");
    s.push('r');
    println!("追加字符 push() -> {}", s); // 追加字符 push() -> Hello r

    s.push_str("ust!");
    println!("追加字符串 push_str() -> {}", s); // 追加字符串 push_str() -> Hello rust!
}
```

#### 插入(insert)

可以：

- 使用`insert()`方法插入单个字符
- 使用`insert_str()`方法插入字符串字面量

与`push()`方法不同，这俩方法需要传入两个参数：

1. 参数1：字符(串)插入位置的索引，索引从0开始计数(越界会发生错误)
2. 参数2：要插入的字符(串)

插入操作会修改原来的字符串，则原字符串必须是可变的，即**字符串变量必须由`mut`关键字修饰**。

```rust
fn main() {
    let mut s = String::from("史存!");
    s.insert(3, '玉');
    println!("插入字符 insert() -> {}", s); // 插入字符 insert() -> 史玉存!
    s.insert_str(9, ", try your best");
    println!("插入字符串 insert_str() -> {}", s); // 插入字符串 insert_str() -> 史玉存, try your best!
}
```

#### 替换(replace)

把字符串中的某个字符串替换成其它字符串，可以使用`replace()`方法。

替换相关的方法有三个：

1. `replace()`
2. `replacen()`
3. `replace_range()`

**方法1：`replace()`**

- 适用于`String`和`&str`类型
- 接收2个参数
  1. 参数1是要被替换的字符串
  2. 参数2是新的字符串
- 会替换所有匹配到的字符串
- 返回新字符串，而不是操作原字符串

```rust
fn main() {
    let string_replace = String::from("I like rust. Learning rust is my favorite!");
    let new_string_replace = string_replace.replace("rust", "RUST");
    dbg!(new_string_replace);
    // new_string_replace = "I like RUST. Learning RUST is my favorite!"
}
```

**方法2：`replacen()`**

- 适用于`String`和`&str`类型
- 接收3个参数
  1. 前2个参数与`replace()`方法一样
  2. 参数3表示替换的个数
- 返回新字符串，而不是操作原字符串

```rust
fn main() {
    let string_replace = String::from("I like rust. Learning rust is my favorite!");
    let new_string_replace = string_replace.replacen("rust", "RUST", 1);
    dbg!(new_string_replace);
    // new_string_replace = "I like RUST. Learning rust is my favorite!"
}
```

**方法3：`replace_range()`**

- 适用于`String`类型
- 接收两个参数
  1. 参数1是要替换字符串的范围
  2. 参数2是新的字符串
- 直接操作原字符串，不会返回新字符串，原字符串需要使用`mut`关键字修饰

```rust
fn main() {
    let mut string_replace_range = String::from("I like rust!");
    string_replace_range.replace_range(7..8, "R");
    dbg!(string_replace_range);
    // string_replace_range = "I like Rust!"
}
```

#### 删除(delete)

删除相关的方法有4个：

1. `pop`：删除并返回字符串的最后一个字符
    - 直接操作原字符串
    - 存在返回值，类型为`Option`，字符串为空时返回`None`
2. `remove`：删除并返回字符串中指定位置的字符
    - 直接操作原字符串
    - 存在返回值，为删除位置的字符串
    - 只接收一个参数，表示字符起始索引位置
    - 方法按照字节处理字符串，如果参数所给位置不是合法的字符边界会发生错误
3. `truncate`：删除字符串中从指定位置开始到结尾的全部字符
    - 直接操作原字符串
    - 无返回值
    - 方法按照字节处理字符串，如果参数所给位置不是合法的字符边界会发生错误
4. `clear`：清空字符串
    - 直接操作原字符串
    - 调用后，删除字符串中的所有字符(等同`truncate()`参数为0)

```rust
fn main() {
    let mut string_pop = String::from("rust pop 中文!");
    let p1 = string_pop.pop();
    let p2 = string_pop.pop();
    dbg!(p1);
    dbg!(p2);
    dbg!(string_pop);
}

// p1 = Some(
//     '!',
// )
// p2 = Some(
//     '文',
// )
// string_pop = "rust pop 中"
```

```rust
fn main() {
    let mut string_remove = String::from("测试remove方法");
    println!(
        "string_remove 占 {} 个字节",
        std::mem::size_of_val(string_remove.as_str())
    );
    // 直接删除第2个汉字
    let ch = string_remove.remove(3);
    dbg!(ch);

    dbg!(string_remove);

    // 下面代码会发生错误
    // string_remove.remove(1);
}

// string_remove 占 18 个字节
// ch = '试'
// string_remove = "测remove方法"
```

```rust
fn main() {
    let mut string_truncate = String::from("测试truncate");
    string_truncate.truncate(3);
    dbg!(string_truncate);
}

// string_truncate = "测"
```

```rust
fn main() {
    let mut string_clear = String::from("string clear");
    string_clear.clear();
    dbg!(string_clear);
}

// string_clear = ""
```

#### 连接(catenate)

**方法1：使用 `+` 或者 `+=` 连接字符串**。

使用`+`/`+=`连接字符串，要求右边的参数必须为字符串的切片引用。

当调用操作符`+`时，相当于调用`std::string`标准库中的`add()`方法。

`add()`方法的第2个参数是一个引用类型。

因此使用`+`时必须传递切片引用类型，不能直接传递`String`类型。

`+`和`+=`都会返回一个新的字符串，所以变量声明可以不使用`mut`关键字。

```rust
fn main() {
    let string_append = String::from("hello ");
    let string_rust = String::from("rust");

    let result = string_append + &string_rust; // &string_rust会自动解引用为&str

    let mut result = result + "!";
    result += "!!!";

    println!("连接字符串 + -> {}", result);
}

// 连接字符串 + -> hello rust!!!!
```

`add()`方法的原型：

```rust
fn add(self, s: &str) -> String // self是String字符串的对象实例
```

**方法2：使用`format!`连接字符串**。

`format!`这种方式适用于`String`和`&str`。

`format!` 的用法与 `print!` 的用法类似。

```rust
fn main() {
    let s1 = "hello";
    let s2 = String::from("rust");
    let s = format!("{} {}!", s1, s2);
    println!("{}", s);
}

// hello rust!
```

### 字符串转义

```rust
fn main() {
    // 1. 通过 \+字符的十六进制表示，转义输出一个字符
    let byte_escape = "I'm writing \x52\x75\x73\x74!";
    println!("What are you doing\x3F (\\x3F means ?) {}", byte_escape);

    // 2. \u 输出一个unicode字符
    let unicode_codepoint = "\u{211D}";
    let character_name = "\"DOUBLE-STRUCK CAPITAL R\"";

    println!(
        "Unicode character {} (U+211D) is called {}",
        unicode_codepoint, character_name
    );

    // 3. 通过\使换行后也保持之前的字符串格式
    let long_string = "String literals \
                      can span multiple lines. \
                      The linebreak and indentation here ->\
                      <- can be escaped too!";
    println!("{}", long_string);
}

// What are you doing? (\x3F means ?) I'm writing Rust!
// Unicode character ℝ (U+211D) is called "DOUBLE-STRUCK CAPITAL R"
// String literals can span multiple lines. The linebreak and indentation here -><- can be escaped too!
```

```rust
fn main() {
    // 1. 通过\转义\
    println!("{}", "hello \\x52\\x75\\x73\\x74");

    // 2. 通过r声明原始字符串，字符串中的\不再进行转义
    let raw_str = r"Escapes don't work here: \x3F \u{211D}";
    println!("{}", raw_str);

    // 3. 原始字符串中包含双引号时，可以在开头和结尾加#
    let quotes = r#"And then I said: "There is no escape!""#;
    println!("{}", quotes);

    // 4. 添加#后有歧义时，可以增加多个#，没有限制
    let longer_delimiter = r###"A string with "# in it. And even "##!"###;
    println!("{}", longer_delimiter);
}

// hello \x52\x75\x73\x74
// Escapes don't work here: \x3F \u{211D}
// And then I said: "There is no escape!"
// A string with "# in it. And even "##!
```

### 操作UTF-8字符串

```rust
fn main() {
    // 1. 按字符输出
    for c in "中国人".chars() {
        println!("{}", c);
    }

    // 按字节输出
    for c in "中国人".bytes() {
        println!("{}", c);
    }
}
```

### 获取子串

[utf8_slice](https://crates.io/crates/utf8_slice)

## 元组

元组是由多种类型组合到一起形成的，因此它是复合类型，元组的长度是固定的，元组中元素的顺序也是固定的。

可以通过以下语法创建一个元组：

```rust
fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);
}
```

变量 `tup` 被绑定了一个元组值 `(500, 6.4, 1)`，该元组的类型是 `(i32, f64, u8)`。

### 使用模式匹配解构元组

```rust
fn main() {
    let tup = (500, 6.4, 1);

    // 用同样的形式把一个复杂对象中的值匹配出来
    let (x, y, _) = tup;

    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
}

// The value of x is: 500
// The value of y is: 6.4
```

### 用`.`来访问元组

```rust
fn main() {
    let tup: (i32, f64, u8) = (500, 6.4, 1);

    // '.'后面接值在元组中的索引
    let x = tup.0;
    let y = tup.1;
    let z = tup.2;

    println!("The value of x is: {}", x);
    println!("The value of y is: {}", y);
    println!("The value of z is: {}", z);
}

// The value of x is: 500
// The value of y is: 6.4
// The value of z is: 1
```

## 结构体

结构体也是由多种类型组合而成。

与元组不同的是，结构体可以为内部的每个字段起一个富有含义的名称。

结构体更加灵活更加强大，无需像元组一样依赖这些字段的顺序进行访问和解析。

### 结构体语法

**定义结构体**：

```rust
struct User { // struct为关键字，User为结构体名称
    // 以下为各个字段，每个字段均由字段名和数据类型组成，中间使用':'分隔
    // 字段间使用','分隔
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}
```

**创建结构体实例**：

```rust
let user1 = User {
    email: String::from("someone@example.com"),
    username: String::from("someusername123"),
    active: true,
    sign_in_count: 1,
};

// 实例的每个字段都需要进行初始化
// 字段初始化顺序不需要和结构体定义顺序一致
```

**访问结构体字段**：

```rust
let mut user1 = User { // 结构体实例必须声明为mut才能修改字段，不支持单独声明某个字段为mut
    email: String::from("someone@example.com"),
    username: String::from("someusername123"),
    active: true,
    sign_in_count: 1,
};

// 通过'.'访问和修改结构体字段
user1.email = String::from("anotheremail@example.com");
```

**简化结构体创建**：

```rust
fn build_user(email: String, username: String) -> User {
    User {
        email: email,
        username: username,
        active: true,
        sign_in_count: 1,
    }
}
```

以上函数可以接收两个字符串参数，用于创建一个`User`结构并返回。

当函数参数和结构体字段同名时，可以直接使用缩略的方式进行初始化，如下：

```rust
fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 1,
    }
}
```

**结构体更新**：

```rust
let user2 = User {
    email: String::from("another@example.com"),
    ..user1 // '..'是结构更新语法
};
```

`user2`相对于`user1`只有`email`字段不一致，可以使用`..user1`初始化`user2`的其余字段。

`..`语法表明没有显式声明的字段全部从`user1`中自动获取，但`..user1` 必须在结构体的尾部使用。

结构体更新语法与赋值语句`=`非常相像，也会有所有权转移的问题，需要额外注意。

```rust
#[derive(Debug)]
struct User {
    active: bool,
    username: String,
    email: String,
    sign_in_count: u64,
}

fn main() {
    let user1 = User {
        email: String::from("someone@example.com"),
        username: String::from("someusername123"),
        active: true,
        sign_in_count: 1,
    };

    let user2 = User {
        email: String::from("another@example.com"),
        ..user1
    };

    println!("user2 --> {:?}", user2);
    println!("user2 --> {:#?}", user2);

    // 以下两句编译就会报错
    // println!("{:?}", user1);
    // println!("{}", user1.username);

    println!("{}", user1.email);
    println!("{}", user1.active);
    println!("{}", user1.sign_in_count);
}

// user2 --> User { active: true, username: "someusername123", email: "another@example.com", sign_in_count: 1 }
// user2 --> User {
//     active: true,
//     username: "someusername123",
//     email: "another@example.com",
//     sign_in_count: 1,
// }
// someone@example.com
// true
// 1
```

### 元组结构体

结构体必须要有名称，但是结构体的字段可以没有名称，这种结构体长得很像元组，因此被称为元组结构体，如：

```rust
struct Color(i32, i32, i32);
struct Point(i32, i32, i32);

let black = Color(0, 0, 0);
let origin = Point(0, 0, 0);
```

元组结构体在希望有一个整体名称，而又不关心字段名称时非常有用。

### 单元结构体

当定义一个类型但不关心该类型的内容, 只关心其行为时，可以使用单元结构体，如：

```rust
struct AlwaysEqual;

let subject = AlwaysEqual;

// 为单元结构实现特征
impl SomeTrait for AlwaysEqual {

}
```

## 枚举

### 枚举类型

```rust
// 定义枚举类型
#[derive(Debug)]
enum COLOR {
    WHITE,
    BLACK,
    RED,
    BLUE,
}

fn main() {
    // 定义枚举类型变量并初始化为枚举成员
    let black = COLOR::BLACK; // 通过"::"访问枚举成员
    println!("{:?}", black);
}

// BLACK
```

### 枚举值

```rust
#[derive(Debug)]
enum PokerCard {
    Clubs(u8),
    Spades(u8),
    Diamonds(u8),
    Hearts(u8),
}

fn main() {
    let c1 = PokerCard::Spades(5);
    let c2 = PokerCard::Diamonds(13);

    println!("{:?}", c1);
    println!("{:?}", c2);
}

// Spades(5)
// Diamonds(13)
```

```rust
use std::fmt::{self, Display, Formatter};

enum PokerCard {
    Clubs { v: u8 },
    Spades { v: u8 },
    Diamonds { v: u8 },
    Hearts { v: u8 },
}

impl Display for PokerCard {
    fn fmt(&self, f: &mut Formatter<'_>) -> fmt::Result {
        match self {
            Self::Clubs { v } => write!(f, "{}", v),
            Self::Spades { v } => write!(f, "{}", v),
            Self::Diamonds { v } => write!(f, "{}", v),
            Self::Hearts { v } => write!(f, "{}", v),
        }
    }
}

fn main() {
    let c1 = PokerCard::Spades { v: 5 };
    let c2 = PokerCard::Diamonds { v: 13 };

    println!("{}", c1);
    println!("{}", c2);
}

// 5
// 13
```

再来看一个来自标准库中的例子：

```rust
struct Ipv4Addr {
    // --snip--
}

struct Ipv6Addr {
    // --snip--
}

enum IpAddr {
    V4(Ipv4Addr),
    V6(Ipv6Addr),
}
```

以上是通过`Ipv4Addr`和`Ipv6Addr`来定义两种不同的IP数据。

从这些例子可以看出，**任何类型的数据都可以放入枚举成员中**：字符串、数值、结构体甚至另一个枚举。

```rust
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn main() {
    let m1 = Message::Quit;
    let m2 = Message::Move { x: 1, y: 1 };
    let m3 = Message::ChangeColor(255, 255, 0);
}
```

该枚举类型代表一条消息，它包含四个不同的成员：

- `Quit`没有任何关联数据
- `Move`包含一个匿名结构体
- `Write`包含一个`String`字符串
- `ChangeColor`包含三个`i32`

当然，也可以用结构体来定义这些消息：

```rust
struct QuitMessage; // 单元结构体
struct MoveMessage {
    x: i32,
    y: i32,
}
struct WriteMessage(String); // 元组结构体
struct ChangeColorMessage(i32, i32, i32); // 元组结构体
```

由于每个结构体都有自己的类型，因此无法在需要同一类型的地方进行使用。

例如某个函数的功能是接收消息并进行发送：

1. 用枚举时，可以接收不同的消息
2. 用结构体时，无法接收4个不同的结构体作为函数参数

从代码规范角度看，枚举的实现更简洁，代码内聚性更强，结构体的实现则会分散在各个地方。

### 用Option枚举处理空值

`Option`枚举包含两个成员：

1. `Some(T)`：表示含有值，T表示数据类型，可以说Some可以包含任何类型的数据
2. `None`：表示没有值

定义如下：

```rust
enum Option<T> {
    Some(T),
    None,
}
```

```rust
let some_number = Some(5);
let some_string = Some("a string");
let absent_number: Option<i32> = None;
```

使用`None`时需要显式声明`Option<T>`的类型，因为编译器通过`None`无法推断`Some`成员保存值的类型。

```rust
fn main() {
    let x: i8 = 5;
    let y: Option<i8> = Some(5);

    let sum = x + y;
}
```

运行以上代码，将得到以下错误信息：

```console
error[E0277]: cannot add `Option<i8>` to `i8`
 --> example.rs:5:17
  |
5 |     let sum = x + y;
  |                 ^ no implementation for `i8 + Option<i8>`
  |
  = help: the trait `Add<Option<i8>>` is not implemented for `i8`
  = help: the following other types implement trait `Add<Rhs>`:
            <&'a f32 as Add<f32>>
            <&'a f64 as Add<f64>>
            <&'a i128 as Add<i128>>
            <&'a i16 as Add<i16>>
            <&'a i32 as Add<i32>>
            <&'a i64 as Add<i64>>
            <&'a i8 as Add<i8>>
            <&'a isize as Add<isize>>
          and 48 others

error: aborting due to previous error

For more information about this error, try `rustc --explain E0277`.
```

以上错误信息意味着不知如何将`Option<i8>`与`i8`相加，因为类型不同。

当使用像`i8`这样的类型时，编译器会确保有一个有效的值，可以放心使用而无需空值检查。

当使用`Option<i8>`这样的类型时，需要做空值检查。

如何从`Some`成员中取出`T`值呢？

`Option<T>`枚举拥有大量用于各种情况的方法，可以查看[文档](https://doc.rust-lang.org/std/option/enum.Option.html)。

```rust
fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1),
    }
}

let five = Some(5);
let six = plus_one(five);
let none = plus_one(None);
```

## 数组

### 创建数组

```rust
fn main() {
    let a1 = [1, 2, 3, 4, 5];
    let a2: [i32; 5] = [1, 2, 3, 4, 5]; // i32表示元素类型，5表示元素个数
    let a3 = [3; 5]; // 数组有5个元素，每个元素的初始值都为3
}
```

### 访问数组元素

数组是连续存放元素的，可以通过索引的方式来访问元素：

```rust
fn main() {
    let a = [9, 8, 7, 6, 5];

    let first = a[0]; // 下标从0开始，获取第1个元素
    let second = a[1]; // 获取第2个元素
}
```

### 越界访问

访问了数组中不存在的元素，会导致rust运行时错误，程序会因此退出并显示错误消息。

使用索引访问元素时，rust将检查索引是否小于数组长度，如果索引大于或等于数组长度，rust会出现`_panic_`。

### 数组切片

```rust
let a: [i32; 5] = [1, 2, 3, 4, 5];

let slice: &[i32] = &a[1..3];

assert_eq!(slice, &[2, 3]);
```

上面的数组切片 `slice` 的类型是`&[i32]`，与之对比，数组的类型是`[i32;5]`，简单总结下切片的特点：

- 切片的长度可以与数组不同，并不是固定的，而是取决于你使用时指定的起始和结束位置
- 创建切片的代价非常小，因为切片只是针对底层数组的一个引用
- 切片类型[T]拥有不固定的大小，而切片引用类型&[T]则具有固定的大小
  - 因为rust很多时候都需要固定大小数据类型，因此&[T]更有用
  - `&str`字符串切片也同理

## 分支控制

### 使用if语句做分支控制

```rust
if condition == true {
    // A...
} else {
    // B...
}
```

```rust
fn main() {
    let condition = true;
    let number = if condition { 5 } else { 6 };
    println!("The value of number is: {}", number);
}
// if语句用于赋值时需要保证每个分支返回的类型一致，不一致时会报错
```

### 多重条件分支

```rust
fn main() {
    let n = 6;

    if n % 4 == 0 {
        println!("number is divisible by 4");
    } else if n % 3 == 0 {
        println!("number is divisible by 3");
    } else if n % 2 == 0 {
        println!("number is divisible by 2");
    } else {
        println!("number is not divisible by 4, 3, or 2");
    }
}
```

## 循环控制

### for循环

```rust
fn main() {
    for i in 1..=5 {
        println!("{}", i);
    }
}
```

```rust
for 元素 in 集合 {
  // ...
}
```

```rust
for item in &container {
  // ...
}
```

```rust
for item in &mut collection {
  // ...
}
```

**注意**：

1. 使用`for`时往往需要使用集合的引用形式，否则所有权会被转移到`for`语句块中
2. 对于实现了`copy`特征的数组，`for item in arr`并不会把`arr`的所有权转移，而是直接对其进行了拷贝
3. 需要在循环中修改该元素时，可以使用`mut`关键字

总结如下：

| 使用方法                      | 等价使用方式                                      | 所有权     |
| ----------------------------- | ------------------------------------------------- | ---------- |
| `for item in collection`      | `for item in IntoIterator::into_iter(collection)` | 转移所有权 |
| `for item in &collection`     | `for item in collection.iter()`                   | 不可变借用 |
| `for item in &mut collection` | `for item in collection.iter_mut()`               | 可变借用   |

**获取元素的索引**：

```rust
fn main() {
    let a = [4, 3, 2, 1];
    // 使用'.iter()'方法把a数组变成一个迭代器
    for (i, v) in a.iter().enumerate() {
        println!("第{}个元素是{}", i + 1, v);
    }
}
```

```rust
for _ in 0..10 {
  // ...
}
// '_'是占位符，可以不声明变量的情况下循环10次，如果声明变量却未使用编译器会有告警
```

**两种循环方式优劣对比**：

```rust
// 1. 循环索引，通过下标访问集合
let collection = [1, 2, 3, 4, 5];
for i in 0..collection.len() {
    let item = collection[i];
    // ...
}

// 2. 直接循环集合中的元素
for item in collection {
    // ...
}
```

- **性能**：
  - 第1种索引访问会进行边界检查导致运行时性能损耗
    - rust会检查并确认索引是否落在集合内
  - 第2种直接迭代的方式不会触发边界检查
    - 编译器会在编译时完成分析并证明访问是合法的
- **安全**：
  - 第1种索引访问是非连续的，存在一定可能性在两次访问之间，`collection`发生了变化，导致脏数据产生
  - 第2种直接迭代的方式是连续访问，因此不存在脏数据产生的风险

### `continue`

跳过当次循环，开始下次循环：

```rust
for i in 1..4 {
    if i == 2 {
        continue;
    }
    println!("{}", i);
}
```

### `break`

跳出当前整个循环：

```rust
for i in 1..4 {
    if i == 2 {
        break;
    }
    println!("{}", i);
}
```

### while循环

```rust
fn main() {
    let mut n = 0;

    while n <= 5 {
        println!("{}!", n);
        n = n + 1;
    }

    println!("我出来了！");
}
```

```rust
fn main() {
    let mut n = 0;

    loop {
        if n > 5 {
            break;
        }
        println!("{}", n);
        n += 1;
    }

    println!("我出来了！");
}
```

```rust
fn main() {
    let a = [10, 20, 30, 40, 50];
    let mut index = 0;

    while index < 5 { // 需要使用索引访问
        println!("the value is: {}", a[index]);
        index = index + 1;
    }
}
```

```rust
fn main() {
    let a = [10, 20, 30, 40, 50];

    for element in a.iter() {
        println!("the value is: {}", element);
    }
}
```

### loop循环

```rust
fn main() {
    let mut counter = 0;

    let result = loop {
        counter += 1;

        if counter == 10 {
            break counter * 2;
        }
    };

    println!("The result is {}", result);
}

// The result is 20
```

- **break可以单独使用，也可以带一个返回值**
- **loop是一个表达式，可以返回一个值**

## 模式匹配

### match匹配

通用形式：

```rust
match target { // target返回值可以是任意类型
    模式1 => 表达式1, // 不同分支间使用逗号分隔
    模式2 => { // 分支有多行代码时需要'{}'包裹
        语句1;
        语句2;
        表达式2 // 分支的最后一行可以是一个表达式，其结果作为match表达式的返回值
    },
    模式3 => 表达式3, // '=>'用于分隔模式与将要运行的代码
    _ => 表达式4 // '_'是通配符，当不想列出所有匹配值的时候使用
}
```

- `match`的匹配必须要穷举出所有可能，`_`用来代表未列出的所有可能性
- `match`的每一个分支都必须是一个表达式，且所有分支的表达式最终返回值的类型必须相同
- `X | Y`类似逻辑运算符`或`，代表该分支可以匹配`X`也可以匹配`Y`，只要满足一个即可

`match`类似于其他语言中的`switch`结构，`_`则类似于`default`分支。

```rust
enum Coin {
    Penny,
    Nickel,
    Dime,
    Quarter,
}

fn value_in_cents(coin: Coin) -> u8 {
    match coin {
        Coin::Penny => {
            println!("Lucky penny!");
            1
        }
        Coin::Nickel => 5,
        Coin::Dime => 10,
        Coin::Quarter => 25,
    }
}
```

`match`本身是一个表达式，因此可用来赋值。

```rust
enum IpAddr {
    Ipv4,
    Ipv6,
}

fn main() {
    let ip1 = IpAddr::Ipv6;

    let ip_str = match ip1 {
        IpAddr::Ipv4 => "127.0.0.1",
        _ => "::1",
    };

    println!("{}", ip_str);
}

// ::1
```

### 模式绑定

模式匹配可用于从模式中取出绑定的值。

```rust
enum Action {
    Say(String),
    MoveTo(i32, i32),
    ChangeColorRGB(u16, u16, u16),
}

fn main() {
    let actions = [
        Action::Say("Hello Rust".to_string()),
        Action::MoveTo(1, 2),
        Action::ChangeColorRGB(255, 255, 0),
    ];
    for action in actions {
        match action {
            Action::Say(s) => {
                println!("{}", s);
            }
            Action::MoveTo(x, y) => {
                println!("point from (0, 0) move to ({}, {})", x, y);
            }
            Action::ChangeColorRGB(r, g, _) => {
                println!("change color into '(r:{}, g:{}, b:0)'", r, g,);
            }
        }
    }
}

// Hello Rust
// point from (0, 0) move to (1, 2)
// change color into '(r:255, g:255, b:0)'
```

### if let匹配

当只要匹配一个条件且忽略其他条件时可以用`if let`匹配，使用`match`匹配会比较麻烦。

```rust
fn main() {
    let v = Some(3u8);
    if let Some(3) = v {
        println!("three");
    }
}

// three
```

### matches!宏

`matches!`是标准库中的宏，可以将一个表达式跟模式进行匹配，匹配的结果为`true`或`false`。

```rust
let foo = 'f';
assert!(matches!(foo, 'A'..='Z' | 'a'..='z'));

let bar = Some(4);
assert!(matches!(bar, Some(x) if x > 2));
```

### 变量覆盖

```rust
fn main() {
    let age = Some(30);
    println!("{:?}", age);

    if let Some(age) = age { // 在{}这个作用域中age=30，覆盖了使用Some(30)定义age
        println!("{}", age);
    } // 退出作用域后age=Some(30)

    println!("{:?}", age);
}

// Some(30)
// 30
// Some(30)
```

### 解构Option

枚举中提到Option用于解决空值问题：一个变量要么有值, 要么为空值。

```rust
enum Option<T> {
    Some(T),
    None,
}
```

`Option`、`Some`、`None`都包含在`prelude`中，可以直接通过名称来使用，无需以`Option::Some`这种形式使用。

`Some`、`None`也是`Option`下的枚举成员。

```rust
fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        None => None,
        Some(i) => Some(i + 1), // 模式绑定将Some中的值绑定到i上，进行i+1操作
    }
}

let five = Some(5);
let six = plus_one(five);
let none = plus_one(None);
```

## 模式适用场景

模式用于匹配类型中的结构和数据，往往和`match`表达式联用，以实现强大的模式匹配能力。

模式一般由以下内容组合而成：

- 字面值
- 解构的数组、枚举、结构体或者元组
- 变量
- 通配符
- 占位符

### match分支

```rust
match VALUE {
    PATTERN => EXPRESSION,
    PATTERN => EXPRESSION,
    _ => EXPRESSION,
}
```

### if let分支

`if let`往往用于匹配一个模式，而忽略剩下的所有模式：

```rust
if let PATTERN = SOME_VALUE {
}
```

### while let条件循环

`while let`允许只要模式匹配就一直进行`while`循环。

```rust
fn main() {
    // Vec是动态数组
    let mut stack = Vec::new();

    // 向数组尾部插入元素
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // stack.pop从数组尾部弹出元素
    while let Some(top) = stack.pop() {
        println!("{}", top);
    }
}
```

### for循环

```rust
fn main() {
    let v = vec!['a', 'b', 'c'];

    for (index, value) in v.iter().enumerate() {
        println!("{} is at index {}", value, index);
    }
}
```

### let语句

变量名也是一种模式，let语句本质上就是将匹配的值绑定到变量上。

```rust
let (x, y, z) = (1, 2, 3);
```

### 函数参数

```rust
fn print_coordinates(&(x, y): &(i32, i32)) {
    println!("Current location: ({}, {})", x, y);
}

fn main() {
    let point = (3, 5);
    print_coordinates(&point);
}
```

### if和if let

对于以下代码，编译器会报错：

```rust
let Some(x) = some_option_value; // 因为右边的值可能为None，这种时候就不能进行匹配了
```

类似`let`、`for`、`match`都必须要求完全覆盖匹配，才能通过编译(不可驳模式匹配)。

但对于`if let`，就可以这样使用：

```rust
if let Some(x) = some_option_value {
    println!("{}", x);
}
```

因为`if let`允许匹配一种模式，而忽略其余的模式(可驳模式匹配)。

## 全模式列表

### 匹配字面值

```rust
let x = 1;

match x {
    1 => println!("one"),
    2 => println!("two"),
    3 => println!("three"),
    _ => println!("anything"),
}
```

### 匹配命名变量

在 [match](https://course.rs/match-if-let.html#变量覆盖) 中，我们有讲过变量覆盖的问题，这个在**匹配命名变量**时会遇到：

```rust
fn main() {
    let x = Some(5);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(y) => println!("Matched, y = {:?}", y),
        _ => println!("Default case, x = {:?}", x),
    }

    println!("at the end: x = {:?}, y = {:?}", x, y);
}

// Matched, y = 5
// at the end: x = Some(5), y = 10
```

### 单分支多模式

```rust
let x = 1;

match x {
    1 | 2 => println!("one or two"), // | 表示或
    3 => println!("three"),
    _ => println!("anything"),
}
```

### 匹配范围

`..=`语法允许匹配一个闭区间序列内的值。

**序列只允许用于数字或字符类型**，因为它们可以连续，同时编译器在编译期可以检查该序列是否为空。

字符和数字值是rust中仅有的可以用于判断是否为空的类型。

```rust
fn main() {
    let x = 5;

    match x {
        1..=5 => println!("one through five"),
        _ => println!("something else"),
    }

    // match x {
    //     1..5 => println!("one through five"),
    //     _ => println!("something else"),
    // }

    // error[E0658]: exclusive range pattern syntax is experimental
    //   --> example.rs:10:9
    //   |
    // 10 |         1..5 => println!("one through five"),
    //   |         ^^^^
    //   |
    //   = note: see issue #37854 <https://github.com/rust-lang/rust/issues/37854> for more information

    // error: aborting due to previous error

    // For more information about this error, try `rustc --explain E0658`.
}

// one through five
```

```rust
fn main() {
    let x = 'c';

    match x {
        'a'..='j' => println!("early ASCII letter"),
        'k'..='z' => println!("late ASCII letter"),
        _ => println!("something else"),
    }
}

// early ASCII letter
```

### 解构结构体

```rust
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    let p = Point { x: 0, y: 7 };

    let Point { x: a, y: b } = p; // 创建变量a、b匹配结构体中的x、y
    assert_eq!(0, a);
    assert_eq!(7, b);

    let Point { x, y } = p; // 创建变量x、y匹配结构体中的x、y
    assert_eq!(0, x);
    assert_eq!(7, y);

    let Point { x: c, y: _ } = p; // 创建变量c匹配结构体中的x
    assert_eq!(0, c);
}
```

### 解构枚举

```rust
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

fn main() {
    let msg = Message::ChangeColor(0, 160, 255);

    match msg {
        Message::Quit => {
            println!("The Quit variant has no data to destructure.")
        }
        Message::Move { x, y } => {
            println!("Move in the x direction {} and in the y direction {}", x, y);
        }
        Message::Write(text) => println!("Text message: {}", text),
        Message::ChangeColor(r, g, b) => {
            println!("Change the color to red {}, green {}, and blue {}", r, g, b)
        }
    }
}

// Change the color to red 0, green 160, and blue 255
```

### 解构嵌套的结构体和枚举

```rust
enum Color {
    Rgb(i32, i32, i32),
    Hsv(i32, i32, i32),
}

enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(Color),
}

fn main() {
    let msg = Message::ChangeColor(Color::Hsv(0, 160, 255));

    match msg {
        Message::ChangeColor(Color::Rgb(r, g, b)) => {
            println!("Change the color to red {}, green {}, and blue {}", r, g, b);
        },
        Message::ChangeColor(Color::Hsv(h, s, v)) => {
            println!(
                "Change the color to hue {}, saturation {}, and value {}",
                h, s, v
            );
        },
        _ => (),
    }
}

// Change the color to hue 0, saturation 160, and value 255
```

### 解构结构体和元组

```rust
struct Point {
    x: i32,
    y: i32,
}

let ((feet, inches), Point {x, y}) = ((3, 10), Point { x: 3, y: -10 });
```

### 忽略模式中的值

#### 使用`_`忽略整个值

```rust
fn foo(_: i32, y: i32) {
    println!("This code only uses the y parameter: {}", y);
}

fn main() {
    foo(3, 4);
}
```

#### 使用嵌套的`_`忽略部分值

```rust
fn main() {
    let mut setting_value = Some(5);
    let new_setting_value = Some(10);

    match (setting_value, new_setting_value) {
        (Some(_), Some(_)) => {
            println!("Can't overwrite an existing customized value");
        }
        _ => {
            setting_value = new_setting_value;
        }
    }

    println!("setting is {:?}", setting_value);
}

// Can't overwrite an existing customized value
// setting is Some(5)
```

#### 下划线开头忽略未使用的变量

```rust
fn main() {
    let _x = 5;
    let y = 10;
}
```

```console
warning: unused variable: `y`
 --> example.rs:3:9
  |
3 |     let y = 10;
  |         ^ help: if this is intentional, prefix it with an underscore: `_y`
  |
  = note: `#[warn(unused_variables)]` on by default

warning: 1 warning emitted
```

#### 用`..`忽略剩余值

使用`..`必须是无歧义的。

如果期望匹配和忽略的值是不明确的，编译会报错。

```rust
struct Point {
    x: i32,
    y: i32,
    z: i32,
}

fn main() {
    let origin = Point { x: 0, y: 0, z: 0 };

    match origin {
        Point { x, .. } => println!("x is {}", x), // y、z忽略匹配
    }
}

// x is 0
```

```rust
fn main() {
    let numbers = (2, 4, 8, 16, 32);

    match numbers {
        (first, .., last) => {
            println!("Some numbers: {}, {}", first, last);
        }
    }
}

// Some numbers: 2, 32
```

### 匹配守卫提供的额外条件

匹配守卫是一个位于`match`分支模式之后的额外`if`条件，能为分支模式提供更进一步的匹配条件。

```rust
let num = Some(4);

match num {
    Some(x) if x < 5 => println!("less than five: {}", x),
    Some(x) => println!("{}", x),
    None => (),
}
```

```rust
fn main() {
    let x = Some(5);
    let y = 10;

    match x {
        Some(50) => println!("Got 50"),
        Some(n) if n == y => println!("Matched, n = {}", n),
        _ => println!("Default case, x = {:?}", x),
    }

    println!("at the end: x = {:?}, y = {}", x, y);
}

// Default case, x = Some(5)
// at the end: x = Some(5), y = 10
```

```rust
fn main() {
    let x = 4;
    let y = false;

    match x {
        4 | 5 | 6 if y => println!("yes"), // (4 | 5 | 6) if y => ...
        _ => println!("no"),
    }
}

// no
```

### @绑定

`@`运算符允许为一个字段绑定另外一个变量。

当想要限定分支范围的同时又想要使用分支的变量时，就可以用`@`来绑定到一个新的变量上。

```rust
fn main() {
    enum Message {
        Hello { id: i32 },
    }

    let msg = Message::Hello { id: 5 };

    match msg {
        Message::Hello {
            id: id_variable @ 3..=7, // 匹配范围内的值并同时将该值绑定到id_variable
        } => {
            println!("Found an id in range: {}", id_variable)
        }
        Message::Hello { id: 10..=12 } => {
            println!("Found an id in another range")
        }
        Message::Hello { id } => {
            println!("Found some other id: {}", id)
        }
    }
}

// Found an id in range: 5
```

#### @前绑定后解构(rust-1.56新增)

使用 `@` 还可以在绑定新变量的同时，对目标进行解构：

```rust
#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

fn main() {
    // 绑定新变量p，同时对Point进行解构
    let p @ Point { x: px, y: py } = Point { x: 10, y: 23 };
    println!("x: {}, y: {}", px, py);
    println!("{:?}", p);

    let point = Point { x: 10, y: 5 };
    if let p @ Point { x: 10, y } = point {
        println!("x is 10 and y is {} in {:?}", y, p);
    } else {
        println!("x was not 10 :(");
    }
}

// x: 10, y: 23
// Point { x: 10, y: 23 }
// x is 10 and y is 5 in Point { x: 10, y: 5 }
```

#### @新特性(rust-1.53新增)

```rust
fn main() {
    match 1 {
        num @ 1 | 2 => { // 只将1绑定到了num上，2未绑定
            println!("{}", num);
        }
        _ => {}
    }
}
```

编译错误信息：

```console
error[E0408]: variable `num` is not bound in all patterns
 --> example.rs:3:19
  |
3 |         num @ 1 | 2 => {
  |         ---       ^ pattern doesn't bind `num`
  |         |
  |         variable not in all patterns

error: aborting due to previous error

For more information about this error, try `rustc --explain E0408`.
```

修改：

```rust
num @ (1 | 2)
```

## 方法

## 定义方法

rust使用关键字`impl`定义方法：

```rust
struct Circle {
    x: f64,
    y: f64,
    radius: f64,
}

impl Circle { // implementation的缩写
    // new是Circle的关联函数，因为它的第一个参数不是self
    // 这种方法往往用于初始化当前结构体的实例
    fn new(x: f64, y: f64, radius: f64) -> Circle {
        Circle {
            x: x,
            y: y,
            radius: radius,
        }
    }

    // Circle的方法，&self表示借用当前的Circle结构体
    fn area(&self) -> f64 {
        std::f64::consts::PI * (self.radius * self.radius)
    }
}
```

以上，对象定义和方法定义是分离的，这种分离方式能给予使用者极高的灵活度。

```rust
#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    println!(
        "The area of the rectangle is {} square pixels.",
        rect1.area()
    );
}

// The area of the rectangle is 1500 square pixels.
```

### self

接下里的内容非常重要，请大家仔细看。在 `area` 的签名中，我们使用 `&self` 替代 `rectangle: &Rectangle`，`&self` 其实是 `self: &Self` 的简写（注意大小写）。在一个 `impl` 块内，`Self` 指代被实现方法的结构体类型，`self` 指代此类型的实例，换句话说，`self` 指代的是 `Rectangle` 结构体实例，这样的写法会让我们的代码简洁很多，而且非常便于理解：我们为哪个结构体实现方法，那么 `self` 就是指代哪个结构体的实例。

需要注意的是，`self` 依然有所有权的概念：

- `self` 表示 `Rectangle` 的所有权转移到该方法中，这种形式用的较少
- `&self` 表示该方法对 `Rectangle` 的不可变借用
- `&mut self` 表示可变借用

总之，`self` 的使用就跟函数参数一样，要严格遵守 Rust 的所有权规则。

回到上面的例子中，选择 `&self` 的理由跟在函数中使用 `&Rectangle` 是相同的：我们并不想获取所有权，也无需去改变它，只是希望能够读取结构体中的数据。如果想要在方法中去改变当前的结构体，需要将第一个参数改为 `&mut self`。仅仅通过使用 `self` 作为第一个参数来使方法获取实例的所有权是很少见的，这种使用方式往往用于把当前的对象转成另外一个对象时使用，转换完后，就不再关注之前的对象，且可以防止对之前对象的误调用。

简单总结下，使用方法代替函数有以下好处：

- 不用在函数签名中重复书写 `self` 对应的类型
- 代码的组织性和内聚性更强，对于代码维护和阅读来说，好处巨大

#### 方法名跟结构体字段名相同

在 Rust 中，允许方法名跟结构体的字段名相同：

```rust
impl Rectangle {
    fn width(&self) -> bool {
        self.width > 0
    }
}

fn main() {
    let rect1 = Rectangle {
        width: 30,
        height: 50,
    };

    if rect1.width() {
        println!("The rectangle has a nonzero width; it is {}", rect1.width);
    }
}
```

当我们使用 `rect1.width()` 时，Rust 知道我们调用的是它的方法，如果使用 `rect1.width`，则是访问它的字段。

一般来说，方法跟字段同名，往往适用于实现 `getter` 访问器，例如:

```rust
pub struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    pub fn new(width: u32, height: u32) -> Self {
        Rectangle { width, height }
    }
    pub fn width(&self) -> u32 {
        return self.width;
    }
}

fn main() {
    let rect1 = Rectangle::new(30, 50);

    println!("{}", rect1.width());
}
```

用这种方式，我们可以把 `Rectangle` 的字段设置为私有属性，只需把它的 `new` 和 `width` 方法设置为公开可见，那么用户就可以创建一个矩形，同时通过访问器 `rect1.width()` 方法来获取矩形的宽度，因为 `width` 字段是私有的，当用户访问 `rect1.width` 字段时，就会报错。注意在此例中，`Self` 指代的就是被实现方法的结构体 `Rectangle`。

> ### `->` 运算符到哪去了？
>
> 在 C/C++ 语言中，有两个不同的运算符来调用方法：`.` 直接在对象上调用方法，而 `->` 在一个对象的指针上调用方法，这时需要先解引用指针。换句话说，如果 `object` 是一个指针，那么 `object->something()` 和 `(*object).something()` 是一样的。
>
> Rust 并没有一个与 `->` 等效的运算符；相反，Rust 有一个叫 **自动引用和解引用**的功能。方法调用是 Rust 中少数几个拥有这种行为的地方。
>
> 他是这样工作的：当使用 `object.something()` 调用方法时，Rust 会自动为 `object` 添加 `&`、`&mut` 或 `*` 以便使 `object` 与方法签名匹配。也就是说，这些代码是等价的：
>
> ```rust
> # #[derive(Debug,Copy,Clone)]
> # struct Point {
> #     x: f64,
> #     y: f64,
> # }
> #
> # impl Point {
> #    fn distance(&self, other: &Point) -> f64 {
> #        let x_squared = f64::powi(other.x - self.x, 2);
> #        let y_squared = f64::powi(other.y - self.y, 2);
> #
> #        f64::sqrt(x_squared + y_squared)
> #    }
> # }
> # let p1 = Point { x: 0.0, y: 0.0 };
> # let p2 = Point { x: 5.0, y: 6.5 };
> p1.distance(&p2);
> (&p1).distance(&p2);
> ```
>
> 第一行看起来简洁的多。这种自动引用的行为之所以有效，是因为方法有一个明确的接收者———— `self` 的类型。在给出接收者和方法名的前提下，Rust 可以明确地计算出方法是仅仅读取（`&self`），做出修改（`&mut self`）或者是获取所有权（`self`）。事实上，Rust 对方法接收者的隐式借用让所有权在实践中更友好。

## 带有多个参数的方法

方法和函数一样，可以使用多个参数：

```rust
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

fn main() {
    let rect1 = Rectangle { width: 30, height: 50 };
    let rect2 = Rectangle { width: 10, height: 40 };
    let rect3 = Rectangle { width: 60, height: 45 };

    println!("Can rect1 hold rect2? {}", rect1.can_hold(&rect2));
    println!("Can rect1 hold rect3? {}", rect1.can_hold(&rect3));
}
```

## 关联函数

现在大家可以思考一个问题，如何为一个结构体定义一个构造器方法？也就是接受几个参数，然后构造并返回该结构体的实例。其实答案在开头的代码片段中就给出了，很简单，不使用 `self` 中即可。

这种定义在 `impl` 中且没有 `self` 的函数被称之为**关联函数**： 因为它没有 `self`，不能用 `f.read()` 的形式调用，因此它是一个函数而不是方法，它又在`impl` 中，与结构体紧密关联，因此称为关联函数。

在之前的代码中，我们已经多次使用过关联函数，例如 `String::from`，用于创建一个动态字符串。

```rust
# #[derive(Debug)]
# struct Rectangle {
#     width: u32,
#     height: u32,
# }
#
impl Rectangle {
    fn new(w: u32, h: u32) -> Rectangle {
        Rectangle { width: w, height: h }
    }
}
```

> Rust 中有一个约定俗称的规则，使用 `new` 来作为构造器的名称，出于设计上的考虑，Rust 特地没有用 `new` 作为关键字

因为是函数，所以不能用 `.` 的方式来调用，我们需要用 `::` 来调用，例如 `let sq = Rectangle::new(3, 3);`。这个方法位于结构体的命名空间中：`::` 语法用于关联函数和模块创建的命名空间。

## 多个 impl 定义

Rust 允许我们为一个结构体定义多个 `impl` 块，目的是提供更多的灵活性和代码组织性，例如当方法多了后，可以把相关的方法组织在同一个 `impl` 块中，那么就可以形成多个 `impl` 块，各自完成一块儿目标：

```rust
# #[derive(Debug)]
# struct Rectangle {
#     width: u32,
#     height: u32,
# }
#
impl Rectangle {
    fn area(&self) -> u32 {
        self.width * self.height
    }
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}
```

当然，就这个例子而言，我们没必要使用两个 `impl` 块，这里只是为了演示方便。

## 为枚举实现方法

枚举类型之所以强大，不仅仅在于它好用、可以[同一化类型](https://course.rs/basic/compound-type/enum.html#同一化类型)，还在于，我们可以像结构体一样，为枚举实现方法：

```rust
#![allow(unused)]
fn main() {
enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    ChangeColor(i32, i32, i32),
}

impl Message {
    fn call(&self) {
        // 在这里定义方法体
    }
}

let m = Message::Write(String::from("hello"));
m.call();
}
```

除了结构体和枚举，我们还能为特征(trait)实现方法，这将在下一章进行讲解，在此之前，先来看看泛型。

## 代码的组织管理

### 相关概念

**包**(Crate)：

- 包是一个独立的可编译单元，编译后可生成可执行文件或库
- 一个包可以将相关联的功能打包在一起，使功能可以在多个项目中分享
- 同一个包中不能有同名的类型，不同的包中可以有

**项目**(Package)，也可以称为工程或软件包：

- 一个项目包含独立的`Cargo.toml`文件以及因为功能被组织在一起的一个或多个包
- 一个项目只能包含一个库(library)类型的包
- 一个项目可以包含多个可执行类型的包

上面cargo使用举例创建了项目`notes_rust_code`：

- 项目中包含了`Cargo.toml`文件
- 文件中并没有提到`src/main.rs`作为程序的入口，因为惯例：
  - `src/main.rs`是二进制包的根文件，该二进制包的包名跟所属项目相同
  - 在这里二进制包的包名都是`notes_rust_code`
  - 所有的代码执行都从`src/main.rs`的`fn main()`开始执行

库类型的项目只能作为三方库被其它项目引用，而不能独立运行。

与`src/main.rs`一样，如果一个项目包含有`src/lib.rs`，即项目包含有一个库类型的同名包，包的根文件是`src/lib.rs`。

上面cargo使用举例创建了项目`notes_rust_lib`，项目名即为包名。

注意：

1. 上面使用`cargo new`创建的项目和它其中包含的包是同名的
2. 包是一个编译单元
3. 项目同时有`src/main.rs`和`src/lib.rs`时，则项目同时包含库包和二进制包，包名也都为项目名
4. 项目包含多个二进制包时，包文件需要放在`src/bin`目录下，每个文件都是独立的二进制包

如下，一个真实项目的典型结构：

```text
.
├── Cargo.toml
├── Cargo.lock
├── src
│   ├── main.rs
│   ├── lib.rs
│   └── bin
│       └── main1.rs
│       └── main2.rs
├── tests
│   └── some_integration_tests.rs
├── benches
│   └── simple_bench.rs
└── examples
    └── simple_example.rs
```

- `src/lib.rs`：唯一库包
- `src/main.rs`：默认二进制包
- `src/bin/main1.rs` `src/bin/main2.rs`：其余二进制包，分别生成可执行程序
- `tests`目录：集成测试文件
- `benches`目录：基准性能测试benchmark文件
- `examples`目录：项目示例

- 箱(Crate)：
  - 二进制程序文件或者库文件，存在于包中
  - 树状结构，树根是编译器开始运行时编译的源文件所编译的程序
- 包(Package)：
  - 整个工程的实质就是一个包
  - 包必须由一个`Cargo.toml`文件来管理，该文件描述了包的基本信息以及依赖项
- 模块(Module)：
  - Rust中的组织单位是模块(Module)
  - 一个Rust文件的内容属于一个模块，文件名是模块的名字

## 附录

### 关键字

https://course.rs/appendix/keywords.html

### 命名规范

https://course.rs/practice/naming.html

### 运算符

https://course.rs/appendix/operators.html#%E8%BF%90%E7%AE%97%E7%AC%A6

### 编译器属性标记

https://course.rs/profiling/compiler/attributes.html
