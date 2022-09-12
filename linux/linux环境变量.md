
# linux环境变量

- [linux环境变量](#linux环境变量)
  - [系统运行级别](#系统运行级别)
  - [登录shell](#登录shell)
  - [系统环境变量配置文件](#系统环境变量配置文件)
    - [系统级文件](#系统级文件)
      - [/etc/profile](#etcprofile)
      - [/etc/bash.bashrc](#etcbashbashrc)
      - [/etc/environment](#etcenvironment)
    - [用户级文件](#用户级文件)
      - [~/.profile](#profile)
      - [~/.bashrc](#bashrc)
      - [~/.bash\_profile](#bash_profile)
      - [~./bash\_login](#bash_login)
      - [~/.bash\_logout](#bash_logout)
  - [`/etc/profile`与`/etc/enviroment`的比较](#etcprofile与etcenviroment的比较)
  - [设置环境变量](#设置环境变量)

## 系统运行级别

linux系统有7个运行级别(runlevel)：

- 运行级别0：系统停机状态，系统默认运行级别不能设为0，否则不能正常启动
- 运行级别1：单用户工作状态，root权限，用于系统维护，禁止远程登陆
- 运行级别2：多用户状态(没有网络文件系统NFS net file system)
- 运行级别3：完全的多用户状态(有NFS)，登陆后进入控制台命令行模式
- 运行级别4：系统未使用，保留
- 运行级别5：X11控制台，登陆后进入图形GUI模式
- 运行级别6：系统正常关闭并重启，默认运行级别不能设为6，否则不能正常启动

在 **/etc/init.d** 下有许多服务器脚本程序，一般称为服务(service)。

在 **/etc** 下有7个名为 **rcN.d** 的目录，对应系统的7个运行级别。

**rcN.d** 目录下都是一些符号链接文件，这些链接文件都指向 **init.d** 目录下的 service 脚本文件。

符号链接文件的命名规则为 **K+nn+服务名** 或 **S+nn+服务名**(nn为两位数字)。

系统根据指定的运行级别进入对应的 rcN.d 目录，按照文件名顺序检索目录下的链接文件：

- 对于以K开头的文件，系统将终止对应的服务
- 对于以S开头的文件，系统将启动对应的服务

查看运行级别用：`runlevel`

进入其它运行级别用：`init N`，**init 0** 为关机，**init 6** 为重启系统。

现在的 linux 系统安装完后默认就运行在第5个级别。

不同运行级别之间的差别的在于系统默认起动的服务的不同。

本质上各运行级别是没有区别的，更无所谓不同级别间功能强弱的问题。

用户完全可自给定义不同级别的默认服务。在任何运行级别，用户都可用 init 命令来切换到其他运行级别。

## 登录shell

登录 shell 是系统运行时最先执行的 shell。

- 当linux系统运行级别为3时，用户可以从本地登录到系统控制台，或
- 在系统运行级别为5时，直接以图形界面方式登录

以上两种情况下都需要输入用户名和密码。

以下文件主要用于设置运行环境，其中一些会被登录 shell 调用，可以把这些环境授予非登录 shell。

用户登录时Bash将会使用以下初始化文件和启动脚本：

- `/etc/profile`：系统级的初始化文件定义了一些环境变量，由登录shell调用执行
- `/etc/bashrc`：文件名与linux版本相关， 交互式shell系统级启动脚本，定义函数和别名
- `/etc/bash.logout`：系统级登录shell清理脚本，登录shell退出时执行
- `$HOME/.bash_profile、.bash_login、.profile`：用户个人初始化脚本，登录shell调用
- `$HOME/.bashrc`：用户个人的每个交互式shell的启动脚本
- `$HOME/.bash_logout`：用户个人的登录shell清理脚本，当登录shell退出时执行
- `$HOME/.inputrc`：用户个人readline使用的启动脚本，定义处理某些情况的键盘映射Bash启动脚本

用户登录时，登录shell会调用如下脚本：

- `/etc/profile`：用户在运行级别3登录系统时首先运行
- `/etc/profile.d`：当`/etc/profile`运行时，会调用该目录下的一些脚本
- `$HOME/.bash_profile(.bash_login、.profile)`：在`/etc/profile`运行后第一个存在的被运行
- `$HOME/.bashrc`：如果此文件存在即被运行
- `/etc/bashrc`：被`$HOME/.bashrc`调用运行
- `/etc/profile.d`：此目录下的脚本将被`/etc/bashrc`或`/etc/bash.bashrc`调用运行

Bash启动脚本主要设置的环境有：

- 设置环境变量PATH和PS1
- 通过变量EDITOR设置默认的文本编辑器
- 设置默认的umask(文件或目录的权限属性)
- 覆盖或移除不想要的变量或别名
- 设置别名
- 加载函数
- 系统环境变量配置文件

## 系统环境变量配置文件

系统环境变量配置文件分为两种：系统级文件和用户级文件。

### 系统级文件

#### /etc/profile

登录时，操作系统定制用户环境时使用的第一个文件，此文件为系统的每个用户设置环境信息。

当用户第一次登录时，该文件被执行，并从`/etc/profile.d`目录的配置文件中搜集shell的设置。

这个文件一般就是调用`/etc/bash.bashrc`文件。

#### /etc/bash.bashrc

为每一个运行bash shell的用户执行此文件。

当bash shell被打开时，该文件被读取。

#### /etc/environment

在登录时操作系统使用的第二个文件，系统在读取用户的profile前，设置环境文件的环境变量。

### 用户级文件

#### ~/.profile

在登录时用到的第三个文件是`.profile`文件，每个用户都可使用该文件输入专用于自己使用的shell信息。

当用户登录时，该文件仅仅执行一次。默认情况下，他设置一些环境变量，并执行用户的`.bashrc`文件。

#### ~/.bashrc

该文件包含专用于某个用户的bash shell的bash信息。

当登录时以及每次打开新的shell时，该该文件被读取。

不推荐放到这儿，因为每开一个shell，这个文件会读取一次，效率上讲不好。

`/etc/profile`中设定的变量(全局)，可以作用于任何用户。

`~/.bashrc`等中设定的变量(局部)只能继承`/etc/profile`中的变量，二者是"父子"关系。

#### ~/.bash_profile

每个用户都可使用该文件输入专用于自己的shell信息，当用户登录时，该文件执行一次。

默认情况下，设置一些环境变量，执行用户的`.bashrc`文件。

`~/.bash_profile`是交互式、login 方式进入 bash 运行的。

`~/.bashrc`是交互式 non-login 方式进入 bash 运行的。

通常二者设置大致相同，所以通常前者会调用后者。

#### ~./bash_login

不推荐使用这个，这些不会影响图形界面。

`.bash_profile`优先级比`bash_login`高。

当它们存在时，登录shell启动时会读取它们。

#### ~/.bash_logout

当每次退出系统(退出bash shell)时，执行该文件。

## `/etc/profile`与`/etc/enviroment`的比较

`/etc/environment`是设置整个系统的环境，与登录用户无关。

`/etc/profile`是设置所有用户的环境，与登录用户相关。

系统应用程序的执行与用户环境可以是无关的，但与系统环境是相关的。

所以当我们登录时，看到的提示信息，比如日期、时间信息的显示格式与系统环境的LANG是相关的。

缺省`LANG=en_US`，如果系统环境`LANG=zh_CN`，则提示信息是中文的，否则是英文的。

登录系统时 shell 读取的顺序是：

1. `/etc/profile`
2. `/etc/enviroment`
3. `$HOME/.profile`
4. `$HOME/.env`

如果同一个变量在用户环境(`/etc/profile`)和系统环境(`/etc/environment`)有不同的值那就以用户环境为准。

在登录linux时要执行文件的过程如下：

1. 首先启动`/etc/profile`文件，然后再启动用户目录下的
2. `~/.bash_profile`、`~/.bash_login`、`~/.profile` 文件中的其中一个
3. 如果`~/.bash_profile`文件存在的话，一般还会执行`~/.bashrc`文件
4. 在退出shell时，还会执行`~/.bash_logout文件`

`~/.bash_profile`文件中一般会有下面的代码：

```shell
if[ -f ~/.bashrc ] ; then
 ../bashrc
fi

if[ -f /etc/bashrc ] ; then
 ./bashrc
fi

# 所以，`~/.bashrc`会调用`/etc/bashrc`文件。
```

由上可知：

1. `/etc/profile`是全局的，随系统启动设置【设置这个文件是一劳永逸的办法】
2. `/root/.profile`和`/home/username/.profile`只对当前窗口有效
3. `/root/.bashrc`和`/home/username/.bashrc`随系统启动，设置用户的环境变量

## 设置环境变量

export可新增、修改或删除环境变量，供后续执行的程序使用。

export的效力仅局限于登录操作。

那么要配置Ubuntu的环境变量，就要在上述几个配置文件中找一个合适的文件进行操作。

如想将一个路径加入到`$PATH`中，可以由下面这样几种添加方法：

```shell
# 控制台中(只在当前控制台中生效)
PATH="$PATH:/new_path"

# 修改profile文件
sudo vim /etc/profile
# 添加以下内容
export PATH=$PATH:/new_path

# 修改.bashrc文件
sudo vim /root/.bashrc
sudo vim ~/.bashrc
# 添加以下内容
export PATH=$PATH:/new_path

# 注销系统或使用以下命令使环境变量生效
source ~/.bashrc
source /etc/profile

# 使用以下命令验证环境变量设置生效
echo $PATH
```

对于C程序员来说，环境变量有：

- `CPATH`：用来定义头文件的环境变量
- `LIBRARY_PATH`：用于连接时定位库文件
- `LD_LIBRARY_PATH`：用于运行期间定位共享库文件

对于PYTHON程序员来说，环境变量还有：`PYTHONPATH`。
