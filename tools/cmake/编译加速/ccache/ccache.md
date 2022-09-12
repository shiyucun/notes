
# ccache

- [ccache](#ccache)
  - [基本原理](#基本原理)
  - [安装](#安装)
  - [配置 ccache](#配置-ccache)
  - [命令行中使用 ccache](#命令行中使用-ccache)
  - [cmake 中使用 ccache](#cmake-中使用-ccache)

在处理一些规模相对较大的工程时，编译花费的时间可能会很长，有时可能还会多次编译相同的程序。

使用 ccache 在第一次编译时会多花费一些时间，但之后的编译会成倍(5-10倍)的提速。

## 基本原理

ccache 通过将头文件高速缓存到源文件之中而改进构建性能，即减少了编译时添加头文件的时间。

ccache 是 `compiler cache` 的缩写，是一个编译器驱动器。

第一次编译时 ccache 缓存了 GCC "-E" 选项的输出、编译选项、".o"文件到 ccache 设置的缓存目录。

之后编译时会尽量利用缓存，必要时会更新缓存。

因此即使 `make clean` 后再 `make` 也能从中获得好处。

ccache 是经过仔细编写的，确保了与直接使用 GCC 编译器获得完全相同的输出。

ccache 工具会高速缓存编译生成的信息，并在编译的特定部分时使用高速缓存的信息，如下代码：

```c++
#include　"test.h"

int main() {
  test();

  return 0;
}

// 假设 test.h 中包含对其它文件的引用
// 第一次编译时 cache 会对这个头文件进行预处理，并将处理后的文件保存到缓存目录中
// 当修改了代码进行第二次编译时，将使用缓存目录中保存的文件直接替换 include 声明，跳过了 test 的解析过程
// 经过上述过程使得 include 被替换后的文件可以直接进行编译
```

## 安装

ccache 不会取代或者以任何方式影响原编译代码使用编译器的方式。

[ccache 源码下载](https://ccache.dev/download.html)。

[源码安装](https://ccache.dev/documentation.html)。

命令行安装：`sudo apt-get install ccache`。

## 配置 ccache

默认情况下，ccache 使用当前用户主目录中的一个目录($HOME/.ccache)来保存高速缓存信息。

在团队环境中，应该使用一个集中的位置来保存，这样在编译过程中每个人都可以使用高速缓存的信息。

环境变量`CCACHE_DIR`指定了高速缓存目录的位置。

在单机环境中，将这个环境变量设置为每一个需要使用 ccache 的人都可以访问的目录。

如果在网络中多台机器上使用进行分布式编译，那么要确保共享的目录通过 NFS 导出并挂载到每一个客户机上。

如果想获得额外加速，则可以使用 tmpfs 文件系统。

环境变量`CCACHE_LOGFILE`定义了使用高速缓存时生成的日志文件所处的位置。

ccache 命令选项：

- -s：获得关于高速缓存性能的统计数据。
- -M：设置高速缓存的最大大小。高速缓存的设置会写入到高速缓存目录，因此每个用户的设置可以不同。
- -F：设置高速缓存目录的最大文件数目。
- -c：清空旧文件，重新计算大小，一般不需要设置，ccache 会自动更新文件。
- -C：完全清空高速缓存。
- -z：清空统计数据

## 命令行中使用 ccache

[使用文档](https://ccache.dev/documentation.html)

[运行模式](https://ccache.dev/manual/4.6.1.html#_run_modes)

模式一：

```shell
// 在编译命令前加上 ccache 前缀

// 编译一个文件，通常会使用：
gcc test.c

// 如果使用 ccache
ccache gcc test.c
```

模式二：

```shell
// 创建到 ccache 的符号链接，让 ccache 伪装成编译器
cp ccache /usr/local/bin/
ln -s ccache /usr/local/bin/gcc
ln -s ccache /usr/local/bin/g++
ln -s ccache /usr/local/bin/cc
ln -s ccache /usr/local/bin/c++
```

## cmake 中使用 ccache

example 文件夹中提供了示例。

```shell
cd example && cmake -H. -Bbuild && pushd build
ccache -c -z -C && time make && ccache -s

# 可以看到以下输出：
# make  0.67s user 0.07s system 100% cpu 0.740 total
# cache hit (direct)                     0
# cache miss                             2

popd && rm -rf build && cmake -H. -Bbuild && pushd build
time make && ccache -s
# 可以看到以下输出：
# make  0.06s user 0.03s system 100% cpu 0.098 total
# cache hit (direct)                     2
# cache miss                             2

# 以上可以看出：
# 第一次编译时 ccache 中没有找到可用的缓存数据
# 因此 cache miss = 2，cache hit = 0
# 第二次编译时 ccache 中找到了可用的缓存数据
# 因此 cache miss = 2，cache hit = 2
# 在编译时间上，第二次的 0.098 秒 明显快于第一次 0.740 秒
```

example 中 CMakeLists.txt 中包含以下内容：

```cmake
find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set(CMAKE_CXX_COMPILER_LAUNCHER ccache)
endif()
```

即 cmake 中配置 CMAKE_CXX_COMPILER_LAUNCHER 后，就可以开启 c++ ccache 加速编译。

此外，对于 c 语言，需要在 cmake 中配置 CMAKE_C_COMPILER_LAUNCHER。
