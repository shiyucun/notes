
# Oracle

- [Oracle](#oracle)
  - [数据类型](#数据类型)
  - [函数](#函数)
    - [字符函数](#字符函数)
    - [数值函数](#数值函数)
    - [日期函数](#日期函数)
    - [转换函数](#转换函数)
    - [多行函数](#多行函数)
  - [SQL语句](#sql语句)
    - [常用语句](#常用语句)
    - [SELECT](#select)
    - [DML](#dml)
  - [DDL](#ddl)
    - [事务处理语句](#事务处理语句)
  - [多表连接](#多表连接)
  - [建表](#建表)
  - [序列与索引](#序列与索引)
  - [视图](#视图)
  - [设计数据库](#设计数据库)
  - [数据字典](#数据字典)
  - [top N 问题和分页显示问题的处理](#top-n-问题和分页显示问题的处理)

数据库与其他语言无关，任何程序员操作数据库的SQL语句都是一样的。

SQL语句本身不区分大小写，除了 '' 和 "" 中。

数据存储方式：内存(变量和数据结构)，硬盘(文件和数据库)。数据存入硬盘是数据的持久化。

文件和数据库的区别：

- 最早的数据库都是存储在文件中，数据库是特殊的文件
- 文件的用途更广泛，硬件要求更低
- 数据库更针对数据，有一套通用的对数据的增删改查支持

关系型数据库都会提供 DBMS(database manage system)，关系型数据库的管理系统简写为RDBMS。

表：关系型数据库数据都是存在表中，表就是数据关系的体现。

表中每行数据称为记录，每列称为字段。定义表时，需要定义字段，记录是之后加入的。

## 数据类型

number()：数值型(整数和小数，右对齐)

- number(7) → 7位整数
- number(7, 2) → 7位数，2位小数，5位整数

varchar2、char：文本型(字符串，左对齐)

- varchar2(20) → 最多20个字符，varchar2 是变长字符串，数据多长就存多长
- char(20) → 20个字符，char 是定长字符串，不足部分自动补空格，相对 varchar2 效率稍好

date：日期型

clob (Character data 4 GB)

blob (Binary data 4 GB)

注：

- Oracle 数据库的日期由7部分组成：世纪、年、月、日、时、分、秒。
- 英文日期显示格式是"日-月-年"，其中月份和语言环境有关，解决方案是使用转换函数。

## 函数

函数分为单行函数和多行函数(分组函数)。

单行函数就是一次处理一条数据(一进一出)；多行函数就是一次处理多条数据，得到一个结果(多进一出)。

在使用上，单行函数和多行函数没有太大区别。

### 字符函数

| 函数                    | 功能                     |
| ----------------------- | ------------------------ |
| LOWER('STRING')         | 转换成全小写             |
| UPPER('string')         | 转换成全大写             |
| INITCAP('good string')  | 转换每个单词首字母为大写 |
| CONCAT('Good','String') | 连接字符串               |
| SUBSTR('String',1,3)    | 截取字符串               |
| LENGTH('String')        | 取字符串长度             |

oracle 官方提供了一个 dual 表，这个表是一个虚表，就是没有固定的字段，字段由用户指定(文本、数值、日期都支持)。

如下：

```sql
select 1+1 from dual;
select sysdate from dual;
select lower('STRING') from dual;
select upper('string') from dual;
select substr('STRING', 2, 3) from dual;
select length('STRING') from dual;
```

### 数值函数

| 函数    | 功能               |
| ------- | ------------------ |
| round() | 对数值进行四舍五入 |
| trunc() | 截断数值(舍弃)     |

```sql
round( 45.923, 0 )      -- 46
round( 45.923, -1 )     -- 50
round( 45.923, 2 )      -- 45.92
trunc( 45.923, 0 )      -- 45
trunc( 45.923, -1 )     -- 40
trunc( 45.923, 2 )      -- 45.92
```

### 日期函数

round 和 trunc 函数都可以对日期使用，但是很少用，没有实际意义。

### 转换函数

| 函数        | 功能           |
| ----------- | -------------- |
| to_char()   | 数值转换成文本 |
| to_number() | 文本转换成数值 |

转换需要一个格式字符串，如下：

```sql
to_char(number, 'fmt')
select to_char(12345.6789, '$999,999.9999') from dual;

to_number(string, 'fmt')
select to_number('$12,345.6789', '$999,999.9999') from dual;

/*
说明：
格式化字符串中 9 代表有一位数，没有就不显示，转换为文本时小数点后面有 9 会补 0，转换为数值不会
格式化字符串中 0 代表有一位数，没有就显示 0，转换为数值是不能使用
$ 代表美元符号
L 代表本地货币符号
. 代表小数点
, 代表千分位
*/
```

数值和文本之间的转换并不常用，常用的是日期和文本之间的转换。

基本上对数据的增加和更改都会使用`to_date()`，对数据的查询会使用`to_char()`。

| 函数      | 功能           |
| --------- | -------------- |
| to_date() | 文本转换为日期 |
| to_char() | 日期转换为文本 |

转换需要一个格式字符串，如下：

```sql
select to_date('2008-08-08 20:08:00', 'yyyy-mm-dd hh24:mi:ss') from dual;
select to_char(sysdate, 'hh24:mi:ss') from dual;

/*
y       1位年
yyyy    4位年
m       1位月
mm      2位月(输出数字，输出英文用 mon 或 month)
d       1位日
dd      2位日
h       1位小时
hh24    2位小时，24小时制
mi      分钟
s       1位秒
ss      2位秒
注意：日期格式大小写都支持
*/
```

补充：

y、yy、yyy、yyyy 可以分别表示年的最后1、2、3、4四位。

mm 表示月，可以用英文简写，mon 与月份简写对应，month 与月份完整拼写对应。

```sql
select to_char(sysdate, 'mon') from dual;
select to_char(sysdate, 'month') from dual;
```

dd 表示当月第几天，ddd 表示当年第几天。

dy 对应星期几的简写，全称 day 对应星期几的完整拼写。

```sql
select to_char(sysdate, 'ddd') from dual;
select to_char(sysdate, 'dd') from dual;
select to_char(sysdate, 'day') from dual;
```

hh 表示 12 进制的小时，hh24表示 24 进制的小时。

q 表示季度(1-4)。

```sql
select to_char(sysdate, 'q') from dual;
```

w 表示当月第几周。

```sql
select to_char(sysdate, 'w') from dual;
```

ww 表示当年第几周。

```sql
select to_char(sysdate, 'ww') from dual;
```

补充：

算两个年份之间间隔多少年？

```sql
select to_number(to_char(sysdate, 'yyyy'), '9999') -
       to_number(to_char(start_date, 'yyyy'), '9999')
from s_emp
where id = 2;
```

### 多行函数

多行函数也称为分组函数。

| 函数  | 功能                     |
| ----- | ------------------------ |
| sum   | 求和，只用于数值型       |
| count | 计算记录数，任何类型均可 |
| avg   | 求平均数，只用于数值型   |
| max   | 求最大值，任何类型均可   |
| min   | 求最小值，任何类型均可   |

注意：

- 分组函数空值默认不参与运算，分组要使用group by子句
- 分组函数最多可以嵌套两层

用法：

```sql
select dept_id, avg(salary) from s_emp
group by dept_id
order by avg(salary) desc;
```

注意：

- select 中如果使用了分组函数就不能随便写任意字段，只能用 group by 中出现的或者分组函数的参数
- where 子句不允许使用分组函数做条件，要使用 having 子句

```sql
select dept_id, avg(salary) from s_emp
group by dept_id
having avg(salary) > 1200;
```

having 和 where 的区别：

- 如果没有 group by 不能使用 having
- where 的条件不能是分组函数
- 从效率上说，where 比 having 高，如果都能用，首选where

## SQL语句

| 语句     | 功能                                    |
| -------- | --------------------------------------- |
| SELECT   | 查询语句                                |
| DML      | 数据操作 – 增删改数据                   |
| 事务处理 | 确认和撤销 DML                          |
| DDL      | 数据定义语言 – 定义数据格式，主要是表   |
| DCL语句  | 数据控制语言 – 各种权限控制 (由DBA管理) |

### 常用语句

```sql
desc s_emp;             -- 查看表的结构(字段)
select * from s_emp;    -- 查看表中数据(记录)                           
exit;                   -- 退出
-- sql语句本身不包括';'，但是在sqlplus中用';'代表结束。
```

### SELECT

```sql
select 查看的字段 from 数据源
-- * 可以代表所有字段
-- 数据源一般是表或视图或子查询
```

数值型字段：可以直接进行算术运算。

日期型字段：可以加减常数，两个日期也可以作减法。

oracle中，当前时间用 sysdate 表示(`sysdate - start_date`可以查看时间差)。

如果想把名字连接起来，使用 || 作为文本的连接符。

文本型和日期型的值用''括起来，""只能用于起别名。

```sql
select id, first_name||' '||last_name "name" from s_emp;
```

在表中，有些字段的值允许不写，记录中没有值的字段用空值代表。

空值不是一个整数，也不是文本和日期，但整数、文本和日期类型的字段都允许是空值。

只要有空值参与的算术运算结果一定是空值。

nvl函数用来处理空值。语法：`nvl(可能为空的字段/表达式，值)`。

如果前面的字段为空，结果取后面的值；如果前面的字段不为空，结果取前面的字段值。

```sql
select id, first_name,
  salary * (1 + nvl(commission_pct, 0) / 100) * 12 income
from s_emp;
```

Oracle数据库允许使用别名，即在原来名字的后面留个空格然后跟上别名。

重复记录：函数distinct可以去除重复记录，但是只有所有的字段值都一样才算是重复记录。

查询的完整写法：

```sql
select ... from ... where ...
group by ...
having ...
order by ...
-- select 和 from 为必须包含的字段
-- 子查询允许一次执行多个查询语句，其中一个叫外部查询，另一个叫子查询
-- 子查询先执行，其结果被外部查询使用，子查询可以出现在 where 和 from 子句中
-- 子查询语法上使用时要用 () 括起来
```

条件查询：

条件查询使用 where 子句，放在 from 子句的后面。

```sql
Select 需要显示的字段或表达式 from 数据源 where 查询条件;
-- 数据源可以是表、视图、子查询等
```

where 子句中运算符：

- 比较运算符：=、>、>=、<、<=、!=、<>
- SQL 官方比较运算符：
  - BETWEEN ... AND ...：在 ... 和 ... 之间，包括两个结点
  - IN(list)：等于 list 中任何一个都行
  - LIKE：模糊查询，'_' 代表一个字符，'%' 代表 n 个字符
  - IS NULL：与空值作比较，数据库中空是空、0 是 0
- 逻辑运算符：AND(与)、OR (或)、NOT(非)

排序子句：

`order by`用于查询结果的排序。

排序分为升序和降序，默认是升序，降序要在后面加`desc`。

`order by`后面可以跟多个排序条件，第一个相同时用第二个排序，依次类推。

### DML

```sql
insert into 表名(字段1, ...) values(值1, ...);
commit;    -- 确认插入数据，insert会生效
-- (字段1, ...)：如果插入全部字段时，可以省略
-- insert 语句通常一次插入一条语句，但插入子查询时可以插入多条数据
```

```sql
update 表名 set 字段1=值1, ... where 条件;
-- 一般有 where 条件，没有 where 时全表修改
```

```sql
delete from 表名 where 条件;
-- 多数情况下都有 where 条件，否则就是全部删除
```

DML语句会锁定相关数据，而不是表，更不是数据库，锁定会在事务处理之后解除。

## DDL

```sql
alter     - 修改，主要修改表
truncate  - 截断表，删除所有数据，但表不会被删除，与delete的区别在于truncate 是DDL，没有事务处理
rename    - 改名

-- 以上会自动 commit
```

### 事务处理语句

产生原因：增删改会直接对数据造成影响，误操作会带来错误数据。

```sql
commit      -- 提交，确认刚才的修改
rollback    -- 回滚，撤销刚才的修改
```

commit 和 rollback 都支持多条以后再提交或者回滚。

commit 和 rollback 后数据的状态：

- commit
  1. 数据库中的数据发生改变，之前的数据就被替换，无法找回
  2. 锁定被解除
  3. 所有窗口看到的都是修改之后的数据
  4. 如果前面有 savepoint 的断点，会被解除
- rollback
  1. 数据库中的数据不发生改变，之前的数据永久保存，DML 操作取消
  2. 锁定被解除
  3. 所有窗口看到的都是修改之前的数据
  4. 如果前面有 savepoint 的断点，会被解除

commit 和 rollback 前数据的状态：

1. 数据库中的数据没有发生改变，还是改变之前的数据
2. DML 所改变的数据被锁定，不允许其它窗口修改、删除
3. 本窗口查询时是修改后的结果，其他窗口查询时是修改之前的结果

关于自动提交和自动回滚：

- 自动提交包括：
  1. 执行 DDL 语句，会自动提交之前的状态然后 DDL
  2. 执行 DCL 语句，会自动提交之前的状态
  3. 正常退出：用 exit 命令
- 自动回滚包括：非正常退出

savepoint 用于保存一个断点，commit 或者 rollback 可以提交或退回到这个断点。

## 多表连接

数据库中有很多表，因此数据并不是只能从一个表中获取。

从多个表中获取数据，叫做多表连接。

理论上多表连接没有数量限制，但实际上最多连接4-5个表，常见2-3个表。

多表连接写法：

```sql
select 表1.字段1, 表1.字段2, ..., 表2.字段1, 表2.字段2, ... from 表1, 表2
where 连接条件;
-- 表名过长可以使用别名简化
-- 字段没有重名，那么”表1.”可以省略
-- 没有连接条件的多表连接是没有意义的(笛卡尔乘积)，连接 N 张表要 N-1 个条件
```

多表连接的方式：

- 等值连接：连接条件为相等的
- 非等值连接：连接条件不是等号的多表连接
- 外连接：符合连接条件的和不符合连接条件的都能显示出来
- 自连接：把一张表用别名当成多表进行连接

外连接：有些查询除了显示匹配连接条件的之外，不匹配的也要显示出来。

外连接就是在等号的左边或者右边加上(+)，分别叫左外连接和右外连接。

需要注意的是只能在一端使用(+)，如下：

```sql
select E1.id, E1.first_name, E1.manager_id, E2.first_name
from s_emp E1, s_emp E2
where E1.manager_id = E2.id(+)  -- 没有写(+)的一端会显示不匹配的
order by  E1.id;

select e.id, first_name, d.name
from s_emp e, s_dept d
where e.dept_id = d.id;

select e.id, first_name, d.name
from s_emp e, s_dept d
where e.dept_id = d.id(+);

select e.id, first_name, d.name
from s_emp e, s_dept d
where e.dept_id(+) = d.id;
```

Oracle 从 9 开始，多表连接支持一种新的写法，更多的时候是使用新的写法：

```sql
select ... from 表1 join 表2 on (连接条件) where 其它条件

select e.id, first_name, d.name
from s_emp e cross join s_dept d;  -- 笛卡尔积要用 cross join

select e.id, first_name, d.name
from s_emp e join s_dept d
on (e.dept_id = d.id);  -- 括号可以有也可以没有

from 表1 join 表2 on() join 表3 on()

select e.id, first_name, d.name, r.name
from s_emp e 
join s_dept d on (e.dept_id = d.id)
join s_region r on (d.region_id = r.id);

-- 外连接的新写法是用 left outer/right outer/full outer 放在 join 前面
select e.id, first_name, d.name
from s_emp e full outer join s_dept d
on (e.dept_id = d.id);

select e.id, first_name, d.name
from s_emp e left outer join s_dept d
on (e.dept_id = d.id);

select e.id, first_name, d.name
from s_emp e right outer join s_dept d
on (e.dept_id = d.id);

-- from A join B,
-- 如果是左外连接，显示 A 表里面为空的对应的内容
-- 如果是右外连接，显示 B 表里面为空的对应的内容
-- 如果是全连接，则 A 与 B 里面的都显示
```

## 建表

```sql
create table [用户名(方案).]表名(
  字段1 字段类型,
  ...
  字段n 字段类型 [default 值],
  [表级约束]
);
```

注意：

1. 最后一个字段或表级约束后面没有','
2. 默认值、约束(表级和字段级)都可以不出现
3. 建表一般不带数据

删除表：

```sql
drop table [用户名(方案).]表名;
```

数据存入表时，应该保证数据的有效和完整，这个工作由建表语句实现。

约束用于对插入表中的数据进行管制，用于保证数据的有效和完整(部分完整)。

约束一共有 5 种：

1. 主键约束：`primary key`(非空+唯一)
2. 非空约束：`not null`
3. 唯一约束(无重复)：`unique`(可以用constraint关键字起别名)
4. 外键约束：`foreign key`
5. check 约束：`check`

```sql
create table openlab.Sstudent(
  id number(10),
  name varchar2(40) not null,
  birthdate date default sysdate,
  mobile varchar2(20) constraint stu_tel unique
);
```

字段级约束：写在字段类型后面，逗号之前。

表级约束：写在所有字段结束后的位置，与字段平行，用','隔开。

多个字段做主键是可以的，叫联合主键，一般不使用。联合主键只能使用表级约束。

```sql
create table openlab.Sstudent(
  id number(10),
  name varchar2(40) not null,
  birthdate date default sysdate,
  mobile varchar2(20) constraint stu_tel unique,
  constraint stu_id primary key(id)
);

create table openlab.Sstudent(
  id number(10) constraint stu_id primary key,
  name varchar2(40) not null,
  birthdate date default sysdate,
  mobile varchar2(20) constraint stu_tel unique
);
```

check约束用于检查数据的有效性，使用方法是在字段名后面写`check()`，括号里面写写入表中的条件。

```sql
create table sycemp(
  id number(10) primary key,
  name varchar2(40) not null,
  salary number(12, 2) constraint lowSA check(salary > 1600)
);
```

注意：约束虽然保证数据的有效和完整，但降低了效率，不是特别需的情况下要少用约束。

外键约束是两张表之间的约束，如员工表的 dept_id 和部门表的 id 就是外键约束。

有些表之间是有关系的，当 a 表的某个数据来自于 b 表时，需要使用主外键约束进行限制。

a 叫做子表，b 表叫做父表(一对多的关系)。

父表只需要建立主键即可，不用额外写约束。子表需要在关联字段上加上外键约束。

外键约束的语法有两种：

```sql
-- 表级写法：在所有字段名之后写上','然后写
constraint 约束名
foreign key (外键字段名)
references 父表名(父表字段名)

-- 字段级写法：在要设为外主键的字段名后面写上下面的句子
constraint 约束名
references 父表名

-- 举例
create table dept_syc(
  id number(10) primary key,
  name varchar2(40) not null
);

create table sycemp(
  id number(10) primary key,
  name varchar2(40) not null,
  salary number(12, 2) constraint lowSA check(salary > 1600),
  dept_id number(10),
  constraint emp_dep_id
  foreign key(dept_id)
  references dept_syc(id)
);

create table sycemp(
  id number(10) primary key,
  name varchar2(40) not null,
  salary number(12, 2) constraint lowSA check(salary > 1600),
  dept_id number(10)
  constraint emp_dep_id
  references dept_syc(id)
);

insert into dept_syc values(1, 'liubei');
insert into dept_syc values(2, 'guanyu');
insert into sycemp values(1, 'liubei', 3000.02, 1);
insert into sycemp values(2, 'guanyu', 2000.56, 2);
insert into sycemp values(3, 'zhangfei', 2000.56, 3); -- 不能插入，部门表中没有部门编号3
```

外键约束在父表删除数据时，如果在子表中找的到关联数据，会有问题。

Oracle提供了两中解决方案：

1. 级联(cascade)删除，即父子表一块删除：`on delete cascade`
2. 设置子表空(子表的关联数据的对应字段置为null)：`on delete set null`

```sql
create table sycemp(
  id number(10) primary key,
  name varchar2(40) not null,
  salary number(12, 2) constraint lowSA check(salary > 1600),
  dept_id number(10)
  constraint emp_dep_id
  references dept_syc(id)
  on delete cascade
);

create table sycemp(
  id number(10) primary key,
  name varchar2(40) not null,
  salary number(12, 2) constraint lowSA check(salary > 1600),
  dept_id number(10)
  constraint emp_dep_id
  references dept_syc(id)
  on delete set null
);
-- 使用外键约束时，一般会加上：on delete set null
```

通常情况下，删除表的同时就会删除约束。

```sql
-- 不删除表的情况下删除约束
alter table 表名 drop constraint 约束;

-- 禁止使用约束但不删除
alter table 表名 disable constraint 约束;  -- 不稳定
alter table 表名 enable constraint 约束;   -- 激活

alter table teacher_wzd disable constraint tea_les_fk;
alter table teacher_wzd enable constraint tea_les_fk;
```

## 序列与索引

可以使用一个子查询建新表，这种方式会复制原表中 select 的字段，同时会舍弃掉除了非空的所有约束。

```sql
create table sycemp as (select id, last_name, salary from s_emp);
```

主键会带来使用的麻烦，不能重复，数据库提供了各种解决方案，有些数据库提供了自增字段。

序列是 Oracle 的内部对象，和表是平级的，序列名和表名在同一用户下不能重复。Oracle 采用序列提供主键。

```sql
-- 创建序列
create sequence 序列名 start with 初值 increment by 增长值;
-- start with 和 increment by 可以采用默认值(从1开始，每次+1)

-- 使用方式
序列名.nextval  -- 下一个值，序列自增
序列名.currval  -- 当前值

create sequence syc;
select syc.currval from dual;
select syc.nextval from dual;
select syc.currval from dual;
-- currval 必须先要 nextval 一下

insert into student values(syc.nextval, '45', 2, '116', sysdate);

-- 表和序列没有关系，序列只是为表提供主键的值
-- 一般情况下，一个表会配一个序列
-- 如果插入失败，序列也会自增

-- 删除序列
drop sequence 序列名;
```

索引是 Oracle 的内部对象，和表、序列平级，但索引的创建依赖于表，没有表就不能创建索引。

数据库的数据量非常大时，查询将非常慢。索引就是提升查询效率的。

Oracle 中有很多索引，其中最多的就是二叉树索引。

索引可以大幅提升查询效率，但同时也会降低增删效率。

因此，索引不要随意加，只有频繁查询的字段才有必要加索引。

```sql
-- 创建索引
create index 索引名 on table (字段1, ...);

-- 删除索引
drop index 索引名;

-- 加了唯一约束的字段自动增加索引，其中主键自带索引。
```

## 视图

视图是 Oracle 内部对象之一，用于给数据添加其它显示方式(区别于表)。

数据存储在表中，视图中不会存储数据，但视图可以根据需要从一个或者多个表中选择出自己想要的数据。

视图的好处：

1. 数据库能控制用户能看的数据
2. 简化查询：select ... from 视图
3. 让数据更少的相互依赖
4. 同样的数据可以显示成不同的风格

创建视图：

```sql
create or replace view 视图名 as 子查询 with read only;
-- 视图可以修改数据，但不推荐，因为数据不完整。
```

## 设计数据库

设计数据库有规范，叫范式。一共有5个范式，还有一个附加的范式。一般都是到范式3就可以了。

范式1：不能有重复字段。

范式2：所有字段都必须依赖主键字段。

范式3：不能有更依赖其他字段的字段。

表间关系有一对一、一对多和多对多三种。

- 一对一就是两个表的关系是依次对应。方法：
  1. 相同主键法：两个表使用相同的主键字段
  2. 主外键关联：两个表用不同的主键，但做关联，可能会造成一对多的效果，因此关联字段最好有唯一约束
  3. 合并两个表，做成一个表
- 一对多的设计方式：表之间是一个对应多个或者多个对应一个的关系。方法：
  1. 主外键关联，父表不用体现关系，子表用外键关联的方式体现关系
- 多对多的设计方式：多对多就是两个表之间的关系是多个对应多个的关系。方法：
  1. 用一个单独的关联表实现，关联表中只需要存储两边的主键，并且都用外键约束关联对应的父表

```sql
create table a(id, ...);
create table b(id, ...);
create table c(
  a_id constraint fk_a references a(id),
  b_id constraint fk_b references b(id)
);
```

## 数据字典

Oracle 建立了很多的系统表，用于记录用户的操作。如：

```sql
-- 约束存储在 user_constraints 表中
select owner, constraint_name, table_name from user_constraints
where lower(constraint_name) like '%tea_les_fk%';

-- 用户表: user_tables
desc user_tables;
```

## top N 问题和分页显示问题的处理

top N 问题的解决方案，不同的数据库是不一样的。

Oracle 使用 rownum：`rownum = 行数`。

rownum 只能使用小于，等于和大于不可以使用。

```sql
select * from
(select id, first_name, salary from s_emp order by salary desc)
where rownum < 11;
```
