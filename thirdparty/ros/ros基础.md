
# ros 基础

- [ros 基础](#ros-基础)
  - [roscore](#roscore)
  - [rosrun](#rosrun)
  - [rqt 工具](#rqt-工具)
  - [rosnode](#rosnode)
  - [rostopic](#rostopic)
  - [rosmsg](#rosmsg)
  - [rosservice](#rosservice)
  - [rosbag](#rosbag)
  - [rosparam](#rosparam)
  - [roslaunch](#roslaunch)

---

## roscore

`roscore`是系统自带的节点(Node)。为了让我们写的节点之间能够通信，第一个命令就是通过roscore命令启动它。

```text
# roscore 输出
... logging to /home/shiyucun/.ros/log/3fb74d4c-f343-11eb-864d-ccd9ac825ef1/roslaunch-kthinkpad-16782.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://kthinkpad:42107/
ros_comm version 1.14.10


SUMMARY
========

PARAMETERS
 * /rosdistro: melodic
 * /rosversion: 1.14.10

NODES

auto-starting new master
process[master]: started with pid [16792]
ROS_MASTER_URI=http://kthinkpad:11311/

setting /run_id to 3fb74d4c-f343-11eb-864d-ccd9ac825ef1
process[rosout-1]: started with pid [16803]
started core service [/rosout]
```

## rosrun

`rosrun`是运行一个单独节点的命令，如果要运行多个节点，则需要使用多次rosrun命令。

```text
# rosrun 输出
Usage: rosrun [--prefix cmd] [--debug] PACKAGE EXECUTABLE [ARGS]
  rosrun will locate PACKAGE and try to find
  an executable named EXECUTABLE in the PACKAGE tree.
  If it finds it, it will run it with ARGS.
```

example：

```shell
rosrun turtlesim turtlesim_node
rosrun turtlesim turtle_teleop_key
```

## rqt 工具

ubuntu 安装 rqt 工具命令：

```shell
sudo apt-get install ros-indigo-rqt
sudo apt-get install ros-indigo-rqt-common-plugins
```

`rqt_graph`能够创建一个显示当前系统运行情况的动态图形。

`rqt_graph`是 rqt 程序包中的一部分。其它 rqt 命令可以输入`rqt_`后双击`tab`键查看。

```text
# rqt_graph --help 输出
usage: main.pyc [-b BINDING] [--clear-config] [--force-discover] [-h]
                [--reload-import] [-t] [-v]

Options for GUI instance:
  -b BINDING, --qt-binding BINDING
                        choose Qt bindings to be used [pyqt|pyside]
  --clear-config        clear the configuration (including all perspectives
                        and plugin settings)
  --force-discover      force a rediscover of plugins
  -h, --help            show this help message and exit
  --reload-import       reload every imported module
  -t, --on-top          set window mode to always on top
  -v, --verbose         output qDebug messages
```

example:`rosrun rqt_graph rqt_graph`。

## rosnode

使用`rosnode`命令可以查看 ros 节点相关的信息。

```text
# rosnode -h 输出
rosnode is a command-line tool for printing information about ROS Nodes.

Commands:
 rosnode ping       test connectivity to node
 rosnode list       list active nodes
 rosnode info       print information about node
 rosnode machine    list nodes running on a particular machine or list machines
 rosnode kill       kill a running node
 rosnode cleanup    purge registration information of unreachable nodes

Type rosnode <command> -h for more detailed usage, e.g. 'rosnode ping -h'
```

使用`rosnode list`列出运行的节点：

```text
# rosnode list 输出
/rosout
/teleop_turtle
/turtlesim
```

使用`rosnode info`查看节点的信息：

```text
# rosnode info /turtlesim 输出
--------------------------------------------------------------------------------
Node [/turtlesim]
Publications:
 * /rosout [rosgraph_msgs/Log]
 * /turtle1/color_sensor [turtlesim/Color]
 * /turtle1/pose [turtlesim/Pose]

Subscriptions:
 * /turtle1/cmd_vel [geometry_msgs/Twist]

Services:
 * /clear
 * /kill
 * /reset
 * /spawn
 * /turtle1/set_pen
 * /turtle1/teleport_absolute
 * /turtle1/teleport_relative
 * /turtlesim/get_loggers
 * /turtlesim/set_logger_level


contacting node http://kthinkpad:38509/ ...
Pid: 19114
Connections:
 * topic: /rosout
    * to: /rosout
    * direction: outbound (48959 - 127.0.0.1:37652) [28]
    * transport: TCPROS
 * topic: /turtle1/cmd_vel
    * to: /teleop_turtle (http://kthinkpad:42487/)
    * direction: inbound (35142 - kthinkpad:40829) [29]
    * transport: TCPROS
```

使用`rosnode ping`查看节点连通状态：

```text
# rosnode ping 输出
Usage: rosnode ping [options] <node>

rosnode: error: Please enter a node to ping. Available nodes are:
/rosout
/teleop_turtle
/turtlesim
Usage: rosnode ping [options] <node>

rosnode: error: Please enter a node to ping

# rosnode ping /turtlesim 输出
rosnode: node is [/turtlesim]
pinging /turtlesim with a timeout of 3.0s
xmlrpc reply from http://kthinkpad:38509/ time=0.475883ms
xmlrpc reply from http://kthinkpad:38509/ time=1.943111ms
xmlrpc reply from http://kthinkpad:38509/ time=1.935005ms
xmlrpc reply from http://kthinkpad:38509/ time=1.905918ms
^Cping average: 1.564980ms
```

## rostopic

`rostopic`可以查看或者发布 topic 相关信息。

```text
# rostopic 输出
rostopic is a command-line tool for printing information about ROS Topics.

Commands:
 rostopic bw       display bandwidth used by topic
 rostopic delay    display delay of topic from timestamp in header
 rostopic echo     print messages to screen
 rostopic find     find topics by type
 rostopic hz       display publishing rate of topic
 rostopic info     print information about active topic
 rostopic list     list active topics
 rostopic pub      publish data to topic
 rostopic type     print topic or field type

Type rostopic <command> -h for more detailed usage, e.g. 'rostopic echo -h'
```

`rostopic info`查看 topic 信息：

```text
# rostopic info /turtle1/cmd_vel 输出
Type: geometry_msgs/Twist

Publishers:
 * /teleop_turtle (http://kthinkpad:42487/)

Subscribers:
 * /turtlesim (http://kthinkpad:38509/)


# rostopic info /turtle1/pose 输出
Type: turtlesim/Pose

Publishers:
 * /turtlesim (http://kthinkpad:38509/)

Subscribers: None
```

`rostopic pub`发布topic信息：

```text
# rostopic pub -h 输出
Usage: rostopic pub /topic type [args...]

Options:
  -h, --help            show this help message and exit
  -v                    print verbose output
  -r RATE, --rate=RATE  publishing rate (hz).  For -f and stdin input, this
                        defaults to 10.  Otherwise it is not set.
  -1, --once            publish one message and exit
  -f FILE, --file=FILE  read args from YAML file (Bagy)
  -l, --latch           enable latching for -f, -r and piped input.  This
                        latches the first message.
  -s, --substitute-keywords
                        When publishing with a rate, performs keyword ('now'
                        or 'auto') substitution for each message
  --use-rostime         use rostime for time stamps, else walltime is used

# 发布 topic 信息
#  rostopic pub -r 10 /turtle1/cmd_vel geometry_msgs/Twist "linear:
#   x: 1.0
#   y: 0.0
#   z: 0.0
# angular:
#   x: 0.0
#   y: 0.0
#   z: 3.0"
```

## rosmsg

`rosmsg`是 ros 自带的命令行工具，用于显示 ros 中 message 相关的信息。

```text
# rosmsg 输出
rosmsg is a command-line tool for displaying information about ROS Message types.

Commands:
 rosmsg show        Show message description
 rosmsg info        Alias for rosmsg show
 rosmsg list        List all messages
 rosmsg md5         Display message md5sum
 rosmsg package     List messages in a package
 rosmsg packages    List packages that contain messages

Type rosmsg <command> -h for more detailed usage
```

example:

```text
# rosmsg show geometry_msgs/Twist 输出
geometry_msgs/Vector3 linear
  float64 x
  float64 y
  float64 z
geometry_msgs/Vector3 angular
  float64 x
  float64 y
  float64 z
```

## rosservice

service 是节点通信的一种方法，`rosservice`是该方法的命令行工具。

```text
# rosservice 输出
Commands:
 rosservice args    print service arguments
 rosservice call    call the service with the provided args
 rosservice find    find services by service type
 rosservice info    print information about service
 rosservice list    list active services
 rosservice type    print service type
 rosservice uri     print service ROSRPC uri

Type rosservice <command> -h for more detailed usage, e.g. 'rosservice call -h'
```

example:

```text
# rosservice list 输出
/clear
/kill
/reset
/rosout/get_loggers
/rosout/set_logger_level
/spawn
/teleop_turtle/get_loggers
/teleop_turtle/set_logger_level
/turtle1/set_pen
/turtle1/teleport_absolute
/turtle1/teleport_relative
/turtlesim/get_loggers
/turtlesim/set_logger_level

# rosservice call reset

# rosservice args /spawn 输出
x y theta name

# rosservice info /spawn 输出
Node: /turtlesim
URI: rosrpc://kthinkpad:48959
Type: turtlesim/Spawn
Args: x y theta name

# rosservice type /spawn 输出
turtlesim/Spawn
```

## rosbag

bag是ros中存储message的一种数据格式，rosbag命令行工具可以录制、回放bag包。

```text
# rosbag -h 输出
Usage: rosbag <subcommand> [options] [args]

A bag is a file format in ROS for storing ROS message data. The rosbag command can record, replay and manipulate bags.

Available subcommands:
   check  Determine whether a bag is playable in the current system, or if it can be migrated.
   compress  Compress one or more bag files.
   decompress  Decompress one or more bag files.
   decrypt  Decrypt one or more bag files.
   encrypt  Encrypt one or more bag files.
   filter  Filter the contents of the bag.
   fix  Repair the messages in a bag file so that it can be played in the current system.
   help
   info  Summarize the contents of one or more bag files.
   play  Play back the contents of one or more bag files in a time-synchronized fashion.
   record  Record a bag file with the contents of specified topics.
   reindex  Reindexes one or more bag files.

For additional information, see http://wiki.ros.org/rosbag
```

example:

```text
# rosbag record -a -O cmd_record 输出
[ INFO] [1627884221.727042418]: Recording to 'cmd_record.bag'.
[ INFO] [1627884221.728004396]: Subscribing to /turtle1/color_sensor
[ INFO] [1627884221.729814698]: Subscribing to /turtle1/cmd_vel
[ INFO] [1627884221.731360296]: Subscribing to /rosout
[ INFO] [1627884221.733002214]: Subscribing to /rosout_agg
[ INFO] [1627884221.734362240]: Subscribing to /turtle1/pose
^C

# rosbag play cmd_record.bag 输出
[ INFO] [1627884252.023785781]: Opening cmd_record.bag

Waiting 0.2 seconds after advertising topics... done.

Hit space to toggle paused, or 's' to step.
 [RUNNING]  Bag Time: 1627884237.736549   Duration: 16.000384 / 16.031601
Done.
```

## rosparam

```text
# rosparam -h 输出
rosparam is a command-line tool for getting, setting, and deleting parameters from the ROS Parameter Server.

Commands:
 rosparam set     set parameter
 rosparam get     get parameter
 rosparam load    load parameters from file
 rosparam dump    dump parameters to file
 rosparam delete  delete parameter
 rosparam list    list parameter names
```

```text
# rosparam get /rosversion 输出
'1.14.10'
```

```text
# rosparam dump param.yaml
```

```text
# cd shiyucun/catkin_ws/src/ && catkin_create_pkg learning_parameter roscpp rospy std_srvs 输出
Created file learning_parameter/package.xml
Created file learning_parameter/CMakeLists.txt
Created folder learning_parameter/include/learning_parameter
Created folder learning_parameter/src
Successfully created files in ~/shiyucun/catkin_ws/src/learning_parameter. Please adjust the values in package.xml.

# ls
CMakeLists.txt  learning_parameter  learning_service  learning_topic

# cd learning_parameter/src/
# touch parameter_config.cpp
# vim parameter_config.cpp
```

输入：

```c++
#include <ros/ros.h>
#include <std_srvs/Empty.h>

int main(int argc, char** argv) {
    int r, g, b;

    ros::init(argc, argv, "parameter_config");

    ros::NodeHandle node;

    ros::param::get("/turtlesim/background_r", r);
    ros::param::get("/turtlesim/background_g", g);
    ros::param::get("/turtlesim/background_b", b);

    ROS_INFO("rgb -> (%d, %d, %d)", r, g, b);

    ros::param::set("/turtlesim/background_r", 255);
    ros::param::set("/turtlesim/background_g", 255);
    ros::param::set("/turtlesim/background_b", 255);

    ROS_INFO("set rgb all 255");

    ros::param::get("/turtlesim/background_r", r);
    ros::param::get("/turtlesim/background_g", g);
    ros::param::get("/turtlesim/background_b", b);

    ROS_INFO("re get rgb -> (%d, %d, %d)", r, g, b);

    ros::service::waitForService("/clear");
    ros::ServiceClient clear_background = node.serviceClient<std_srvs::Empty>("/clear");
    std_srvs::Empty srv;

    clear_background.call(srv);

    sleep(1);

    return 0;
}
```

```text
# cd ..
# vim CMakeLists.txt
```

添加以下内容：

```cmake
add_executable(learning_param src/parameter_config.cpp)
target_link_libraries(learning_param ${catkin_LIBRARIES})
```

依次执行以下命令测试：

```shell
roscore
rosrun turtlesim turtlesim_node
rosrun learning_parameter learning_param
```

## roslaunch

```text
# roslaunch -h 输出
Usage: roslaunch [options] [package] <filename> [arg_name:=value...]
       roslaunch [options] <filename> [<filename>...] [arg_name:=value...]

If <filename> is a single dash ('-'), launch XML is read from standard input.

Options:
  -h, --help            show this help message and exit
  --files               Print list files loaded by launch file, including
                        launch file itself
  --args=NODE_NAME      Print command-line arguments for node
  --nodes               Print list of node names in launch file
  --find-node=NODE_NAME
                        Find launch file that node is defined in
  -c NAME, --child=NAME
                        Run as child service 'NAME'. Required with -u
  --local               Do not launch remote nodes
  --screen              Force output of all local nodes to screen
  --required            Force all nodes to be required
  --log                 Force output of all local nodes to log
  -u URI, --server_uri=URI
                        URI of server. Required with -c
  --run_id=RUN_ID       run_id of session. Required with -c
  --wait                wait for master to start before launching
  -p PORT, --port=PORT  master port. Only valid if master is launched
  --core                Launch core services only
  --pid=PID_FN          write the roslaunch pid to filename
  -v                    verbose printing
  --no-summary          hide summary printing
  --dump-params         Dump parameters of all roslaunch files to stdout
  --skip-log-check      skip check size of log folder
  --ros-args            Display command-line arguments for this launch file
  --disable-title       Disable setting of terminal title
  -w NUM_WORKERS, --numworkers=NUM_WORKERS
                        override number of worker threads. Only valid for core
                        services.
  -t TIMEOUT, --timeout=TIMEOUT
                        override the socket connection timeout (in seconds).
                        Only valid for core services.
  --master-logger-level=MASTER_LOGGER_LEVEL
                        set rosmaster.master logger level ('debug', 'info',
                        'warn', 'error', 'fatal')
```

launch文件中根元素采用 `<launch>` 标签定义，如下：

```text
<launch>
    <node pkg="turtlesim" name="sim1" type="turtlesim_node"/>
    <node pkg="turtlesim" name="sim2" type="turtlesim_node"/>
</launch>
```

`<node>` 标签：

```text
pkg:      节点所在功能包名称
type:     节点可执行文件的名称
name:     节点运行时的名称
output:   节点日志信息是否打印到终端
respawn:  节点挂掉是否重启
required: 节点是否必须启动
ns:       节点命名空间，防止冲突
args:     节点可执行文件输入的参数
```

`<param>` 和 `<rosparam>` 标签：

```text
<param name="output_frame" value="odom"/>   # 设置ros系统运行中的参数，存储在参数服务器中
                                            # name：参数名，value：参数值
<rosparam file="params.yaml" command="load" ns="params"/>    # 加载参数文件中的多个参数
```

`<arg>` 标签：

```text
<arg name="arg-name" default="arg-value"/>    # launch 文件内部的局部变量，仅限于launch文件使用
                                              # name：参数名，value：参数值
# 使用文件内局部变量：
<param name="foo" value="$(arg arg-name)"/>
<node name="node" pkg="package" type="type" args="$(arg arg-name)"/>
```

`<remap>` 标签：

```text
<remap from="/turtlebot/cmd_vel" to="/cmd_vel"/>    # 重映射ros计算图资源的命名
                                                    # from：原命名，to：映射之后的命名
```

`<include>` 标签：

```text
<include file="$(dir)/other.launch"/>   # 包含其它launch文件，类似c语言中 #include
                                        # file：其它launch文件路径
```
