# JSON

- [JSON](#json)
  - [nlohmann库](#nlohmann库)
    - [构造对象](#构造对象)
    - [解析与序列化](#解析与序列化)
    - [获取与修改](#获取与修改)
    - [flatten](#flatten)
    - [items](#items)
    - [类型判断](#类型判断)
    - [结构体json](#结构体json)
    - [get_to](#get_to)
    - [示例](#示例)

json的全称为：`JavaScript Object Notation`，是一种轻量级的数据交互格式。

json就是一种在各个编程语言中流通的数据格式，负责不同编程语言中的数据传递和交互。

## nlohmann库

nlohmann/json是一个用于解析json的开源c++库，使用方便直观。

[nlohmann库](https://github.com/nlohmann/json)提供了丰富而且符合直觉的[接口](https://json.nlohmann.me/api/basic_json/)，只需导入头文件即可使用，方便整合到项目中。

### 构造对象

可声明普通json、数组或对象：

```c++
json j1;
json j2 = json::object();
json j3 = json::array();
```

也可直接构造(通过`_json`字面量格式直接构造)：

```c++
json j = R"(
  {
    "name": "Mike",
    "age": 15,
    "score": 85.5
  }
)"_json;

json j{
  { "name", "Mike"},
  { "age", 15 },
  { "score", 85.5}
};
```

### 解析与序列化

从字符串中解析：

```c++
auto j = json::parse(str);
// ...
// 序列化为字符串
std::string out = j.dump();
```

从文件中解析：

```c++
json j;

std::ifstream("test.json") >> j;
// ...

// 序列化到文件
std::ofstream("test.json") << j;
```

### 获取与修改

通过`at`或者`operator[]`的方式获取元素的引用。

通过`get<T>()`来获取其值，直接赋值可修改其内容。

`at`返回对象的引用，当不存在时会抛出异常(`out_of_range`或`parse_error`)。

- `at(key)`：根据下标获取数组元素
- `at(index)`：根据键获取对象元素
- `at(jsonPtr)`：根据路径获取对象元素

`operator[]`与`at`类似，不存在时可能会自动添加NULL元素，而非抛出异常。

```c++
void jsonAt() {
  json j = {{"number", 1}, {"string", "foo"}, {"array", {1, 2}}};
  std::cout << j << '\n';

  std::cout << j.at("/number"_json_pointer) << '\n';
  std::cout << j.at("/string"_json_pointer) << '\n';
  std::cout << j.at("/array"_json_pointer) << '\n';
  std::cout << j.at("/array/1"_json_pointer) << '\n';

  auto ary = j.at("array");
  std::cout << ary.at(1) << '\n';

  auto n = j.at("number").get<int>();
  auto str = j.at("string").get<std::string>();
  std::cout << n << ", " << str << '\n';

  // change the string
  j.at("/string"_json_pointer) = "bar";
  // change an array element
  j.at("/array/1"_json_pointer) = 21;
  // output the changed array
  std::cout << j["array"] << '\n';

  // out_of_range.106
  try {
    // try to use an array index with leading '0'
    json::reference ref = j.at("/array/01"_json_pointer);
  } catch (json::parse_error &e) {
    std::cout << e.what() << '\n';
  }

  // out_of_range.109
  try {
    // try to use an array index that is not a number
    json::reference ref = j.at("/array/one"_json_pointer);
  } catch (json::parse_error &e) {
    std::cout << e.what() << '\n';
  }

  // out_of_range.401
  try {
    // try to use an invalid array index
    json::reference ref = j.at("/array/4"_json_pointer);
  } catch (json::out_of_range &e) {
    std::cout << e.what() << '\n';
  }

  // out_of_range.403
  try {
    // try to use a JSON pointer to a nonexistent object key
    json::const_reference ref = j.at("/foo"_json_pointer);
  } catch (json::out_of_range &e) {
    std::cout << e.what() << '\n';
  }
}

// {"array":[1,2],"number":1,"string":"foo"}
// 1
// "foo"
// [1,2]
// 2
// 2
// 1, foo
// [1,21]
// [json.exception.parse_error.106] parse error: array index '01' must not begin with '0'
// [json.exception.parse_error.109] parse error: array index 'one' is not a number
// [json.exception.out_of_range.401] array index 4 is out of range
// [json.exception.out_of_range.403] key 'foo' not found
```

可通过`value(key, defVal)`来获取元素，当不存在时返回默认值`defVal`。

defValue的类型与key对应元素的类型不匹配时，会抛出type_error异常。

```c++
void jsonValue() {
  json j = {{"integer", 1},
            {"floating", 42.23},
            {"string", "hello world"},
            {"boolean", true},
            {"object", {{"key1", 1}, {"key2", 2}}},
            {"array", {1, 2, 3}}};

  // access existing values
  int v_integer = j.value("integer", 0);
  double v_floating = j.value("floating", 0.0);

  // access nonexisting values and rely on default value
  std::string v_string = j.value("nonexisting", "[none]");
  bool v_boolean = j.value("nonexisting", false);

  // output values
  std::cout << std::boolalpha << v_integer << " " << v_floating << " " << v_string << " "
            << v_boolean << "\n";
}

// 1 42.23 [none] false
```

通过`contains`可判断元素是否存在：

- `contains(key)`：根据键判断
- `contains(jsonPtr)`：根据路径判断(对于数组，若索引不是数字会抛出异常)

通过`iterator find(key)`进行查找，返回iterator，通过*it获取其值。

```c++
void jsonFind() {
  // create a JSON object
  json j_object = {{"one", 1}, {"two", 2}};

  // call find
  auto it_two = j_object.find("two");
  auto it_three = j_object.find("three");

  // print values
  std::cout << std::boolalpha;
  std::cout << "\"two\" was found: " << (it_two != j_object.end()) << '\n';
  std::cout << "value at key \"two\": " << *it_two << '\n';
  std::cout << "\"three\" was found: " << (it_three != j_object.end()) << '\n';
}
```

### flatten

原型：`basic_json flatten()`。

可扁平化所有键(全部展开成一层`key-value`，key为对应的路径)，通过`unflatten`可反扁平化。

```c++
void jsonFlatten() {
  // create JSON value
  json j = {{"pi", 3.14},        {"happy", true},
            {"name", "Niels"},   {"nothing", nullptr},
            {"list", {1, 2, 3}}, {"object", {{"currency", "USD"}, {"value", 42.99}}}};

  // call flatten()
  std::cout << j.dump(2) << '\n';
  std::cout << std::setw(4) << j.flatten() << '\n';
}

// {
//   "happy": true,
//   "list": [
//     1,
//     2,
//     3
//   ],
//   "name": "Niels",
//   "nothing": null,
//   "object": {
//     "currency": "USD",
//     "value": 42.99
//   },
//   "pi": 3.14
// }
// {
//     "/happy": true,
//     "/list/0": 1,
//     "/list/1": 2,
//     "/list/2": 3,
//     "/name": "Niels",
//     "/nothing": null,
//     "/object/currency": "USD",
//     "/object/value": 42.99,
//     "/pi": 3.14
// }
```

### items

通过`items`可循环获取所有元素。

```c++
void jsonItems() {
  // create JSON values
  json j_object = {{"one", 1}, {"two", 2}};
  json j_array = {1, 2, 4, 8, 16};

  // example for an object
  for (auto& x : j_object.items()) {
    std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';
  }

  // example for an array
  for (auto& x : j_array.items()) {
    std::cout << "key: " << x.key() << ", value: " << x.value() << '\n';
  }
}
```

### 类型判断

通过`is_*`判断元素所属类型：

- is_array：是数组
- is_object：是对象
- is_null：为空
- is_number：是数字(可继续细化is_number_float/is_number_integer/is_number_unsigned)
- is_boolean：是布尔类型
- is_string：是字符串
- is_prmitive：是简单类型(非数组与对象)
- is_strucctured：数组或对象

### 结构体json

通过`void from_json(const json& j, MyStruct& p)`可以把json序列化为结构体。

通过`void to_json(json &j, const MyStruct& p)`可以把结构体序列化为json。

### get_to

通过`get_to`可把元素值赋值给类型兼容的变量：

```c++
namespace nj {

struct Asset {
  std::string name;
  int value;
};

void to_json(json &j, const Asset &a) {
  j = json{{"name", a.name}, {"value", a.value}};
}

void from_json(const json &j, Asset &a) {
  j.at("name").get_to(a.name);
  j.at("value").get_to(a.value);
}

}  // namespace nj
```

### 示例

```c++
void jsonBuild() {
  // {
  //  "pi": 3.141,
  //  "happy": true,
  //  "name": "Niels",
  //  "nothing": null,
  //  "answer": {
  //        "everything": 42
  //  },
  //  "list": [1, 0, 2],
  //  "object": {
  //        "currency": "USD",
  //         "value": 42.99
  //  }
  //}
  json jData;
  jData["pi"] = 3.141;
  jData["happy"] = true;
  jData["name"] = "Niels";
  jData["nothing"] = nullptr;
  jData["answer"]["everything"] = 42;  // 初始化answer对象
  jData["list"] = {1, 0, 2};           // 使用列表初始化的方法对"list"数组初始化
  jData["money"] = {{"currency", "USD"}, {"value", 42.99}};  // 初始化object对象

  std::cout << std::boolalpha;
  std::cout << jData << std::endl;
  std::cout << jData.at("pi") << std::endl;
  std::cout << jData["pi"].get<float>() << std::endl;
  std::cout << jData["none"].is_null() << std::endl;
  //    std::cout << jData.at("notAt") << std::endl; // throw exception
  std::cout << (jData.find("notFound") != jData.end()) << std::endl;
  std::cout << jData.contains("notContain") << std::endl;
  std::cout << jData.value("notExist", 0) << std::endl;

  std::cout << "sub-object" << std::endl;
  std::cout << jData.at("money") << std::endl;
  std::cout << jData.contains("currency") << std::endl;

  auto str = jData.dump(2);
  std::cout << "JSON OUT: \n";
  std::cout << str << std::endl;
  //    std::cout <<jData.value("name", 0)<<std::endl; // throw exception
}

// {"answer":{"everything":42},"happy":true,"list":[1,0,2],"money":{"currency":"USD","value":42.99},"name":"Niels","nothing":null,"pi":3.141}
// 3.141
// 3.141
// true
// false
// false
// 0
// sub-object
// {"currency":"USD","value":42.99}
// false
//
// JSON OUT: 
// {
//   "answer": {
//     "everything": 42
//   },
//   "happy": true,
//   "list": [
//     1,
//     0,
//     2
//   ],
//   "money": {
//     "currency": "USD",
//     "value": 42.99
//   },
//   "name": "Niels",
//   "none": null,
//   "nothing": null,
//   "pi": 3.141
// }

// 以上示例可看出：
//  通过 operator[] 获取不存在的 key 时，会添加一个值为 null 的键值对
//  通过 at 获取不存在的 key 时，会抛出异常
//  通过 contains 与 find 可判断元素是否存在
//  通过 value 获取存在，但类型与默认值不一致的元素时，会抛出异常
```
