
# 常用库源码安装

- [常用库源码安装](#常用库源码安装)
  - [protobuf](#protobuf)
  - [yaml-cpp](#yaml-cpp)

## protobuf

```shell
# 安装依赖软件
sudo apt-get install autoconf automake libtool curl make g++ unzip

# 下载源码
git clone https://github.com/google/protobuf.git

# 配置
cd protobuf && git submodule update --init --recursive && ./autogen.sh && ./configure

# 编译、检查、安装
make && make check && sudo make install

# refresh shared library cache
sudo ldconfig
```

## yaml-cpp

```shell
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp
mkdir build && cd build
cmake .. && make -j
sudo make install
```
