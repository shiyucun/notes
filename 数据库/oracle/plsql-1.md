
# PLSQL

- [PLSQL](#plsql)
  - [优缺点](#优缺点)
  - [程序的组成及内容](#程序的组成及内容)
  - [变量](#变量)
    - [类型](#类型)
    - [record](#record)
    - [table](#table)
    - [作用域](#作用域)
  - [控制语句](#控制语句)
    - [条件语句](#条件语句)
    - [循环语句](#循环语句)
    - [GOTO 语句](#goto-语句)
    - [多重循环](#多重循环)
  - [PLSQL 中使用 SQL 语句](#plsql-中使用-sql-语句)
    - [DDL 语句动态 sql 方式使用](#ddl-语句动态-sql-方式使用)
    - [DML 语句直接使用](#dml-语句直接使用)
    - [DML 语句动态 sql 方式使用](#dml-语句动态-sql-方式使用)
    - [占位符](#占位符)
  - [游标 cursor](#游标-cursor)
  - [带参游标](#带参游标)
  - [参考游标](#参考游标)

PLSQL 是 Oracle 提供的一个更强大的数据库开发方式。

SQL 语句都是单条的, 类似于命令; PLSQL是过程化开发语言, 类似于 C 语言。

PLSQL 不能应用在其他数据库中。

PLSQL 是 Oracle 的开发语言, 核心是学会写存储过程和函数(自定义函数)。

## 优缺点

优点:

- 提升效率, 可以避免多次访问, 一次访问执行多条 SQL 语句
- 在 Oracle 数据库中可以随意移植
- 能提供比 SQL 强大的多的功能, 是增强版 SQL

缺点:

- 不能移植到其他数据库
- 和 SQL 不同, 很多项目完全不可以使用 PLSQL

## 程序的组成及内容

组成：

```plsql
declare   -- 声明区, 定义各种变量，可不出现
...
begin     -- 执行区, 代码写在这里
...
exception -- 异常处理，可不出现
end;      -- 执行结束

begin
  dbms_output.put_line('hello plsql!');
end; -- dbms_output默认是关闭的, 可以用set serveroutput on打开
```

内容：包含变量、变量类型、流程控制语句、其他对象和函数。

注意:

- PLSQL 不区分大小写, 但单引号('')和双引号("")中除外
- PLSQL 标示符 和 SQL 一样，可给变量、类型、游标、函数、存储过程等命名

## 变量

```plsql
var_i number;       -- 在声明区定义变量时，先写变量名再写类型
var_i number := 10; -- 在声明变量时进行初始化

declare
  var_i number;
  var_j number := 100;
begin
  var_i := 10;
  dbms_output.put_line(var_i ||' '||var_j);
end;

var_j constant number := 100;  -- 定义常量，constant代表常量，默认初始化为 null
```

### 类型

- 标量类型
  - 数字型 number、binary_integer
  - 字符型 char(n)、varchar2(n)
  - 布尔型 boolean(值可以是true、false、null)
  - 日期型 date
- 组合类型
  - record(记录) - 类似结构体
  - table(表) - 类似数组, 但下标可以不连续
  - cursor(游标)
- 引用类型：refcursor(参考类型)
- 大类型：blob、clob

### record

```plsql
declare
  type emp is record( -- 声明 emp 类型
    salary s_emp.salary%type,
    name s_emp.first_name%type
  );
  var_emp emp; -- 定义 emp 类型变量
begin
  select salary, first_name into var_emp
  from s_emp where id = 1;
  dbms_output.put_line(var_emp.salary ||',' ||var_emp.name);
end;
```

PLSQL 中同种记录类型可以任意赋值，记录和记录可以互相赋值, 记录中的成员也能互相赋值。

```plsql
var_emp1 emp;
var_emp2 emp;

var_emp1 emp := var_emp2 emp;
var_emp1.salary:=var_emp2.salary;

-- %rowtype 可以获取一个表中所有字段
-- s_emp%rowtype -- s_emp表中所有字段
declare
  var_emp s_emp%rowtype;
begin
  select salary, first_name into var_emp.salary, var_emp.first_name
  from s_emp where id = 1;
  dbms_output.put_line(var_emp.salary ||',' ||var_emp.first_name);
end;
```

record 和 %rowtype 的区别:

1. record 是自由组合的，%rowtype 的次序和数量与表一致
2. 没有 into 的成员默认值是null

### table

table 类似于 C 语言的数组，定义格式如下：

```plsql
TYPE 类型名 IS TABLE OF 元素类型 index by binary_integer;
```

定义 table 后，使用时需要单独定义该类型的变量。

table 的索引与 C 语言不同，可以为负数，也可以不连续

一般情况下索引都是从0开始，未使用的索引不分配内存。

访问未使用的索引返回的结果：`no data found`。

table 中元素的内存分配发生在数据插入 table 时，而不是定义 table 时。

table 中的元素类型可以是标量类型，也可以是组合类型。

table 类型提供了以下关于索引的函数：

- first() 取第一个元素对应的索引
- next() 取下一个元素对应的索引
- last() 取最后一个元素对应的索引

关于上述三个索引函数的注意事项：

- 调用形式是`'table的变量名'||'.'||函数名||'()'`
- 关于 next 的使用，要指定一个参数，即 next 的上一个数的索引

```plsql
set serveroutput on    -- 每次启动终端都要使用

declare
  TYPE tablenumber IS TABLE OF 
  s_emp.id%type index by binary_integer;    -- 定义类型

  var_num tablenumber;    -- 定义变量
  pos binary_integer;
begin
  var_num(0) := 100;
  var_num(1) := 200;
  var_num(4) := 300;
  dbms_output.put_line('var_num(1)' || ':' || var_num(1));

  select id into var_num(2) from s_emp where id = 2;
  dbms_output.put_line('var_num(2)' || ':' || var_num(2));

  pos := var_num.first();
  dbms_output.put_line('var_num(0)' || ':' || var_num(pos));

  pos := var_num.next(pos);
  dbms_output.put_line('var_num(1)' || ':' || var_num(pos));

  pos := var_num.next(pos);
  dbms_output.put_line('var_num(2)' || ':' || var_num(pos));

  pos := var_num.last();
  dbms_output.put_line('var_num(4)' || ':' || var_num(pos));
end;
```

### 作用域

在 begin 与 end 之间(执行区)，可以定义其它的 PLSQL 程序块，称为内部程序块。

内部程序块中，可以使用外部程序块的变量；外部程序块中，不能使用内部程序块的变量。

如果内部和外部程序块定义了同名变量，在内部程序块中，默认使用内部变量。

内部程序块中可以使用标签调用外部程序块的同名变量。

## 控制语句

- 条件语句
- 循环语句
- GOTO语句
- 多重循环

### 条件语句

if 语句：

```plsql
-- 语法
if 表达式 then ...
elsif 表达式 then ...
elsif 表达式 then ...
else...
end if;
-- 以上 if 和 end if 必须成对出现，else 和 elsif 可选

-- 示例
declare
  var_x number := 9;
  var_y number := 10;
begin
  if var_x > var_y then
    dbms_output.put_line('x>y');
  elsif var_x < var_y then
    dbms_output.put_line('x<y');
  elsif var_x = var_y then
    dbms_output.put_line('x=y');
  elsif var_x is null and var_y is null then
    dbms_output.put_line('is null');
  else
    dbms_output.put_line('other');
  end if;
end;
```

### 循环语句

loop 循环：

```plsql
-- 语法
loop
  循环体;
end loop;

-- 循环退出的两种方式：1. 使用 if 和 exit 退出；2. 使用 exit when 退出

-- 示例
declare
  var_i number := 1;
begin
  loop
    /*
    if var_i = 11 then
      exit;
    end if;
    */
    exit when  var_i = 11;
    dbms_output.put_line( var_i );
    var_i := var_i + 1;
  end loop;
end;
```

while 循环：

```plsql
-- 语法
while 条件 loop
  循环体;
end loop;
-- 和 loop 循环没有太大区别，也能用 exit when 退出
```

for 循环：

```plsql
-- 语法
for 循环变量 in 低值..高值 loop
  循环体;
end loop;
/*
注意：
1. 循环变量的自增、类型都不用管
2. 循环变量不用 declare 声明
3. 低值和高值是循环变量的范围，包括边界，中间要用 '..' 连接
*/

-- 示例
begin
  for var_i in 1..10 loop
    exit when var_i = 5;
    dbms_output.put_line(var_i);
  end loop;
end;
```

### GOTO 语句

GOTO 语句：

```plsql
-- 语法
goto lable_name;
-- 可以跳转到代码的任何位置，只要一个标签就行

-- 示例
declare
  var_i number := 1;
begin
  <<aaa>>  -- 定义标签
  if var_i < 11 then
    dbms_output.put_line(var_i);
    var_i := var_i + 1;
    goto aaa;  -- 跳转到标签
  end if;
end;
```

### 多重循环

```plsql
for 循环变量 in 低值..高值 loop
  for 循环变量 in 低值..高值 loop
    循环体;
  end loop;
end loop;
-- 内层循环中想直接退出两重循环，可以使用 exit + 标签
```

## PLSQL 中使用 SQL 语句

select 语句不能直接使用，要加 into 后使用。

dml(增删改) 语句可以直接使用，也可以动态使用。

ddl语句(建表等) 要动态使用。

动态使用就是把 sql 语句拼成一个字符串，然后执行字符串。

### DDL 语句动态 sql 方式使用

```plsql
declare
  sqlstr varchar2(100);
begin
  sqlstr := 'create table syc(id number(10), name varchar2(40))';
  execute immediate sqlstr;
end;
```

### DML 语句直接使用

```plsql
begin
  insert into syc values(1, 'syc');
  commit;
end;
```

### DML 语句动态 sql 方式使用

```plsql
declare
  sqlstr varchar2(100);
begin
  sqlstr := 'insert into syc values(2, ''gy'')';
  execute immediate sqlstr;
end;

declare
  sqlstr varchar2(100);
  var_name varchar2(40) := 'guanyu';
begin
  sqlstr := 'insert into syc values(3, '''||var_name||''')';
  execute immediate sqlstr;
end;
```

对于`'''||var_name||'''`的理解：

1. 连接符的左右都应该是字符串
2. 左侧三个单引号表示一个字符串，字符串内容为一个单引号
3. 右侧三个单引号和左侧是同样的道理
4. 两个连接符中间是一个字符串，内容存储在变量`var_name`中
5. 因此，`'''||var_name||'''`表示的内容为`'guanyu'`

特别注意：

1. 在需要变量的位置先放置两组三个单引号，然后中间放置两个连接符(||)，连接符中间放置变量
2. `execute immediate`执行的 SQL 语句中只能有一条 SQL 语句

### 占位符

占位符可以实现上述字符串的简便连接。

```plsql
declare
  sqlstr varchar2(100);
  var_name varchar2(40) := 'liubei';
begin
  sqlstr := 'insert into syc values(3, :b)';
  execute immediate sqlstr using var_name;
  commit;
end;
```

使用占位符可以很好的解决字符串拼接的问题，如上所示，':b'是占位符。

然后在 execute 中使用 using。如果有多个占位符，using后面用 ',' 隔开多个变量。

注意：

1. ':b'里面的 b 只表示一个占位符号，可以用其它字符
2. 使用占位符更安全

select 语句也支持动态 SQL 方式，使用：

`execute immediate sql into 变量;`

但要注意，这种方法在使用游标和参考游标之前只能取一条结果。

sql 中所有的函数在 PL/SQL 中都可以直接使用。

## 游标 cursor

处理多行的查询结果集需要使用游标或参考游标。

cursor 的使用步骤：

```plsql
-- 声明 cursor
cursor 游标名 is select 查询语句;

-- 打开cursor
open 游标名;

-- 用游标提取数据
-- fetch 可以将数据提取到 n 个变量或者组合型变量中
fetch 游标名 into 变量名;

-- 关闭 cursor
close 游标名;

-- 示例
declare
  cursor emp_cursor is select id, first_name from s_emp;
  var_id s_emp.id%type;
  var_name s_emp.first_name%type;
begin
  open emp_cursor;
  for i in 1..25 loop
    fetch emp_cursor into var_id, var_name;
    dbms_output.put_line(var_id);
    dbms_output.put_line(var_name);
  end loop;
  close emp_cursor;
end;
```

游标提供了一些属性，帮助实现结果集的控制。

%found – 提取数据时，有新数据则返回 true，否则返回false。
要求 cursor 必须打开，打开没有 fetch 返回 null。

%notfound – 提取数据时，有新数据则返回false，否则返回true。
要求 cursor 必须打开，打开没有 fetch 返回 null。

%isopen – 判断游标是否打开，打开则返回true，否则返回false。

%rowcount – 游标指针的偏移量。
属性的使用：游标变量名%属性名，例如：emp_cursor%notfound。

```plsql
declare
  cursor emp_cursor is select id, first_name from s_emp;
  var_id s_emp.id%type;
  var_name s_emp.first_name%type;
begin
  open emp_cursor;
  loop  -- cursor 使用 loop 循环取值
    fetch emp_cursor into var_id,var_name;
    if emp_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_id);
    dbms_output.put_line(var_name);
  end loop;
  close emp_cursor;
end;


declare
  cursor emp_cursor is select * from s_emp;
  var_emp s_emp%rowtype;
begin
  open emp_cursor;
  loop  -- cursor 使用 loop 循环取值
    fetch emp_cursor into var_emp;
    if emp_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_emp.id||','||var_emp.first_name);
  end loop;
  close emp_cursor;
end;

declare
  cursor emp_cursor is select * from s_emp;
  var_emp s_emp%rowtype;
begin
  open emp_cursor;
  fetch emp_cursor into var_emp;
  while emp_cursor%found loop  -- cursor 使用 while 循环取值
    dbms_output.put_line(var_emp.id||','||var_emp.first_name);
    fetch emp_cursor into var_emp;
  end loop;
  close emp_cursor;
end;

declare
  cursor emp_cursor is select * froms_emp;
-- var_emp s_emp%rowtype;
begin
  for var_emp in emp_cursor loop  -- cursor 使用 for 循环取值
    dbms_output.put_line(var_emp.id||','||var_emp.first_name);
  end loop;
end;
```

## 带参游标

游标在定义时可以设计参数，并且这些参数可以在游标对应的sql语句中使用。游标的参数类型不能有长度修饰但可以使用%type。

```plsql
declare
  cursor var_cursor is select id, first_name from s_emp;
  var_id s_emp.id%type;
  var_name s_emp.first_name%type;
begin
  open var_cursor;
  loop
    fetch var_cursor into var_id, var_name;
    if var_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_id||','||var_name);
  end loop;
  close var_cursor;
end;

declare
  cursor var_cursor(var_id number) is
  select id, first_name from s_emp where id > var_id;
  var_id s_emp.id%type;
  var_name s_emp.first_name%type;
begin
  open var_cursor(3);
  loop
    fetch var_cursor into var_id, var_name;
    if var_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_id||','||var_name);
  end loop;
  close var_cursor;
end;

declare
  cursor var_cursor(var_id number) is
  select id, first_name from s_emp where id > var_id;
begin
  for var_emp in var_cursor(20)
    loop
      dbms_output.put_line(var_emp.id||','||var_emp.first_name);
    end loop;
end;

declare
  cursor var_cursor(var_id number) is 
  select id, first_name from s_emp where id > var_id;
  type var_emp is record(
    var_id s_emp.id%type,
    var_name s_emp.first_name%type);
begin
  for var_emp in var_cursor(20)
    loop
      dbms_output.put_line(var_emp.id||','||var_emp.first_name);
    end loop;
end;
```

## 参考游标

ref cursor 的使用步骤：

1. 定义参考游标类型(TYPE 参考游标类型名 is ref cursor)
2. 使用参考游标类型定义游标变量(游标变量参考类型游标名)
3. 打开游标时，把游标变量对应到一个查询字符串
    - open 游标变量 for sqlstr;
    - open 游标变量 for sqlstr using 值, ...;

```plsql
-- 示例：把 'select * from s_emp'对应的内容查询处理并打印

declare
  type var_cursor is ref cursor;
  emp_cursor var_cursor;
  var_emp s_emp%rowtype;
  sqlstr varchar2(100);
begin
  sqlstr := 'select * from s_emp';
  open emp_cursor for sqlstr;
  loop
    fetch emp_cursor into var_emp;
    if emp_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_emp.id||','||var_emp.first_name);
  end loop;
  close emp_cursor;
end;

declare
  type var_cursor is ref cursor;
  emp_cursor var_cursor;
  var_emp s_emp%rowtype;
  sqlstr varchar2(100);
begin
  sqlstr := 'select * from s_emp where id > :b';
  open emp_cursor for sqlstr using 15; -- 用15代替占位符':b'
  loop
    fetch emp_cursor into var_emp;
    if emp_cursor%notfound then
      exit;
    end if;
    dbms_output.put_line(var_emp.id||','||var_emp.first_name);
  end loop;
  close emp_cursor;
end;
```
