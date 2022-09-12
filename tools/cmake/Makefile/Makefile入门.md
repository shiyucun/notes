# Makefile 入门

- [Makefile 入门](#makefile-入门)
  - [语法规则](#语法规则)
  - [变量](#变量)
  - [变量赋值](#变量赋值)
  - [预定义变量](#预定义变量)
  - [函数](#函数)
  - [伪目标 .PHONY](#伪目标-phony)
  - [代码清理](#代码清理)
  - [嵌套执行 Makefile](#嵌套执行-makefile)
  - [指定头文件路径](#指定头文件路径)
  - [指定库文件路径](#指定库文件路径)
  - [example](#example)

---

## 语法规则

```makefile
目标 ... : 依赖 ...
	命令1
	命令2
	. . .
```

Makefile 并不会关心命令是如何执行的，仅仅只是会去执行所有定义的命令，和平时直接输入命令行是一样的效果。

目标：即要生成的文件。

如果目标文件的更新时间晚于依赖文件更新时间，则说明依赖文件没有改动，目标文件不需要重新编译。否则会进行重新编译并更新目标文件。

默认情况下 Makefile 的第一个目标为终极目标。

依赖：即目标文件由哪些文件生成。

命令：即通过执行命令由依赖文件生成目标文件。

注意每条命令之前必须有一个 tab 保持缩进，这是语法要求。

all：Makefile文件默认只生成第一个目标文件即完成编译，但是我们可以通过all 指定所需要生成的目标文件。

## 变量

$ 符号表示取变量的值，当变量名多于一个字符时，使用"( )"。

$符的其他用法：

- $^ 表示所有的依赖文件
- $@ 表示生成的目标文件
- $< 代表第一个依赖文件

```makefile
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

ALL: hello.out

hello.out: $(OBJ)
	gcc $< -o $@

$(OBJ): $(SRC)
	gcc -c $< -o $@
```

## 变量赋值

"="是最普通的等号，在Makefile中容易搞错赋值等号，使用"="进行赋值，变量的值是整个Makefile中最后被指定的值。

```makefile
VIR_A = A
VIR_B = $(VIR_A) B
VIR_A = AA

# 最后 VIR_B 的值是"AA B"，而不是"A B"，在 make 时，会把整个 Makefile 展开，来决定变量的值。
```

":="表示直接赋值，赋予当前位置的值。

```makefile
VIR_A := A
VIR_B := $(VIR_A) B
VIR_A := AA

# 最后 VIR_B 的值是"A B"，即根据当前位置进行赋值。因此相当于"="，":="才是真正意义上的直接赋值。
```

"?="表示如果该变量没有被赋值，赋值为等号后面的值。

```makefile
VIR ?= new_value

# 如果VIR在之前没有被赋值，那么 VIR 的值就为new_value。

VIR := old_value
VIR ?= new_value

# 这种情况下，VIR 的值就是 old_value。
```

"+="和平时写代码的理解是一样的，表示将符号后面的值添加到前面的变量上。

## 预定义变量

CC：c编译器的名称，默认值为cc。取值：$(CC)。

```makefile
CC = gcc
```

回显问题，Makefile中的命令都会被打印出来。如果不想打印命令部分 可以使用@去除回显

```makefile
@echo "clean done!"
```

## 函数

```makefile
SRC = $(wildcard ./*.c)

# 匹配目录下所有 .c 文件，并将其赋值给 SRC 变量。
```

```makefile
OBJ = $(patsubst %.c, %.o, $(SRC))
# 这个函数有三个参数，意思是取出 SRC 中的所有值，然后将 .c 替换为 .o 最后赋值给OBJ变量。
```

```makefile
# 如果目录下有很多个 .c 源文件，就不需要写很多条规则语句了，而是可以像下面这样写。

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

ALL: hello.out

hello.out: $(OBJ)
	gcc $(OBJ) -o hello.out
 
$(OBJ): $(SRC)
	gcc -c $(SRC) -o $(OBJ)

# 先将所有 .c 文件编译为 .o 文件，这样后面更改某个 .c 文件时，其他的 .c 文件将不在编译，而只是编译有更改的 .c 文件，可以大大提高大项目中的编译速度。
```

## 伪目标 .PHONY

伪目标只是一个标签，clean是个伪目标没有依赖文件，只有用make来调用时才会执行。

当目录下有与 make 命令同名的文件时，执行 make 命令就会出现错误。

解决办法就是使用伪目标：

```makefile
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

ALL: hello.out

hello.out: $(OBJ)
	gcc $< -o $@

$(OBJ): $(SRC)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJ) hello.out

.PHONY: clean ALL

# 通常也会把ALL设置成伪目标。
```

## 代码清理

```makefile
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

ALL: hello.out

hello.out: $(OBJ)
	gcc $< -o $@

$(OBJ): $(SRC)
	gcc -c $< -o $@

clean:
	rm -rf $(OBJ) hello.out
```

## 嵌套执行 Makefile

在一些大工程中，会把不同模块或不同功能的源文件放在不同的目录中。

我们可以在每个目录中都写一个该目录的 Makefile，这有利于让我们的 Makefile 变的更加简洁，不至于把所有东西全部写在一个Makefile中。

例如：在子目录 subdir 下有个 Makefile 文件，来指明这个目录下文件的编译规则。外部总Makefile可以这样写：

```makefile
subsystem:
	cd subdir && $(MAKE)
```

等价于：

```makefile
subsystem:
	$(MAKE) -C subdir
```

定义 $(MAKE) 宏变量的意思是，也许我们的 make 需要一些参数，所以定义成一个变量比较有利于维护。

以上两个例子的意思都是先进入"subdir"目录，然后执行make命令。

我们把这个 Makefile 叫做总控 Makefile，总控 Makefile 的变量可以传递到下级的 Makefile 中，但是不会覆盖下层 Makefile 中所定义的变量，除非指定了"-e"参数。

如果传递变量到下级 Makefile 中，可以使用"export"声明。

如果不想传递某些变量到下级 Makefile 中，可以使用"unexport"声明。

```makefile
export variable = value    # 等价于 variable = value
export variable            # 等价于 export variable := value
variable := value          # 等价于 export variable
                           # 只有一个 export 时，可以传递所有变量
```

## 指定头文件路径

一般都是通过"-I"(大写i)来指定。

```makefile
# 假设头文件在
/code/include/path

# 可以通过 -I 指定
-I/home/develop/include

# 将目录添加到头文件搜索路径中，然后在编译的时候引用CFLAGS即可
CFLAGS=-I/code/include/path

target: *.c
	gcc $(CFLAGS) -o target
```

## 指定库文件路径

使用的是"-L"来指定库搜索路径，使用"-l"来指定要链接的库。

```makefile
# 假设库文件在
/code/lib/path

# 将目录添加到库文件搜索路径中
LDFLAGS=-L/code/lib/path

# 告诉链接器要链接哪些库文件
LIBS = -lpthread
```

## example

当前目录下，文件夹 example 是一个 Makefile 的演示示例。

示例中，创建了多层目录，编译了静态库、动态库以及可执行程序，在 example 下直接 make 即可。

- make：编译
- make clean：删除编译生成的文件
- make install：生成 Makefile-example/build 目录，将库文件、头文件、可执行程序安装到该目录下
- make uninstall：删除 build 目录下安装的文件
- make distclean：删除 build 目录下安装的文件，同时删除编译生成的中间文件
