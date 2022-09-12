
# ros-topic

- [ros-topic](#ros-topic)
  - [publisher](#publisher)
    - [pub-c++](#pub-c)
    - [pub-python](#pub-python)
  - [subscriber](#subscriber)
    - [sub-c++](#sub-c)
    - [sub-python](#sub-python)
  - [topic message](#topic-message)
    - [生成头文件](#生成头文件)
    - [使用头文件](#使用头文件)

## publisher

```shell
cd ~/shiyucun/catkin_ws/src/
catkin_create_pkg learning_topic std_msgs rospy roscpp geometry_msgs turtlesim
```

### pub-c++

```shell
cd learning_topic/src/
touch velocity_publisher.cpp
vim velocity_publisher.cpp
```

代码如下:

```c++
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "velocity_publisher");

    ros::NodeHandle n;

    ros::Publisher turtle_vel_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

    ros::Rate loop_rate(10);

    int cnt = 0;
    while(ros::ok()) {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;

        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("publish turtle velocity command");

        loop_rate.sleep();
    }

    return 0;
}
```

修改 CMakeLists.txt:

```shell
vim ../CMakeLists.txt
```

在cmake 155行添加以下编译规则:

```cmake
add_executable(velocity_publisher src/velocity_publisher.cpp)
target_link_libraries(velocity_publisher ${catkin_LIBRARIES})
```

完成后进入workspace根目录，执行编译:

```shell
cd ~/shiyucun/catkin_ws
catkin_make
source devel/setup.bash
rosrun learning_topic velocity_publisher
```

图形界面看到效果，需要先执行以下命令:

```shell
rosrun turtlesim turtle_teleop_key
rosrun turtlesim turtlesim_node
roscore
```

### pub-python

```python
import rospy
from geometry_msgs.msg import Twist

def velocity_publisher():
    rospy.init_node('velocity_publisher', anonymous=True)

    turtle_vel_pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)

    rate = rospy.Rate(10)

    while not rospy.is_shutdown():
        vel_msg = Twist()
        vel_msg.linear.x = 4
        vel_msg.angular.z = 0.3

        turtle_vel_pub.publish(vel_msg)
        rospy.loginfo('pulish turtle velocity command')

        rate.sleep()


if __name__=='__main__':
    try:
        velocity_publisher()
    except rospy.ROSInterruptException:
        pass
```

## subscriber

### sub-c++

```c++
#include <ros/ros.h>
#include "turtlesim/Pose.h"

void poseCallBack(const turtlesim::Pose::ConstPtr& msg) {
    ROS_INFO("turtle pose -> x: %0.6f, y:%0.6f", msg->x, msg->y);
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "pose_subscriber");

    ros::NodeHandle n;

    ros::Subscriber pose_sub = n.subscribe("/turtle1/pose", 10, poseCallBack);

    ros::spin();

    return 0;
}
```

### sub-python

```python
import rospy
from turtlesim.msg import Pose

def poseCallBack(msg):
    rospy.loginfo("turtle pose -> x:%0.6f, y:%0.6f", msg.x, msg.y)


def pose_subscriber():
    rospy.init_node("pose_subscriber", anonymous=True)

    rospy.Subscriber("/turtle1/pose", Pose, poseCallBack)

    rospy.spin()


if __name__=="__main__":
    pose_subscriber()
```

## topic message

### 生成头文件

在以下目录中创建并修改文件：

```shell
cd shiyucun/catkin_ws/src/learning_topic/
mkdir msg && cd msg
touch Person.msg
vim Person.msg
```

输入以下内容：

```text
string name
uint8 sex
uint8 age

uint8 unknown=0
uint8 male=1
uint8 female=2
```

修改 package.xml：

```shell
cd ..
vim package.xml
```

添加以下两行依赖项：

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

```shell
vim CMakeLists.txt
```

对应修改以下内容：

```cmake
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
  message_generation
)

add_message_files(
    FILES
    Person.msg
)

generate_messages(
    DEPENDENCIES
    geometry_msgs
    std_msgs
)
```

编译：

```shell
cd ../../
catkin_make
```

编译出的 msg 头文件位于：

```shell
ls devel/include/learning_topic/
$
```

### 使用头文件

创建文件：

```shell
cd shiyucun/catkin_ws/src/learning_topic/src/
touch person_subscriber.cpp person_publisher.cpp
vim person_subscriber.cpp
```

输入：

```c++
#include <ros/ros.h>
#include "learning_topic/Person.h"

void poseCallBack(const learning_topic::Person::ConstPtr& msg) {
    ROS_INFO("info -> name: %s, age: %d, sex: %d", msg->name, msg->age, msg->sex);
}


int main(int argc, char **argv) {
    ros::init(argc, argv, "pose_subscriber");

    ros::NodeHandle n;

    ros::Subscriber pose_sub = n.subscribe("/person_info", 10, poseCallBack);

    ros::spin();

    return 0;
}
```

```shell
vim person_publisher.cpp
```

输入：

```c++
#include <ros/ros.h>
#include "learning_topic/Person.h"


int main(int argc, char **argv) {
    ros::init(argc, argv, "person_publisher");

    ros::NodeHandle n;

    ros::Publisher person_pub = n.advertise<learning_topic::Person>("/person_info", 10);

    ros::Rate loop_rate(1);

    int cnt = 0;
    int age = 10;
    while(ros::ok()) {
        learning_topic::Person msg;
        msg.name = "abc";
        msg.age = age++;
        msg.sex = learning_topic::Person::male;

        person_pub.publish(msg);
        ROS_INFO("publish msg");

        loop_rate.sleep();
    }

    return 0;
}
```

修改 CMakeLists.txt：

```shell
cd ..
vim CMakeLists.txt
```

添加：

```cmake
add_executable(person_subscriber src/person_subscriber.cpp)
target_link_libraries(person_subscriber ${catkin_LIBRARIES})

add_executable(person_publisher src/person_publisher.cpp)
target_link_libraries(person_publisher ${catkin_LIBRARIES})
```

执行测试：

```shell
rosrun learning_topic person_publisher
rosrun learning_topic person_subscriber
```
