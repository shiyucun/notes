
# IWYU

- [IWYU](#iwyu)
  - [优点](#优点)
  - [编译安装](#编译安装)
  - [使用](#使用)

include-what-you-use，简称 IWYU，是 Google 推出的用来检查头文件冗余的工具。

IWYU 可以分辨出 #include 中哪些是当前文件完全没有用到的，以及哪些可以使用前置声明来替代 #include。

大型项目中经过一段时间的开发过程，经常会有间接引用的问题。

间接引用的情况下，虽然编译能通过，但是增加了耦合，不利于后续的维护。

## 优点

1. 编译更快：包含冗余的头文件时，预处理过程会有更多操作。
2. 重构更容易：间接引用的存在会导致删除 #include 时，编译失败，不利于解耦。
3. 头文件自注释：可通过查看头文件注释知道该功能依赖的其他子功能。

## 编译安装

IWYU 是使用 clang 分析符号的引用，每个 clang 版本更新时，IWYU 都会有对应的改动。

因此，编译 IWYU 前需要先安装 clang 环境，并确认 clang 版本。

```shell
uname -v
# #49~20.04.1-Ubuntu SMP Fri Feb 5 09:57:56 UTC 2021
# 当前系统为 ubuntu 20.04

sudo apt-get install llvm-10-dev
sudo apt-get install libclang-10-dev
sudo apt-get install clang-10
# 安装 llvm 和 clang-10

clang --version
# clang version 10.0.0-4ubuntu1
# Target: x86_64-pc-linux-gnu
# Thread model: posix
# InstalledDir: /usr/bin
```

[github IWYU 源码](https://github.com/include-what-you-use/include-what-you-use)。

以上 github 链接中包含 clang 版本与 IWYU 分支对应关系。

```shell
git clone git@github.com:include-what-you-use/include-what-you-use.git
# 获取 IWYU 源码

cd include-what-you-use && git checkout clang_10
# 以上安装的 llvm 和 和 clang 版本均为 10，查询对应关系后 IWYU 分支为 clang_10

cmake -H. -Bbuild -G "Unix Makefiles" -DCMAKE_PREFIX_PATH=/usr/lib/llvm-10 && \
cd build && make && sudo make install
# 编译安装
```

## 使用

进入 example 目录，`cd example`。

直接使用`include-what-you-use`分析文件：

```shell
include-what-you-use example.cc
# example.cc should add these lines:
#
# example.cc should remove these lines:
# - #include <cmath>  // lines 3-3
#
# The full include-list for example.cc:
# #include <iostream>  // for operator<<, endl, basic_ostream, # cout, ostream
# ---

# 输出如以上所示：
#  example.cc 中包含了两个头文件，其中 cmath 中声明的内容并未使用
#  因此提示应删除该声明
```

在 Makefile 中分析文件：

```shell
make -k CXX=include-what-you-use
# include-what-you-use    -c -o example.o example.cc
#
# example.cc should add these lines:

# example.cc should remove these lines:
# - #include <cmath>  // lines 3-3

# The full include-list for example.cc:
# #include <iostream>  // for operator<<, endl, basic_ostream, # cout, ostream
# ---
# make: *** [<builtin>: example.o] Error 3
# make: Target 'example' not remade because of errors.

# 输出如以上所示，因为包含不需要的头文件编译中止
```

在 CMake 中分析文件：

```shell
# CMake 3.3版本中引入 CXX_INCLUDE_WHAT_YOU_USE，用于支持 IWYU
cmake -H. -Bbuild -DCMAKE_CXX_INCLUDE_WHAT_YOU_USE=include-what-you-use && \
pushd build && make
# - #include <cmath>  // lines 3-3
# 同 Makefile，将包含以上输出，说明此头文件的包含可以被删除
# 但在 CMake 下，即使输出以上内容，编译也不会中止
```
