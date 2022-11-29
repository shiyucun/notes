
# shell

- [shell](#shell)
  - [什么是shell](#什么是shell)
  - [模式扩展](#模式扩展)
    - [八种模式扩展](#八种模式扩展)
    - [字符类](#字符类)
    - [量词语法](#量词语法)
  - [引号和转义](#引号和转义)
    - [转义](#转义)
    - [单引号](#单引号)
    - [双引号](#双引号)
    - [Here文档](#here文档)
    - [Here字符串](#here字符串)
  - [变量](#变量)
    - [创建变量](#创建变量)
    - [读取变量](#读取变量)
    - [删除变量](#删除变量)
    - [输出变量](#输出变量)
    - [特殊变量](#特殊变量)
    - [变量默认值](#变量默认值)
    - [declare命令](#declare命令)
    - [readonly命令](#readonly命令)
    - [let命令](#let命令)
  - [字符串操作](#字符串操作)
    - [长度](#长度)
    - [子字符串](#子字符串)
    - [搜索与替换](#搜索与替换)
    - [改变大小写](#改变大小写)
  - [算数运算](#算数运算)
    - [算数表达式](#算数表达式)
    - [expr命令](#expr命令)
    - [进制](#进制)
  - [行操作](#行操作)
    - [光标移动](#光标移动)
    - [清除屏幕](#清除屏幕)
    - [编辑操作](#编辑操作)
    - [自动补全](#自动补全)
    - [操作历史](#操作历史)
    - [其它快捷键](#其它快捷键)
  - [目录堆栈](#目录堆栈)
  - [bash脚本](#bash脚本)
    - [指定解释器](#指定解释器)
    - [执行权限和路径](#执行权限和路径)
    - [env命令](#env命令)
    - [注释](#注释)
    - [脚本参数](#脚本参数)
    - [shift命令](#shift命令)
    - [getopts命令](#getopts命令)
    - [配置项参数终止符](#配置项参数终止符)
    - [exit命令](#exit命令)
    - [命令执行结果](#命令执行结果)
    - [source命令](#source命令)
    - [alias别名](#alias别名)
  - [read命令](#read命令)
  - [条件判断](#条件判断)
    - [if结构](#if结构)
    - [test命令](#test命令)
    - [文件判断](#文件判断)
    - [字符串判断](#字符串判断)
    - [整数判断](#整数判断)
    - [正则判断](#正则判断)
    - [逻辑运算](#逻辑运算)
    - [算数判断](#算数判断)
    - [case结构](#case结构)
  - [循环](#循环)
    - [while循环](#while循环)
    - [until循环](#until循环)
    - [for...in循环](#forin循环)
    - [for循环](#for循环)
    - [break和continue](#break和continue)
    - [select结构](#select结构)
  - [bash函数](#bash函数)
    - [参数变量](#参数变量)
    - [return命令](#return命令)
    - [全局变量和局部变量](#全局变量和局部变量)
  - [数组](#数组)
    - [创建数组](#创建数组)
    - [读取数组](#读取数组)
    - [默认位置](#默认位置)
    - [数组长度](#数组长度)
    - [提取数组序号](#提取数组序号)
    - [提取数组成员](#提取数组成员)
    - [追加数组成员](#追加数组成员)
    - [删除数组](#删除数组)
    - [关联数组](#关联数组)
  - [set命令](#set命令)
    - [set -u](#set--u)
    - [set -x](#set--x)
    - [bash错误处理](#bash错误处理)
    - [set -e](#set--e)
    - [set -o pipefail](#set--o-pipefail)
    - [其它参数](#其它参数)
  - [脚本除错方法](#脚本除错方法)
  - [启动环境](#启动环境)
    - [登录session](#登录session)
    - [非登录session](#非登录session)
    - [.bash_logout](#bash_logout)
    - [启动参数](#启动参数)
    - [键盘绑定](#键盘绑定)
  - [命令提示符](#命令提示符)
    - [PS1](#ps1)
    - [颜色](#颜色)
    - [PS2 PS3 PS4](#ps2-ps3-ps4)
  - [异步任务](#异步任务)
  - [命名管道](#命名管道)
  - [重定向](#重定向)
  - [正则表达式](#正则表达式)
  - [shell命令](#shell命令)
    - [shopt](#shopt)
    - [type](#type)
    - [whatis](#whatis)
    - [apropos](#apropos)
    - [which](#which)
    - [whereis](#whereis)
    - [help](#help)
    - [man](#man)
    - [script](#script)
    - [echo](#echo)
    - [mktemp](#mktemp)
    - [trap](#trap)
    - [gzip](#gzip)
    - [bzip2](#bzip2)
    - [zip](#zip)
    - [tar](#tar)
    - [rsync](#rsync)
    - [cp](#cp)
    - [scp](#scp)
    - [mkdir](#mkdir)
    - [mv](#mv)
    - [rm](#rm)
    - [ln](#ln)
    - [ls](#ls)
    - [stat](#stat)
    - [touch](#touch)
    - [file](#file)
    - [chmod](#chmod)
    - [du](#du)
    - [md5sum](#md5sum)
    - [locate](#locate)
    - [find](#find)
    - [xargs](#xargs)
    - [df](#df)
    - [free](#free)
    - [mount](#mount)
    - [umount](#umount)
    - [fdisk](#fdisk)
    - [mkfs](#mkfs)
    - [fsck](#fsck)
    - [dd](#dd)
    - [demidecode](#demidecode)
    - [lspci](#lspci)
    - [lsusb](#lsusb)
    - [hostname](#hostname)
    - [ps](#ps)
    - [top](#top)
    - [jobs](#jobs)
    - [fg](#fg)
    - [bg](#bg)
    - [kill](#kill)
    - [killall](#killall)
    - [pstree](#pstree)
    - [vmstat](#vmstat)
    - [xload](#xload)
    - [tload](#tload)
    - [tee](#tee)
    - [basename](#basename)
    - [uname](#uname)
    - [service](#service)
    - [cat](#cat)
    - [nl](#nl)
    - [sort](#sort)
    - [uniq](#uniq)
    - [cut](#cut)
    - [paste](#paste)
    - [wc](#wc)
    - [head](#head)
    - [tail](#tail)
    - [grep](#grep)
    - [egrep](#egrep)
    - [sed](#sed)
    - [date](#date)
    - [cal](#cal)
    - [id](#id)
    - [su](#su)
    - [sudo](#sudo)
    - [chown](#chown)
    - [chgrp](#chgrp)
    - [useradd](#useradd)
    - [usermod](#usermod)
    - [adduser](#adduser)
    - [groupadd](#groupadd)
    - [groupdel](#groupdel)
    - [passwd](#passwd)
    - [awk](#awk)
    - [pv](#pv)
    - [last](#last)
    - [lpq](#lpq)
    - [lpr](#lpr)
    - [tr](#tr)
    - [uptime](#uptime)
    - [w](#w)

## 什么是shell

shell是内核外面的一层，是用于与内核交互的对话界面。

shell是一个程序，提供与用户对话的环境，一般情况下，shell就是指命令行环境。

shell是一个命令行解释器，解释用户输入的命令，支持变量、条件判断、循环，因此可以写出各种脚本程序。

shell是一个工具箱，提供各种小工具，方便用户使用操作系统的功能。

shell有sh、bash、zsh、csh等多种。

bash是目前最常用的shell：

- `echo $SHELL`：命令用于查看当前系统使用的shell
- `cat /etc/shells`：命令用于查看当前系统安装的所有shell

注意：

1. 命令的参数一般有长短两种形式
    - 长形式用于脚本，可读性更好
    - 短形式用于手动输入，更方便
2. 以空格或Tab键区分命令的不同参数，多个空格会被自动忽略
3. 分号是命令结束符，使一行可以放置多个命令
    - 无论分号前面的命令是否执行成功，分号后面的命令都会执行
4. 命令组合符
    - `&&`：连接两个命令时，前面的命令执行**成功**才会执行后面的命令
    - `||`：连接两个命令时，前面的命令执行**失败**才会执行后面的命令
5. 快捷键：
    - `Ctrl + L`：清除屏幕并将当前行移到页面顶部
    - `Ctrl + C`：中止当前正在执行的命令
    - `Shift + PageUp`：向上滚动
    - `Shift + PageDown`：向下滚动
    - `Ctrl + U`：从光标位置删除到行首
    - `Ctrl + K`：从光标位置删除到行尾
    - `Ctrl + D`：关闭 Shell 会话
    - `↑`和`↓` ：浏览已执行命令的历史记录

## 模式扩展

shell接收到用户的命令后，会先将用户的输入拆分成一个个词元(token)。

然后shell会扩展词元里面的特殊字符，扩展完成后才会调用相应的命令。

### 八种模式扩展

1. 波浪线扩展
    - `~`：扩展为用户主目录
    - `~user`：扩展为user用户的主目录，user用户不存在则波浪线扩展不起作用
    - `~+`：扩展为当前所在目录，等同于`pwd`命令
2. `?`字符扩展
    - `?`匹配单个字符，匹配多个字符需要多个`?`连用
    - 这种扩展属于文件名扩展，文件存在时才会发生，文件不存在时扩展不会发生
3. `*`字符扩展
    - `*`匹配0个或多个字符
    - 这种扩展属于文件名扩展，文件存在时才会发生，文件不存在时扩展不会发生
    - 不匹配以`.`开头的隐藏文件
    - 只匹配当前目录，不匹配子目录，匹配多层目录时需要多写几层星号
4. 方括号扩展
    - 形式：`[...]`、`[^...]`、`[!...]`
    - 这种扩展属于文件名匹配，扩展后的结果必须符合现有文件路径，不存在时保持原样不扩展
    - `[ab]`：匹配a和b
    - `[^abc]`：匹配abc以外的字符
    - `[!abc]`：匹配abc以外的字符
    - 匹配`[`时直接将字符放在方括号内
    - 匹配`-`时需要将字符放在方括号内部的开头或结尾
    - `[a-d]`等价于`[abcd]`
5. 大括号扩展
    - 形式：`{...}`、`{start..end}`、`{start..end..step}`，扩展成大括号里面的所有值，各个值之间使用`,`分隔
    - 这种扩展不属于文件名扩展，会扩展成所有给定的值，不管对应文件是否存在
    - 内部`,`前后不能有空格，否则扩展失效
    - 与其他扩展模式联用时先于其他扩展模式扩展
    - `{a..d}`会扩展为`a b c d`
    - `{d..a}`会扩展为`d c b a`
    - `{05..1}`会扩展为`05 04 03 02 01`，整数有前导0，扩展的每一项都有前导0
    - `{02..10..2}`会扩展为`02 04 06 08 10`
    - `{002..10..2}`会扩展为`002 004 006 008 010`
    - 大括号扩展可以嵌套形成复杂的扩展
6. 变量扩展
    - 以`$`开头的词元视为变量，会扩展为变量值，也可以将词元放在`{}`中
    - `${!string*}`、`${!string@}`返回所有匹配给定字符串`string`的变量名
7. 算术扩展
    - `$((...))`可以扩展成整数运算的结果
    - `$((3+4))`扩展为7
8. 子命令扩展
    - `$(...)`可以扩展为另一个命令的运行结果，命令的所有输出均作为返回值
    - 该扩展方式可以嵌套

```shell
echo $(date)
# Thu Nov 10 19:47:05 CST 2022

echo `date`  # 较早的语法
# Thu Nov 10 19:47:34 CST 2022

echo $(ls $(pwd))
# bin boot dev etc home lib media mnt notes opt proc root run sbin srv sys tmp usr var
```

扩展功能打开：

1. `set -o noglob`
2. `set -f`

扩展功能关闭：

1. `set +o noglob`
2. `set +f`

### 字符类

`[[:class:]]`表示一个字符类，扩展成某一类特定字符之中的一个。

字符类属于文件名扩展，没有可匹配文件时字符原样输出。

常用的字符类如下：

- `[[:alnum:]]`：匹配任意英文字母与数字
- `[[:alpha:]]`：匹配任意英文字母
- `[[:blank:]]`：空格和Tab键
- `[[:cntrl:]]`：ASCII码0-31的不可打印字符
- `[[:digit:]]`：匹配任意数字0-9
- `[[:graph:]]`：A-Z、a-z、0-9 和标点符号
- `[[:lower:]]`：匹配任意小写字母a-z
- `[[:print:]]`：ASCII码32-127的可打印字符
- `[[:punct:]]`：标点符号(除了 A-Z、a-z、0-9 的可打印字符)
- `[[:space:]]`：空格、Tab、LF(10)、VT(11)、FF(12)、CR(13)
- `[[:upper:]]`：匹配任意大写字母A-Z
- `[[:xdigit:]]`：16进制字符(A-F、a-f、0-9)

```shell
echo [[:lower:]]*  # 输出所有以小写字母开头的文件名
# bin boot dev etc home lib media mnt notes opt proc root run sbin srv sys tmp usr var

echo [![:upper:]]*  # 输出所有以非大写字母开头的文件名
# bin boot dev etc home lib media mnt notes opt proc root run sbin srv sys tmp usr var
```

以上，需注意：

1. 通配符先解释再执行
2. 文件名扩展在不匹配时会原样输出
3. 只适用于单层路径
4. 文件名可以使用通配符，此时需要把文件名放在单引号中

### 量词语法

量词语法用来控制模式匹配的次数。

只有在bash的extglob参数打开的情况下才能使用，一般默认是打开的：

```shell
shopt extglob  # 查询
# extglob on
```

量词语法有下面几个：

- `?(pattern-list)`：匹配零个或一个模式
- `*(pattern-list)`：匹配零个或多个模式
- `+(pattern-list)`：匹配一个或多个模式
- `@(pattern-list)`：只匹配一个模式
- `!(pattern-list)`：匹配零个或一个以上的模式，但不匹配单独一个的模式

## 引号和转义

bash中只有字符串一种数据类型，因此不管输入什么数据，bash均视为字符串。

### 转义

`$`、`&`、`*`等字符在bash中有特殊含义，不能直接输出。

如果想输出这些字符，需要在字符前加上`\`，将其转义成普通字符。

`\`本身也是特殊字符，输出`\`时，需要对自身进行转义，即连续使用两个反斜杠`\\`。

反斜杠除了用于转义，还用于表示一些不可打印的字符：

- `\a`：响铃
- `\b`：退格
- `\n`：换行
- `\r`：回车
- `\t`：制表符

如果想要在命令行使用这些不可打印字符，可以将其放在引号里面，执行`echo`命令时使用`-e`参数。

反斜杠还可以对换行符进行转义，bash会认为换行符是一个普通字符，因此一条命令可以写成多行。

### 单引号

单引号用于保留字符的字面含义，特殊字符在单引号中会变为普通字符。

单引号使bash扩展、变量引用、算术运算、子命令都失效，不使用单引号时他们都会被bash自动扩展。

### 双引号

相较于单引号，双引号比较宽松，可以保留大部分特殊字符的本来含义，但美元符号、反引号、反斜杠除外(即bash仍会自动扩展)。

`*`放在双引号中会变成普通字符，双引号中不会进行文件名扩展。

在双引号中：

- 美元符号用来引用变量
- 反引号用来执行子命令
- 反斜杠用于转义

文件名包含空格时必须使用双引号。

双引号会原样保留多余的空格，还可以保存命令原始的输出格式。

### Here文档

Here文档是一种输入多行字符串的方法：

```shell
<< here_doc_name  # 开始标记："<<"需要顶格，here_doc_name是文档的名称，写完后必须换行
text              # 字符串内容
here_doc_name     # 结束标记：需要顶格写文档名称，不顶格不起作用
```

Here文档内部会发生变量替换和通配符扩展，双引号和单引号变为普通字符。

不希望文档内部发生变量替换时需要将开始标记放在单引号之中。

Here文档本质是重定向，将字符串重定向输出给某个命令，相当于包含了`echo`命令：

```shell
command << token
string
token

# 等同于

echo string | command
```

因此Here文档只适用于可以接受标准输入作为参数的命令，对于其它命令无效(如`echo`)。

Here文档也不能作为变量的值，只能用于命令的参数。

### Here字符串

Here字符串用于将字符串通过标准输入传递给命令。

有些命令直接传入给定参数，与通过标准输入传入给定参数，结果是不一样的，因此有了Here字符串语法。

```shell
# 语法：
<<< string    # 以三个小于号开头，称为Here字符串

# 举例：
cat <<< "here string"

#等价于

echo "here string" | cat
```

## 变量

bash变量分为环境变量和自定义变量两类。

环境变量是bash环境自带的变量，进入shell时已经定义好了，可以直接使用。

环境变量通常是系统定义好的，也可以由用户从父shell传入子shell。

命令`env`和`printenv`可以显示所有环境变量。

- `BASHPID`：bash进程的进程ID
- `BASHOPTS`：当前shell的参数，可以用`shopt`命令修改
- `DISPLAY`：图形环境的显示器名字，通常是`:0` ，表示X Server的第一个显示器
- `EDITOR`：默认的文本编辑器
- `HOME`：用户的主目录
- `HOST`：当前主机的名称
- `IFS`：词与词之间的分隔符，默认为空格
- `LANG`：字符集以及语言编码，比如`zh_CN.UTF-8`
- `PATH`：由冒号分开的目录列表，当输入可执行程序名后，会搜索这个目录列表
- `PS1`：shell提示符
- `PS2`：输入多行命令时，次要的shell提示符
- `PWD`：当前工作目录
- `RANDOM`：返回一个0到32767之间的随机数
- `SHELL`：shell的名字
- `SHELLOPTS`：启动当前shell的set命令的参数
- `TERM`：终端类型名，即终端仿真器所用的协议
- `UID`：当前用户的ID编号
- `USER`：当前用户的用户名
- ...

很多环境变量很少发生变化，而且是只读的，可以视为常量。

由于环境变量名全部是大写，所以传统上，如果用户要自己定义一个常量，也会使用全部大写的变量名。

bash变量名是区分大小写的，Home和home是两个不同的变量。

```shell
# 以下三种方式均可用打印某个环境变量
printenv PATH
echo ${PATH}
echo $PATH
```

自定义变量是用户在当前shell里自己定义的变量，必须先定义后使用，且仅在当前shell可用。

`set`命令可以显示所有环境变量和自定义变量，以及所有bash函数。

### 创建变量

规则：

1. 由字母、数字、下划线组成
2. 第一个字符必须是字母或下划线
3. 不能包含空格和标点符号

语法：

```shell
variable=value  # 注：等号两侧不能有空格

# 举例：
a=z                  # 变量a赋值为字符串z
b="a string"         # 变量值包含空格，就必须放在引号里面
c="a string and $b"  # 变量值可以引用其他变量的值
d="\t\ta string\n"   # 变量值可以使用转义字符
e=$(ls -l foo.txt)   # 变量值可以是命令的执行结果
f=$((5 * 7))         # 变量值可以是数学运算的结果
```

在bash中所有变量的值都是字符串。

### 读取变量

读取变量的时候，直接在变量名前加上`$`就可以了。

变量不存在时，bash不会报错，而是输出空字符串。

使用`$`原义时，需要进行转义。

如果变量的值本身也是变量，可以使用`${!varname}`读取最终值。

### 删除变量

变量删除后仍可以读取值，值为空字符串，因此删除变量有以下3种方式：

```shell
unset VARIABLE_NAME
VARIABLE_NAME=''
VARIABLE_NAME=

# 举例：
STRING="a string"
echo ${STRING}
unset STRING
echo ${STRING}

STRING="a string"
echo ${STRING}
STRING=''
echo ${STRING}
```

### 输出变量

用户创建的的变量仅可用于当前shell，子shell默认读取不到父shell定义的变量。

使用`export`命令可以将变量作为子shell的环境变量传递给子shell。

语法：

```shell
export VARIABLE_NAME
export VARIABLE_NAME=VALUE
```

子shell修改继承的变量不影响父shell。

### 特殊变量

bash提供一些特殊变量，变量的值由shell提供，用户不能进行赋值。

`$?`：上一个命令的退出码，值为0表示上一个命令执行成功，值非0表示上一个命令执行失败。

```shell
ls abc
# ls: cannot access 'abc': No such file or directory
echo $?
# 2
which abc
echo $?
# 1
ls
echo $?
# 0
```

`$$`：当前shell的进程ID。

```shell
echo $$
# 9

# $$可用于命名临时文件
LOGFILE=/tmp/output_log.$$
```

`$_`：上一个命令的最后一个参数。

```shell
which abc
echo $_
# abc
```

`$!`：最近一个后台执行的异步命令的进程ID。

`$0`：命令行直接执行时是shell的名称，脚本中执行时是脚本名。

`$-`：当前shell启动参数。

`$@`和`$#`：脚本参数数量。

### 变量默认值

bash提供一下特殊语法，以保证变量不为空。

```shell
${VARIABLE_NAME:-DEFAULT_VALUE}
# 用于返回一个默认值
#   变量存在且不为空返回变量值，否则返回默认值

${VARIABLE_NAME:=DEFAULT_VALUE}
# 用于设置变量默认值
#   变量存在且不为空返回变量值，否则将变量设置为默认值再返回

${VARIABLE_NAME:+word}
# 用于测试变量是否存在
#   变量存在且不为空返回word，否则返回空值

${VARIABLE_NAME:?message}
# 用于防止变量未定义
#   变量存在且不为空返回变量值，否则将打印message相关的错误信息
#   打印错误信息后，脚本会中断执行
#   message可以省略，默认会输出"parameter null or not set."
```

### declare命令

`declare`用于声明一些特殊变量类型，为变量设置一些限制。

语法：

```shell
declare OPTION VARIABLE_NAME=VALUE

# OPTION:
# -a: 声明数组变量
# -f: 输出所有函数定义
# -F: 输出所有函数名
# -i: 声明整数变量
# -l: 声明变量为小写字母
# -p: 查看变量信息
# -r: 声明只读变量
# -u: 声明变量为大写字母
# -x: 变量输出为环境变量
```

`declare`用于函数中，声明的变量只在函数内部有效，等同于`local`命令。

不带任何参数时，`declare`输出当前环境的所有变量(包括函数)，等同于不带有任何参数的`set`命令。

`declare`的使用：

```shell
declare -i val1=1 val2=2 sum
sum=val1+val2
echo ${sum}
# 3
# 上述sum=3是因为sum声明为整数
#     sum不声明为整数时，val1+val2会被当做字面量
#     val1和val2如果不声明为整数，由于sum声明为整数，对sum的赋值会自动解释为整数运算
# 注：变量声明为整数后，依然可以赋值字符串，但值不确定

declare -x sum
# -x选项等同于export命令，输出变量为子shell的环境变量

declare -r val3=1
val3=2
# bash: val3: readonly variable
# 声明只读变量，变量值无法改变

declare -u val4
val4=upper
echo ${val4}
# UPPER
# 自动将变量值转换为大写字母

declare -u val5
val5=LOWER
echo ${val5}
# LOWER
# 自动将变量值转换为小写字母

declare -p val5
# declare -u val5="LOWER"
declare -p val6
# bash: declare: val6: not found
# 输出已定义变量的值，未定义的变量会提示找不到
# 不提供变量名时 declare -p 会输出所有变量的信息

declare -f
# 输出当前环境的所有函数，包括定义

declare -F
# 输出当前环境的所有函数名，不包括定义
```

### readonly命令

`readonly`命令等同于`declare -r`，用来声明只读变量，不能改变变量的值，也不能`unset`变量。

```shell
readonly val6=1
val6=2
# bash: val6: readonly variable
unset val6
# bash: unset: val6: cannot unset: readonly variable
```

选项：

- -f: 声明的变量为函数名
- -p: 打印所有只读变量
- -a: 声明的变量为数组

### let命令

`let`命令声明变量时，可以直接执行算术表达式。

```shell
let foo=1+2
echo $foo
# 3

let "v1 = 1" "v2 = v1++"  # 表达式中有空格时需要使用引号
echo $v1,$v2
# 2,1
```

## 字符串操作

### 长度

语法：`${#VARIABLE_NAME}`。

以上语法中`{}`是必需的，否则`$#`将理解为参数个数。

### 子字符串

语法：`${VARIABLE_NAME:offset:length}`。

以上返回VARIABLE_NAME字符串的子字符串，从offset位置开始，返回的长度为length。

这种语法不能直接操作字符串，只能通过变量来读取字符串，不会改变原始字符串。

```shell
s="abcdefg"
echo ${s:3:2}
# de
echo ${s:3}
# defg
echo ${s: -3:2}  # 当offset为负数时前面需有空格，以区分变量默认值
# ef
```

### 搜索与替换

**字符串头部模式匹配**：

匹配成功，删除匹配部分，返回剩余部分；匹配不成功，返回原始字符串。

原始变量不会发生变化。

```shell
# 语法：
${VARIABLE_NAME#pattern}          # 删除最短匹配
${VARIABLE_NAME##pattern}         # 删除最长匹配
${VARIABLE_NAME/#pattern/string}  # 使用string替换匹配到的内容
# 以上pattern是指匹配模式，可以使用*、?、[]等通配符
# *   可以匹配任意个字符
# ?   匹配一个字符
# []  可以匹配的字符集合

# 注：头部模式匹配是从字符串第一个字符开始匹配，第一个字符不匹配时就算不匹配

# 举例：
s=abc/def/ghi/jkl.txt
echo ${s#*}
# abc/def/ghi/jkl.txt
echo ${s#*/}
# def/ghi/jkl.txt      # 最短匹配
echo ${s#?/}
# abc/def/ghi/jkl.txt  # 不匹配输出原始字符串
echo ${s#?bc}
# /def/ghi/jkl.txt     # 最短匹配，删除abc
echo ${s#[abc]}
bc/def/ghi/jkl.txt     # 匹配到字符集合中的a
echo ${s#[abc]+}
# abc/def/ghi/jkl.txt  # 不匹配输出原始字符串，这里会匹配加号
echo ${s##*/}
# jkl.txt              # 最长匹配，可以匹配到字符串中最后一个斜杠，可用于提取路径中的文件名
echo ${s##?bc}
# /def/ghi/jkl.txt
echo ${s##?bc/}
# def/ghi/jkl.txt
echo ${s##[abc]}
# bc/def/ghi/jkl.txt
echo ${s##[def]}
# abc/def/ghi/jkl.txt
echo ${s/#abc/xyz}
# xyz/def/ghi/jkl.txt  # 字符串abc替换为xyz
```

**字符串尾部模式匹配**：

匹配成功，删除匹配部分，返回剩余部分；匹配不成功，返回原始字符串。

原始变量不会发生变化。

```shell
# 语法：
${VARIABLE_NAME%pattern}          # 删除最短匹配
${VARIABLE_NAME%%pattern}         # 删除最长匹配
${VARIABLE_NAME/%pattern/string}  # 使用string替换匹配到的内容
# 以上pattern是指匹配模式，可以使用*、?、[]等通配符
# *   可以匹配任意个字符
# ?   匹配一个字符
# []  可以匹配的字符集合

# 注：尾部模式匹配是从字符串最后一个字符开始匹配，最后一个字符不匹配时就算不匹配

# 举例：
s=abc/def/ghi/jkl.txt
echo ${s%/*}
# abc/def/ghi           # 最短匹配提取出文件路径
echo ${s%/*.txt}
# abc/def/ghi           # 最短匹配提取出文件路径
echo ${s%/*.txa}
# abc/def/ghi/jkl.txt
echo ${s%%/*}
# abc
echo ${s%%/*.txt}
# abc
echo ${s/%jkl.txt/mno.txt}
# abc/def/ghi/mno.txt
```

**字符串任意位置模式匹配**：

匹配成功，将匹配部分替换为其他字符串返回；匹配不成功，返回原字符串。

```shell
# 语法：
${VARIABLE_NAME/pattern/string}   # 最长匹配，但仅替换第一个匹配
${VARIABLE_NAME//pattern/string}  # 最长匹配，所有匹配都替换

s=abc/abc/def/abc/def/abc/ghi
echo ${s/abc/xyz}
# xyz/abc/def/abc/def/abc/ghi
echo ${s//abc/xyz}
# xyz/xyz/def/xyz/def/xyz/ghi
echo ${s/a?c/xyz}
# xyz/abc/def/abc/def/abc/ghi
echo ${s//a?c/xyz}
# xyz/xyz/def/xyz/def/xyz/ghi
s=abc:def:ghi
echo -e ${s//:/'\n'}
# abc
# def
# ghi
s=/home/root/abc.txt
echo ${s//\//\\}
# \home\root\abc.txt
echo ${s//:/\\}
# /home/root/abc.txt
```

### 改变大小写

```shell
# 语法：
${VARIABLE_NAME^^}  # 转换为大写
${VARIABLE_NAME,,}  # 转换为小写

# 举例
UPPER=upper
echo ${UPPER^^}
# UPPER
echo ${UPPER}  # 原始变量不会发生变化
# upper

LOWER=LOWER
echo ${LOWER,,}
# lower
echo ${LOWER}  # 原始变量不会发生变化
# LOWER
```

## 算数运算

### 算数表达式

**语法**：`((...))`。

以上语法会自动忽略内部空格。

```shell
((1+2))
echo $?  # 上一条命令执行的退出码，0表示成功，非0失败
# 0
((1-1))
echo $?  # 算数运算的结果为0，视为失败
# 1
$((1+2))  # 读取算数运算的结果，为3，在bash命令行中直接执行3会报错
# bash: 3: command not found
echo $((1+2))  # 显示运算结果
# 3
```

`((...))`语法支持`+`、`-`、`*`、`/`、`%`、`**`、`++`、`--`算数运算符。

```shell
echo $((2.0/2))  # 只能计算整数，否则报错
# bash: 2.0/2: syntax error: invalid arithmetic operator (error token is ".0/2")
echo $((3/2))  # 整除
# 1
a=10
echo $((a++))  # 后置++，先返回再加1，改变原始值
# 10
echo $((++a))  # 前置++，先加1再返回，改变原始值
# 12
echo ${a}
# 12
a=1;b=2
echo $(((a++)+b))
# 3
echo ${a}
# 2
echo $(((++a)+b))
# 5
a=1;b=2
echo $(((a+b)*b))  # ()可以改变运算优先级
# 6
echo $(($((a+b))*b))  # 语法可以嵌套
# 6
echo $(($(("a"+"b"))*"b"))  # 语法内字符串会认为是变量
# 6
```

`((...))`语法支持`<<`、`>>`、`&`、`|`、`~`、`!`、`^`位运算符。

`((...))`语法支持`<`、`>`、`<=`、`>=`、`==`、`!=`、`&&`、`||`、`?:`逻辑运算符。

逻辑运算为真返回1，否则返回0。

`((...))`语法支持`=`、`+=`、`-=`、`*=`、`/=`、`%=`、`<<=`、`>>=`、`&=`、`|=`、`^=`赋值运算符。

`((...))`语法内可以进行求值运算，如：`echo $((foo = 1 + 2, 3 * 4))`。

### expr命令

`expr`命令支持算数运算，但只支持整数运算。

```shell
expr 2*3
# 2*3
expr 2 * 3
# 6
expr 2 * 3 + 4
# 10
a=3
expr a + 2
# expr: non-integer argument
expr ${a} + 2
# 5
expr 3.5 + 2
# expr: non-integer argument
```

### 进制

bash中数据默认为十进制，算数表达式中也可以使用其他进制。

- number：十进制
- 0number：八进制
- 0xnumber：十六进制
- base#number：base进制

## 行操作

bash内置Readline库，具有这个库提供的很多"行操作"功能，如命令自动补全，可大大加快操作速度。

### 光标移动

Readline提供快速移动光标的快捷键。

- `Ctrl+a`：移到行首
- `Ctrl+b`：向行首移动一个字符，与左箭头作用相同
- `Ctrl+e`：移到行尾
- `Ctrl+f`：向行尾移动一个字符，与右箭头作用相同
- `Alt+f`：移动到当前单词的词尾
- `Alt+b`：移动到当前单词的词首

### 清除屏幕

快捷键`Ctrl+l`等价于`clear`命令。

### 编辑操作

- `Ctrl+d`：删除光标位置的字符
- `Ctrl+w`：删除光标前面的单词
- `Ctrl+t`：光标位置的字符与它前面一位的字符交换位置
- `Alt+t`：光标位置的词与它前面一位的词交换位置
- `Alt+l`：将光标位置至词尾转为小写
- `Alt+u`：将光标位置至词尾转为大写

注：使用`Ctrl+d`时，如果当前行没有任何字符，会导致退出当前shell。

- `Ctrl+k`：剪切光标位置到行尾的文本
- `Ctrl+u`：剪切光标位置到行首的文本
- `Alt+d`：剪切光标位置到词尾的文本
- `Alt+Backspace`：剪切光标位置到词首的文本
- `Ctrl+y`：在光标位置粘贴文本

### 自动补全

- `Tab`：完成自动补全
- `Alt+?`：列出可能的补全，与连按两次Tab键作用相同
- `Alt+/`：尝试文件路径补全
- `Ctrl+x/`：先按`Ctrl+x`，再按`/`，等同于`Alt+?`，列出可能的文件路径补全
- `Alt+!`：命令补全
- `Ctrl+x!`：先按`Ctrl+x`，再按`!`，等同于`Alt+!`，命令补全
- `Alt+~`：用户名补全
- `Ctrl+x~`：先按`Ctrl+x`，再按`~`，等同于`Alt+~`，用户名补全
- `Alt+$`：变量名补全
- `Ctrl+x$`：先按`Ctrl+x`，再按`$`，等同于`Alt+$`，变量名补全
- `Alt+@`：主机名补全
- `Ctrl+x@` ：先按`Ctrl+x` ，再按`@`，等同于`Alt+@`，主机名补全
- `Alt+*` ：在命令行一次性插入所有可能的补全
- `Alt+Tab` ：尝试用`.bash_history`里面以前执行命令，进行补全

### 操作历史

环境变量`HISTFILE`总是指向操作历史记录文件。

```shell
echo ${HISTFILE}
# /root/.bash_history
```

方向键`↑`和`↓`，可以快速浏览上一条和下一条命令。

`!string`表示找出操作历史之中，最近的那一条以string开头的命令并执行。

`Ctrl+r`会显示操作历史，可以用方向键上下移动，选择其中要执行的命令，也可以键入命令的首字母查询并显示匹配的结果。

`history`命令可以显示`HISTFILE`指向文件的内容，显示时每一行的命令都会有编号，`!编号`可以执行命令。

- `Ctrl + p`：显示上一个命令，等同上箭头
- `Ctrl + n`：显示下一个命令，等同下箭头
- `Alt + <`：显示第一个命令
- `Alt + >`：显示最后一个命令，即当前的命令
- `Ctrl + o`：执行历史文件里面的当前条目，并自动显示下一条命令
- `!!`：执行上一个命令
- `!n`：执行历史文件里面行号为n的命令
- `!-n`：执行当前命令之前n条的命令
- `!string`：执行最近一个以指定字符串string开头的命令
- `!?string`：执行最近一条包含字符串string的命令
- `^string1^string2`：执行最近一条包含string1的命令，将其替换成string2

### 其它快捷键

- `Ctrl+j`：等同于回车键(LINEFEED)
- `Ctrl+m`：等同于回车键(CARRIAGE RETURN)
- `Ctrl+o`：等同于回车键，并展示操作历史的下一个命令
- `Ctrl+v`：将下一个输入的特殊字符变成字面量，比如回车变成`^M`
- `Ctrl+[`：等同于`ESC`
- `Alt+.`：插入上一个命令的最后一个词
- `Alt+_`：等同于`Alt+.`

## 目录堆栈

为了方便用户在不同目录之间切换，bsh提供了目录堆栈功能。

- `cd -`返回前一次的目录
- `pushd`、`popd`用于操作目录堆栈
  - `pushd dirname`表示将目录推入堆栈顶部
  - `popd`表示移除并进入堆栈顶部记录
  - 两个命令都支持`-n`参数，表示只操作堆栈不改变目录
  - 两个命令都支持整数参数，整数表示堆栈中指定位置的记录(从0开始)作为操作对象，这是不切换目录
    - 正数：从栈顶算起
    - 负数：从栈底算起
- `dirs`显示目录堆栈的内容
  - `-c`：清空目录栈
  - `-l`：用户主目录不显示波浪号前缀，打印完整的目录
  - `-p`：每行一个条目打印目录栈，默认是打印在一行
  - `-v`：每行一个条目，每个条目之前显示位置编号(从0开始)
  - `+N`：N为整数，表示显示堆顶算起的第N个目录，从0开始
  - `-N`：N为整数，表示显示堆底算起的第N个目录，从0开始

## bash脚本

### 指定解释器

脚本的第一行通常是指定解释器，即脚本通过什么解释器执行。

指定解释器必须以`#!`开头，然后紧随脚本解释器的位置，如下：

```shell
#!/bin/sh
#!/bin/bash
# 以上形式，解释不在bin目录下脚本就无法执行了，因此可以写成如下形式：
#!/usr/bin/env bash
# 以上形式使用env命令获取了bash可执行文件的位置
```

指定解释器不是必须的，但不指定解释器时，执行时需要手动将脚本输入给解释器，而指定解释器时可以执行。

```shell
/bin/bash ./scripts.sh  # 不指定解释器
./scripts.sh            # 指定解释器
```

### 执行权限和路径

```shell
# 给所有用户执行权限
chmod +x script.sh

# 给所有用户读权限和执行权限
chmod +rx script.sh
# 或者
chmod 755 script.sh

# 只给脚本拥有者读权限和执行权限
chmod u+rx script.sh

# 脚本的权限通常设为755(拥有者有所有权限，其他人有读和执行权限)或者700(只有拥有者可以执行)
```

### env命令

`env`命令总是指向`/usr/bin/env`文件，或者说，这个二进制文件总是在目录`/usr/bin`。

`#!/usr/bin/env NAME`就是让shell查找`$PATH`环境变量里面第一个匹配的`NAME`。

当不知道某个命令的具体路径，或者希望兼容其他用户的机器时，这样写就很有用。

env 命令的参数如下：

- `-i`(`--ignore-environment`)：不带环境变量启动
- `-u`(`--unset=NAME`)：从环境变量中删除一个变量

### 注释

bash脚本中，`#`表示注释，可以放在行首，也可以放在行尾。

### 脚本参数

调用脚本的时候，脚本文件名后面可以带有参数。

```shell
script.sh word1 word2 word3
```

上面例子中，script.sh是一个脚本文件，word1、word2、word3是三个参数。

脚本文件内部，可以使用特殊变量，引用这些参数。

- `$0`：脚本文件名，即script.sh
- `$1`~`$9`：对应脚本的第一个参数到第九个参数
- `$#`：参数的总数
- `$@`：全部的参数，参数之间使用空格分隔
- `$*`：全部的参数，参数之间使用变量`$IFS`值的第一个字符分隔，默认为空格，但是可以自定义

如果脚本的参数多于9个，那么第10个参数可以用`${10}`的形式引用，以此类推。

注意：如果命令是`command -o foo bar`，那么`-o`是`$1`，`foo`是`$2`，`bar`是`$3`。

### shift命令

`shift`命令可以改变脚本参数，每次执行都会移除脚本当前的第一个参数`$1`。

移除第一个参数后，`$2`变`$1`、`$3`变`$2`，以此类推。

`while`循环结合`shift`命令，也可以读取每一个参数。

```shell
#!/bin/bash

echo "一共输入了 $# 个参数"

while [ "$1" != "" ]; do
  echo "剩下 $# 个参数"
  echo "参数：$1"
  shift
done
```

`shift`可以接受一个整数作为参数，指定所要移除的参数个数，默认为1。

```shell
shift 3  # 令移除前三个参数，原来的 $4 变成 $1
```

### getopts命令

`getopts`命令用在脚本内部，可以解析复杂的脚本命令行参数。

命令通常与`while`循环一起使用，取出脚本所有的带有前置连词线`-`的参数。

```shell
getopts optstring name
```

它带有两个参数：

1. 参数`optstring`是字符串，给出脚本所有的连词线参数，如：
   - 某个脚本可以有三个配置项参数`-l`、`-h`、`-a`，其中只有`-a`可以带有参数值，而`-l`和`-h`是开关参数
   - 那么`getopts`的第一个参数写成`lha:`，顺序不重要
     - `a`后面有一个`:`，表示该参数带有参数值
     - `getopts`规定带有参数值的配置项参数，后面必须带有一个冒号`:`
2. 参数`name`是一个变量名，用来保存当前取到的配置项参数，即`l`、`h`、`a`

```shell
# 循环不断执行：getopts 'lha:' OPTION
# 执行时会读取一个连词线参数，有值时会同时读取对应的参数值
# 然后进入循环体执行
while getopts 'lha:' OPTION; do  # OPTION会保存连线词参数
  case "${OPTION}" in
    l)
      echo "option l"
      ;;
    h)
      echo "option h"
      ;;
    a)
      avalue="${OPTARG}"  # 环境变量OPTARG保存的是参数值
      echo "option a=${avalue}"
      ;;
    ?)  # 用户输入了没有指定的参数，OPTION=?
      echo "script usage: $(basename $0) [-l] [-h] [-a value]" >&2
      exit 1
      ;;
  esac
done
# 只要遇到不带连词线的参数， getopts就会执行失败，从而退出while循环

shift "$(($OPTIND - 1))"
# 变量$OPTIND在getopts开始执行前是1，然后每次执行就会加1
# 退出while循环时，意味着连词线参数全部处理完毕
# 此时，$OPTIND-1就是已经处理的连词线参数个数
# 使用shift命令是为了将这些全部参数移除，以保证后面的代码可以用$1、$2等
```

### 配置项参数终止符

`--`称为配置项参数终止符。

`--`表示命令选项的结束，之后只接受位置参数。

```shell
ls -l ~
# total 4
# drwxr-xr-x 2 root root 4096 Nov 12 16:21 work
ls -- -l ~
# ls: cannot access '-l': No such file or directory
# /root:
# work
```

### exit命令

`exit`用于终止当前脚本的执行，并向shell返回一个退出码作为脚本退出状态。

退出码为0表示正常退出，退出码非0表示异常退出：

- 0：正常退出
- 1：发生错误
- 2：用法不对
- 126：非可执行脚本
- 127：没有发现命令
- 128+N：表示被信号N终止
- ...

### 命令执行结果

`$?`用于读取前一个命令的返回值，在脚本中可以对命令执行结果进行判断。

### source命令

`source`用于执行脚本，常用于重新加载配置文件。

使用`source`命令在当前shell执行其它脚本时不会新建子shell，因此不需要`export`变量。

`source`还可以用于加载外部库，这样在当前脚本中就可以使用外部库定义的函数。

一个`.`是`source`的简写形式。

### alias别名

`alias`用来定义命令的别名，`unalias`可以删除别名定义。

```shell
# 语法：
alias NAME=DEFINITION

# 举例：
alias rmi="rm -i"
unalias rmi
```

## read命令

脚本执行时需要由用户输入数据时可以使用read命令读入用户输入数据。

```shell
read [-options] [variable...]
# options   选项参数
# variable  用来保存输入数值的一个或多个变量名
#     不提供变量名时，环境变量REPLY会包含用户输入的一整行数据
```

如下脚本：

```shell
#!/bin/bash

echo Please, enter your firstname and lastname
read FN LN
echo "Hi! $LN, $FN !"

echo -n "Enter one or more values > "
read
echo "REPLY = '$REPLY'"
```

参数：

- `-t` 设置超时秒数，超时后脚本将放弃等待继续执行，环境变量TMOUT也有同样的作用
- `-p` 提示信息用于提示用户输入
- `-a` 把用户的输入赋值给一个数组，从0号位置开始
- `-n` 只读取n个字符作为变量值，而不进行整行读取
- `-e` 允许用户输入时使用readline库提供的快捷键

```shell
#!/bin/bash

echo -n "输入一些文本 > "
if read -t 3 response; then
  echo "用户已经输入了"
else
  echo "用户没有输入"
fi

TMOUT=3
read response

read -p "Enter one or more values > "
echo "REPLY = '$REPLY'"

read -a values  # 可以通过索引访问数组
echo ${values[0]}

read -n 3 value
echo ${value}
```

其它参数：

- `-d delimiter` 定义字符串delimiter的第一个字符作为用户输入的结束，而不是一个换行符
- `-r` raw模式，表示不把用户输入的反斜杠字符解释为转义字符。
- `-s` 使得用户的输入不显示在屏幕上，这常常用于输入密码或保密信息
- `-u fd` 使用文件描述符fd作为输入

read读取数据默认以空格分隔，可以通过自定义环境变量`IFS`修改分隔标志。

以下设置`IFS`为`:`，分解未见内容：

```shell
# 方式1：
IFS=":" read user pw uid gid name home shell <<< "$file_info"

# 方式2：
OLD_IFS="$IFS"
IFS=":"
read user pw uid gid name home shell <<< "$file_info"
IFS="$OLD_IFS"

# 方式1中，IFS与命令在同一行，IFS的改变仅对后面的命令生效，执行后，IFS恢复原来的值
# 如果IFS与命令不写在同一行，就需要使用方式2了
```

## 条件判断

### if结构

语法：

```shell
if commands; then
  commands
[elif commands; then
  commands...]
[else
  commands]
fi

# then与if或elif写在同一行时需要分号分隔，写在两行时不需要
if commands
then
  commands
[elif commands
then
  commands...]
[else
  commands]
fi

# 单行形式
if commands; then commands; fi

# 注意：
# 1. if后可以接一条命令，命令执行成功，意味着判断条件成立
# 2. if后可以接多条命令，最后一个命令成功，就意味着判断条件成立
# 3. elif部分可以有多个
```

### test命令

if结构的条件判断一般使用`test`命令，有三种形式：

```shell
# 方式1：
test expression
# 方式2：
[ expression ]
# 方式3：
[[ expression ]]

# 以上：
#   方式3可以支持正则判断
#   expression是一个表达式
#       test执行成功，返回0，表达式为真
#       test执行失败，返回1，表达式为假
#       表达式为0表示条件为真，否则条件为假
#   方式2和方式3中两侧的中括弧需与中间的expression之间有空格

# 举例：
[ -f /etc/hosts ]
echo $?
# 0
if [ -e /etc/hosts ]; then echo "hosts found."; fi
# hosts found.
```

### 文件判断

- `[ -a file ]`：如果file存在，则为true
- `[ -b file ]`：如果file存在并且是一个块(设备)文件，则为true
- `[ -c file ]`：如果file存在并且是一个字符(设备)文件，则为true
- `[ -d file ]`：如果file存在并且是一个目录，则为true
- `[ -e file ]`：如果file存在，则为true
- `[ -f file ]`：如果file存在并且是一个普通文件，则为true
- `[ -g file ]`：如果file存在并且设置了组ID，则为true
- `[ -G file ]`：如果file存在并且属于有效的组ID，则为true
- `[ -h file ]`：如果file存在并且是符号链接，则为true
- `[ -k file ]`：如果file存在并且设置了它的"sticky bit"，则为true
- `[ -L file ]`：如果file存在并且是一个符号链接，则为true
- `[ -N file ]`：如果file存在并且自上次读取后已被修改，则为true
- `[ -O file ]`：如果file存在并且属于有效的用户ID，则为true
- `[ -p file ]`：如果file存在并且是一个命名管道，则为true
- `[ -r file ]`：如果file存在并且可读(当前用户有可读权限)，则为true
- `[ -s file ]`：如果file存在且其长度大于零，则为true
- `[ -S file ]`：如果file存在且是一个网络socket，则为true
- `[ -t fd ]`：  如果fd是一个文件描述符，并且重定向到终端，则为true(可用于判断是否重定向了标准输入输出错误)
- `[ -u file ]`：如果file存在并且设置了setuid位，则为true
- `[ -w file ]`：如果file存在并且可写(当前用户拥有可写权限)，则为true
- `[ -x file ]`：如果file存在并且可执行(有效用户有执行\搜索权限)，则为true
- `[ file1 -nt file2 ]`：如果file1比file2的更新时间近，或者file1存在而file2不存在，则为true
- `[ file1 -ot file2 ]`：如果file1比file2的更新时间旧，或者file2存在而file1不存在，则为true
- `[ file1 -ef file2 ]`：如果file1和file2引用相同的设备和inode编号，则为true

以上file实际使用时建议放在双引号中，以防止file字符串为空：

- `[ -e ]`：判断为真
- `[ -e "" ]`：判断为假

### 字符串判断

- `[ string ]`：如果string不为空，则判断为真
- `[ -n string ]`：如果string不为空，则判断为真
- `[ -z string ]`：如果string的长度为零，则判断为真
- `[ string1 = string2 ]`：如果string1和string2相同，则判断为真
- `[ string1 == string2 ]`：等同于`[ string1 = string2 ]`
- `[ string1 != string2 ]`：如果string1和string2不相同，则判断为真
- `[ string1 '>' string2 ]`：如果按照字典顺序string1排列在string2之后，则判断为真
- `[ string1 '<' string2 ]`：如果按照字典顺序string1排列在string2之前，则判断为真

注：`test`命令内部的`<`、`>`必须用引号括起来，或者使用反斜杠转义，否则会被shell解释为重定向操作。

```shell
if [ "abc" '>' "abd" ]; then echo ">"; else echo "<"; fi
# <
if [ "abc" '<' "abd" ]; then echo "<"; else echo ">"; fi
# <
```

### 整数判断

- `[ integer1 -eq integer2 ]`：两个数相等，则为true (equal)
- `[ integer1 -ne integer2 ]`：两个数不相等，则为true (not equal)
- `[ integer1 -le integer2 ]`：integer1小于等于integer2，则为true (less than or equal to)
- `[ integer1 -lt integer2 ]`：integer1小于integer2，则为true (less than)
- `[ integer1 -ge integer2 ]`：integer1大于等于integer2，则为true (greater than or equal to)
- `[ integer1 -gt integer2 ]`：integer1大于integer2 ，则为true (greater than)

### 正则判断

`[[ expression ]]`这种判断形式，支持正则表达式。

```shell
# 语法：
[[ string =~ regex ]]
# regex是一个正则表达式，=~是正则比较运算符

INT=-5; if [[ "$INT" =~ ^-?[0-9]+$ ]]; then echo "an integer."; else echo "not an integer."; fi
# an integer.
```

### 逻辑运算

- `AND`：符号`&&`，也可使用参数`-a`
- `OR`：符号`||`，也可使用参数`-o`
- `NOT`：符号`!`。

```shell
MIN_VAL=1
MAX_VAL=100
INT=50

# ||和&&用于[[...]]
# -a和-o用于[...]
if [[ "$INT" =~ ^-?[0-9]+$ ]]; then
  if [[ $INT -ge $MIN_VAL && $INT -le $MAX_VAL ]]; then
    echo "$INT is within $MIN_VAL to $MAX_VAL."
  else
    echo "$INT is out of range."
  fi
else
  echo "INT is not an integer."
fi

if [[ "$INT" =~ ^-?[0-9]+$ ]]; then
  if [ $INT -ge $MIN_VAL -a $INT -le $MAX_VAL ]; then
    echo "$INT is within $MIN_VAL to $MAX_VAL."
  else
    echo "$INT is out of range."
  fi
else
  echo "INT is not an integer."
fi

if [[ "$INT" =~ ^-?[0-9]+$ ]]; then
  if [[ $INT -lt $MIN_VAL || $INT -gt $MAX_VAL ]]; then
    echo "$INT is out of range."
  else
    echo "$INT is within $MIN_VAL to $MAX_VAL."
  fi
else
  echo "INT is not an integer."
fi

if [[ "$INT" =~ ^-?[0-9]+$ ]]; then
  if [ $INT -lt $MIN_VAL -o $INT -gt $MAX_VAL ]; then
    echo "$INT is out of range."
  else
    echo "$INT is within $MIN_VAL to $MAX_VAL."
  fi
else
  echo "INT is not an integer."
fi

# ()用于[...]必须进行转义
# ()用于[[...]]不需要进行转义
if [ \( $INT -lt $MIN_VAL -o $INT -gt $MAX_VAL \) ]; then
  echo "$INT is out of range."
else
  echo "$INT is within $MIN_VAL to $MAX_VAL."
fi

if [[ ($INT -lt $MIN_VAL || $INT -gt $MAX_VAL) ]]; then
  echo "$INT is out of range."
else
  echo "$INT is within $MIN_VAL to $MAX_VAL."
fi

# !
if [[ ! ("$INT" -lt $MIN_VAL || "$INT" -gt $MAX_VAL) ]]; then
  echo "$INT is within $MIN_VAL to $MAX_VAL."
else
  echo "$INT is out of range."
fi
```

### 算数判断

`((...))`可以作为算数条件进行算数运算的判断。

算数运算的结果为非0值，表示判断成立，与test命令返回值正好相反。

```shell
if ((2+3)); then
  echo "6"
fi

if ((2-2)); then
  echo "0"
fi

if ((value=2)); then
  echo ${value}
fi

if (( ((4 % 2)) == 0)); then
  echo "INT is even."
else
  echo "INT is odd."
fi
```

### case结构

`case`结构用于多值判断，可以为每个值指定对应的命令。

```shell
case expression in    # expression是一个表达式
  pattern )           # pattern是表达式的值或者一个匹配模式，可以有多条，用来匹配多个值
    commands ;;       # 每个pattern以;;结束
  pattern )
    commands ;;
  ...
  *)                  # 通配符*用于匹配其它情况，类似c语言中的default和if-else中的else分支
    commands ;;
esac
```

以下举例用于判断当前的操作系统：

```shell
#!/bin/bash

OS=$(uname -s)

case "${OS}" in
  FreeBSD)
    echo "This is FreeBSD"
    ;;
  Darwin)
    echo "This is Mac OSX"
    ;;
  AIX)
    echo "This is AIX"
    ;;
  Minix)
    echo "This is Minix"
    ;;
  Linux)
    echo "This is Linux"
    ;;
  *)
    echo "Failed to identify this OS"
    ;;
esac
```

`case`的匹配模式可以使用各种通配符，下面是一些例子：

- `a)`：匹配`a`
- `a|b)`：匹配`a`或`b`
- `[[:alpha:]])`：匹配单个字母
- `???)`：匹配3个字符的单词
- `*.txt)`：匹配`.txt`结尾
- `*)`：匹配任意输入

```shell
#!/bin/bash

echo -n "输入一个字母或数字 > "

read character

case ${character} in
  [[:lower:]] | [[:upper:]] )
    echo "输入了字母 ${character}"
    ;;
  [0-9] )
    echo "输入了数字 ${character}"
    ;;
  * )
    echo "输入不符合要求"
    ;;
esac
```

bash 4.0之后，case结构允许匹配多个条件，这时需要使用`;;&`终止每个条件块。

```shell
#!/bin/bash

read -n 1 -p "Type a character > "
echo  # 空行

case ${REPLY} in
  [[:upper:]])
    echo "'${REPLY}' is upper case." 
    ;;&
  [[:lower:]])
    echo "'${REPLY}' is lower case." 
    ;;&
  [[:alpha:]])
    echo "'${REPLY}' is alphabetic." 
    ;;&
  [[:digit:]])
    echo "'${REPLY}' is a digit." 
    ;;&
  [[:graph:]])
    echo "'${REPLY}' is a visible character." 
    ;;&
  [[:punct:]])
    echo "'${REPLY}' is a punctuation symbol." 
    ;;&
  [[:space:]])
    echo "'${REPLY}' is a whitespace character." 
    ;;&
  [[:xdigit:]])
    echo "'${REPLY}' is a hexadecimal digit." 
    ;;&
esac
```

## 循环

bash提供`for`、`while`、`until`三种循环。

### while循环

语法：

```shell
# 形式1
while condition; do    # condition是循环条件，可以使用test命令，与if结构的判断条件写法一致
  commands
done

# 形式2
while condition
do
  commands
done

# 形式3
while condition; do commands; done
```

使用举例：

```shell
while true
do
  echo 'Hi, while looping ...';
done

number=0
while [ "${number}" -lt 10 ]; do
  echo "Number = ${number}"
  number=$((number + 1))
done

# 条件部分可以使用命令，当有多个命令时，执行成功与否只看最后一个命令
# 如下echo总是执行成功，因此以下就是个死循环
while echo 'ECHO'; do echo 'Hi, while looping ...'; done
```

### until循环

until循环是不符合判断条件时就会一直执行，符合判断条件循环退出。

语法：

```shell
# 形式1
until condition; do
  commands
done

# 形式2
until condition
do
  commands
done

# 形式3
until condition; do commands; done
```

使用举例：

```shell
number=0
until [ "${number}" -ge 10 ]; do
  echo "Number = ${number}"
  number=$((number + 1))
done

# 以下条件一直为false，死循环
until false; do echo 'Hi, until looping ...'; done
```

### for...in循环

`for...in`循环用于遍历列表的每一项。

语法：

```shell
# 形式1
for variable in list; do
  commands
done

# 形式2
for variable in list
do
  commands
done

# 注意：in list部分可以省略，省略后list默认等于脚本($@)或函数的所有参数
```

使用举例：

```shell
for i in word1 word2 word3; do
  echo $i  # i依次等于word1、word2、word3
done

for i in *.png; do  # *.png会扩展称为当前目录中的所有PNG图片
  ls -l $i
done
```

### for循环

for循环还支持C语言循环语法。

```shell
# 语法：
for (( expression1; expression2; expression3 )); do
  commands
done
# expression1用来初始化循环条件
# expression2用来决定循环结束的条件
# expression3在每次循环迭代的末尾执行，用于更新值
# 循环条件放在双重圆括号之中
# 圆括号之中使用变量，不需要加上$符号

# 举例：
for (( i=0; i<5; i=i+1 )); do
  echo $i
done
```

### break和continue

`break`用于立刻终止循环。

`continue`用于终止本次循环，立刻跳入下次循环。

### select结构

`select`结构主要用于生成简单的菜单，与`for...in`语法基本一致。

语法：

```shell
select name
[in list]
do
  commands
done
# 处理过程：
# 1. select生成一个菜单，内容是列表list的每一项，并且每一项前面还有一个数字编号
# 2. bash提示用户选择一项，输入它的编号
# 3. 用户输入以后，bash会将该项的内容存在变量name，该项的编号存入环境变量REPLY
# 4. 如果用户没有输入，就按回车键，bash会重新输出菜单，让用户选择
# 5. 执行命令体commands
# 6. 执行结束后，回到第一步，重复这个过程
# 7. 按下ctrl+c可以退出执行
```

使用示例：

```shell
#!/bin/bash

echo "Which Operating System do you like?"

select os in Ubuntu LinuxMint Windows8 Windows7 WindowsXP
do
  case ${os} in
    "Ubuntu"|"LinuxMint")
      echo "I also use ${os}."
      ;;
    "Windows8" | "Windows10" | "WindowsXP")
      echo "Why don't you try Linux?"
      ;;
    *)
      echo "Invalid entry."
      ;;
  esac
  # break  # 使用break可以跳出select循环
done
```

## bash函数

- 函数与脚本同名，函数优先执行
- 函数与别名同名，别名优先执行

```shell
# 语法：
fn() {
  # codes
}

function fn() {
  # codes
}

# 举例：
function helloworld() {
  echo "Hello, world."
}
```

调用时直接写函数名，参数跟在函数名后面。

删除函数使用`unset`命令。

`declare`命令可用于查看当前shell已经定义的所有函数。

### 参数变量

函数体内可以使用参数变量，获取函数参数。

函数的参数变量，与脚本参数变量是一致的。

- `$1~$9`：函数的第1个到第9个参数
- `$0`：函数所在的脚本名
- `$#`：函数的参数总数
- `$@`：函数的全部参数，参数之间使用空格分隔
- `$*`：函数的全部参数，参数之间使用变量`$IFS`值的第一个字符分隔，默认为空格，可以自定义

参数多于9个时，第10个参数可以使用`${10}`的形式引用。

```shell
#!/bin/bash

function alice() {
  echo "alice: $@"
  echo "$0: $1 $2 $3 $4"
  echo "$# arguments"
}

alice in wonderland
```

### return命令

`return`命令用于从函数返回一个值。

函数执行到这条命令，就不再往下执行了，直接返回了。

函数将返回值返回给调用者。

如果命令行直接执行函数，下一个命令可以用`$?`拿到返回值。

`return`后面不跟参数，只用于返回也是可以的。

### 全局变量和局部变量

一般情况下声明的变量均为全局变量。

`local`命令用于声明局部变量。

## 数组

数组(array)是包含多个值的变量。

数组成员的编号从0开始，数量没有上限，不要求成员索引连续。

### 创建数组

```shell
ARRAY[INDEX]=value
# ARRAY是数组名字，即变量名
# INDEX是一个大于等于的整数，也可以是算数表达式
# 注意：数组第一个元素的下标是0，而不是1

ARRAY=(value1 value2 ... valueN)                          # 顺序赋值
ARRAY=([index1]=value1 [index2]=value2 ... [indexN]=valueN)  # 指定位置赋值
ARRAY=([index1]=value1 [index2]=value2 ... [indexK]=valueK valueN)  # valueN的索引为indexK+1
# 一次性赋值方式创建数组

# 定义数组时可以使用通配符
mp3s=( *.mp3 )  # 将当前目录的所有MP3文件，放进一个数组

# 使用declare声明一个数组
declare -a ARRAY
# 使用read将输入读入一个数组
read -a ARRAY
```

### 读取数组

```shell
echo ${ARRAY[index]}
# 读取数组指定位置的成员
# 必须使用{}，否则会读取ARRAY的值，然后索引部分原样输出

echo ${foo[@]}
echo ${foo[*]}
# @和*是数组的特殊索引，表示返回数组的所有成员
```

如下遍历数组：

```shell
for i in "${ARRAY[@]}"; do
  echo $i
done
```

`@`和`*`是否放在`""`中是有差别的，遍历数组时最好放在`""`中，原因如下：

```shell
activities=( swimming "water skiing" canoeing "white-water rafting" surfing )

for act in ${activities[@]}; do
  echo "Activity: $act";
done
# Activity: swimming
# Activity: water
# Activity: skiing
# Activity: canoeing
# Activity: white-water
# Activity: rafting
# Activity: surfing

for act in ${activities[*]}; do
  echo "Activity: $act";
done
# Activity: swimming
# Activity: water
# Activity: skiing
# Activity: canoeing
# Activity: white-water
# Activity: rafting
# Activity: surfing

for act in "${activities[@]}"; do  # 放在双引号中遍历可以返回正确的结果
  echo "Activity: $act";
done
# Activity: swimming
# Activity: water skiing
# Activity: canoeing
# Activity: white-water rafting
# Activity: surfing

for act in "${activities[*]}"; do  # 放在双引号中会理解为一个字符串
  echo "Activity: $act";
done
# Activity: swimming water skiing canoeing white-water rafting surfing

# 所以，拷贝数组最好写成以下形式
ARRAY1=( "${ARRAY2[@]}" )
```

### 默认位置

读取数组成员时，如果没有指定哪一个位置的成员，默认使用0号位置成员。

引用一个不带下标的数组变量，则引用的是0号位置的数组元素。

### 数组长度

```shell
${#array[*]}  # 返回数组长度
${#array[@]}  # 返回数组长度
${#array[index]}  # 返回index位置元素的长度
```

### 提取数组序号

```shell
# 返回数组的成员序号，即哪些位置是有值的
${!array[@]}
${!array[*]}

# 举例：
arr=([2]=a [5]=b c d)
for i in ${!arr[@]}; do
  echo ${i}:${arr[i]}
done
# 2:a
# 5:b
# 6:c
# 7:d
```

### 提取数组成员

```shell
# 可以提取数组成员
${array[@]:position:length}

# 使用举例：
food=( apples bananas cucumbers dates eggs fajitas grapes )
echo ${food[@]:1:1}
# bananas
echo ${food[@]:1:3}
# bananas cucumbers dates
echo ${food[@]:1}  # length参数省略时，返回指定位置开始的所有成员
# bananas cucumbers dates eggs fajitas grapes
```

### 追加数组成员

数组末尾追加成员，可以使用`+=`运算符。

`+=`可以自动的将值追加到数组末尾，否则需要知道数组的最大序号。

```shell
foo=(a b c)
echo ${foo[@]}
# a b c
foo+=(d e f)
echo ${foo[@]}
# a b c d e f
```

### 删除数组

`unset`命令或将成员值设置为空值，可以将数组成员删除。

直接将数组变量赋值为空字符串，相当于删除数组的第一个成员。

`unset ARRAYNAME`用于清空数组。

### 关联数组

`declare -A`可以声明关联数组。

整数索引的数组可以直接使用变量名创建数组，关联数组必须使用以上命令创建。

访问关联数组成员的方式，几乎与整数索引数组相同。

```shell
declare -A colors

colors["red"]="#ff0000"
colors["green"]="#00ff00"
colors["blue"]="#0000ff"

echo ${colors["blue"]}
```

## set命令

set命令用来修改子shell环境的参数，即用于定制环境。

```shell
set # 直接运行set命令会显示所有环境变量和shell函数
```

### set -u

一般情况下，遇到不存在的变量，脚本会继续向下执行，但大多数情况这不是开发者想要的行为。

在脚本头部加上`set -u`命令，遇到不存在的变量时会报错并停止执行。

```shell
#!/usr/bin/env bash
# test.sh

set -u    # 等价于 set -o nounset

echo ${abc}
# ./test.sh: line 6: abc: unbound variable
# 输出以上内容并停止执行
echo abc
```

### set -x

`set -x`用于在运行命令前先输出执行的命令，以免无法区分运行结果是某个命令产生的。

`set +x`用于关闭命令输出。

`set -x`等价于`set -o xtrace`。

```shell
#!/usr/bin/env bash
# test.sh

set -x    # 等价于 set -o xtrace

abc=abc
echo ${abc}

echo 123

set +x

echo 456

# 输出：
# + abc=abc    # 输出的命令前面有+号
# + echo abc
# abc
# + echo 123
# 123
# + set +x
# 456
```

### bash错误处理

一般情况下，执行命令报错时，bash会忽略这个错误，继续向下执行。

实际开发中，如果某个命令失败，往往需要停止脚本执行，一般有以下三种写法：

```shell
# 方法1：
command || { echo "command failed"; exit 1; } # 在逻辑运算中，命令返回0认为是true

# 方法2：
if ! command; then echo "command failed"; exit 1; fi

# 方法3：
command
if [ "$?" -ne 0 ]; then echo "command failed"; exit 1; fi
```

### set -e

`set -e`命令使脚本只要发生错误就停止执行，`set +e`命令用于关闭。

### set -o pipefail

`set -e`不适用于管道命令。

管道命令是多个子命令通过管道运算符`|`组合成一个大的命令，bash会把最后一个子命令的返回值作为整个大命令的返回值。

即：最后一个子命令只要不失败，管道命令执行总会成功。

`set -o pipefail`命令用于解决上述问题，只要一个子命令失败，整个管道命令就失败，脚本会终止执行。

### 其它参数

- `set -n`：等同于`set -o noexec`，不运行命令，只检查语法是否正确
- `set -f`：等同于`set -o noglob`，不对通配符进行文件名扩展
- `set -v`：等同于`set -o verbose`，打印shell接收到的每一行输入

`set +f`、`set +v`用于关闭`set -f`和`set -v`的功能。

以上介绍的参数可以放在一起使用：

```shell
# 方法1：
set -euxo pipefail

# 方法2：
set -eux
set -o pipefail
```

执行bash脚本时可以通过命令行传入这些参数，如：`bash -euxo pipefail test.sh`。

## 脚本除错方法

编写shell脚本时，一定要考虑命令执行失败的情况，否则很容易出错。

除错方法：

- 使用`set -x`：执行命令前会打印命令，出错易查
- 使用环境变量：
  - `LINENO`：返回所在脚本文件的行号
  - `FUNCNAME`：返回一个数组，内容是当前函数调用堆栈，0号成员是当前调用函数，1号成员是调用当前函数的函数
  - `BASH_SOURCE`：返回一个数组，内容是当前脚本调用栈，0号成员是当前脚本，1号成员是调用当前脚本的脚本
  - `BASH_LINENO`：返回一个数组，内容是每一轮调用对应的行号
    - `${BASH_LINENO[$i]}`与`${FUNCNAME[$i]}`是一一对应关系

## 启动环境

用户每次使用shell，都会开启一个与shell的session。

session有两种类型：登录session(login shell)、非登录session(non-login shell)。

### 登录session

登录session是用户登录系统以后，系统为用户开启的原始session，通常需要用户输入用户名和密码进行登录。

登录session一般进行整个系统环境的初始化，启动的初始化脚本依次如下：

1. `/etc/profile`：所有用户的全局配置脚本
2. `/etc/profile.d`：目录中所有的`.sh`文件
3. `~/.bash_profile`：用户的个人配置脚本
     - 注：如果脚本存在，则执行完成后不再向下执行
4. `~/.bash_login`：如果3中的配置脚本没有找到，则尝试执行该脚本
    - 注：如果脚本存在，则执行完成后不再向下执行
5. `~/.profile`：如果3和4中的配置脚本都没有找到，则尝试执行该脚本

linux发行版更新的时候，会更新`/etc`里面的文件，比如`/etc/profile`，因此不要直接修改这个文件。

如果想修改所有用户的登陆环境，就在`/etc/profile.d`目录里面新建`.sh`脚本。

如果想修改某个用户的登录环境，一般是写在`~/.bash_profile`里面，该文件一般会执行`~/.bashrc`，因此也可以修改该文件。

`bash --login`会强制执行登录session会执行的脚本。

`bash --noprofile`会跳过上面这些profile脚本。

### 非登录session

非登录session是用户进入系统后手动新建的session，这时不会进行环境初始化。

如在命令行执行`bash`就会新建一个非登录session。

非登录session的初始化脚本依次如下：

1. `/etc/bash.bashrc`：对全体用户有效
2. `~/.bashrc`：仅对当前用户有效

对用户来说，`~/.bashrc`通常是最重要的脚本：

- 非登录session默认会执行它
- 登陆session一般也会通过调用执行它。

由于每次执行bash脚本，都会新建一个非登录session，所以`~/.bashrc`也是每次执行脚本都会执行的。

`bash --norc`可以禁止非登录session执行`~/.bashrc`脚本。

`bash --rcfile filename`可以指定另一个脚本替代`~/.bashrc`。

### .bash_logout

`~/.bash_logout`脚本在每次退出session时执行，通常用来做一些清理工作和记录工作，如：

- 删除临时文件
- 记录用户在本次session花费的时间

如果没有退出时要执行的命令，这个文件也可以不存在。

### 启动参数

```shell
bash -n scriptname  # 不运行脚本，只检查是否有语法错误
bash -v scriptname  # 输出每一行语句运行结果前，会先输出该行语句
bash -x scriptname  # 每一个命令处理完以后，先输出该命令，再进行下一个命令的处理
```

### 键盘绑定

bash允许用户定义自己的快捷键。

全局的键盘绑定文件默认为`/etc/inputrc`，可以在主目录创建自己的键盘绑定文件`.inputrc`文件。

如果定义了自己的键盘绑定文件，需要在其中加入`$include /etc/inputrc`，以保证全局绑定不会被遗漏。

`.inputrc`文件里面的快捷键，可以像这样定义：

```shell
"\C-t":"pwd\n"  # 表示将ctrl+t绑定为运行pwd命令
```

## 命令提示符

命令提示符用于提示用户在该位置后面输入命令。

### PS1

命令提示符通常是`$`符号，对于root用户则是`#`符号，这些符号是有环境变量`PS1`决定的。

修改`PS1`可以修改命令提示符。

命令提示符可以包含特殊的转义字符，表示特定内容：

- `\a`：响铃，计算机发出一记声音
- `\d`：以星期、月、日格式表示当前日期，如：`Mon May 26`
- `\h`：本机的主机名
- `\H`：完整的主机名
- `\j`：运行在当前shell会话的工作数
- `\l`：当前终端设备名
- `\n`：一个换行符
- `\r`：一个回车符
- `\s`：shell的名称
- `\t`：24小时制的当前时间`hours:minutes:seconds`
- `\T`：12小时制的当前时间
- `\@`：12小时制的`AM/PM`格式表示当前时间
- `\A`：24小时制的`hours:minutes`表示当前时间
- `\u`：当前用户名
- `\v`：shell的版本号
- `\V`：shell的版本号和发布号
- `\w`：当前的工作路径
- `\W`：当前目录名
- `\!`：当前命令在命令历史中的编号
- `\#`：当前shell会话中的命令数
- `\$`：普通用户显示为`$`字符，根用户显示为`#`字符
- `\[`：非打印字符序列的开始标志
- `\]`：非打印字符序列的结束标志

### 颜色

默认情况下，命令提示符是显示终端预定义的颜色。

bash允许自定义提示符颜色。

使用下面的代码，可以设定其后文本的颜色：

- `\033[0;30m`：黑色
- `\033[1;30m`：深灰色
- `\033[0;31m`：红色
- `\033[1;31m`：浅红色
- `\033[0;32m`：绿色
- `\033[1;32m`：浅绿色
- `\033[0;33m`：棕色
- `\033[1;33m`：黄色
- `\033[0;34m`：蓝色
- `\033[1;34m`：浅蓝色
- `\033[0;35m`：粉红
- `\033[1;35m`：浅粉色
- `\033[0;36m`：青色
- `\033[1;36m`：浅青色
- `\033[0;37m`：浅灰色
- `\033[1;37m`：白色

举例来说，如果要将提示符设为红色，可以将`PS1`设成：

```shell
PS1='\[\033[0;31m\]<\u@\h \W>\$'
```

但是，上面这样设置以后，用户在提示符后面输入的文本也是红色的。

为了解决以上问题， 可以在结尾添加另一个特殊代码`\[\033[00m\]`，表示将其后的文本恢复到默认颜色：

```shell
PS1='\[\033[0;31m\]<\u@\h \W>\$\[\033[00m\]'
```

除了设置前景颜色，bash还允许设置背景颜色：

- `\033[0;40m`：蓝色
- `\033[1;44m`：黑色
- `\033[0;41m`：红色
- `\033[1;45m`：粉红
- `\033[0;42m`：绿色
- `\033[1;46m`：青色
- `\033[0;43m`：棕色
- `\033[1;47m`：浅灰色

下面是一个带有红色背景的提示符：

```shell
PS1='\[\033[0;41m\]<\u@\h \W>\$\[\033[0m\] '
```

### PS2 PS3 PS4

环境变量`PS2`是命令行折行输入时系统的提示符，默认为`>`。

环境变量`PS3`是使用`select`命令时，系统输入菜单的提示符。

环境变量`PS4`默认为`+`，是使用bash的`-x`参数执行脚本先打印命令时，在行首出现的提示符。

## 异步任务

bash有内置命令`wait`，用于管理异步执行的任务。

如以下两个脚本：

```shell
# 父脚本
#!/bin/bash
# async-parent : Asynchronous execution demo (parent)
echo "Parent: starting..."
echo "Parent: launching child script..."
async-child &  # 调用子脚本并放到后台执行
pid=$!         # $!总是包含放到后台执行的最后一个任务的进程ID号
echo "Parent: child (PID= $pid) launched."
echo "Parent: continuing..."
sleep 2
echo "Parent: pausing to wait for child to finish..."
wait $pid      # 等待子脚本执行结束
echo "Parent: child is finished. Continuing..."
echo "Parent: parent is done. Exiting."

# 子脚本
#!/bin/bash
# async-child : Asynchronous execution demo (child)
echo "Child: child is running..."
sleep 5
echo "Child: child is done. Exiting."
```

## 命名管道

命名管道用来在两个进程之间建立连接，也可以像其它类型的文件一样使用。

命名管道的行为类似于文件，但实际上形成了先入先出(FIFO)的缓冲。

和普通(未命名的)管道一样，数据从一端进入，然后从另一端输出。

```shell
process1 > named_pipe  # 写命名管道
process2 < named_pipe  # 读命名管道
```

使用`mkfifo`命令可以创建命名管道：

```shell
mkfifo named_pipe
ls -lh named_pipe
# prw-r--r-- 1 root root 0 Nov 20 19:00 named_pipe
# ls命令查看命名管道第一个字母为p，表示为命名管道
```

使用命名管道：

```shell
# 上面创建了命名管道named_pipe
# 新建两个终端窗口

# 第一个窗口输入以下命令，输入后命令后会挂起
# 这时因为管道另一端没有读取数据，管道阻塞了
ls -l > named_pipe

# 第二个串口输入以下命令读取数据
# 输入以下命令后，第一个窗口命令也执行完成不再阻塞，成功结束
cat named_pipe
```

## 重定向

重定向指的是将命令行输出写入指定位置。

- `cmd1 | cmd2`：Pipe; take standard output of cmd1 as standard input to cmd2.
- `> file`：Direct standard output to file.
- `< file`：Take standard input from file.
- `>> file`：Direct standard output to file; append to file if it already exists.
- `>| file`：Force standard output to file even if noclobber is set.
- `n>| file`：Force output to file from file descriptor n even if noclobber is set.
- `<> file`：Use file as both standard input and standard output.
- `n<> file`：Use file as both input and output for file descriptor n.
- `<< label`：Here-document; see text.
- `n > file`：Direct file descriptor n to file.
- `n < file`：Take file descriptor n from file.
- `n >> file`：Direct file descriptor n to file; append to file if it already exists.
- `n>&`：Duplicate standard output to file descriptor n.
- `n<&`：Duplicate standard input from file descriptor n.
- `n>&m`：File descriptor n is made to be a copy of the output file descriptor.
- `n<&m`：File descriptor n is made to be a copy of the input file descriptor.
- `&>file`：Directs standard output and standard error to file.
- `<&-`：Close the standard input.
- `>&-`：Close the standard output.
- `n>&-`：Close the output from file descriptor n.
- `n<&-`：Close the input from file descriptor n.
- `n>&word`：If n is not specified, the standard output (file descriptor 1) is used. If the digits in word do not specify a file descriptor open for output, a redirection error occurs. As a special case, if n is omitted, and word does not expand to one or more digits, the standard output and standard error are redirected as described previously.
- `n<&word`：If word expands to one or more digits, the file descriptor denoted by n is made to be a copy of that file descriptor. If the digits in word do not specify a file descriptor open for input, a redirection error occurs. If word evaluates to -, file descriptor n is closed. If n is not specified, the standard input (file descriptor 0) is used.
- `n>&digit-`：Moves the file descriptor digit to file descriptor n, or the standard output (file descriptor 1) if n is not specified.
- `n<&digit-`：Moves the file descriptor digit to file descriptor n, or the standard input (file descriptor 0) if n is not specified. digit is closed after being duplicated to n.

`>`用来将标准输出重定向到指定文件。

如果重定向后的指定文件已经存在，就会被覆盖，不会有任何提示。

如果命令没有任何输出，那么重定向之后，得到的是一个长度为0的文件。

因此，`>`具有创建新文件或改写现存文件、将其改为长度0的作用。

`>>`用来将标准输出重定向追加到指定文件。

`2>`用来将标准错误重定向到指定文件。

如果不希望输出错误信息，可以将它重定向到一个特殊文件`/dev/null`。

`tee`命令用于将标准输出重定向到文件，同时作为另一个命令的标准输入。

`$(command)`表示命令替换，另一种写法是使用反引号，如下：

```shell
echo $(ls)
echo `ls`
ls -l $(which cp)
ls -l `which cp`
```

## 正则表达式

参照[正则表达式](../../linux/正则表达式.md)。

## shell命令

### shopt

shopt可以调整bash的行为。

```shell
# 打开某个参数
shopt -s [optionname]

# 关闭某个参数
shopt -u [optionname]

# 查询某个参数关闭还是打开
shopt [optionname]

# 查询某个参数关闭还是打开，不会直接输出查询结果，通过命令执行状态表示查询结果
shopt -q [optionname]
# $?为0表示打开
# $?为1表示关闭
```

参数：

- `dotglob`：让扩展结果包含隐藏文件
- `nullglob`：让通配符不匹配任何文件名时返回空字符
- `failglob`：让通配符不匹配任何文件名时直接报错
- `extglob`：使bash支持ksh的一些扩展语法
- `nocaseglob`：让通配符扩展不区分大小写
- `globstar`：使`**`匹配零个或多个子目录，默认关闭

### type

type用于判断命令是内置命令还是外部程序。

参数：

- `-a`：查看命令的所有定义
- `-t`：返回命令的类型，包括：alias、keyword、function、builtin、file

```shell
type type
# type is a shell builtin
type echo
# echo is a shell builtin
type which
# which is /usr/bin/which
type -a echo
# echo is a shell builtin
# echo is /usr/bin/echo
# echo is /bin/echo
type -t echo
# builtin
type -t ls
# alias
type -t which
# file
type -t function
# keyword
```

### whatis

`whatis`可以显示指定命令的描述。

### apropos

`apropos`会返回符合搜索条件的命令列表。

```shell
apropos scp
# libssh2_scp_recv(3)      - request a remote file via SCP
# libssh2_scp_recv2(3)     - request a remote file via SCP
# libssh2_scp_send(3)      - convenience macro for libssh2_scp_send_ex(3) calls
# libssh2_scp_send64(3)    - Send a file via SCP
# libssh2_scp_send_ex(3)   - Send a file via SCP
# scp(1)                   - OpenSSH secure file copy
```

### which

`which`用于显示可执行程序的路径。

```shell
which ls
# /bin/ls
```

### whereis

`whereis`用来显示某个命令的位置。

当有多个程序符合条件时，会全部列出。

### help

`help`命令可用于查看shell内置命令的帮助信息，如：`help cd`。

### man

man手册是linux系统提供的一种帮助手册。

`man`命令可用于查看帮助手册。

安装man手册：`apt-get install man-db`。

man手册共分为9章，可以通过`man man`命令查看每个章节的具体内容：

章节 | 具体内容
--- | ---
1 | 可执行文件或者shell命令
2 | 系统调用（内核提供的函数）
3 | 库函数
4 | 特别的文件（通常在/dev）
5 | 文件格式，如/etc/passwd
6 | 游戏
7 | 杂项（包括宏包）
8 | 系统管理员命令（通常给root用户使用）
9 | 内核例程（非标准例程）

通过`man`命令查询man手册时，如果不指定章节，将会按照默认顺序查找命令，且只返回含有命令的第一个文档。

因此有时需要指定章节查找命令。

举例：

```shell
man passwd
man 5 passwd
```

### script

`script`可以对输入、输出进行录制，内容会保存进一个文件。

未指定文件名时，所有结果会保存进当前目录下的`typescript`文件。

按下`ctrl+d`可以结束录制。

### echo

echo命令用于在屏幕输出一行文本，可以将该命令的参数原样输出。

输出多行文本时需要将多行文本放在引号里面。

参数：

- `-n`：命令执行后默认追加输出换行，该参数可取消输出换行
- `-e`：默认情况下引号中的内容原样输出，使用该参数后输出时会解释字符串中的特殊字符

```shell
echo abc
# abc
echo "abc def"
# abc def
echo "abc\ndef"
# abc\ndef
echo -e "abc\ndef"
# abc
# def
echo -n "abcdef"
# abcdef$
```

### mktemp

生成临时文件应该遵循下面的规则：

- 创建前检查文件是否已经存在
- 确保临时文件已成功创建
- 临时文件必须有权限的限制
- 临时文件要使用不可预测的文件名
- 脚本退出时，要删除临时文件(使用trap命令)

`mktemp`命令就是为安全创建临时文件而设计的。

在创建临时文件之前，`mktemp`不会检查临时文件是否存在。

`mktemp`支持唯一文件名和清除机制，因此可以减轻安全攻击的风险。

直接运行该命令可以生成临时文件，文件名是随机的，权限是只有用户本人可读写：`TMPFILE=$(mktemp)`。

为了确保临时文件创建成功，`mktemp`最好与运算符`||`连用，保证创建失败时退出脚本：`TMPFILE=$(mktemp) || exit 1`。

命令参数：

- `-d`：用于创建临时目录
- `-p`：指定临时文件所在目录
  - 默认使用环境变量`$TMPDIR`指定的目录
  - 如果以上环境变量未设置，则使用`/tmp`目录
- `-t`：指定临时文件的文件名模版
  - 模版的末尾至少包含三个连续的`X`字符，表示随机字符
  - 建议至少使用六个`X`
  - 默认的文件名模版是`tmp.`后接十个随机字符
  - 举例：`mktemp -t mytemp.XXXXXXX`

### trap

`trap`命令用于相应系统信号。

`trap -l`可以列出所有的系统信号。

命令格式：`trap [动作] [信号1] [信号2] ...`。

常用信号：

- `HUP`：编号1，脚本与所在的终端脱离联系
- `INT`：编号2，用户按下`Ctrl+C`，意图让脚本中止运行
- `QUIT`：编号3，用户按下`Ctrl+/`，意图退出脚本
- `KILL`：编号9，该信号用于杀死进程
- `TERM`：编号15，这是`kill`命令发出的默认信号
- `EXIT`：编号0，这不是系统信号，而是bash脚本特有的信号，不管什么情况，只要退出脚本就会产生

所以可以使用`trap`命令在脚本退出时删除临时文件：`trap 'rm -f $"TMPFILE"' EXIT`。

注：`trap`命令必须放在脚本开头，否则上方任何命令导致脚本退出时都不会被`trap`捕获。

### gzip

`gzip`程序用来压缩文件，压缩文件名为原文件名添加`.gz`后缀。

`gunzip`用来还原压缩文件。

`gzcat`用于查看一个`gz`文件，但实际上并没有解压。

`gzip`参数：

- `-c`：把输出写入到标准输出，并且保留原始文件
- `-d`：解压缩
- `-f`：强制压缩，即使原始文件的压缩文件已经存在也会执行
- `-h`：显示用法信息
- `-l`：列出每个被压缩文件的压缩数据
- `-r`：若命令的一个或多个参数是目录，则递归地压缩目录中的文件
- `-t`：测试压缩文件的完整性
- `-v`：显示压缩过程中的信息
- `-number`：设置压缩指数，1~9(最快最小压缩~最慢最大压缩)之间的整数
  - 1和9也可以分别用`-—fast`和`-—best`选项来表示，默认值是整数6

### bzip2

`bzip2`程序与`gzip`相似，使用了不同的压缩算法，舍弃了压缩速度，实现了更高的压缩级别。

由`bzip2`压缩的文件使用扩展名`.bz2`。

### zip

`zip`程序既是压缩工具也是一个打包工具，读取和写入`.zip`文件。

```shell
# 语法：
zip options zipfile file...

# 举例：
zip -r dir.zip dir  # 将dir目录压缩为dir.zip
```

解压缩使用`unzip`命令。

`unzip`命令参数：

- `-l`：列出文件包中的内容而不解压
- `-v`：显示冗余信息
- `-p`：输出发送到标准输出

### tar

`tar`是`tape archive`的简称，原来是一款制作磁带备份的工具，现在主要用于打包。

```shell
# 语法：
tar mode[options] pathname...

# mode：
#   c：create，为文件或目录列表创建归档文件
#   x：抽取归档文件
#   r：追加具体的路径到归档文件的末尾
#   t：列出归档文件的内容

# options：
#   f：表示文件，用于指定生成的文件

# 注：必须先指定模式，然后才是其它选项
```

`tar`命令还原的时候，总是还原为相对路径。

如果归档的时候，保存的是绝对路径，那么还原的时候，这个绝对路径会整个变成相对路径。

```shell
find playground -name 'file.txt' -exec tar rf playground.tar '{}' '+'
```

如上，先用`find`程序找到所有名为`file.txt`的文件，然后使用追加模式`r`的`tar`命令，把匹配的文件添加到归档文件。

这种`tar`和`find`的配合使用，可以创建逐渐增加的目录树或者整个系统的备份。

通过`find`命令匹配新于某个时间戳的文件，我们就能够创建一个归档文件，其只包含新于上一个`tar`包的文件。

`tar`支持压缩功能：

```shell
# 打成gzip压缩包
tar czvf assets.tar.gz dist

# 打成bz2压缩包
tar cvfj assets.tar.bz2 dist

# 解压 tar.gz 文件
tar xzv archive.tar.gz
tar xvf archive.tar.gz

# 解压bz2压缩包
tar xvf archive.tar.bz2

# 显示gzip压缩包内容
tar tvf archive.tar.gz

# 显示bz2压缩包内容
tar tvf archive.tar.bz2

# 从gzip压缩包取出单个文件
tar zxvf archive.tar.gz file.txt

# 从bz2压缩包取出单个文件
tar jxvf archive.tar.bz2 file.txt

# 按通配符取出文件
tar zxvf archive.tar.gz --wildcards '*.php'
tar jxvf archive.tar.bz2 --wildcards '*.php'

# 追加文件到压缩包
tar rvf archive.tar.gz xyz.txt
tar rvf archive.tar.bz2 xyz.txt
```

### rsync

`rsync`命令用于在多个目录之间、或者本地与远程目录之间进行同步，`r`表示remote。

语法：

```shell
rsync options source destination
# source和destination是以下选项之一：
#   一个本地文件或目录
#   一个远端文件或目录，以 [user@]host:path 的形式存在
#   一个远端rsync服务器，由 rsync://[user@]host[:port]/path 指定

# source和destination之中必须有一个是本地文件，不支持远端复制到远端
```

参数：

- `-a`：递归和保护文件属性
- `-v`：冗余输出
- `--delete`：删除可能在备份设备中存在但已不存在于源设备的文件
- `--rsh=ssh`：使用`ssh`作为远程shell，目的地址必须标注主机名

使用举例：

```shell
# 同步两个本地目录
rsync -av playground foo

# 删除源设备不存在的文件
sudo rsync -av --delete /etc /home /usr/local /media/BigDisk/backup

# 远程同步
sudo rsync -av --delete --rsh=ssh /etc /home /usr/local remote-sys:/backup

# 与远程rsync主机同步
rsync -av -delete rsync://rsync.gtlib.gatech.edu/path/to/oss fedora-devel
```

### cp

`cp`命令用于拷贝文件或目录。

参数：

- `-a`：拷贝时保留所有属性，包括所有者与权限
- `-v`：显示拷贝的详细信息
- `-r`：拷贝文件夹时需要使用
- `-u`：只复制目标目录中不存在或源目录中更新的文件

### scp

`scp`是"secure copy"的缩写，用来在两台主机之间加密传送文件。

底层为SSH协议，默认端口是22。

主要用于以下三种复制操作：

- 从本地系统到远程系统
- 从远程系统到本地系统
- 在本地系统的两个远程系统之间

使用`scp`传输数据时，文件和密码都是加密的，不会泄漏敏感信息。

`scp`的语法类似`cp`的语法。

**注意**：如果传输的文件在本机和远程系统，有相同的名称和位置，`scp`会在没有警告的情况下覆盖文件。

```shell
# 本地文件复制到远程系统
scp SourceFile user@host:directory/TargetFile

# 远程系统文件复制到本地
scp user@host:directory/TargetFile SourceFile

# 两个远程系统之间复制文件
scp user@host1:directory/SourceFile user@host2:directory/SourceFile
```

选项：

- `-r`：以递归方式复制目录
- `-P`：指定远程主机的SSH端口，默认为端口22
- `-p`：保留文件原始属性，如修改时间、访问时间、权限等
- `-l`：限制传输速率，单位：Kbit/sec
- `-c`：指定加密算法
- `-C`：在传输时压缩文件
- `-q`：不显示拷贝进度条
- `-F`：用来指定ssh_config文件
- `-v`：显示详细的输出
- `-i`：用来指定秘钥

### mkdir

`mkdir`命令用于新建目录，`-p`参数可以创建多层目录。

### mv

`mv`命令用于移动源文件或目录。

参数：

- `-i`：覆盖已经存在的文件时，会提示确认
- `-u`：只移动目的地不存在的文件，或比目的地更新的文件

### rm

`rm`命令用于删除文件。

参数：

- `-i`：文件存在时，会提示确认
- `-r`：递归删除一个子目录
- `-f`：如果删除不存在的文件，不报错
- `-v`：删除时展示详细信息

### ln

`ln`命令用于建立链接文件。

新建硬链接：`ln file link`。

新建软链接：`ln -s item link`。

### ls

`ls`目录可以显示指定目录的内容，不加参数时，显示当前目录的内容。

文件类型：

- `-`：普通文件
- `d`：目录
- `l`：符号链接，对于符号链接文件，文件权限总是`rwxrwxrwx`
- `c`：字符设备文件，指按照字节流处理数据的设备，如串口
- `b`：块设备文件，指按照数据块处理数据的设备，比如硬盘

```shell
# 显示多个目录的内容
ls ~ /usr

# -a --all 显示隐藏文件
ls -a

# -A 与-a类似，但是不显示当前目录和上一级目录两个点文件
ls -A

# -l 显示详细信息
ls -l

# -1 单列显示，每行只显示一个文件
ls -1

# -d 显示当前目录本身，而不是它的内容
# 通常与-l配合使用，列出一个目录本身的详细信息
ls -dl

# -F 目录名之后添加斜杠，可执行文件后面添加星号
ls -F

# -h 与-l配合使用，将文件大小显示为人类可读的格式

# -t 按文件修改时间排序，修改晚的排在前面
ls -t

# -s 按文件大小排序

# --reverse 显示结果倒序排列
ls -lt --reverse

# 只显示常规目录
ls -d */
ls -F | grep /
ls -l | grep ^d
tree -dL 1

# 只显示隐藏目录
ls -d .*/

# 隐藏目录和非隐藏目录都显示
find -maxdepth 1 -type d
```

### stat

`stat`可以显示一个文件的详细信息。

```shell
stat test.sh
#   File: test.sh
#   Size: 202       	Blocks: 8          IO Block: 4096   regular file
# Device: 7eh/126d	Inode: 6553815     Links: 1
# Access: (0755/-rwxr-xr-x)  Uid: (    0/    root)   Gid: (    0/    root)
# Access: 2022-11-17 17:09:47.783915428 +0800
# Modify: 2022-11-17 17:09:46.352033992 +0800
# Change: 2022-11-17 17:09:46.352033992 +0800
#  Birth: -
```

### touch

`touch`用来设置或更新文件的访问、更改、修改时间。

当文件名参数指定的文件不存在时，会创建一个空文件。

```shell
# 创建目录，包含一百个子目录，每个子目录中包含了26个空文件
mkdir -p playground/dir-{00{1..9},0{10..99},100}
touch playground/dir-{00{1..9},0{10..99},100}/file-{A..Z}
```

### file

`file`命令用于显示指定文件的类型。

```shell
file /etc/passwd
# /etc/passwd: ASCII text
```

### chmod

`chmod`命令用于修改文件权限。

`chmod`可以接受四个缩写，为不同的对象单独设置权限：

- `u`：所有者"user"的简写
- `g`：用户组"group"的缩写
- `o`：其他所有人"others"的简写
- `a`：所有人"all"的简写

如`chmod u+rwx test.sh`为所有者添加读、写、执行权限，删除权限需要将`+`修改为`-`。

### du

`du`命令用于查看指定目录的大小。

参数：

- `-h`：表示人可读的格式
- `-s`：表示总结信息，否则会显示该目录内所有文件和子目录的信息
- `-x`：不显示不在当前分区的目录
- `-c`：显示当前目录总共占用的空间大小
- `--exclude`：用于排除某些目录或文件
- `--max-depth`：设置目录大小统计到第几层

`tree`命令也可以显示子目录大小。

### md5sum

`md5sum`用于计算文件的md5校验码。

### locate

`locate`程序用于快速搜索本机的路径名数据库，输出每个与给定字符串相匹配的文件名。

locate数据库由另一个叫做`updatedb`的程序创建。

大多数装有locate的系统会每隔一天运行一回updatedb程序。

因为数据库不能被持续地更新，所以当使用`locate`时，可以发现目前最新的文件不会出现。

为了克服以上问题，可以手动运行`updatedb`程序，更改为超级用户身份，在提示符下运行`updatedb`命令。

locate 支持正则查找：

- `--regexp`：参数支持基本的正则表达式
- `--regex`：参数支持扩展的正则表达式

举例：`locate --regex 'bin/(bz|gz|zip)'`

### find

`locate`程序只能依据文件名来查找文件，而`find`程序能基于各种各样的属性，搜索一个给定目录以及子目录查找文件。

```shell
# 输出当前目录的所有子目录和文件
find
find .

# 输出当前目录文件总数
find . | wc -l

# 输出当前目录子目录总数
find . -type d | wc -l

# 输出当前目录的文件总数(不含子目录)
find . -type f | wc -l

# 输出当前目录动态库文件且文件大于1M的文件总数
find . -name "*.so" -size +1M | wc -l
```

`-type`参数支持的文件类型：

- `b`：块设备文件
- `c`：字符设备文件
- `d`：目录
- `f`：普通文件
- `l`：符号链接

`-size`参数支持的文件大小类型：

- `b`：512个字节块，如果没有指定单位，则这是默认值
- `c`：字节
- `w`：两个字节的字
- `k`：千字节
- `M`：兆字节
- `G`：千兆字节

`find`程序支持的查询参数：

- `-cmin n`：匹配的文件和目录的内容或属性最后修改时间正好在n分钟之前
  - 指定少于n分钟之前，使用`-n`
  - 指定多于n分钟之前，使用`+n`
- `-cnewer file`：匹配的文件和目录的内容或属性最后修改时间早于那些文件
- `-ctime n`：匹配的文件和目录的内容和属性最后修改时间在`n*24`小时之前
- `-empty`：匹配空文件和目录
- `-group name`：匹配的文件和目录属于一个组
  - 组可以用组名或组ID来表示
- `-iname pattern`：就像`-name`测试条件，但是不区分大小写
- `-inum n`：匹配的文件的inode号是n
  - 对于找到某个特殊inode的所有硬链接很有帮助
- `-mmin n`：匹配的文件或目录的内容被修改于n分钟之前
- `-mtime n`：匹配的文件或目录的内容被修改于`n*24`小时之前
- `-name pattern`：用指定的通配符模式匹配的文件和目录
- `-newer file`：匹配的文件和目录的内容早于指定的文件
  - 编写shell脚本做文件备份时，非常有帮助
  - 每次制作一个备份，更新文件(如日志)，使用`find`命令可以找到自从上次更新后哪一个文件已经更改了
- `-nouser`：匹配的文件和目录不属于一个有效用户
  - 可以用来查找属于删除帐户的文件或监测攻击行为
- `-nogroup`：匹配的文件和目录不属于一个有效的组
- `-perm mode`：匹配的文件和目录的权限已经设置为指定的mode
  - mode可以用八进制或符号表示法
- `-samefile name`：相似于`-inum`测试条件
  - 匹配和文件name享有同样inode号的文件
- `-size n`：匹配的文件大小为n
- `-type c`：匹配的文件类型是c
- `-user name`匹配的文件或目录属于某个用户
  - 用户可以通过用户名或用户ID来表示
- `-depth`：指导find程序先处理目录中的文件，再处理目录自身
  - 当指定`-delete`行为时，会自动应用这个选项
- `-maxdepth levels`：当执行测试条件和行为的时候，设置find程序陷入目录树的最大级别数
- `-mindepth levels`：在应用测试条件和行为之前，设置find程序陷入目录数的最小级别数
- `-mount`：指导find程序不要搜索挂载到其它文件系统上的目录
- `-regex`：指定正则表达式
  - 如找出包括空格或其它不规范字符的文件名或路径名：`find . -regex '.*[^-\_./0-9a-zA-Z].*'`

`find`程序还支持逻辑操作符：

- `-and`：如果操作符两边的测试条件都是真，则匹配
  - 可以简写为`-a`
  - 若没有使用操作符，则默认使用`-and`
- `-or`：若操作符两边的任一个测试条件为真，则匹配
  - 可以简写为`-o`
- `-not`：若操作符后面的测试条件是真，则匹配
  - 可以简写为`!`
- `()`：用来控制逻辑计算的优先级，可以把测试条件和操作符组合起来形成更大的表达式
  - 在命令行中使用`()`时，必须用引号引起来才能作为实参传递给find命令
  - 通常反斜杠字符被用来转义圆括号字符

举例：

```shell
# 或关系
( expression 1 ) -or ( expression 2 )

# 找出不是600权限的文件，或者不是700权限的目录
find ~ \( -type f -not -perm 0600 \) -or \( -type d -not -perm 0700 \)
```

`find`程序的逻辑表达式，具有**短路运算**的特点，即对于`expr1 -operator expr2`这个表达式， `expr2`不一定执行。

以上是为了提高运行速度：

- `expr1`为真，操作符为`-and`，`expr2`总是执行
- `expr1`为假，操作符为`-and`，`expr2`从不执行
- `expr1`为真，操作符为`-or`，`expr2`从不执行
- `expr1`为假，操作符为`-or`，`expr2`总是执行

为了方便执行一些常见操作， `find`程序定义了一些预定义操作：

- `-delete`：删除当前匹配的文件
- `-ls`：对匹配的文件执行等同的`ls -dils`命令，并将结果发送到标准输出
- `-print`：把匹配文件的全路径名输送到标准输出
  - 如果没有指定其它操作，这是默认操作
- `-quit`：找到一个匹配就退出

举例：

```shell
# 找到匹配的文件，并显示在标准输出
# -print是默认操作，可以省略
find . -print

# 删除后缀名为BAK的文件
# 执行delete操作前，最好先执行 print 操作，确认要删除哪些文件
find . -type f -name '*.BAK' -delete

# 预定义操作与逻辑表达式结合使用
find ~ -type f -and -name '*.BAK' -and -print
```

除以上预定义操作外，还可以使用参数`-exec`来自定义操作。

自定义操作基本语法：`-exec command {} ;`：

- `command`是一个命令行命令
- `{}`用来指定当前路径
- `;`表示命令结束
  - 当使用`;`结束命令时，每找到一个匹配的文件，都会启动一个新的指定命令的实例
  - 将`;`修改为`+`可以让自定义操作只执行一次

```shell
# 预定义操作-delete等同于如下自定义操作
-exec rm '{}' ';'
```

### xargs

`xargs`命令从标准输入接受输入，并把输入转换为一个特定命令的参数列表。

如`find ~ -type f -name 'foo\*' -print | xargs ls -l`。

### df

`df`命令用于查看硬盘信息，如：`df -h`。

### free

`free`命令查看内存占用情况，如：`free -h`。

### mount

`mount`不带参数时，显示当前挂载的文件系统。

`mount`带参数时，用于将设备文件挂载到挂载点，`-t`参数用来指定文件系统类型。

### umount

`umount`命令用来卸载设备。

### fdisk

`fdisk`命令用于格式化磁盘。

### mkfs

`mkfs`命令用于在一个设备上新建文件系统。

```shell
sudo mkfs -t ext3 /dev/sdb1
sudo mkfs -t vfat /dev/sdb1
```

### fsck

`fsck`命令用于检查(修复)文件系统。

```shell
sudo fsck /dev/sdb1
```

### dd

`dd`命令用于将大型数据块，从一个磁盘复制到另一个磁盘。

```shell
dd if=input_file of=output_file [bs=block_size [count=blocks]]

# 将/dev/sdb的所有数据复制到/dev/sdc
dd if=/dev/sdb of=/dev/sdc

# 将/dev/sdb的所有数据拷贝到一个镜像文件
dd if=/dev/sdb of=flash_drive.img

# 从cdrom制作一个iso文件
dd if=/dev/cdrom of=ubuntu.iso

# 磁盘数据写满0
dd if=/dev/zero of=/dev/sda1

# 磁盘数据写满随机字符
dd if=/dev/urandom of=/dev/sda1
```

### demidecode

`dmidecode`命令用于输出BIOS信息。

`dmidecode`会输出全部BIOS信息，为了便于查看，往往需要指定所需信息的类别：

- `0`：BIOS
- `1`：System
- `2`：Base Board
- `3`：Chassis
- `4`：Processor
- `5`：Memory Controller
- `6`：Memory Module
- `7`：Cache
- `8`：Port Connector
- `9`：System Slots
- `10`：On Board Devices
- `11`：OEM Strings
- `12`：System Configuration Options
- `13`：BIOS Language
- `14`：Group Associations
- `15`：System Event Log
- `16`：Physical Memory Array
- `17`：Memory Device
- `18`：32-bit Memory Error
- `19`：Memory Array Mapped Address
- `20`：Memory Device Mapped Address
- `21`：Built-in Pointing Device
- `22`：Portable Battery
- `23`：System Reset
- `24`：Hardware Security
- `25`：System Power Controls
- `26`：Voltage Probe
- `27`：Cooling Device
- `28`：Temperature Probe
- `29`：Electrical Current Probe
- `30`：Out-of-band Remote Access
- `31`：Boot Integrity Services
- `32`：System Boot
- `33`：64-bit Memory Error
- `34`：Management Device
- `35`：Management Device Component
- `36`：Management Device Threshold Data
- `37`：Memory Channel
- `38`：IPMI Device
- `39`：Power Supply

`dmidecode`还支持关键词查看，关键词与类别的对应关系如下：

- `bios`：0,13
- `system`：1,12,15,23,32
- `baseboard`：2,10
- `chassis`：3
- `processor`：4
- `memory`：5,6,16,17
- `cache`：7
- `connector`：8
- `slot`：9

使用举例：

```shell
# 查看内存信息
sudo dmidecode -t 17
dmidecode --type 17
sudo dmidecode -t memory
```

### lspci

`lspci`命令会列出本机的所有PCI设备。

### lsusb

`lsusb`可以列出本机所有USB端口，输出格式如下：

```text
Bus 002 Device 003: ID 0781:5567 SanDisk Corp. Cruzer Blade
```

- `Bus 002`：bus编号
- `Device 003`：bus 002连接的第三个设备
- `ID 0781:5567`：当前设备的编号，冒号前是厂商编号，冒号后是设备编号
- `SanDisk Corp. Cruzer Blade`：厂商和设备名

找出本机有多少usb接口可用：

```shell
find /dev/bus/
# /dev/bus/
# /dev/bus/usb
# /dev/bus/usb/002
# /dev/bus/usb/002/006
# /dev/bus/usb/002/005
# /dev/bus/usb/002/004
# /dev/bus/usb/002/002
# /dev/bus/usb/002/001
# /dev/bus/usb/001
# /dev/bus/usb/001/007

# 查看某个USB设备的详细情况
lsusb -D /dev/bus/usb/002/005

# 查看所有设备的详细情况
lsusb -v

# 查看USB端口的版本
lsusb -v | grep -i bcdusb
```

### hostname

`hostname`返回当前服务器的主机名。

### ps

`ps`命令用来列出进程信息。

不带任何参数时，`ps`只列出与当前session相关的进程。

输出结果中：

- `PID`是进程ID
- `TTY`是进程的终端号
  - 如果显示`?`，则表示进程没有终端
- `TIME`是消耗的CPU时间
- `CMD`是触发进程的命令

参数`x`列出所有进程的详细信息，包括不在当前session的信息。

增加`x`参数后输出结果会多出`STAT`一栏，表示状态，它的各种值如下：

- `R`：正在运行或准备运行
- `S`：正在睡眠
  - 未运行，等待事件唤醒
- `D`：不可中断睡眠
  - 等待`I/O`，如磁盘驱动器的`I/O`
- `T`：已停止，即进程停止运行
- `Z`：僵尸进程
  - 是一个已经终止的子进程，但父进程还没有清空它
  - 即没有把子进程从进程表中删除
- `<`：高优先级进程
  - 可能会授予一个进程更多重要的资源，给它更多的CPU时间
- `N`：低优先级进程
  - 只有当其它高优先级进程执行之后，才会得到处理器时间

参数`aux`可以显示更多信息：

- `USER`：用户ID，表示进程的所有者
- `%CPU`：百分比表示的CPU使用率
- `%MEM`：百分比表示的内存使用率
- `VSZ`：虚拟内存大小
- `RSS`：进程占用的物理内存的大小，以千字节为单位
- `START`：进程运行的起始时间，若超过24小时，则用天表示

### top

`top`命令可以查看机器的当前状态。

输出结果分为两部分，最上面是系统概要，下面是进程列表，以CPU的使用率排序。

### jobs

`jobs`命令用来查看后台任务。

```shell
jobs
# [1]+ Running xlogo &
# 编号是1
# +表示正在运行
```

### fg

`fg`命令用于将后台任务切换到前台，如`fg %1`。

`fg`命令之后，跟随着一个百分号和工作序号，用来指定切换哪一个后台任务。

如果只有一个后台任务，那么`fg`命令可以不带参数。

### bg

`bg`命令用于将一个暂停的前台任务，转移到后台，如`bg %1`。

只有暂停的任务，才能使用`bg`命令，因为正在运行的任务，命令行是无法输入的。

`ctrl+z`可以暂停正在运行的前台任务。

### kill

`kill`命令的实质是操作系统向进程发送信号。

键盘`ctrl+c`会发送一个叫做INT(中断)的信号。

键盘`ctrl+z`会发送一个叫做TSTP(终端停止)的信号。

`kill`命令可以用来向进程发送指定信号，`kill [-signal] PID`。

`kill -l`可以列出所有信号：

- `HUP`：编号1，表示挂起
  - 发送这个信号到前台程序，程序会终止
  - 许多守护进程也使用这个信号，来重新初始化
  - 这意味着，当发送这个信号到一个守护进程后，这个进程会重新启动，并且重新读取它的配置文件
- `INT`：编号2，中断
  - 实现和`ctrl+c`一样的功能，由终端发送
  - 通常，它会终止一个程序
- `KILL`：编号9，杀死
  - 进程可能选择忽略这个信号，所以，操作系统不发送该信号到目标进程，而是内核立即终止这个进程
  - 当一个进程以这种方式终止的时候，它没有机会去做些"清理"工作，或者是保存劳动成果
  - 因为这个原因，把`KILL`信号看作杀手锏，当其它终止信号失败后，再使用它
- `TERM`：编号15，终止
  - 这是`kill`命令发送的默认信号
  - 如果程序仍然"活着"，可以接受信号，那么这个信号终止
- `CONT`：编号18，继续
  - 在停止一段时间后，进程恢复运行
- `STOP`：编号19，停止
  - 这个信号导致进程停止运行，而没有终止
  - 像`KILL`信号，它不被发送到目标进程，因此它不能被忽略
- `QUIT`：编号3，退出
- `SEGV`：编号11，段错误
  - 如果一个程序非法使用内存，就会发送这个信号
  - 即程序试图写入内存，而这个内存空间是不允许此程序写入的
- `TSTP`：编号20，终端停止
  - 当按下`ctrl+z`组合键后，终端发送这个信号
  - 不像`STOP`信号，`TSTP`信号 由目标进程接收，且可能被忽略
- `WINCH`：编号28，改变窗口大小
  - 当改变窗口大小时，系统会发送这个信号
  - 一些程序，像`top`和`less`程序会响应这个信号，按照新窗口的尺寸，刷新显示的内容

### killall

`killall`命令用于向指定的程序或用户发送信号：`killall [-u user] [-signal] name`。

### pstree

`pstree`输出树型结构的进程列表，这个列表展示了进程间父/子关系。

### vmstat

`vmstat`输出一个系统资源使用快照，包括内存，交换分区和磁盘 I/O。

为了看到连续的显示结果，则在命令名后加上延时的时间(以秒为单位)，如：`vmstat 5`，按`ctrl+c`结束。

### xload

`xload`一个图形界面程序，可以画出系统负载的图形。

### tload

`tload`与`xload`程序相似，但是在终端中画出图形，使用`ctrl+c`可以终止输出。

### tee

`tee`命令用于将标准输出重定向到文件，同时作为另一个命令的标准输入：`ls /usr/bin | tee ls.txt | grep zip`。

### basename

`basename`命令用于清除一个路径名的开头部分，只留下一个文件的基本名称。

```shell
#!/bin/bash
PROGNAME=$(basename $0)
```

### uname

`uname`命令返回当前机器的信息。

```shell
uname -r  # 内核版本，可以查看文件/etc/issue
uname -m  # CPU架构
uname -a  # 完整信息
```

### service

`service`命令可以查看当前正在运行的服务。

```shell
service --status-all
#  [ - ]  dbus
#  [ ? ]  hwclock.sh
#  [ - ]  procps
#  [ + ]  udev
#  [ - ]  x11-common

# + 表示正在运行
# - 表示已经停止
# ? 表示service命令未知相关状态
```

### cat

`cat`可以将文件的内容显示在标准输出。

`cat`可以同时输出多个文件，与重定向结合可以合并多个文件。

```shell
# 合并文本文件
cat text* > text.all

# 合并二进制文件
cat movie.mpeg.0* > movie.mpeg
```

调用`cat`命令时如果没有任何参数，它将读取标准输入，然后显示到标准输出。

按下`ctrl+d`，将会结束`cat`读取标准输入。

利用这一点，可以将键盘输入写入指定文件，按下`ctrl+d`结束输入。

参数：

- `-n`：输出结果显示行号
- `-s`：将多个连续的空白行，输出为一行
- `-A`：输出结果中显示控制符，如：
  - tab键显示为`^I`
  - 行尾显示`$`

### nl

`nl`命令为文本文件添加行号，显示在标准输出。

### sort

`sort`命令将所有文本文件的所有行排序后输出。

参数：

- `-b`，`--ignore-leading-blanks`：
  - 默认情况下，排序用的是每行的第一个字符
  - 该参数忽略每行开头的空格，从第一个非空白字符开始排序
- `-f`，`--ignore-case`：
  - 让排序不区分大小写
- `-n`，`--numeric-sort`
  - 按照数值排序，而不是字符值，用于行首是数值的情况
- `-r`，`--reverse`：
  - 按相反顺序排序
  - 结果按照降序排列，而不是升序
- `-k`，`--key=field1[,field2]`：
  - 指定按照每行的第几个字段(从1开始)排序，而不是按照行首字符排序
  - 该属性可以多个连用，用于指定多重排序标准，还可以指定每个字段指定排序标准，这些值与全局属性一致
  - 如b(忽略开头的空格)、n(数值排序)、r(逆向排序)等
- `-m`，`--merge`：
  - 把每个参数看作是一个预先排好序的文件
  - 把多个文件合并成一个排好序的文件，而没有执行 额外的排序
- `-o`，`--output=file`：
  - 把排好序的输出结果发送到文件，而不是标准输出
- `-t`，`--field-separator=char`：
  - 定义字段分隔字符
  - 默认情况下，字段由空格或制表符分隔
- `-u`：输出结果中删除重复行

### uniq

`uniq`命令在排序后的行中，删除所有重复的行，保证所有输出没有重复：`ls /bin /usr/bin | sort | uniq`。

`uniq`命令在排序后的行中，输出目录中所有重复的程序：`ls /bin /usr/bin | sort | uniq -c`。

参数：

- `-c`：输出所有的重复行，并且每行开头显示重复的次数
- `-d`：只输出重复行，而不输出不重复的文本行
- `-f n`：忽略每行开头的n个字段，字段之间由空格分隔，正如`sort`程序中的空格分隔符
  - 不同于`sort`程序，`uniq`没有选项来设置备用的字段分隔符
- `-i`：在比较文本行的时候忽略大小写
- `-s n`：跳过(忽略)每行开头的n个字符
- `-u`：只输出独有的文本行，这是默认操作

### cut

`cut`程序用来从文本行中抽取文本，并把其输出到标准输出，它能够接受多个文件参数或者标准输入。

参数：

- `-c char_list`：抽取指定范围的文本
- `-f field_list`：抽取指定字段，字段之间可以tab分隔也可以逗号分隔
- `-d delim_char`：指定字段分隔符，默认是tab键
- `--complement`：抽取整个文本行，除了那些由`-c`、`-f`选项指定的文本

```shell
# 抽取每行的第1个字符
cut -c 1 /etc/passwd

# 抽取每行的第1和第2个字符
cut -c 1-2 /etc/passwd

# 抽取每行的第2个到结尾的字符
cut -c 2- /etc/passwd

# 指定:为分隔符，抽取每行的第1个字段
cut -f 1 -d ':' /etc/passwd

# 指定:为分隔符，抽取每行的第1和第2个字段
cut -f 1-2 -d ':' /etc/passwd

# 指定:为分隔符，抽取每行的第2个到结尾的字段
cut -f 2- -d ':' /etc/passwd
```

### paste

`paste`程序将多个文本文件按行合并，即每一行都由原来文本文件的每一行组成，显示在标准输出。

如：`paste /etc/passwd ~/.bashrc`。

### wc

`wc`命令输出一个文本文件的统计信息(word count)，一共有三个值：行数、词数、字节数。

```shell
wc /etc/passwd
#  23   33 1233 /etc/passwd

wc -l /etc/passwd  # 只输出行数
# 23 /etc/passwd
```

### head

`head`命令返回文本文件的头部，默认显示10行。

`-n`参数可以指定显示的行数。

### tail

`tail`命令返回文本文件的尾部，默认显示10行。

`-n`参数可以指定显示的行数。

`-f`会实时追加显示新增的内容，常用于实时监控日志，按`ctrl+c`停止。

### grep

`grep`程序用于在指定文件之中，搜索符合某个模式的行，并把搜索结果输出到标准输出。

- `-v`/`--invert-match`：只返回不符合模式的行
- `-c`/`--count`：输出匹配的数量，而不是匹配的文本行
  - 如果使用了`-v` ，则输出不匹配的数量
- `-h`/`--no-filename`：应用于多文件搜索，不在每行匹配的文本前，输出文件名
- `-i`/`--ignore-case`：忽略大小写
- `-l`/`--files-with-matches`：输出包含匹配项的文件名，而不是文本行本身
- `-L`/`--files-without-match`：输出不包含匹配项的文件名
- `-n`/`--line-number`：每个匹配行之前输出其对应的行号
- `-r`/`--recursive`：表示要递归查找，即子目录中的文件也会进行查找

```shell
# 输出文件中包含root关键字的行号和内容
grep -n root /etc/passwd
# 1:root:x:0:0:root:/root:/bin/bash

# 输出文件中包含root关键字的行数
grep -c root /etc/passwd
# 1

# 输出文件中不包含root关键字的行数
grep -vc root /etc/passwd
# 22

# 查找文件夹中包含root关键字的文件的文件名
grep -rl root /etc/

# 查找文件夹中包含root关键字的文件的文件名
grep -rL root /etc/
```

### egrep

`egrep`命令用于显示匹配正则模式的行，与`grep -E`命令等价。

举例：`egrep '(root|rot)' /etc/passwd`。

### sed

`sed`是一个强大的文本编辑工具，可以对文本进行过滤和替换处理。

```shell
# 输出2~5段(行)
sed -n '2,5p' example.txt

# 输出包含指定内容的段(行)
sed -n '/ABC/p' example.txt

# 输出不包含指定内容的段(行)
sed -n '/ABC/!p' example.txt

# 替换内容(只替换每一行的第一个匹配项)
sed 's/ABC/DEF/' example.txt
sed 's/A.C/DEF/' example.txt  # .表示一个字符

# 替换内容(替换每一行的每一个匹配项)
sed 's/A.C/DEF/g' example.txt
```

### date

`date`用于输出当前时间。

命令后用`+`可以指定显示格式。

```shell
date +%d_%b_%Y
# 29_Nov_2022
```

格式参数：

- `%a`：星期名的缩写
- `%A`：星期名的全称
- `%b`：月份的缩写
- `%B`：月份的全称
- `%c`：日期和时间(Tue Nov 29 01:45:37 2022)
- `%C`：世纪，是年份数省略后两位
- `%d`：一个月的第几天
- `%D`：日期，等同于`%m/%d/%y`
- `%e`：一个月的第几天，用空格补零，等同于`%_d`
- `%F`：完整的日期，等同于`%Y-%m-%d`
- `%g`：年份的最后两位数
- `%H`：小时(00-23)
- `%I`：小时(01-12)
- `%j`：一年中的第几天(001-366)
- `%k`：小时(0-23)
- `%l`：小时(1-12)
- `%m`：月份(01-12)
- `%M`：分钟(00-59)
- `%N`：纳秒(000000000-999999999)
- `%p`：输出一天中的上午(AM)或者下午(PM)
- `%P`：与`%p`，单输出的字母是小写
- `%r`：12小时制输出时间(02:02:33 AM)
- `%R`：24小时制输出小时与分钟(02:03)，与`%H:%M`一致
- `%s`：从`1970-01-01 00:00:00`开始至今的秒数(UTC)
- `%S`：秒(00-60)
- `%T`：时间`%H:%M:%S`
- `%u`：一周中的第几天(1-7)，1为周一
- `%U`：一年中的第几周(00-53)，周日作为一周的第1天
- `%V`：一年中的第几周(01-53)，周一作为一周的第1天
- `%w`：一周中的第几天(0-6)，0为周日
- `%W`：一年中的第几周(00-53)，周一作为一周的第1天
- `%x`：当地日期(11/29/22)
- `%X`：当地时间(02:14:09)
- `%y`：年份的最后两位
- `%Y`：年份
- `%z`：时区，格式：`+hhmm`(-0800)
- `%:z`：时区，格式：`+hh:mm`(-08:00)
- `%::z`：时区，格式：`+hh:mm:ss`(-08:00:00)
- `%Z`：时区缩写(CST)

### cal

`cal`命令用于显示日历，不带参数时显示的是当前月份。

### id

`id`用于查看指定用户的用户名和组名。

用户账户信息存放在文件`/etc/passwd`中，用户组信息存放在文件`/etc/group`中。

```shell
# 返回UID
id -u [UserName]

# 返回GID
id -g [UserName]

# 返回用户名
id -un [UserName]

# 返回组名
id -gn [UserName]

# 注：以上省略UserName时输出当前用户的信息
```

### su

`su`命令允许以另一个用户的身份，启动一个新的shell会话，或者是以这个用户的身份来发布一个命令。

```shell
su [UserName]
# 执行上面的命令后，系统会提示输入密码
# 通过以后，就以另一个用户身份在执行命令了
# 省略用户名表示切换到root用户

su -l
# 参数表示启动一个需要登录的新的Shell
# 工作目录会切换到该用户主目录
# 缩写形式：-，即：su -

su -c 'command'  # -c参数表示只以其他用户的身份执行单个命令，不启动新的session
su -c 'ls -l /root/*'
```

### sudo

`sudo`命令类似`su`命令。

差别：

1. 对于管理员来说，`sudo`命令的可配置性更高
2. `sudo`命令通常只用于执行单个命令，而不是开启另一个session
3. `sudo`命令不要求超级用户的密码，而是用户使自己的密码来认证

`sudo`相关的设置在文件`/etc/sudoers`之中。

`-l`参数用于列出用户拥有的所有权限。

### chown

`chown`用于更改文件或目录的所有者和用户组，使用这个命令需要超级用户权限。

```shell
# 更改文件所有者
sudo chown shiyucun example.txt

# 更改文件所有者和用户组
sudo chown shiyucun:shiyucun example.txt

# 更改用户组
sudo chown :shiyucun example.txt

# 更改文件所有者和用户组(默认为用户登录系统时所属的用户组）
sudo chown shiyucun: example.txt
```

### chgrp

`chgrp`用于更改用户组，用法与`chown`类似。

### useradd

`useradd`用于新增用户。

```shell
# 新增用户shiyucun
useradd -G admin -d /home/shiyucun -s /bin/bash -m shiyucun
# 参数:
#  -G 指定用户所在的组
#  -d 指定用户的主目录
#  -s 指定用户的shell
#  -m 如果该目录不存在，则创建该目录
```

### usermod

`usermod`用于修改用户的各项属性。

修改用户的主要用户组为admin：`usermod -g admin shiyucun`。

### adduser

`adduser`用于将一个用户加入用户组。

将用户shiyucun加入admin用户组：`sudo adduser shiyucun admin`。

### groupadd

`groupadd`用于新建一个用户组。

```shell
sudo groupadd group1
sudo adduser shiyucun group1
```

### groupdel

`groupdel`用于删除一个用户组，如：`sudo groupdel group1`。

### passwd

`passwd`用于修改密码。

```shell
# 修改自己的密码
passwd

# 修改其他用户的密码
sudo passwd shiyucun
```

### awk

`awk`是处理文本文件的一个应用程序，几乎所有linux系统都自带这个程序。

`awk`依次处理文件的每一行，并读取里面的每一个字段。

对于日志、CSV每行格式都相同的文本文件，`awk`几乎是最方便的工具。

**基本语法**：`awk action file_name`，action是处理每一行文本的动作。

`awk`会根据空格和制表符将每一行分成若干字段：

- `$0`代表整行内容
- `$1`、`$2`、`$3`分别代表第1、2、3个字段
- 其余字段按顺序类推
- 可以使用`-F`选项指定分隔符

**变量**：

- `NF`：表示当前行有多少个字段，`$NF`代表最后一个字段
- `NR`：表示当前处理的是第几行
- `FILENAME`：表示当前文件名
- `FS`：表示字段分隔符，默认是空格和制表符
- `RS`：表示行分隔符，用于分隔每一行，默认是换行符
- `OFS`：表示输出字段的分隔符，用于打印时分隔字段，默认为空格
- `ORS`：表示输出记录的分隔符，用于打印时分隔记录，默认为换行符
- `OFMT`：表示数字输出的格式，默认为`％.6g`

**函数**：

- `toupper()`：字符转为大写
- `tolower()`：字符转为小写
- `length()`：返回字符串长度
- `substr()`：返回子字符串
- `sin()`：正弦
- `cos()`：余弦
- `sqrt()`：平方根
- `rand()`：随机数

举例：

```shell
echo 'this is a test' | awk '{print $0}'
# this is a test

echo 'this is a test' | awk '{print $1}'
# this

echo 'this is a test' | awk '{print $4}'
# test

awk -F ':' '{print $1}' /etc/passwd

echo 'this is a test' | awk '{print NF}'
# 4

echo 'this is a test' | awk '{print $NF}'
# test

echo 'this is a test' | awk '{print $1, $NF}'  # ,表示输出时两部分之间使用空格分隔
# this test

awk -F ':' '{print NR ") " $1}' /etc/passwd

awk -F ':' '{ print toupper($1) }' /etc/passwd
```

**条件**：

`awk`允许指定输出条件，只输出符合条件的行。

输出条件要写在动作的前面：`awk 'condition action' file_name`。

`awk`还提供了`if`结构，用于编写复杂条件。

举例：

```shell
# condition可以是一个正则表达式，正则表达式写在//中
awk -F ':' '/root/ {print $1}' /etc/passwd
awk -F ':' '/ro+t/ {print $1}' /etc/passwd

# condition可以是一个条件表达式
awk -F ':' 'NR % 2 == 1 {print $1}' /etc/passwd
awk -F ':' 'NR > 3 {print $1}' /etc/passwd
awk -F ':' '$1 == "root" {print $1}' /etc/passwd

# if条件
awk -F ':' '{if ($1 > "m") print $1}' /etc/passwd
awk -F ':' '{if ($1 > "m") print $1; else print "---"}' /etc/passwd
```

### pv

磁盘的复制通常需要很久，为了监控进展，可以使用Pipe Viewer工具软件。

安装：`sudo apt install pv`。

使用：`dd if=/dev/urandom | pv | dd of=/dev/sda1`。

### last

`last`命令显示用户登录系统的记录。

### lpq

`lpq`命令用于显示打印机队列。

### lpr

`lpr`命令用于打印文件。

### tr

`tr`命令用于按照给定模式转换文本。

```shell
# 将小写字母转换为大写字母
cat example.txt | tr 'a-z' 'A-Z'

# 将空格转换为换行符
cat example.txt | tr ' ' '\n'

# 字母t转换为字母a，字母T转换为字母A
cat example.txt | tr 'tT' 'aA'
```

### uptime

`uptime`可以显示本次开机运行的时间。

### w

`w`命令可以显示当前在线用户。


