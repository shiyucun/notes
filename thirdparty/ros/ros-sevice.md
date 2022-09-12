
# ros service

- [ros service](#ros-service)
  - [client](#client)
  - [server](#server)
  - [service data](#service-data)
    - [生成 data 头文件](#生成-data-头文件)
    - [头文件的使用](#头文件的使用)

## client

创建 workspace 和代码文件，并修改代码文件：

```shell
cd shiyucun/catkin_ws/src/
catkin_create_pkg learning_service rospy roscpp std_msgs geometry_msgs turtlesim  # 创建节点
cd learning_service/src/
touch turtle_spawn.cpp  # 创建代码源文件
vim turtle_spawn.cpp
```

输入：

```c++
#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "turtle_spawn");

    ros::NodeHandle node;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");

    turtlesim::Spawn srv;
    srv.request.x = 2.0;
    srv.request.y = 2.0;
    srv.request.name = "turtle2";

    ROS_INFO("call service to spawn a turtle");

    add_turtle.call(srv);

    ROS_INFO("spawn turtle successfully [name:%s]", srv.response.name.c_str());

    return 0;
}
```

修改 cmake，添加以下：

```cmake
add_executable(turtle_spawn src/turtle_spawn.cpp)
target_link_libraries(turtle_spawn ${catkin_LIBRARIES})
```

编译后运行。

## server

创建并编辑文件：

```shell
cd shiyucun/catkin_ws/src/learning_service/src/
touch turtle_command_server.cpp  # 创建代码源文件
vim turtle_command_server.cpp
```

输入：

```c++
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_srvs/Trigger.h>


ros::Publisher turtle_vel_pub;
bool pubCommand = false;

bool commandCallBack(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& res) {
    pubCommand = !pubCommand;

    ROS_INFO("publish turtle velocity command [%s]", pubCommand == true ? "yes" : "no");

    res.success = true;
    res.message = "change turtle command state!";

    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "turtle_command_server");

    ros::NodeHandle n;

    ros::ServiceServer command_service = n.advertiseService("/turtle_command", commandCallBack);

    turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ROS_INFO("ready to receive turtle command.");

    ros::Rate loop_rate(10);

    while(ros::ok()) {
        ros::spinOnce();
        if (pubCommand) {
            geometry_msgs::Twist msg;
            msg.linear.x = 0.5;
            msg.angular.z = 0.2;
            turtle_vel_pub.publish(msg);
        }
        loop_rate.sleep();
    }
    return 0;
}
```

修改 cmake 后编译，在终端中输入`rosservice call /turtle_command`调用服务。

## service data

### 生成 data 头文件

创建和修改srv文件：

```shell
cd shiyucun/catkin_ws/src/learning_service/
mkdir srv
cd srv
touch Person.srv
vim Person.srv
```

输入：

```text
string name
uint8 age
uint8 sex

uint8 unknown = 0
uint8 male = 1
uint8 female = 2

---

string result
```

修改 package.xml：

```xml
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>geometry_msgs</build_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>rospy</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_depend>turtlesim</build_depend>
  <build_depend>message_generation</build_depend>
  <build_export_depend>geometry_msgs</build_export_depend>
  <build_export_depend>roscpp</build_export_depend>
  <build_export_depend>rospy</build_export_depend>
  <build_export_depend>std_msgs</build_export_depend>
  <build_export_depend>turtlesim</build_export_depend>
  <exec_depend>geometry_msgs</exec_depend>
  <exec_depend>roscpp</exec_depend>
  <exec_depend>rospy</exec_depend>
  <exec_depend>std_msgs</exec_depend>
  <exec_depend>turtlesim</exec_depend>
  <exec_depend>message_runtime</exec_depend>
```

修改 CMakeLists.txt：

```cmake
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
  message_generation
)

add_service_files(FILES Person.srv)
generate_messages(DEPENDENCIES geometry_msgs std_msgs)

catkin_package(
   INCLUDE_DIRS include
   LIBRARIES learning_service
   CATKIN_DEPENDS geometry_msgs roscpp rospy std_msgs turtlesim
   DEPENDS system_lib
   message_runtime
)
```

执行 catkin_make 编译。

编译完成后在 devel/include/learning_service 目录下有生成的 request & response 头文件。

### 头文件的使用

```shell
cd shiyucun/catkin_ws/src/learning_service/src/
touch person_client.cpp
touch person_service.cpp
vim person_client.cpp
```

输入：

```c++
#include <ros/ros.h>
#include "learning_service/Person.h"


int main(int argc, char** argv) {
    ros::init(argc, argv, "person_client");

    ros::NodeHandle node;

    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = node.serviceClient<learning_service::Person>("/show_person");

    learning_service::Person srv;
    srv.request.name = "Tom";
    srv.request.age = 20;
    srv.request.sex = learning_service::Person::Request::male;

    ROS_INFO("call /show_person server");

    person_client.call(srv);

    ROS_INFO("result: %s", srv.response.result.c_str());

    return 0;
}
```

```shell
vim person_service.cpp
```

输入：

```c++
#include <ros/ros.h>
#include "learning_service/Person.h"

bool personCallBack(learning_service::Person::Request& req,
                    learning_service::Person::Response& res) {
    ROS_INFO("Person -> name:%s, age:%d, sex:%d", req.name.c_str(), req.age, req.sex);
    res.result = "OK";

    return true;
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "person_server");

    ros::NodeHandle n;

    ros::ServiceServer person_service = n.advertiseService("/show_person", personCallBack);

    ROS_INFO("ready to show ...");

    ros::spin();

    return 0;
}
```

修改 cmake，添加以下内容：

```cmake
add_executable(person_server src/person_service.cpp)
target_link_libraries(person_server ${catkin_LIBRARIES})
add_dependencies(person_server ${PROJECT_NAME}_gencpp)

add_executable(person_client src/person_client.cpp)
target_link_libraries(person_client ${catkin_LIBRARIES})
add_dependencies(person_server ${PROJECT_NAME}_gencpp)
```

编译后运行。
