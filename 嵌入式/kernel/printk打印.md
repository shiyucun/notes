
# 内核printk打印函数

- [内核printk打印函数](#内核printk打印函数)
  - [输出级别(0~7)](#输出级别07)
  - [用法](#用法)
  - [输出级别](#输出级别)

## 输出级别(0~7)

输出级别的宏定义在"include/linux/kernel.h"，值越小越严重。

```c
#define KERN_EMERG "<0>"
...
#define KERN_DEBUG "<7>"
```

## 用法

```c
printk(KERN_ERR "error messages!\n");
printk("<7>""error messsage!\n");
```

## 输出级别

printk的信息是否需要向终端打印输出，关键看默认的打印输出级别设置为多少。

假设默认的打印输出级别为4，则级别小于4的信息printk会打印输出，否则不输出。

默认打印输出级别的设置方法：

方法1：通过修改配置文件来设置默认的打印输出级别

```shell
cat /proc/sys/kernel/printk
# 输出：7(用于终端)   4       1       7
# 如上输出，目前系统的默认打印输出级别为7

echo 8 > /proc/sys/kernel/printk
# 以上将默认的输出级别设置为8
# 这种方法对于内核启动时的输出级别设置无效
```

方法2：通过设置内核的启动参数来指定默认的打印输出级别

```text
setenv bootargs root=/dev/nfs nfsroot=... debug(10)
setenv bootargs root=/dev/nfs nfsroot=... quiet(4)
setenv bootargs root=/dev/nfs nfsroot=... loglevel = 数字
```

系统启动后要查看没有输出的信息，可以用dmesg命令来获取输出缓冲区中的内容。
