
# ros-workspace

- [ros-workspace](#ros-workspace)
  - [workspace 工作空间](#workspace-工作空间)
  - [创建功能包](#创建功能包)

## workspace 工作空间

如下执行，catkin_ws 为工作空间，空间下 src 文件夹存放源代码。

在 src 下使用命令 catkin_init_workspace 初始化工作空间，在 catkin_ws 下使用 catkin_make 编译。

为了能够找到执行命令，需要设置环境变量：source devel/setup.bash。

查看环境变量是否设置成功：echo $ROS_PACKAGE_PATH。

```shell
mkdir -p ~/shiyucun/catkin_ws/src/    # 创建文件夹
cd ~/shiyucun/catkin_ws/src/ && catkin_init_workspace    # 初始化工作空间
cd .. && catkin_make    # 编译
source devel/setup.bash    # source 环境变量
echo $ROS_PACKAGE_PATH    # 输出环境变量
```

## 创建功能包

在src下可以使用命令catkin_create_pkg创建功能包，如下:

```text
# catkin_create_pkg -h 输出
usage: catkin_create_pkg [-h] [--meta] [-s [SYS_DEPS [SYS_DEPS ...]]]
                         [-b [BOOST_COMPS [BOOST_COMPS ...]]] [-V PKG_VERSION]
                         [-D DESCRIPTION] [-l LICENSE] [-a AUTHOR]
                         [-m MAINTAINER] [--rosdistro ROSDISTRO]
                         name [dependencies [dependencies ...]]

Creates a new catkin package

positional arguments:
  name                  The name for the package
  dependencies          Catkin package Dependencies

optional arguments:
  -h, --help            show this help message and exit
  --meta                Creates meta-package files
  -s [SYS_DEPS [SYS_DEPS ...]], --sys-deps [SYS_DEPS [SYS_DEPS ...]]
                        System Dependencies
  -b [BOOST_COMPS [BOOST_COMPS ...]], --boost-comps [BOOST_COMPS [BOOST_COMPS ...]]
                        Boost Components
  -V PKG_VERSION, --pkg_version PKG_VERSION
                        Initial Package version
  -D DESCRIPTION, --description DESCRIPTION
                        Description
  -l LICENSE, --license LICENSE
                        Name for License, (e.g. BSD, MIT, GPLv3...)
  -a AUTHOR, --author AUTHOR
                        A single author, may be used multiple times
  -m MAINTAINER, --maintainer MAINTAINER
                        A single maintainer, may be used multiple times
  --rosdistro ROSDISTRO
                        The ROS distro (default: environment variable
                        ROS_DISTRO if defined)
$
```

example:

```shell
cd ~/shiyucun/catkin_ws/src/
catkin_create_pkg test_pkg std_msgs rospy roscpp    # 创建功能包
```
