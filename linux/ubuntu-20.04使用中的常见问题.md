
# 使用中的常见问题

- [使用中的常见问题](#使用中的常见问题)
  - [scp 任务放入后台执行](#scp-任务放入后台执行)
  - [内存不足编译失败](#内存不足编译失败)
  - [开关机、重启慢问题](#开关机重启慢问题)
  - [打开和关闭图形界面](#打开和关闭图形界面)

## scp 任务放入后台执行

```shell
nohup scp ./code.tar.gz shiyucun@172.25.28.15:/home/shiyucun/Downloads > /dev/null 2>&1 &
jobs
disown %1
```

## 内存不足编译失败

编译代码有时会报错 **internal compiler error: Killed**，这是由于内存不足导致的。

可以增大 swap 空间解决该问题。

```shell
sudo dd if=/dev/zero of=swap bs=1024 count=10000000
# swap 是文件名字，1024 是指 1024 字节，10000000 是指 10G 大小空间
# 可以将该文件放在根目录下

sudo chmod 600 swap
# 修改文件权限

sudo mkswap -f swap
# 将该文件转换成 swap 空间

sudo swapoff swapfile
sudo rm swapfile
# 根目录下可能还存在 swapfile 文件，需要将该文件删除

sudo swapon swap
# 使能 swap 交换空间

sudo vim /etc/fstab
# 编辑文件，修改 swapfile 为 swap，使交换空间配置永久生效
```

## 开关机、重启慢问题

开关机，或者重启时，等待时间很长，大约1分30秒，且有光标闪烁。

等待时间长，可能是由于开关机时后台要打开或关闭某些程序。

这些程序花费的时间是有系统设定的默认时间的，大约90秒，只有到了90秒系统才能打开或是关闭。

光标闪烁就是后台一系列活动的简化，它表示后台有一系列活动在进行，只是我们看不到。

以上现象会让我们觉的卡住了。

```shell
# 打开文件
sudo gedit /etc/default/grub

# 找到以下内容
GRUB_CMDLINE_LINUX_DEFAULT="quiet splash"

# 如下修改
GRUB_CMDLINE_LINUX_DEFAULT=""

# 重启后可以发现以下动作
A stop job is running for Snappy daemon (1min 16s / 1min 30s)
```

修改方法如下：

```shell
# 成为root用户
sudo su

# ubuntu默认没有开启root权限，以下操作为root用户设置密码：
sudo passwd root

# 打开文件
vim /etc/systemd/system.conf

# 找到以下内容
#DefaultTimeoutStartSec=90s
#DefaultTimeoutStopSec=90s

# 修改为
DefaultTimeoutStartSec=3s
DefaultTimeoutStopSec=3s

# 加载修改后的配置
systemctl daemon-reload
```

## 打开和关闭图形界面

```shell
# 关闭用户图形界面，使用tty登录
sudo systemctl set-default multi-user.target
sudo reboot

# 开启用户图形界面
sudo systemctl set-default graphical.target
sudo reboot
```
