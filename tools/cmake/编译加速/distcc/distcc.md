
# distcc

- [distcc](#distcc)
  - [安装](#安装)
  - [配置](#配置)
  - [使用](#使用)

distcc 是一个快速且免费的分布式 C/C++ 编译工具。

客户机：启动编译的计算机。

志愿机：接受客户机发送的编译请求的计算机。

一个 distcc 编译集群可以包含一台或多台志愿机。

distcc分为两个部分：

- distcc：可以让客户机上的 C/C++ 代码在客户机和很多志愿机上进行分布式编译
- distccd：守护进程，每个志愿机上都需要安装这个守护进程，用来处理客户机发送的待编译资源

此外，还有 distccmon-text，这是一个监控程序，用来监控编译的分布情况以及志愿机编译使用情况。

## 安装

[源码下载](https://github.com/distcc/distcc/releases)。

源码安装：

```shell
# 下载源码，解压后执行以下命令
./configure && make && sudo make install
```

命令行安装：

```shell
sudo apt-get install distcc distccmon-gnome
# distccmon-gnome 是图形界面监控程序
# 在 ubuntu 20.04 下安装的 distcc 版本为 3.3.3，以下测试的即为该版本
```

## 配置

当前安装了两台虚拟机，志愿机 IP 地址为 192.168.0.108，客户机 IP 地址为 192.168.0.105。

志愿机需要启动守护进程，如下：

```shell
# 需要以 root 用户启动，否则会忽略 user 参数
distccd --daemon --allow 192.168.0.0/24 --user nobody --enable-tcp-insecure
```

客户机需要进行环境变量的配置，如下：

```shell
vim ~/.bashrc
# 添加以下环境变量
#  export DISTCC_HOSTS="localhost 192.168.0.108"
#  export DISTCC_POTENTIAL_HOSTS="192.168.0.108"
#  export DISTCC_LOG="./distcc_runtime.log"
# 以上配置完成后，编译将会在 本机 和 IP 地址为 192.168.0.108 志愿机上进行编译
# 在进行 make 的目录将会产生分布式编译的 log 文件 distcc_runtime.log
```

## 使用

如果安装了`distccmon-gnome`，在终端执行`distccmon-gnome`即可打开监控界面。

在终端执行`distccmon-text n`(每n秒刷新一次)，也可以在命令行进行监控。

同 ccache 一样，在 cmake 中也可以配置使用 distcc，如下：

```cmake
find_program(DISTCC_FOUND distcc)
if (DISTCC_FOUND)
  message(STATUS "distcc found.")
  set(CMAKE_CXX_COMPILER_LAUNCHER distcc)
endif()
```

本质上讲就是在 gcc、g++ 编译前添加了 distcc。

如 example 目录下的示例，执行：

```shell
distccmon-gnome
# 打开监控窗口

cd example && cmake -H. -Bbuild
# 构建 example 目录下的 cmake 工程

cd build && make -j4
# 编译

make clean && make -j4
# 多次执行观察监控窗口

vim distcc_runtime.log
# 查看分布式编译 log
```

参考：

[centos install distcc](https://blog.csdn.net/niu91/article/details/111491038)
