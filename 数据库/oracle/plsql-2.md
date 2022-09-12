
# PLSQL

- [PLSQL](#plsql)
  - [异常处理](#异常处理)
  - [用户自定义异常](#用户自定义异常)
  - [存储过程](#存储过程)
  - [函数](#函数)
  - [包 package](#包-package)
  - [触发器 trigger](#触发器-trigger)

## 异常处理

异常的分类：编译错误、运行时错误。

plsql中程序出现错误的默认处理：

```plsql
declare
  var_name s_emp.first_name%type;
begin
  dbms_output.put_line('app start');

  select first_name into var_name from s_emp where id = 10;
  dbms_output.put_line('name='||var_name);

  select first_name into var_name from s_emp where id>10;
  dbms_output.put_line('name='||var_name);
  dbms_output.put_line('app stop');
exception
  when NO_DATA_FOUND then
    dbms_output.put_line('no emp search!');
  when TOO_MANY_ROWS then
    dbms_output.put_line('data too much!');
  when OTHERS then
    dbms_output.put_line('have execption!');
end;
```

PL/SQL中有两个宏：

- SQLCODE：sql 的错误编号
- SQLERRM：sql 的错误消息

## 用户自定义异常

```plsql
/*
1. 定义异常
根据程序中可能会出现的问题使用异常把这些问题描述清楚
too_many_order exception;

2. 根据条件抛出异常
raise 异常对象名;

3. 捕获异常
when 异常对象名 then

4. 处理异常
根据不同的异常做不同的处理
*/

declare
  too_many_order exception;
begin
  if 1 = 1 then
    raise too_many_order;
  end if;
exception
  when too_many_order then
    dbms_output.put_line('you''re sick!');
end;
```

## 存储过程

把一组逻辑相关的 sql 语句和 plsql 语句封装成一个逻辑结构，然后为这个逻辑结构起一个名字。

我们把这个逻辑结构称为存储过程。

```plsql
-- 定义两个整数变量，选出这两个变量的最大值
declare    -- 匿名块，无法保存
  var_x number(10) := 100;
  var_y number(10) := 200;
begin
  if var_x > var_y then
    dbms_output.put_line('max='||var_x);
  else
    dbms_output.put_line('max='||var_y);
  end if;
end;
```

定义和调用存储过程：

```plsql
-- 定义存储过程
create or replace procedure 过程名(参数列表) is
  (存储过程执行时需要的变量)
begin
  (执行实体)
exception
  (错误处理)
end;

-- 举例定义存储过程
create or replace procedure 
  getmax_syc(var_x number, var_y number:=200) is max_val number;
begin
  if var_x > var_y then
    max_val := var_x;
  else
    max_val := var_y;
  end if;
  dbms_output.put_line('max='||max_val);
end;

-- 调用存储过程
declare
  var_x number := 123;
  var_y number := 456;
begin
  getmax_syc(var_x);
  getmax_syc(var_y);
  getmax_syc(var_x + var_y);
  getmax_syc(1, 2);
  getmax_syc(2, 1);
end;

-- 查看存储过程源代码
select text from user_source where name='GETMAX_SYC';

-- 查看编译错误
show errors
```

查看存储过程：`desc 过程名;`。

执行后可以得到：参数的名字、类型、模式、有无默认值。

模式分为三种：

1. in：默认模式输入值
2. out：输出值
3. in out：输入输出值

参数有默认值时，具体的值需要查看源代码或文档。

注意：

1. 带有 out 修饰的参数必须是变量且不能有默认值
2. 调用存储过程可通过(`形参=>实参`)进行参数传递，在使用默认值的时候就要使用这种方式
3. 形式参数的模式为 in 时不可以进行赋值操作

## 函数

过程和函数的区别：

1. 关键字不同：procedure、function
2. 函数有返回值及返回值类型，过程没有
3. 调用方式不同：过程可直接在 plsql 中调用，函数必须组成表达式才能调用

```plsql
-- 语法
create or replace function
  函数名(参数列表)
  return 返回值类型
is
  (变量定义)
begin
  (函数语句)
  return 值;
end;

-- 示例
create or replace
  function getmax_syc(var_x number, var_y number)
  return number
is
begin
  if var_x > var_y then
    return var_x;
  else
    return var_y;
  end if;
end;

-- 调用
declare
  var_x number := 10;
  var_y number := 20;
begin
  dbms_output.put_line(getmax_syc(var_x, var_y));
end;
```

## 包 package

把一组逻辑相关的数据(变量、类型、过程、函数)组织到一起，然后为这个逻辑结构起一个名字，这个名字就是包。

`desc 包名;`可以查看包的内容。

系统提供的包(使用包中的数据：`包名.数据名`)：

```plsql
-- dbms_output：输出包
dbms_output.put_line('hello');

-- dbms_random：随机包
select dbms_random.value(1, 100) from dual;

-- dbms_lob：操作 blob、clob 的包
-- dbms_job：定时执行存储过程

-- dbms_job
dbms_job.submit(          -- 把定时任务提交给系统
  job out binary_integer, -- 定时任务提交给数据库管理系统之后，任务编号通过 job 带出
  what in varchar2,       -- 需要定时调用的存储过程
  next_date in date,      -- 下一次调用的时间
  interval in varchar2    -- 周期(时间间隔)
); 
dbms_job.run(job in binary_integer);    –- 执行编号为 job 的定时任务
dbms_job.remove(job in binary_integer); –- 删除编号为 job 的定时任务

-- 示例：使用 dbms_job 定时调用存储过程
-- 1. 创建一个表格
drop table job_syc;
create table job_syc(id number primary key, name varchar2(30));
-- 2. 创建一个序列
drop sequence job_syc_id;
create sequence job_syc_id;
-- 3. 创建一个存储过程
create or replace procedure insert_syc
is
begin
  insert into job_syc values(job_syc_id.nextval, 'test'||job_syc_id.currval);
  commit;
end;
-- 4. 提交需要定时调用的存储过程，并让其开始执行
declare
  job_no binary_integer;
begin
  dbms_job.submit(job_no, 'insert_syc;', sysdate, 'sysdate + 1 / ( 24 * 60)');
  dbms_job.run(job_no);
  dbms_output.put_line(job_no);
end;
-- 5. 查看表中数据 
select * from job_syc;
-- 6. 移除定时器定时执行的过程
begin
  dbms_job.remove(25);      -- 25 这个位置是第4步中的 job_no
end;
```

自定义包：

```plsql
-- 语法
create or replace package 包名
is
  procedure 过程名(参数列表);
  function 函数名(参数列表) return 返回值类型;
end;

-- 示例
-- 定义包
create or replace package package_syc
is
procedure getmax(x number, y number);
function getmin(x number, y number) return number;
end;
-- 实现包
create or replace package body package_syc
is
  procedure getmax(x number, y number)
  is
    begin
      if x < y then
        dbms_output.put_line(y);
      else
        dbms_output.put_line(x);
      end if;
    end;
  function getmin(x number, y number) return number
  is
    begin
      if x < y then
        return x;
      else
        return y;
      end if;
    end;
end;

-- 使用包
select package_syc.getmin(10,20) min from dual;
begin
  package_syc.getmax(10,20);
end;
```

## 触发器 trigger

当进行 DML(insert、delete、update) 操作时可以被数据库管理系统捕获到。

捕获到这些操作后可以进行一些辅助操作。

```plsql
-- 语法
create or replace trigger 触发器名
before|after            -- 二选一
insert|delete|update    -- 三选一
on 表名
[for each row]          -- 可选
declare
begin
end;
注意：触发器中不能写事物控制语句不能。

-- 示例

-- 快速建表
create table emp_syc as select id, first_name name, salary from s_emp;

-- 创建触发器：语句级触发器，无论影响多少行，只触发一次
create or replace trigger emp_syc_tri after update on emp_syc
declare
begin
  dbms_output.put_line('Have no rights.');
end;

-- 创建触发器：行级触发器，影响的每一行都会触发触发器
create or replace trigger emp_syc_tri after update on emp_syc
for each row
declare
begin
  dbms_output.put_line('Have no rights!');
  dbms_output.put_line(:old.id||':'||:old.salary);
  dbms_output.put_line(:new.id||':'||:new.salary);
end;
```
