
# 修改软件源

[阿里源官方镜像站](https://developer.aliyun.com/mirror/)有关于修改各个系统软件源的相关说明。

URL：<https://developer.aliyun.com/mirror/>

- [修改软件源](#修改软件源)
  - [ubuntu 20.04修改软件源](#ubuntu-2004修改软件源)
  - [docker 中修改软件源](#docker-中修改软件源)

## ubuntu 20.04修改软件源

``` text
# 阿里源
deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse

deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
```

```shell
# 备份系统原有软件源配置
sudo cp /etc/apt/sources.list /etc/apt/sources.list.bak

# 将阿里源复制到 sources.list 中
sudo vim /etc/apt/sources.list

# 更新
sudo apt-get update && apt-get upgrade
```

## docker 中修改软件源

```shell
sed -i s@/archive.ubuntu.com/@/mirrors.aliyun.com/@g /etc/apt/sources.list
sed -i s@/security.ubuntu.com/@/mirrors.aliyun.com/@g /etc/apt/sources.list
apt clean
apt-get update -y
```
