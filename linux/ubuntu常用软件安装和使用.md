
# 常用软件安装和使用说明

- [常用软件安装和使用说明](#常用软件安装和使用说明)
  - [docker中使用GPU](#docker中使用gpu)
  - [docker](#docker)
  - [SSH](#ssh)
  - [Samba](#samba)
  - [ubuntu-restrcited-extras](#ubuntu-restrcited-extras)
  - [VLC](#vlc)
  - [Kazam](#kazam)
  - [Meld](#meld)

## [docker中使用GPU](https://nvidia.github.io/nvidia-container-runtime/)

```shell
# 添加库
curl -s -L https://nvidia.github.io/nvidia-container-runtime/gpgkey | \
  sudo apt-key add -
distribution=$(. /etc/os-release;echo $ID$VERSION_ID)
curl -s -L https://nvidia.github.io/nvidia-container-runtime/$distribution/nvidia-container-runtime.list | \
  sudo tee /etc/apt/sources.list.d/nvidia-container-runtime.list
sudo apt-get update

# 安装
sudo apt-get install nvidia-container-runtime

# 重启docker
systemctl restart docker

# 验证
docker run --gpus all --rm nvidia/cuda:11.0-base nvidia-smi
```

## [docker](https://zhuanlan.zhihu.com/p/143156163)

[docker docs](https://docs.docker.com/engine/install/debian/)

```shell
# 更新软件包索引
sudo apt update

# 安装必要的依赖软件，添加一个新的HTTPS 软件源
sudo apt install apt-transport-https ca-certificates curl gnupg-agent software-properties-common

# curl导入源仓库的GPG key
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo apt-key add -

# Docker APT软件源添加到系统
sudo add-apt-repository "deb [arch=amd64] https://download.docker.com/linux/ubuntu $(lsb_release -cs) stable"

# 更新软件包索引
sudo apt update

# 安装Docker最新版本
sudo apt install docker-ce docker-ce-cli containerd.io

# 更新软件包索引
sudo apt update

# 列出Docker软件源中所有可用的版本
# 输出：docker-ce/focal 5:20.10.3~3-0~ubuntu-focal amd64
# VERSION：5:20.10.3~3-0~ubuntu-focal
apt list -a docker-ce

# 安装指定版本
sudo apt install docker-ce=<VERSION> docker-ce-cli=<VERSION> containerd.io

# 查看docker服务状态
sudo systemctl status docker

# 版本锁定，阻止Docker自动更新
sudo apt-mark hold docker-ce

# 默认情况下，只有 root 或者 有 sudo 权限的用户可以执行 Docker 命令
# 将当前用户加入docker用户组
# 需重新登录，以刷新组用户信息
sudo usermod -aG docker $USER

# 验证安装
docker container run hello-world

# 卸载docker前，需要移除所有的容器、镜像、卷、网络
docker container stop $(docker container ls -aq)
docker system prune -a --volumes

# 卸载docker
sudo apt purge docker-ce
sudo apt autoremove

# 添加docker用户组
sudo groupadd docker

# 将普通用户加入docker组
sudo gpasswd -a $USER docker

# 更新docker组
newgrp docker
```

## SSH

```shell
# 安装客户端，如果只用于连接其他机器，则可以只安装客户端
sudo apt-get install openssh-client

# 安装服务器端
sudo apt-get install openssh-server

# 确认SSH服务是否已启动
ps -e | grep ssh

# 启动SSH服务
sudo /etc/init.d/ssh start

# 停止SSH服务
sudo /etc/init.d/ssh stop

# 重启SSH服务
sudo /etc/init.d/ssh restart

# macbook停止SSH服务
sudo launchctl unload  /System/Library/LaunchDaemons/ssh.plist

# macbook启动SSH服务
sudo launchctl load -w /System/Library/LaunchDaemons/ssh.plist

# SSH连接，默认端口22，未配置公钥需要输入密码
ssh shiyucun@192.168.0.1

# SSH连接，使用端口9999，未配置公钥需要输入密码
ssh -p 9999 shiyucun@192.168.0.1

# 本机生成密钥对，-t表示类型选项，这里采用rsa加密算法
ssh-keygen -t rsa

# 将公钥复制到远程主机，配置公钥后再次连接不需要输入密码
ssh-copy-id shiyucun@192.168.0.1

# 利用ssh在远程主机上跑程序时，只要关闭了终端就会中断ssh连接，然后远程主机上正在跑的程序或者服务就会自动停止运行。
# 可以利用(nohup + 需要运行的程序)使运行的程序在切断ssh连接的时候仍然能够继续在远程主机中运行。
# nohup即no hang up(不挂起)。
```

## Samba

Samba是一个文件服务器，可以在linux、Windows、Mac之间共享文件。

```shell
# 安装
sudo apt-get install samba samba-common

# 在文件 "/etc/samba/smb.conf" 末尾追加以下内容
[share]
path = /home/shiyucun  # 共享的文件夹路径
guest ok = no
comment = smb share
available = yes
browseable = yes
public    = yes
writeable = yes

# 添加用户并设置密码
sudo smbpasswd -a shiyucun  

# 重启samba服务
sudo /etc/init.d/smbd restart
```

## ubuntu-restrcited-extras

ubuntu-restricted-extras 是一个包含各种基本软件的软件包。

其中包括 Flash 插件、ubrar、gstreamer、mp4、chromium的编解码器等。

由于这些软件包非开源，而且涉及到一些专利的问题，所以ubuntu没有预装他们。

```shell
# 安装命令
sudo add-apt-repository multiverse
sudo apt install ubuntu-restricted-extras

# Kubuntu
sudo apt install kubuntu-restricted-extras

# Lubuntu
sudo apt install lubuntu-restricted-extras

# Xubuntu
sudo apt install xubuntu-restricted-extras
```

## VLC

VLC是一个好用的视频播放器

```shell
# 安装命令
sudo apt install vlc
```

## Kazam

Kazam 是一个很轻量级的屏幕录制工具，也可以用来截图。

```shell
# 安装命令
sudo apt install kazam
```

## Meld

Meld 是类似 Beyong Compare 的一种优秀的文件或目录比较软件，并支持许多流行的版本控制系统。

```shell
# 安装命令
sudo apt-get install meld
```
