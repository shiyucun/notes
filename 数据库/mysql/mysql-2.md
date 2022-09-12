
# MySql

- [MySql](#mysql)
  - [语句结束](#语句结束)
  - [数据库操作](#数据库操作)
  - [表格操作](#表格操作)
  - [操作约束](#操作约束)
  - [索引操作](#索引操作)
  - [视图操作](#视图操作)
  - [触发器](#触发器)
  - [更新数据](#更新数据)
  - [查询数据](#查询数据)
  - [多表数据记录查询](#多表数据记录查询)
  - [合并查询数据记录](#合并查询数据记录)
  - [子查询](#子查询)
  - [MySQL支持的模式字符串](#mysql支持的模式字符串)
  - [函数](#函数)
    - [字符串函数](#字符串函数)
    - [数值函数](#数值函数)
    - [日期和时间函数](#日期和时间函数)
    - [系统信息函数](#系统信息函数)
  - [数据类型](#数据类型)

## 语句结束

在执行sql语句时可以使用';'、'\g'、 '\G'表示结束。'\G'可以使显示更加美观。

## 数据库操作

```sql
create database database_name;            # 创建数据库
show databases;                           # 查看数据库
use database_name;                        # 选择数据库
drop database data_basename;              # 删除数据库
show engines/variables;                   # 查看支持的存储引擎
show variables like 'storage_engine%';    # 查看默认存储引擎
help contents;                            # 查看帮助
```

## 表格操作

```sql
# 创建表格
create table table_name(
  属性名 数据类型, .. 属性名 数据类型,
);

# 查看表定义/详细定义
describe/desc table_name;
show create table table_name;
show table status;

# 删除表
drop table table_name;

# 修改表名
alter table old_table_name rename [to] new_table_name;
rename table old_table_name to new_table_name;

# 增加表字段
alter table table_name add 属性名 属性类型;                # 最后一个位置增加字段
alter table table_name add 属性名 属性类型 first;          # 第一个位置增加字段
alter table table_name add 属性名 属性类型 after 属性名;    # 指定属性后增加字段

# 删除表字段
alter table table_name drop 属性名;

# 修改字段
alter table table_name modify 属性名 数据类型;               # 修改属性数据类型
alter table table_name change 旧属性名 新属性名 旧数据类型;    # 修改属性名
alter table table_name change 旧属性名 新属性名 新数据类型;    # 同时修改属性名和数据类型

# 修改字段顺序
alter table table_name modify 属性名1 数据类型 [first]|[after 属性名2];
# [first]表示将属性1调整到表的第一个位置，[after 属性名2]表示属性名1调整到属性名2位置之后
```

## 操作约束

```sql
# 设置非空
create table table_name(
    属性名 数据类型 not null,
    ......
);

# 设置默认值
create table table_name(
    属性名 数据类型 default 默认值,
    ......
);

# 设置字段值唯一
create table table_name(
    属性名 数据类型 unique,
    ......
);

# 设置主键
create table table_name(
    属性名 数据类型 primary key,
    ......
);
create table table_name(
    属性名 数据类型,
    ......
    [contraint 约束名] primary key(属性名, 属性名 ......)
);

# 设置字段值自动增加
create table table_name(
    属性名 数据类型 auto_increment,
    ......
);

# 设置外键
create table table_name(
    属性名 数据类型,
    属性名 数据类型,
    ......
    contraint 外键约束名 foreign key(属性名1)
    references 表名(属性名2)
);
```

完整性约束关键字：
| 关键字         | 含义                                         |
| -------------- | -------------------------------------------- |
| NOT NULL       | 约束字段值不能为空                           |
| DEFAULT        | 设置字段默认值                               |
| UNIQUE KEY     | 约束字段的值唯一                             |
| PRIMARY KEY    | 约束字段为表的主键，可作为该表记录的唯一标识 |
| AUTO_INCREMENT | 约束字段的值为自动增加                       |
| FOREIGN KEY    | 约束字段为表的外键                           |

## 索引操作

```sql
# 创建表时创建普通索引
create table table_name(
    属性名 数据类型,
    属性名 数据类型,
    ......
    属性名 数据类型,
    [unique|fulltext] index|key [索引名] (属性名1 [(长度)] [ASC|DESC])
);
# unique       表示创建唯一索引
# fulltext     表示创建全文索引
# index|key    指定字段为索引
# 索引名        指定索引名
# 属性名1       指定索引所关联的字段名称
# 长度          指定索引长度
# ASC|DESC     指定排序

# 在已创建的表上创建普通索引
create [unique|fulltext] index 索引名 on 表名 (属性名 [(长度)] [ASC|DESC]);

# 通过 alter table 创建普通索引
alter table table_name add [unique|fulltext] index|key 索引名 (属性名 [(长度)] [ASC|DESC]);

# 创建表格时创建多列索引
create table table_name(
    属性名 数据类型,
    属性名 数据类型,
    ......
    属性名 数据类型,
    index|key [索引名] (
    属性名1 [(长度)] [ASC|DESC],
    ......
    属性名n [(长度)] [ASC|DESC])
);

# 在已创建的表上创建多列索引
create index 索引名 on 表名 (
    属性名1 [(长度)] [ASC|DESC],
    ......
    属性名n [(长度)] [ASC|DESC]
);

# 通过 alter table 创建多列索引
alter table table_name add index|key 索引名 (
    属性名1 [(长度)] [ASC|DESC],
    ......
    属性名n [(长度)] [ASC|DESC]
);

# 删除索引
drop index index_name on table_name;
```

## 视图操作

```sql
# 创建视图
create view view_name as 查询语句;

# 查看视图
show create view view_name;
describe|desc view_name;

# 删除视图
drop view view_name1[, view_name2, ...... ]

# 修改视图
create or replace view view_name as 查询语句;
alter view view_name as 查询语句;
```

## 触发器

```sql
# 创建触发器
create trigger trigger_name before|after trigger_event on
    table_name for each row [begin] trigger_stmt [end]
# trigger_name    触发器名字
# before|after    触发器执行时间，
# trigger_event   表示触法事件
# for each row    表示任何一条记录上的操作满足触法事件都会触发该触发器
# trigger_stmt    表示激活触发器后所执行的语句
# begin/end       当有多条执行语句时用来将语句包含起来

# 查看触发器
show triggers;

# 删除触发器
drop trigger trigger_name;
```

## 更新数据

```sql
# 插入数据
insert into table_name(field1, ...... fieldn)
    values (value11, ...... valuen1),
    (value12, ...... valuen2),
    (value1m, ...... valuenm);

# 插入查询结果
insert into table_name1(field11, ...... field1n)
    select (field21, ...... field2n) from table_name2 where ......

# 更新数据记录
update table_name
    set field1 ＝ value1, field2 ＝ value2, field3 = value3
    where condition;

# 删除数据记录
delete from table_name where condition;
```

## 查询数据

```sql
# 简单数据查询
select field1, field2, ...... fieldn from table_name;
select * from table_name;

# 避免重复数据查询
select distinct field1, field2, ...... fieldn from table_name;

# 设置显示格式查询
select concat(field1, '......', field2) new_name from table_name;
# concat 用于连接字符串，new_name 表示连接后字符串表头名字

# 条件查询
select field1, field2, ...... fieldn from table_name where condition;
select field1, field2, ...... fieldn from table_name where field like value;
select field1, field2, ...... fieldn from table_name
    where field between value1 and value2;
select field1, field2, ...... fieldn from table_name
    where field is [not] null;
select field1, field2, ...... fieldn from table_name
    where field [not] in (value1, value2, ...... valuen);
# like 为关键字，可做模糊查询，支持通配符'_'和'%'，'_'可以匹配单个字符，'%'可以匹配多个字符

# 排序查询
select field1, ......, fieldn from table_name 
    where condition order by fileldm1 [ASC|DESC] [,fileldm2 [ASC|DESC]];

# 限制数量查询
select field1, ...... fieldn from table_name
    where condition limit offset_start, row_count;

# 聚合函数：count、avg、sum、max、min
select function(field) from table_name where condition;
# count(*)           实现对表中记录进行统计，不会忽略null值
# count(field)       实现对指定字段的记录进行统计，忽略null值
# avg/sum/max/min    分别求平均数/总和/最大值/最小值，均会忽略null值
# 对于空表 count 函数返回0，其它函数返回 null

# 分组查询
select function() from table_name where condition
    group by field;
select group_concat(field) from table_name where condition
    group by field;
select  group_concat(field), function(field) from table_name where condition
    group by field1, field2, ....... fieldn;
select function(field) from table_name where condition
    group by field1, field2, ...... fieldn having condition;
# group_concat函数可以用来显示分组中指定的字段值
```

## 多表数据记录查询

并(UNION)：把具有相同字段数目和字段类型的表合并到一起。

笛卡尔积：没有连接条件表关系返回的结果。

内连接：笛卡尔积数据记录中保留所有匹配的数据记录，分为自然连接、等值连接、不等值连接。

外连接：笛卡尔积数据记录中保留所有匹配的数据记录和部分不匹配数据记录，分为左外连接、右外连接、全连接。

内连接查询：

```sql
select field1, ...... fieldn from join_tablename1
    inner join join_tablename2 [inner join join_tablenamen]
    on join_condition;
# fieldn             表示所要查询的字段名字
# join_tablenamen    表示要连接的表的名字
# inner join         表示内连接
# join_condition     表示匹配条件
```

外连接查询：

```sql
select field1, ...... fieldn from join_tablename1
    left|right|full [outer] join join_tablename2
    on join_condition;
# fieldn             表示所要查询的字段名字
# join_tablenamen    表示要连接的表的名字
# outer join         表示外连接
# join_condition     表示匹配条件
# left               左外连接查询
# right              右外连接查询
# full               全连接查询
```

## 合并查询数据记录

```sql
select field1, ...... fieldn from table_name1 union|union all
select field1, ...... fieldn from table_name2 union|union all
select field1, ...... fieldn from table_name3;
# union        会把多条语句的查询结果合并到一起，并删除重复记录
# union all    不会删除重复记录
```

## 子查询

做内连接查询和外连接查询时，首先会对两个表做笛卡尔积操作，然后选取符合条件的数据记录。

笛卡尔积产生的数据记录数等于**两个表数据记录数的乘积**，当数据条数较大时会造成死机。

子查询是指在一个查询中嵌套查询，即在 select 语句的 where 或 from 子句中包含另一个 select 语句。

在查询语句中，外层select查询语句称为主查询，where子句中的select查询称为子查询，也被称为嵌套查询。

子查询可以实现多表查询，语句中可能包含 in、any、all 和 exists 等关键字，也可能有比较运算符。

理论上子查询可以出现在查询语句的任意位置，但在实际开发中子查询经常出现在 where 和 from 子句中。

## MySQL支持的模式字符串

|模式字符 |含义 |
|----|----|
|^|匹配字符串的开始部分|
|str1｜str2｜str3|匹配str1、str2、str3种任意一个字符串|
|$|匹配字符串的结束部分|
|＊|匹配字符，包含0个和1个|
|.|匹配字符串中的任意个字符|
|＋|匹配字符，包含一个|
|[字符集合]|匹配字符集合中的任一个字符|
|字符串(N)|字符串出现N次|
|[^字符集合]|匹配字符集合外的任一个字符|
|字符串(M,N)|字符串至少出现M次，最多N次|

## 函数

### 字符串函数

|函数|功能|
|---|---|
|concat(str1, ..... strm)|连接所有字符串|
|insert(str, x, y, instr)|str 从 x 开始 y 个字符被替换为 instr|
|lower(str) lcase(str)|str 中所有字符变为小写|
|upper(str) ucase(str)|str 中所有字符变为大写|
|left(str, x)|返回 str 最左边 x 个字符|
|right(str, x)|返回 str 最右边 x 个字符|
|LPAD(str, n, pad)|使用字符串 pad 对 str 前 n 个字符进行填充|
|RPAD(str, n, pad)|使用字符串 pad 对 str 最后开始 n 个字符进行填充|
|length(str) char_length(str)|返回 str 的长度|
|ltrim(str)|去掉 str 左边空格|
|rtrim(str)|去掉 str 右边空格|
|repeat(str, x)|返回 str 重复 x 次的结果|
|replace(str, a, b)|使用字符串 b 替换字符串 str 中出现的字符串 a|
|strcmp(str1, str2)|比较 str1 和 str2|
|trim(str)|去掉 str 头尾空格|
|substring(str, x, y)|返回 str 从第 x 开始的 y 个字符|
|concat(sep, str1, ...... strn)|使用 sep 连接所有字符串|

### 数值函数

|函数|功能|
|---|---|
|abs(x)|返回 x 的绝对值|
|ceil(x)|返回大于 x 的最小整数值|
|floor(x)|返回小于 x 的最大整数值|
|mod(x, y)|返回 x%y 的值|
|rand()|返回 0～1 内的随机数|
|round(x, y)|x 四舍五入后有 y 位小数|
|truncate(x, y)|x 截断为 y 位小数|

### 日期和时间函数

|函数|功能|
|---|---|
|curdate()[+0]|获取当前日期(+0时修改了显示格式)|
|week(date)|返回日期 date 为一年中的第几周|
|curtime()|获取当前时间|
|year(date)|返回日期 date 的年份|
|now()|获取当前日期和时间|
|hour(time)|返回时间 time 的小时值|
|unix_timestamp(date)|获取日期 date 的 unix 时间戳|
|minute(time)|返回时间 time 的分钟值|
|from_unixtime()|获取 unix 时间戳的日期值|
|month(date)|返回时间 time 的月份值|
|date_add(date, interval num 单位)|date+num 值返回一个新的日期|
|date_sub(date, interval num 单位)|date－num 值返回一个新的日期|
|dayofyear(date)|年中第几天|
|day(date)|月中第几天|
|extract(type from date)|从 date 中获取指定 type 类型的值|
|datediff(date1, date2)|date1 和 date2 相差天数|

### 系统信息函数

|函数|作用|
|---|---|
|version()|数据库版本号|
|database()|当前数据名|
|user()|当前用户|
|last_insert_id()|返回最近生成的 auto_increment 值|

## 数据类型

|类型|字节|类型|字节|
|---|---|---|---|
|TINYINT|1|TINYTEXT|0-255|
|SMALLINT|2|TEXT|0-65535|
|MEDIUMINT|3|MEDIUMTEXT|0-167772150|
|INT、INTEGER|4|LONGTEXT|0-4294967295|
|BIGINT|8|BINARY(M)|M|
|FLOAT|4|VARBINARY(M)|M|
|DOUBLE|8|TINYBLOB|0-255|
|DEC(M,D) DECIMAL(M,D)|M+2|BLOB|0-2**16|
|BIT(M)|1-8|MEDIUMBLOB|0-2**24|
