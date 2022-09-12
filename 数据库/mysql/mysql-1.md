
# MySql

- [MySql](#mysql)
  - [数据的存储](#数据的存储)
  - [数据类型](#数据类型)
  - [sql语句](#sql语句)
  - [运算符](#运算符)

## 数据的存储

数据库中数据是以行、列的形式存储的。
每一行表示一条**记录**(元组)，每一列表示记录的一个**属性**。
多条记录构成一个表。
多个表组成了数据库，表与表之间的逻辑关联叫做关系。
关系型数据库中的核心内容是关系。关系操作的对象和结果也是关系。
关系操作的方式为集合操作，即操作的对象和结果都是集合。
集合操作：
|操作|说明|
|---|---|
|选择|从表里抽取满足给定限制条件的行|
|投影|从表里取出指明的列|
|并|两个表合成为一个表，属性个数一样，属性顺序一样|
|差|两个表中不一样的部分，需要运算的两个表具有相同的字段|
|笛卡尔积|记录所有可能的组合方式，记录数量是表记录数的乘积|
ubuntu 下 MySQL 服务器相关操作：

```shell
sudo /etc/init.d/mysql start
sudo /etc/init.d/mysql stop
```

连接数据库：`mysql -u 用户名 -p密码 -h 服务器名称 -P端口`
退出数据库：`\q; exit; quit;`
查看表结构：`desc TableName;`

## 数据类型

```sql
char(len)              定长字符串
varchar(len)           不定长字符串
int                    整型
decimal(len1, len2)    定长小数
float                  浮点型
datetime               年-月-日 时:分:秒
date                   年-月-日
time                   时:分:秒
```

## sql语句

sql语句不区分大小写，以分号结尾，以这些关键词开头：
`select / insert / update / delete / alter / drop / create / use / show`

==注意==：不区分大小写是指sql语句不区分大小写，数据仍然区分大小写。

创建数据库：

```sql
create database DatabaseName;
```

查询已有数据库：

```sql
show databases;
```

选择数据库：

```sql
use DatabaseName;
```

删除数据库：

```sql
drop database DatabaseName;
```

创建表格：

```sql
create table TableName(
    column1 DataType,
    column2 DataType,
    column3 DataType,
    ...
    co1umnN DataType);
```

查询已有表：

```sql
show tables;
```

查询已有表的各个字段：

```sql
show create table TableName;
```

删除表格：

```sql
drop table TableName;
```

插入语句：

```sql
insert into TableName [(column1, ...... columnN)] values (value1, ...... valueN);
# 当value提供了表中所有字段的数据时"[]"的内容可以省略

insert into TableName2 (column1, ...... columnN) select column1, ...... columnN from TableName1;
# 选取TableName1的字段作为values插入到表2，TableName1的数据可以筛选后再插入
```

查询语句：

```sql
select column1, ...... columnN from TableName;
select * from TableName;
# 可以查询表中一个字段或多个字段，查询所有字段时可以使用"*"代替
```

修改：

```sql
update TableName set column1 = value1, ..... columnN = valueN where 条件;
# 没有where条件语句时表中所有记录的对应字段都将被修改
```

删除记录：

```sql
delete from TableName where 条件;
# 没有where条件语句表中所有记录都将被删除
```

where条件语句：

```sql
select column1, ...... columnN from TableName where 条件;
```

limit限制：

```sql
select ...... from TableName limit n;
# 从表中取n条数据

select ...... from  表名 limit m,n;
# 从表中第m条记录开始，取n条数据
```

排序：

```sql
select ...... from 表名 where 条件 order by ...... ASC/DESC;
# ASC升序，DESC降序
# order by 后面出现的列名可以不出现在 select 语句后
```

分组：

```sql
select column1, column2, ......, columnN 聚合函数(表达式) from 表名
where 条件
group by column1,column2,......,columnN
order by column1,column2,......,columnN;
# group by 用来与聚合函数联合使用，可以得到一个或多个列的结果集
# group by 之后的列必须出现在 select 语句之中或聚合函数表达式中
# group by 语句必须在 where 语句之后、order by 语句之前
# where 语句后不能直接跟聚合函数
# 因为聚合函数通过作用于一组数据而只返回单个值，因此：
#     在 select 语句中出现的元素要么为一个聚合函数的输入值，要么为 group by 语句的参数，否则会出错
```

having语句：

```sql
select column1,column2,......,columnN,聚合函数(表达式) from customers
where 条件 
group by column1,column2,......,columnN
having 条件1,条件2,...条件N;
# having 语句通常与 group by 语句联合使用，用来过滤 group by 语句返回的记录集
# having 语句的存在弥补了 where 关键字不能与聚合函数联合使用的不足

select name,address,max(salary) from customers where age > 23 and address != "Beijing"
group by name,address having max(salary) > 3000
order by max(salary) ASC;
```

聚合函数：

```sql
count()    # 总数
sum()      # 求和
avg()      # 平均值
min()      # 最小值
max()      # 最大值
# count(*) 与 group by 联合使用表示计算每个分组的记录条数
```

去重：

```sql
select distinct column1, column2, ......, columnN from 表名 where 条件;
# distinct 与 select 一起使用去除重复项，提取唯一的记录项目
```

## 运算符

```text
+, -, *, /, %
=, !=, <>(不等于), >, <, >=, <=, !<, !>
all, and, any, between .. and .., exists, in .., like, not, or
is null, unique
```

运算符优先级：

1. ~(bitwise or)
2. *, /, %
3. +, -, &(bitwise and), ^(bitwise exclusive or), |(bitwise or)
4. =, >, <, >=, <=, <>, !=, !<, !>
5. not
6. and
7. all, any, between, in, like, or
8. =

==注意==：同其它语言一样，可以用圆括号()控制优先级。

and 和 or 运算符：

```sql
...... where 条件1 and 条件2 ...... and 条件N;
...... where 条件1 or 条件2 ...... or 条件N;
```

between 运算符：

```sql
where ....... between vlaue1 and value2;
```

like运算符和通配符：

```sql
# 通配符'%'：0,1,或更多 表示后面有很多字符
# 通配符'_'：单一数字或者单一字符
where column like 'xxx%xxx';
where column like '_xxx_';
```
