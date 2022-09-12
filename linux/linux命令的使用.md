
# linux 命令的使用

- [linux 命令的使用](#linux-命令的使用)
  - [格式化U盘：mkfs](#格式化u盘mkfs)
  - [创建指定大小的文件：dd](#创建指定大小的文件dd)

## 格式化U盘：mkfs

```shell
sudo umount /dev/sda1    # 格式化 U 盘必须先卸载该分区

# 格式化为FAT分区，-F参数必须大写，参数有 12/16/32，分别对应 FAT12/FAT16/FAT32
sudo mkfs.vfat -F 32 /dev/sda1  

# 格式化为 NTFS 分区，先要安装 ntfsprogs，然后执行格式化
sudo apt-get install ntfsprogs
sudo mkfs.ntfs /dev/sda1

# 格式化为 ext4/ext3/ext2
sudo mkfs.ext4 /dev/sda1
sudo mkfs.ext3 /dev/sda1
sudo mkfs.ext2 /dev/sda1
sudo mkfs.ext3 -m 0.05 /dev/sda1    # -m 表示设定预留空间百分比，这里为 0.05%
```

## 创建指定大小的文件：dd

dd 命令可以轻易实现创建指定大小的文件，如下：

```shell
dd if=/dev/zero of=test bs=1M count=1000

# 输出：
# 1000+0 records in
# 1000+0 records out
# 1048576000 bytes (1.0 GB, 1000 MiB) copied, 0.331072 s, 3.2 GB/s

# 当前目录下会生成一个 1000M 的 test 文件
# /dev/zero 为数据源(0)，因此文件内容全为 0
# 文件实际写入硬盘，产生速度取决于硬盘读写速度
# 产生超大文件，速度很慢
```

某种场景下，只想让文件系统认为存在一个超大文件在此，如下：

```shell
dd if=/dev/zero of=test bs=1M count=0 seek=100000

# 输出：
# 0+0 records in
# 0+0 records out
# 0 bytes copied, 0.000284513 s, 0.0 kB/s

# 创建的文件在文件系统中的显示大小为 100000MB，但是并不实际占用硬盘
# 因此创建速度与内存速度相当
# seek 的作用是跳过输出文件中指定大小的部分，这就达到了创建大文件，但是并不实际写入的目的
# 因为不实际写入硬盘，所以在容量只有 10G 的硬盘上也可以创建 100G 的此类文件
```

随机生成 100 万个 1K 的文件，如下：

```shell
seq 1000000 | xargs -i dd if=/dev/zero of={}.dat bs=1024 count=1
```
