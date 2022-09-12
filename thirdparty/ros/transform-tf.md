
# transform-tf

- [transform-tf](#transform-tf)
  - [安装](#安装)
  - [命令行测试](#命令行测试)
  - [写代码测试](#写代码测试)
    - [编码](#编码)
    - [修改cmake](#修改cmake)
    - [执行命令测试](#执行命令测试)

## 安装

```shell
sudo apt-get install ros-molodic-turtle-tf    # 安装tf示例程序
roslaunch turtle_tf turtle_tf_demo.launch    # 运行示例程序
```

## 命令行测试

```text
# rosrun tf view_frames  当前目录下生成pdf文件，查看坐标系关系

# rosrun tf tf_echo turtle1 turtle2 输出
At time 1627992937.894
- Translation: [0.000, 0.000, 0.000]        # xyz
- Rotation: in Quaternion [0.000, 0.000, 0.748, 0.664]    # 四元数
            in RPY (radian) [0.000, -0.000, 1.690]        # 弧度
            in RPY (degree) [0.000, -0.000, 96.827]       # 角度
At time 1627992938.615
- Translation: [0.000, 0.000, 0.000]
- Rotation: in Quaternion [0.000, 0.000, 0.748, 0.664]
            in RPY (radian) [0.000, -0.000, 1.690]
            in RPY (degree) [0.000, -0.000, 96.827]
```

## 写代码测试

### 编码

创建 workspace 和代码文件：

```shell
cd shiyucun/catkin_ws/src/
catkin_create_pkg learning_tf rospy roscpp tf turtlesim
cd learning_tf/src/
touch turtle_tf_broadcaster.cpp
touch turtle_tf_listener.cpp
```

修改文件：

```shell
vim turtle_tf_broadcaster.cpp
```

输入：

```c++
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>


std::string turtle_name;

void poseCallBack(const turtlesim::PoseConstPtr& msg) {
    static tf::TransformBroadcaster br;

    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0.0));
    tf::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transform.setRotation(q);

    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "tf_broad");

    if (argc != 2) {
        ROS_ERROR("params error");
        return -1;
    }

    turtle_name = argv[1];

    ros::NodeHandle node;
    ros::Subscriber sub = node.subscribe(turtle_name + "/pose", 10, &poseCallBack);

    ros::spin();

    return 0;
}
```

修改文件：

```shell
vim turtle_tf_listener.cpp
```

输入：

```c++
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <geometry_msgs/Twist.h>
#include <turtlesim/Spawn.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "tf_listener");

    ros::NodeHandle node;

    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = node.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn srv;
    add_turtle.call(srv);

    ros::Publisher turtle_vel = node.advertise<geometry_msgs::Twist>("/turtle2/cmd_vel", 10);

    tf::TransformListener listener;

    ros::Rate rate(10);
    while(node.ok()) {
        tf::StampedTransform transform;
        try {
            listener.waitForTransform("/turtle2", "/turtle1", ros::Time(0), ros::Duration(3.0));
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
        } catch (tf::TransformException &ex) {
            ROS_ERROR("%s", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        }

        geometry_msgs::Twist vel_msg;
        vel_msg.angular.z = 4.0 * atan2(transform.getOrigin().y(), transform.getOrigin().x());
        vel_msg.linear.x = 0.5 * sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2));

        turtle_vel.publish(vel_msg);

        rate.sleep();
    }

    return 0;
}
```

### 修改cmake

```shell
vim ../CMakeLists.txt
```

添加以下内容：

```cmake
add_executable(tf_broadcast src/turtle_tf_broadcaster.cpp)
target_link_libraries(tf_broadcast ${catkin_LIBRARIES})

add_executable(tf_listener src/turtle_tf_listener.cpp)
target_link_libraries(tf_listener ${catkin_LIBRARIES})
```

### 执行命令测试

```shell
roscore
rosrun turtlesim turtlesim_node
rosrun learning_tf tf_broadcast __name:=turtle1_tf_broadcaster /turtle1
rosrun learning_tf tf_broadcast __name:=turtle2_tf_broadcaster /turtle2
rosrun learning_tf tf_listener
rosrun turtlesim turtle_teleop_key
```
