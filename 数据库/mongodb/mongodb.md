
# MongoDB

- [MongoDB](#mongodb)
  - [简介](#简介)
  - [集合](#集合)
  - [数据库](#数据库)
  - [使用情景](#使用情景)
  - [基础操作](#基础操作)
  - [插入文档](#插入文档)
  - [删除文档(永久删除)](#删除文档永久删除)
  - [查询文档](#查询文档)
  - [条件语意：$](#条件语意)
  - [更新文档](#更新文档)
  - [文档替换](#文档替换)
  - [投影](#投影)
  - [查询数组](#查询数组)
  - [内嵌文档](#内嵌文档)
  - [聚合函数和管道操作符](#聚合函数和管道操作符)
  - [mapReduce 函数](#mapreduce-函数)

MongoDB是一种非关系型数据库。

非关系型数据库的种类：

- 键值存储数据库：Redis
- 文档存数数据库：MongoDB
- 列存储数据库：Cassandra
- 图数据库

## 简介

MongoDB 中的最小数据存储单元是文档，文档是键值对的一个有序集。

Python 中用字典表示文档，键通常是字符串。

MongoDB 使用了 BSON 这种结构来存储数据、进行网络数据交换。

BSON 是类 JSON 的一种二进制形式的存储格式，简称 Binary JSON。

BSON 和 JSON 一样，支持内嵌的文档对象和数组对象。

BSON 有 JSON 没有的一些数据类型，如 Date 和 BinData 类型。

BSON 可以做为网络数据交换的一种存储形式，优点是灵活性高，缺点是空间利用率不是很理想。

BSON有三个特点：轻量性、可遍历性、高效性。

与关系型数据相比MongoDB具有以下优点：

- 没有模式
- 每个单一对象的结构很清晰
- 没有复杂的表连接
- 深度查询能力
- 调整
- 易扩展
- 不需要转换和映射应用对象到数据库对象
- 用内存存贮工作集，更快速连接数据

## 集合

文档类似于关系型数据库中的表，一组文档构成集合。

一个集合里面的文档可以是各种各样的。

将文档按类型区分放在不同的集合，便于管理，查询速度更快，数据更集中，可以更有效的创建索引。

集合还可以包含子集合，用 '.' 分隔不同的命名空间的子集合。

集合命名规范：

- 不能是空字符串
- 不能包含 '\0' 字符，这种字符标识集合名结束
- 不能以 "system." 开头，这是系统集合保留的前缀
- 不能包含保留字符 '.' 和 '$'

## 数据库

多个文档组成集合，多个集合组成数据库。

数据库命名规范：

- 不能是空字符串
- 字母数字下划线
- 区分大小写，通常最好全部小写
- 最多为64字节

数据库最终会变成文件系统中的文件，而数据库的名就是相应的文件名。

系统保留数据库：

- admin：root数据库，用户将获得所有的权限，一些特定的服务器命令只能从该库运行
- local：永远都不可以复制，服务器上的所有本地集合都可以存储在该库中

## 使用情景

- 面向文档的存储，数据用 JSON 文档存储
- 在任意属性上建立索引
- 复制和高可利用性
- 自动分片
- 丰富的查询
- 快速原位置更改
- 处理大数据、内容管理和传送、移动或者社交设施、用户数据管理、数据中心

## 基础操作

```mongodb
// 创建新的数据库，新建数据库在插入文档或创建集合前不在列表中
use database_name

// "db"是芒果数据库里的一个全局变量，表示客户端正在连接的数据库

// 查询所有数据库
show dbs

// 删除当前正在使用的数据库
db.dropDatabase()

// 创建集合
db.createCollection(集合名)

// 查看所有集合
show collections
// MongoDB中，不必显式创建集合，当插入文档时候会自动创建

// 删除集合
db.集合名.drop()
```

## 插入文档

```mongodb
db.集合名.insert(文档)

// 如下示例：
db.mycol.insert([
  {
    "title": "MongoDB Overview",
    "desription": "MongoDB is no sql database",
    "by": "tutorials points",
    "url": "http://www.tutorialspoint.com",
    "tags": ['mongodb', 'database', 'NoSQL'],
    "likes": 100
  },
  {
    "title": "Python Overview",
    "desription": "Python is a programming language",
    "by": "tutorials points",
    "url": "http: //www.tutorialspoint.com",
    "tags": ['Python', 'Programming'],
    "likes": 40
  }
])
```

## 删除文档(永久删除)

```mongodb
db.集合名.remove(删除条件，删除一条还是所有文档)
// 这两个参数均为可选参数，true：删除一条文档，false：删除所有文档
// 删除条件以字典的方式列出 {键:值}
// {}空字典代表没有任何条件

// 如下示例：
db.mycol.remove（{}）// 删除集合中的所有文档
db.mycol.remove({'title':'MongoDB Overview'}, true) // 删除满足条件的第一个文档
db.mycol.remove({'title':'MongoDB Overview'}) // 默认删除所有满足条件的文档
```

## 查询文档

```mongodb
db.集合名.find()
db.集合名.find().pretty()
db.集合名.findOne() // 查询一条文档
```

## 条件语意：$

```mongodb
// 等于某个值的所有文档
db.mycol.find({"likes": 100}).pretty()

// 大于某个值的所有文档：$gt
db.mycol.find({"likes": {$gt: 50}}).pretty()

// 小于某个值的所有文档：$lt
db.mycol.find({"likes": {$lt: 41}}).pretty()

// 大于等于某个值的所有文档：$gte
db.mycol.find({"likes": {$gte: 40}}).pretty()

// 小于等于某个值的所有文档：$lte
db.mycol.find({"likes": {$lte: 100}}).pretty()

// 不等于某个值的所有文档：$ne
db.mycol.find({"likes": {$ne: 100}}).pretty()

// $and
db.mycol.find({$and: [{key1: value1}, ... {keyn: valuen}]})

// $or
db.mycol.find({$or: [{key1: value1}, ... {keyn: valuen}]})

// $in
db.mycol.find({key: {$in: [value1, ... valuen]}})

// $nin
db.mycol.find({key: {$nin: [value1, ... valuen]}})
```

## 更新文档

```mongodb
// 语法
db.集合名.update(查询条件，修改内容[，{multi:true}])
// 查询条件：查询文档，用于定位需要更新的目标文档
// 修改内容：用于说明要对找到的文档进行的修改，可以使用修改器
// {multi: true}：用于标识修改所有匹配文档，默认只修改第一个匹配的文档

// set 修改器：指定一个字段的值，如果该字段不存在，则创建它
post = {"name": "joe", "age": 30, "sex": "male", "location": "beijing"}
db.users.insert(post)
db.users.find().pretty()
db.users.update({"name": "joe"}, {"$set": {"address": "shanghai"}})


// $unset 修改器：将某个键完全删除
db.users.update({"name": "joe"}, {"$unset": {"address": "shanghai"}})
db.users.update({"name": "joe"}, {"$unset": {"address": 1}})

// $inc 修改器：已有的键对应的值会累加，该键不存在则创建，只用于数值类型
db.users.update({"name": "joe"}, {$inc: {"age": 10}})
db.users.update({"name": "joe"}, {$inc: {"age": -5}})
db.users.find().pretty()

// $push 修改器：数组已存在则向数组末尾加入一个元素，不存在则创建一个新的数组
db.blog.insert({"title": "a blog post", "content": "my day"})
db.blog.update({"title": "a blog post"}, {$push: {"comments": {"name": "Yang", "content": "nice post"}}})
db.blog.update({"title": "a blog post"}, {$push: {"comments": {"name": "Wei","content": "bad post"}}})
db.blog.insert({"title": "2nd blog post", "content": "my 2nd day"})
db.blog.update({"title": "2nd blog post"}, {$push: {"comments": {"name": "Feng","content": "bad post"}}})

// $pop 修改器：从数组任何一端删除元素
{"$pop": {键: 1}}     // 从数组的末尾删除一个元素
{"$pop": {键: -1}}    // 从数组的头部删除一个元素
db.lists1.insert({"todo": ["dishes", "laundry", "cooking"]})
db.lists1.update({}, {$pop: {"todo": 1}})
db.lists1.update({}, {$pop: {"todo": -1}})

// $pull 修改器：基于特定条件来删除元素
db.lists.update({}, {$pull: {"todo": "laundry"}})

// $pull、$pop修改器只是针对文档中的列表(数组)
```

## 文档替换

```mongodb
db.集合名.save({_id: ObjectId(.......), 新的文档})
// 如下示例：
db.blog.save(
  {
    "_id": ObjectId("5a37598d01cc2593640441ba"),
    "title": "3rd blog post",
    "content": "my third day",
    "comments": {"yang": "great post"}
  }
)
```

## 投影

投影用于选择文档中有用的数据，而不是所有数据。

```mongodb
find() // 可以限制所选择的键，1表示显示该键，0表示隐藏该键
db.集合名.find({}, {键: 1})
db.post.insert([{"title": "MongoDB"}, {"title": "NoSQL"}])
db.post.find().pretty()
db.post.find({}, {"title": 1, "_id": 0})

limit() // 设置展示文档条数
db.集合名.find().limit(n)

skip() // 跳过几行文档
db.集合名.find().limit(n2).skip(n1) // skip n1 行之后显示 n2 行
```

## 查询数组

```mongodb
$all // 通过多个元素来匹配数组
db.集合名.find({key: {$all: [value1, ... valuen]}})

$size // 查询特定长度的数组
db.集合名.find({key: {$size: 长度}})

$slice // 返回某个键匹配的数组元素的一个子集
{"$slice": num} (num > 0) // 返回数组里前 num 条信息
{"$slice": -num} (num > 0) // 返回数组里倒数 num 条信息
{"$slice": [start, num]} // 返回数组里从 start 开始的 num 条信息
db.集合名.find({key: {"$slice": num}}).pretty()
db.集合名.find({key: {"$slice": -num}}).pretty()
db.集合名.find({key: {"$slice": [start, num]}}).pretty()
```

## 内嵌文档

查询内嵌文档：

```mongodb
// 点表示法
db.集合名.find({"key.内嵌字段名": value}).pretty()
// 所有内嵌字段值为 value 的文档将被打印出来，此时只有一个条件

// match 匹配法
db.集合名.find({key: {"$elemMatch": {内嵌字段名1: value1, ... 内嵌字段名n: valuen}}}).pretty()
// 使用多个并列选择条件查询内嵌文档时必须用 $elemMatch
// find 函数({需要满足的条件}，{选项})，各种选项之间用逗号区分
```

修改内嵌文档：

```mongodb
// 数组有多个值，对其中的一个或全部进行操作时，有两种方法：

// 定位操作符$ (适用于选择条件中指明内嵌文档的属性)
db.集合名.update(条件, {$set: {"key.$.内嵌字段名": value}}, {multi: true})

// 通过位置：数组下标是以0开头的，可以将下标直接作为键来选择元素
db.集合名.update(条件, {$set: {"key.数组下标.内嵌字段名": value}})
```

## 聚合函数和管道操作符

```mongodb
aggregate() // 聚合函数
$project    // 投影，相当于SQL里面的select
$match      // 匹配，相当于sql里面的where
$limit      // 相当于sql里面的limit
$group      // 分组，相当于sql里面的group by
$sort       // 排序，相当于sql里面的order by
$sum        // 求和，相当于sql里面的sum(...)
$lookup     // 相当于sql里面的join, 最新的mongodb版本才有

// 插入测试数据
db.student.insert({StudentName: "Vijay", Section: "A", Marks: 70, Subject: ["Hindi", "English", "Math"]})
db.student.insert({StudentName: "Gaurav", Section: "A", Marks: 90, Subject: ["English"]})
db.student.insert({StudentName: "Ajay", Section: "A", Marks: 70, Subject: ["Math"]})
db.student.insert({StudentName: "Ankur", Section: "B", Marks: 10, Subject: ["Hindi"]})
db.student.insert({StudentName: "Sunil", Section: "B", Marks: 70, Subject: ["Math"]})
db.student.insert({StudentName: "Preeti", Section: "C", Marks: 80, Subject: ["Hindi", "English"]})
db.student.insert({StudentName: "Anuj", Section: "C", Marks: 50, Subject: ["English"]})
db.student.insert({StudentName: "Palka", Section: "D", Marks: 40, Subject: ["Math"]})
db.student.insert({StudentName: "Soniya", Section: "D", Marks: 20, Subject: ["Math", "English"]})

// 用 $match 匹配出 section 为 A 的所有学生
db.student.aggregate([{$match: {Section: "A"}}]).pretty()

// 用 $match 匹配出 section 为 A 且成绩大于 80 的所有学生
db.student.aggregate([{$match: {$and: [{Section: "A"}, {Marks: {$gt: 80}}]}}])

// 用 $project 只列出 StudentName、Section、Marks (1代表显示，0代表隐藏)
db.student.aggregate([{$project:{StudentName: 1, Section: 1, Marks: 1, _id: 0}}])

// 用 $project 和 $match 选出 Section 为 A 的文档，并且只显示 StudentName、Section、Marks三个值
db.student.aggregate([
  {$match: {Section: "A"}},
  {$project: {StudentName: 1, Section: 1, Marks: 1, _id: 0}}
]).pretty()

// $unwind 展开, 只针对数组
db.student.aggregate([
  {$match: {"StudentName": "Vijay"}},
  {$unwind: "$Subject"},
  {$project: {StudentName: 1, Section: 1, Marks: 1, _id: 0, Subject: 1}}
])

// 输出：
// {"StudentName": "Vijay", Section: "A", "Marks": 70, "Subject": "Hindi"}
// {"StudentName": "Vijay", Section: "A", "Marks": 70, "Subject": "English"}
// {"StudentName": "Vijay", Section: "A", "Marks": 70, "Subject": "Math"}


// 使用 $group 按照各个 Section 对文档进行分组，并求得各个 Section 的总分 Marks
db.student.aggregate([
  {$group: {
    _id: {Section: "$Section"},
    total_marks: {$sum: "$Marks"}
}}])
// 输出：
// {"_id": {Section: "D"}, "total_marks": 60}
// {"_id": {Section: "C"}, "total_marks": 130}
// {"_id": {Section: "B"}, "total_marks": 80}
// {"_id": {Section: "A"}, "total_marks": 230}
// 注意：$group管道操作符中，按照某个属性进行分组的时候，该属性必须放到一个表达式中
//      所以在上述例子中：_id: {Section: "$Section"} 不能简化为 Section: "$Section"

// 列出所有 Section 为 A 的文档，并按照 Section 类别把成绩 Marks 的最大值打印出来
db.student.aggregate([
  {$match: {Section: 'A'}},
  {$group: {
    _id: {Section: "$Section"},
    max_a: {$max: "$Marks"}
}}])

// 把各个 Section 里的学生的总分和平均分打印出来 
db.student.aggregate([
  {$group: {
    _id: {Section: "$Section"},
    total: {$sum: "$Marks"},
    average: {$avg: "$Marks"}
}}])

// 把各个 Section 里的学生人数打印出来 
db.student.aggregate([
  {$group: {
    _id: {Section: "$Section"},
    count: {$sum: 1}    // 表示求各个 section 里对应的文档总数
}}])

// 用 $project 重命名
db.student.aggregate([
  {$group: {
    _id: {Section: "$Section"},
    count: {$sum: 1}
  }},
  {$project: {
    SectionName: "$_id.Section",
    total_num: "$count",
    _id: 0
  }
}])
// 注意：$project 的投影功能，默认没列出的属性被隐藏
//      数据库自动生成的_id列，默认情况下被显示出来

// $sort 排序(1表示升序，-1表示降序)
// 按照各个Section对应的成绩总和进行升序排列
db.student.aggregate([
  {$group: {
    "_id": {Section: "$Section"},
    "total_marks": {$sum: "$Marks"}
  }},
  {$sort: {"total_marks": 1}}
])

// limit() 只显示几行信息
// skip() 跳过几行
db.student.aggregate([
  {$group: {
    "_id": {Section: "$Section"},
    "total_marks": {$sum: "$Marks"}
  }},
  {$sort: {"total_marks": 1}},
  {$skip: 1},
  {$limit: 2}
])

// $lookup 表关联(类似 sql 中的 join)，语法如下：
db.集合名1.aggregate({
  $lookup:
  {from: 集合名2, localField: key1, foreignField: key2, as: key3}
})
// 参数：
//    from：需要关联的集合(集合名2)
//    localField：集合需要关联的键(key1)
//    foreignField：关联的集合的键(key2)
//    as：key3对应的外键集合的数据

// $cond: condition条件，检查 bool 表达式，根据结果返回对应的值
db.student.aggregate({
  $project: {
    _id: 0,
    StudentName: 1, 
    Result: {$cond: {if: {$gte: ["$Marks", 70]}, then: "Good", else:"Poor"
}}}})

// $setIntersection: 返回两个数组中的相同部分， 如下例：
db.Test.insert({
  "Array1": ["1", "2", "3"],
  "Array2": ["1", "2", "3", "4"]
})
db.Test.aggregate({
  $project: {
    "Array1": 1,
    "Array2": 1,
    "commonToBoth": {$setIntersection: ["$Array1", "$Array2"]},
    "_id": 0
}})
db.student.aggregate([
  {$match: {"StudentName": {$in: ["Preeti","Anuj"]}}},
  {$unwind: "$Subject"},
  {$group: {_id: "$Subject", count: {$sum: 1}}},
  {$project: {
    _id: 0,
    "Subject": '$_id',
    common: {$cond: {if: {$gte: ["$count", 2]}, then: "Yes", else: "No"}}
  }}
])
```

## mapReduce 函数

mapReduce 可以表达任意复杂的逻辑，但是很慢，不应该用在实时的数据分析中。

mapReduce 能够在多台服务器之间并行执行。

将一个大问题拆分成多个小问题，将各个小问题发送到不同的机器上，每台机器只完成一部分工作。

所有机器都完成时，再将这些零碎的解决方案合并为一个完整的解决方案。

基本语法：

```mongodb
db.collection.mapReduce(
  function() { emit(key, value); }, // map 函数
  function(key, values) { return reduceFunction }, // reduce函数
  {
    out: collection,
    query: document,
    sort: document,
    limit: number
  }
)
```

使用 mapReduce 要实现两个函数 map 函数和 reduce 函数。

map 函数必须调用 emit(key, value) 返回键值对。

map 函数会遍历 collection 中所有的记录，将 key 与 value 传递给 reduce 函数进行处理。

参数说明：

- map：映射函数，生成键值对序列，作为reduce函数参数
- reduce：统计函数，将 key-values 变成 key-value，即将 values 数组转换为单值 value
- out：统计结果存放集合，不指定则使用临时集合，客户端断开后自动删除
- query：筛选条件，满足条件的文档才会调用map函数
- sort：发往 map 函数处理前对文档进行排序，最好结合 limit 使用，单独使用意义不大
- limit：发往 map 函数的文档数量的上限

使用所示：

```mongodb
db.orders.insert([
  {cust_id: "A123", amount: 500, status: "A"},
  {cust_id: "A123", amount: 250, status: "A"},
  {cust_id: "B212", amount: 200, status: "A"},
  {cust_id: "A123", amount: 300, status: "D"}
])

db.orders.mapReduce(
  function(){ emit(this.cust_id, this.amount); },
  function(key, values){ returnArray.sum(values); },
  {
    query: {status: "A"},
    out: "order_totals"
  }
)

db.order_totals.find().pretty()

// 输出：
// {"_id":"A123","value":750}
// {"_id":"B212","value":200}
```
