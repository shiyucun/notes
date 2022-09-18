
# YAML

- [YAML](#yaml)
  - [定义规则](#定义规则)
  - [数据格式](#数据格式)
  - [库](#库)
  - [解析](#解析)
  - [增删改查](#增删改查)

## 定义规则

YAML是专门用来写配置文件的语言，非常简洁和强大，比JSON和xml格式要方便很多。

YAML实质上是一种通用的数据串行化格式。

基本语法规则如下：

- 大小写敏感
- 使用缩进表示层级关系
- 缩进时不允许使用Tab键，只允许使用空格
- 缩进的空格数目不重要，只要相同层级的元素左侧对齐即可
- `#`表示注释，从这个字符一直到行尾，都会被解析器忽略
- 字符串默认不使用引号表示，如果字符串之中包含空格或特殊字符，需要放在引号之中
- 单引号和双引号都可以使用，双引号不会对特殊字符转义
- 单引号之中如果还有单引号，必须连续使用两个单引号转义
- 字符串可以写成多行，从第二行开始，必须有一个单空格缩进
- 换行符会被转为空格

## 数据格式

YAML支持的数据结构有三种：

- 对象：键值对的集合，又称为映射(mapping)/哈希(hashes)/字典(dictionary)
- 数组：一组按次序排列的值，又称为序列(sequence)/列表(list)
- 纯量(scalars)：单个不可再分的值

## 库

c++中常用的解析库为yaml-cpp。

ubuntu中安装yaml-cpp：

```shell
# 源码安装
git clone https://github.com/jbeder/yaml-cpp.git
cd yaml-cpp
mkdir build && cd build
cmake .. && make -j
sudo make install

# 命令行安装
sudo apt install libyaml-cpp-dev
```

cmake配置：

```cmake
find_package(yaml-cpp REQUIRED)
include_directories(${YAML_CPP_INCLUDE_DIR})
target_link_libraries(app yaml-cpp)
```

## 解析

Node是yaml-cpp中的核心概念，是最重要的数据结构，它用于存储解析后的yaml信息。

Node一共有以下几种type：

- `Null`空节点
- `Sequence`序列，类似于Vector，对应YAML格式中的数组
- `Map`类似标准库中的Map，对应YAML格式中的对象
- `Scalar`标量，对应YAML格式中的常量

生成Node的形式有很多种，`loadFile()`是最常见的一种。

```c++
Node LoadFile(const std::string& filename);
# filename: yaml文件路径
```

如以下配置文件：

```text
name: frank
sex: male
age: 18
 
skills: 
  c++: 1
  java: 1
  android: 1
  python: 1
```

解析以上配置文件：

```c++
#include <fstream>
#include <iostream>

#include "yaml-cpp/yaml.h"

using namespace std;

int main(int argc, char **argv) {
  YAML::Node config;
  try {
    config = YAML::LoadFile("config.yaml");
  } catch (YAML::BadFile &e) {
    std::cout << "read error." << std::endl;
    return -1;
  }

  cout << "Node type " << config.Type() << endl;
  cout << "skills type " << config["skills"].Type() << endl;

  // 可以用string类型作为下表，读取参数
  string age = "age";
  cout << "age when string is label:" << config[age].as<int>() << endl;

  cout << "name:" << config["name"].as<string>() << endl;
  cout << "sex:" << config["sex"].as<string>() << endl;
  cout << "age:" << config["age"].as<int>() << endl;

  // 读取不存在的node值，报 YAML::TypedBadConversion 异常
  try {
    string label = config["label"].as<string>();
  } catch (YAML::TypedBadConversion<string> &e) {
    std::cout << "label node is NULL" << std::endl;
  }  // TypedBadConversion 是模板类，读取什么类型的参数就传入什么类型

  cout << "skills c++:" << config["skills"]["c++"].as<int>() << endl;
  cout << "skills java:" << config["skills"]["java"].as<int>() << endl;
  cout << "skills android:" << config["skills"]["android"].as<int>() << endl;
  cout << "skills python:" << config["skills"]["python"].as<int>() << endl;

  # 使用 yaml 迭代器
  for (YAML::const_iterator it = config["skills"].begin(); it != config["skills"].end(); ++it) {
    cout << it->first.as<string>() << ":" << it->second.as<int>() << endl;
  }

  YAML::Node test1 = YAML::Load("[1,2,3,4]");
  cout << " Type: " << test1.Type() << endl;

  YAML::Node test2 = YAML::Load("1");
  cout << " Type: " << test2.Type() << endl;

  YAML::Node test3 = YAML::Load("{'id':1,'degree':'senior'}");
  cout << " Type: " << test3.Type() << endl;

  ofstream fout("./testconfig.yaml");  //保存 config 为 yaml 文件

  config["score"] = 99;  //添加新元素

  fout << config;  // 输出到文件

  fout.close();

  return 0;
}
```

## 增删改查

```c++
#include <cassert>

#include <iostream>
#include <fstream>

#include "yaml-cpp/yaml.h"

int main() {
  YAML::Node node;
  assert(node.IsNull());  // 初始化的节点是Null类型

  node["key"] = "value";  // 当你给它赋值键值对，它转变为Map类型

  // 以下操作和上面等价，但不会检查是否存在 key 键，不推荐使用
  // node.force_insert("key", "value");

  //单纯的查询操作不会增加一个 key
  if (node["mascot"]) {
    std::cout << node["mascot"].as<std::string>() << "\n";
  }

  node["number"] = 255;
  assert(node.IsMap());  // node 是一个 Map

  // 以下 node 的 seq 下是 Sequence 类型，添加两个参数
  node["seq"].push_back("first element");
  node["seq"].push_back("second element");

  YAML::Node node_2;
  //如果你不给 node_2 键值对，它是一个 sequence 类型
  node_2.push_back("first item");
  node_2.push_back("second_item");
  node_2.push_back("third_item");

  //给 node_2 插入一个 Sequence
  std::vector<int> v = {1, 3, 5, 7, 9};
  node_2.push_back(v);
  assert(node_2.IsSequence());

  //对于 Sequence 类型，你可以使用下标来访问
  //as<T> 是一个模板转换，node_2[0] 的 type 是 NodeType::Scalar
  assert(node_2[0].as<std::string>() == "first item");

  //也可以用迭代器访问
  //类型分别是 NodeType::Scalar，NodeType::Scalar，NodeType::Scalar，NodeType::Sequence
  //取值时记得使用as进行模板转换
  auto it = node_2.begin();
  for (; it != node_2.end(); it++) {
    std::cout << *(it) << std::endl;
  }

  // node_2 接收到键值对就会转变为 Map 类型
  node_2["key"] = "value";
  assert(node_2.IsMap());
  // 此时，Sequence 的下标变为它的 key 值
  assert(node_2[0].as<std::string>() == "first item");
  // 将 node_2 作为 node 的一个子项
  node["node_2"] = node_2;
  // 可以给已有的 node 设置一个别名
  node["pointer_to_first_element"] = node["seq"][0];
  assert(node["pointer_to_first_element"].as<std::string>() == "first element");

  // 通过下标删除指定 node
  node.remove(node["seq"][0]);
  // 通过 key 删除指定 node
  node.remove("pointer_to_first_element");

  // 输出
  std::cout << node << endl;
}
```


