
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
    - [变量解构](#变量解构)
      - [解构式赋值](#解构式赋值)
    - [变量和常量之间的差异](#变量和常量之间的差异)
    - [变量遮蔽(shadowing)](#变量遮蔽shadowing)
  - [基本类型](#基本类型)
  - [函数](#函数)
  - [代码的组织管理](#代码的组织管理)
    - [相关概念](#相关概念)
  - [附录](#附录)
    - [关键字](#关键字)
    - [命名规范](#命名规范)

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

```rust
fn main() {
    let x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}
```

保存文件，再使用 `cargo run` 运行它，迎面而来的是一条错误提示：

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
error[E0384]: cannot assign twice to immutable variable `x`
 --> src/main.rs:4:5
  |
2 |     let x = 5;
  |         -
  |         |
  |         first assignment to `x`
  |         help: consider making this binding mutable: `mut x`
3 |     println!("The value of x is: {}", x);
4 |     x = 6;
  |     ^^^^^ cannot assign twice to immutable variable

error: aborting due to previous error
```

具体的错误原因是 `cannot assign twice to immutable variable x`（无法对不可变的变量进行重复赋值），因为我们想为不可变的 `x` 变量再次赋值。

这种错误是为了避免无法预期的错误发生在我们的变量上：一个变量往往被多处代码所使用，其中一部分代码假定该变量的值永远不会改变，而另外一部分代码却无情的改变了这个值，在实际开发过程中，这个错误是很难被发现的，特别是在多线程编程中。

这种规则让我们的代码变得非常清晰，只有你想让你的变量改变时，它才能改变，这样就不会造成心智上的负担，也给别人阅读代码带来便利。

但是可变性也非常重要，否则我们就要像 ClojureScript 那样，每次要改变，就要重新生成一个对象，在拥有大量对象的场景，性能会变得非常低下，内存拷贝的成本异常的高。

在 Rust 中，可变性很简单，只要在变量名前加一个 `mut` 即可, 而且这种显式的声明方式还会给后来人传达这样的信息：嗯，这个变量在后面代码部分会发生改变。

为了让变量声明为可变,将 _src/main.rs_ 改为以下内容：

```rust
fn main() {
    let mut x = 5;
    println!("The value of x is: {}", x);
    x = 6;
    println!("The value of x is: {}", x);
}
```

运行程序将得到下面结果：

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
    Finished dev [unoptimized + debuginfo] target(s) in 0.30s
     Running `target/debug/variables`
The value of x is: 5
The value of x is: 6
```

选择可变还是不可变，更多的还是取决于你的使用场景，例如不可变可以带来安全性，但是丧失了灵活性和性能（如果你要改变，就要重新创建一个新的变量，这里涉及到内存对象的再分配）。而可变变量最大的好处就是使用上的灵活性和性能上的提升。

例如，在使用大型数据结构或者热点代码路径（被大量频繁调用）的情形下，在同一内存位置更新实例可能比复制并返回新分配的实例要更快。使用较小的数据结构时，通常创建新的实例并以更具函数式的风格来编写程序，可能会更容易理解，所以值得以较低的性能开销来确保代码清晰。

### 使用下划线开头忽略未使用的变量

如果你创建了一个变量却不在任何地方使用它，Rust 通常会给你一个警告，因为这可能会是个 BUG。但是有时创建一个不会被使用的变量是有用的，比如你正在设计原型或刚刚开始一个项目。这时**你希望告诉 Rust 不要警告未使用的变量，为此可以用下划线作为变量名的开头**：

```rust
fn main() {
    let _x = 5;
    let y = 10;
}
```

使用 `cargo run` 运行下试试:

```shell
warning: unused variable: `y`
 --> src/main.rs:3:9
  |
3 |     let y = 10;
  |         ^ help: 如果 y 故意不被使用，请添加一个下划线前缀: `_y`
  |
  = note: `#[warn(unused_variables)]` on by default
```

可以看到，两个变量都是只有声明，没有使用，但是编译器却独独给出了 `y` 未被使用的警告，充分说明了 `_` 变量名前缀在这里发挥的作用。

值得注意的是，这里编译器还很善意的给出了提示( Rust 的编译器非常强大，这里的提示只是小意思 ): 将 `y` 修改 `_y` 即可。这里就不再给出代码，留给大家手动尝试并观察下运行结果。

更多关于 `_x` 的使用信息，请阅读后面的[模式匹配章节](https://course.rs/basic/match-pattern/all-patterns.html?highlight=_#使用下划线开头忽略未使用的变量)。

### 变量解构

`let` 表达式不仅仅用于变量的绑定，还能进行复杂变量的解构：从一个相对复杂的变量中，匹配出该变量的一部分内容：

```rust
fn main() {
    let (a, mut b): (bool,bool) = (true, false);
    // a = true,不可变; b = false，可变
    println!("a = {:?}, b = {:?}", a, b);

    b = true;
    assert_eq!(a, b);
}
```

#### 解构式赋值

在 [Rust 1.59](https://course.rs/appendix/rust-versions/1.59.html) 版本后，我们可以在赋值语句的左式中使用元组、切片和结构体模式了。

```rust
struct Struct {
    e: i32
}

fn main() {
    let (a, b, c, d, e);

    (a, b) = (1, 2);
    // _ 代表匹配一个值，但是我们不关心具体的值是什么，因此没有是一个变量名而是使用了 _
    [c, .., d, _] = [1, 2, 3, 4, 5];
    Struct { e, .. } = Struct { e: 5 };

    assert_eq!([1, 2, 1, 4, 5], [a, b, c, d, e]);
}
```

这种使用方式跟之前的 `let` 保持了一致性，但是 `let` 会重新绑定，而这里仅仅是对之前绑定的变量进行再赋值。

需要注意的是，使用 `+=` 的赋值语句还不支持解构式赋值。

> 这里用到了模式匹配的一些语法，如果大家看不懂没关系，可以在学完模式匹配章节后，再回头来看。

### 变量和常量之间的差异

变量的值不能更改可能让你想起其他另一个很多语言都有的编程概念：**常量**(_constant_)。与不可变变量一样，常量也是绑定到一个常量名且不允许更改的值，但是常量和变量之间存在一些差异：

- 常量不允许使用 `mut`。**常量不仅仅默认不可变，而且自始至终不可变**，因为常量在编译完成后，已经确定它的值。
- 常量使用 `const` 关键字而不是 `let` 关键字来声明，并且值的类型**必须**标注。

我们将在下一节[数据类型](https://course.rs/basic/base-type/index.html)中介绍，因此现在暂时无需关心细节。

下面是一个常量声明的例子，其常量名为 `MAX_POINTS`，值设置为 `100,000`。（Rust 常量的命名约定是全部字母都使用大写，并使用下划线分隔单词，另外对数字字面量可插入下划线以提高可读性）：

```rust
const MAX_POINTS: u32 = 100_000;
```

常量可以在任意作用域内声明，包括全局作用域，在声明的作用域内，常量在程序运行的整个过程中都有效。对于需要在多处代码共享一个不可变的值时非常有用，例如游戏中允许玩家赚取的最大点数或光速。

> 在实际使用中，最好将程序中用到的硬编码值都声明为常量，对于代码后续的维护有莫大的帮助。如果将来需要更改硬编码的值，你也只需要在代码中更改一处即可。

### 变量遮蔽(shadowing)

Rust 允许声明相同的变量名，在后面声明的变量会遮蔽掉前面声明的，如下所示：

```rust
fn main() {
    let x = 5;
    // 在main函数的作用域内对之前的x进行遮蔽
    let x = x + 1;

    {
        // 在当前的花括号作用域内，对之前的x进行遮蔽
        let x = x * 2;
        println!("The value of x in the inner scope is: {}", x);
    }

    println!("The value of x is: {}", x);
}
```

这个程序首先将数值 `5` 绑定到 `x`，然后通过重复使用 `let x =` 来遮蔽之前的 `x`，并取原来的值加上 `1`，所以 `x` 的值变成了 `6`。第三个 `let` 语句同样遮蔽前面的 `x`，取之前的值并乘上 `2`，得到的 `x` 最终值为 `12`。当运行此程序，将输出以下内容：

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
   ...
The value of x in the inner scope is: 12
The value of x is: 6
```

这和 `mut` 变量的使用是不同的，第二个 `let` 生成了完全不同的新变量，两个变量只是恰好拥有同样的名称，涉及一次内存对象的再分配
，而 `mut` 声明的变量，可以修改同一个内存地址上的值，并不会发生内存对象的再分配，性能要更好。

变量遮蔽的用处在于，如果你在某个作用域内无需再使用之前的变量（在被遮蔽后，无法再访问到之前的同名变量），就可以重复的使用变量名字，而不用绞尽脑汁去想更多的名字。

例如，假设有一个程序要统计一个空格字符串的空格数量：

```rust
// 字符串类型
let spaces = "   ";
// usize数值类型
let spaces = spaces.len();
```

这种结构是允许的，因为第一个 `spaces` 变量是一个字符串类型，第二个 `spaces` 变量是一个全新的变量且和第一个具有相同的变量名，且是一个数值类型。所以变量遮蔽可以帮我们节省些脑细胞，不用去想如 `spaces_str` 和 `spaces_num` 此类的变量名；相反我们可以重复使用更简单的 `spaces` 变量名。如果你不用 `let` :

```rust,
let mut spaces = "   ";
spaces = spaces.len();
```

运行一下，你就会发现编译器报错：

```console
$ cargo run
   Compiling variables v0.1.0 (file:///projects/variables)
error[E0308]: mismatched types
 --> src/main.rs:3:14
  |
3 |     spaces = spaces.len();
  |              ^^^^^^^^^^^^ expected `&str`, found `usize`

error: aborting due to previous error
```

显然，Rust 对类型的要求很严格，不允许将整数类型 `usize` 赋值给字符串类型。`usize` 是一种 CPU 相关的整数类型，在[数值类型](https://course.rs/basic/base-type/numbers.html#整数类型)中有详细介绍。

万事开头难，到目前为止，都进展很顺利，那下面开始，咱们正式进入 Rust 的类型世界，看看有哪些挑战在前面等着大家。

## 基本类型

## 函数


模块







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
