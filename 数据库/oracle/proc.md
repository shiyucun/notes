
# PROC 程序

- [PROC 程序](#proc-程序)
  - [与 C 程序比较](#与-c-程序比较)
  - [开发 PROC 程序](#开发-proc-程序)
  - [宿主变量](#宿主变量)
  - [指示变量](#指示变量)
  - [数组变量使用的注意事项](#数组变量使用的注意事项)
  - [sqlca 通信区](#sqlca-通信区)
  - [oraca 通信区](#oraca-通信区)
  - [proc 中嵌入 sql 语句](#proc-中嵌入-sql-语句)
  - [proc 中调用 plsql](#proc-中调用-plsql)
  - [数据库的连接](#数据库的连接)
  - [proc 中的错误处理](#proc-中的错误处理)
  - [proc 中的数据处理](#proc-中的数据处理)
  - [动态 sql](#动态-sql)

通过在过程化编程语言中嵌入sql语句开发出的应用程序叫做pro程序。

宿主语言：sql语句所嵌入的语言。

proc/c++ 可以使 c 和 c++ 这些更接近底层的高效语言成为访问 Oracle 数据库的工具。

```c
#include<stdio.h>

EXEC SQL BEGIN DECLARE SECTION;
char username[20];
char password[20];
char last_name[25];
EXEC SQL END DECLARE SECTION;

EXEC SQL INCLUDE sqlca;

void sqlerror();

main() {
  EXEC SQL WHENEVER SQLERROR DO sqlerror();
  strcpy(username, "ABC");
  strcpy(password, "Aa123456");
  EXEC SQL CONNECT:username IDENTIFIED BY:password;
  EXEC SQL select LAST_NAME into :last_name from S_EMP where id = 2;
  printf("ID=2, last_name=%s\n", last_name);
}

void sqlerror() {
  EXEC SQL WHENEVER SQLERROR CONTINUE;
  printf("\n---- oracle error detected:\n");
  printf("%.70s\n", sqlca.sqlerrm.sqlerrmc);
  EXEC SQL ROLLBACK WORK RELEASE;
  exit(1);
}
```

## 与 C 程序比较

相同点：都需要导入头文件、定义变量、声明变量、定义函数、使用类库函数。

不同点：

```c
// 包含一个数据结构 sqlca
exec sql include sqlca;

// 连接数据库
exec sql connect:username identified by:userpasswd;
exec sql connect:usernamepasswd;

// 查询数据库
EXEC SQL select LAST_NAME
into :last_name 
from S_EMP 
where id=2;

// 断开数据库连接
exec sql commit work release;
exec sql rollback work release;
```

## 开发 PROC 程序

```txt
1. 编写源代码(vim *.pc)
2. 预编译(proc *.pc，将 pc 文件转换成 c 文件)
3. 编译连接
    gcc *.c -lclntsh    (linux)
    gcc *.c -lorasql10  (windows)
```

## 宿主变量

宿主变量是既能在 sql 语句中使用，又能在宿主语言中使用的变量。

宿主变量的类型：

1. `char c;` → 字符型
2. `char var[10];` → 定长字符串
3. `short、int、long、float、double`
4. `varchar var[n];` → 变长字符串

```c
// 定长字符串：
char name[30];

// 变长字符串：
//   把 char 更换成 varchar 类型
//   在 select 语句中要和正常的变量一样去使用
//   在宿主语言中取得字符串的数据需要使用 '变量名.arr' 获取
// 注意垃圾值问题：
//   方法1，整个字符串初始化为 0：
varchar var_name[30]={0};
//   方法2，在字符串结尾添加 '\0'：
var_name.len  // 存储数据的实际长度
var_name.arr[var_name.len]='\0';
```

编译选项以及编译：

```txt
// 使用 proc 的预编译选项解决变长字符串问题
char_map=charz           // 默认处理方式，char 数组定长，按空格补齐，以'\0'结尾
char_map=charf|varchar2  // 定长，按空格补齐
char_map=string          // 变长，以'\0'结尾

// proc++ 程序相关的编译选项
oname     // 输出文件名，默认输出'.c'，但是 c++ 推荐使用'.cpp'文件
parse     // 默认是以 c 语言的 full 方式解析
  partia  // 严格的 c++ 解析，不推荐使用
  none    // c++ 推荐的方式
code      // 默认是 ansi_c 的 c 方式，c++ 需要使用 cpp 方式
          // code=cpp时需要把所有的宿主变量放入声明区：
          //   exec sql begin declare section;

// 编译
gcc 文件名 -lclntsh -lstdc++
g++ 文件名 -lclntsh

// PLSQL调用相关的预编译选项
sqlcheck=semantics
userid=用户名/密码
```

宿主变量使用的注意事项：

```c
// 1. 宿主变量强烈建议放入声明区，这样可以避免系统和语言的差异
exec sql begin declare section;
exec sql end declare section;

// 2. 宿主变量可以是指针类型，但使用之前要分配内存
Emp *emp = (Emp *)malloc(sizeof(Emp));
char *userpasswd = "openlab/open123";  // 只读

// 3. DDL 中不能使用宿主变量
char table_name[30] = "s_emp";
exec sql drop table table_name;  // 删除表 table_name
exec sql drop table s_emp;       // 删除表 s_emp

// 4. SQL 语句中使用宿主变量时，需要在宿主变量前加":"
```

## 指示变量

指示变量用于获取数据库中字段值赋值给宿主变量时的赋值的状态。

状态：

- 0：赋值正常
- -1：数据库中的字段值为 NULL
- 大于0：截断赋值(应该避免)

语法：

```c
// 指示变量必须是short类型
exec sql select 字段名 into :宿主变量 [indicator] :指示变量
from 表 where 条件;
```

## 数组变量使用的注意事项

- proc 中只支持一维数组，但是字符数组除外
- proc 中不支持数组指针(不允许指针指向数组)
- 数组的元素个数最大是 32767
- 在 select 语句使用数组变量时，出现数组名即可，不需要出现下标

## sqlca 通信区

sqlca 本质上就是一个结构体，每执行一次 sql 就会把这个结构体中的字段更新一遍。

所以 sql 执行的信息要通过 sqlca 立即获取，否则会被下次执行 sql 覆盖。

通过 sqlca 可以获取的信息：

```c
struct sqlca {
  char sqlcaid[8];
  int sqlabc;
  int sqlcode;
  struct{
    unsigned short sqlerrml;
    char sqlerrmc[70];
  } sqlerrm;
  char sqlerrp[8];    /* 系统保留 */
  int sqlerrd[6];   /* 0、1、3、5系统保留 */
  char sqlwarn[8];  /* 2、6、7系统保留 */
  char sqlext[8];   /* 系统保留 */
};

sqlca.sqlerrd[2]    // 可以获取执行每条 sql 语句的时候处理的行数
sqlca.sqlerrd[4]    // 保存相对位移，指向出现语法错误的地方
sqlca.sqlcode       // 可以获取sql语句执行的状态
                    // =0：正常， >0：发生异常，<0：系统、网络或数据库本身错误
sqlca.sqlerrm.sqlerrmc    // sql 出错的错误消息，最多记录70个字符
sqlca.sqlerrm.sqlerrml    // sql 出错的错误消息的长度
sqlwarn[8]
    // 0－指示是否设置了警告标志
    // 1－指示是否将字符结果返回给宿主变量时，数据截短了
    // 3－如果查询时，返回的列数和指定的宿主数组变量的维数不等时设置该位
    // 4－UPDATE和DELETE时没有行被处理，设置改标志位
    // 5－当EXEC SQL CREATE {PROCEDURE|FUNCTION|PACKAGE|PACKAGE|BODY}失败时设置该位
```

sqlca.sqlcode 在编程中的使用：处理事务操作。

事务操作的四大特性：

1. 原子性：事务中的语句是一个不可分割的整体
2. 一致性：事务中的语句要么一起成功、要么一起失败
3. 隔离性：事务的操作在提交之前不能被别的事务发现
4. 持久性：保证事务操作的结果今后不变

```c
update account set money = money – 5 where ano='A';
fa = sqlca.sqlcode;
update account set money = money + 5 where ano='B';
fb = sqlca.sqlcode;

if(fa == 0 && fb == 0) {
  exec sql commit;
} else {
  exec sql rollback;
}
```

## oraca 通信区

oraca 通信区是对 sqlca 通信区信息的补充，可以从 oraca 中获取执行的sql。

oraca通信区的使用：

```c
// 1. 包含
oraca(exec sql include oraca;)

// 2. 打开
oraca(exec oracle option(oraca=yes);) 

// 3. 设置 sql 的保存标志
oraca.orastxtf = n
// n = 0 默认设置(不保存 sql)
// n = 1 sql 出错保存 sql
// n = 2 sql 出现警告或错误保存 sql
// n = 3 尽最大可能保存

// 4. 获取 sql 文本
oraca.orastxt.orastxtc

// oraca 结构
struct oraca {
  char oracaid[8];  /* Reserved */
  int  oracabc;     /* Reserved */
  int  oracchf;     /* <> 0 if "check cur cache consistncy" */
  int  oradbgf;     /* <> 0 if "do DEBUG mode checking" */
  int  orahchf;     /* <> 0 if "do Heap consistency check" */
  int  orastxtf;    /* SQL stmt text flag */
  struct {
    unsigned short orastxtl;
    char  orastxtc[70];
  } orastxt;        /* text of last SQL stmt */
  struct {
    unsigned short orasfnml;
    char orasfnmc[70];
  } orasfnm;        /* name of file containing SQL stmt */
  int  oraslnr;     /* line nr-within-file of SQL stmt */
  orahoc;           /* highest max open OraCurs requested */
  oramoc;           /* max open OraCursors required */
  int  oracoc;      /* current OraCursors open */
  int  oranor;      /* nr of OraCursor re-assignments */
  int  oranpr;      /* nr of parses */
  int  oranex;      /* nr of executes */
};
// oracaid[8]：标识一个ORACA通信区
// oracabc：用于保存ORACA通信区的长度
// oradbgf：调试标志，0－关闭，1－开启
// oracchf：如果 oradbgf＝1，那 oracchf 遵循下列规则：
//     0－禁止光标缓冲一致性检查
//     1－进行光标缓冲一致性检查
// orahchf：如果 oradbgf＝1，那 oracchf 遵循下列规则：
//     0－禁止堆缓冲一致性检查
//     1－进行堆缓冲一致性检查
// orastxtf 可以是以下各值：
//     0－不保存SQL文本
//     1－仅对SQLERROR保存SQL文本
//     2－仅对SQLERROR和SQLWARNING保存SQL文本
//     3－总是保存SQL文本
```

## proc 中嵌入 sql 语句

在 proc 中使用 select 语句：

1. select 语句之前加 exec sql
2. 结合 into 把数据放入宿主变量中

DDL 语句包含 create、drop、alter；
DML 语句包含 insert、delete、update；
TCL 语句包含 commit、rollback、savepoint；

proc 中使用 DDL、DML、TCL 语句：

1. 在这些语句前加 exec sql
2. 在DDL语句中不能使用宿主变量

## proc 中调用 plsql

前提条件：plsql 的过程或者函数要先放入数据库中。

```c
exec sql execute
begin
  // 这里需要遵循 plsql 的语法
end;
end-exec;

// 注意添加和 PLSQL 调用相关的预编译选项
// 1. sqlcheck=semantics
// 2. userid=用户名/密码 (编译时连接数据库，以此确认程序)
```

## 数据库的连接

本地连接：

```c
exec sql connect:userpasswd;
exec sql connect:username identified by:userpasswd;
echo $ORACLE_SID    // 获得服务名
```

远程连接：

```c
// 相关文件
// $ORACLE_HOME/network/admin/tnsnames.ora 文件内容：
//   DB20 =  /* 远程数据库描述 */
//   (DESCRIPTION = (ADDRESS = (PROTOCOL = TCP)(HOST = 172.30.13.20)
//   (PORT = 1521)) (CONNECT_DATA = (SERVER = DEDICATED) (SERVICE_NAME = orcl)))


// 使用 using 加 at 的方式连接
exec sql connect:用户名/密码 at:标签 using:远程数据库描述;
// 用户名/密码、标签、远程数据库描述都可以存储在数组中
// 然后用户名/密码用于登录、标签用于区分不同的连接、远程数据库描述在上述的文件中
// 注意：操作多个数据库时，需要连接多个数据库，因此也要多次断开连接

char userpasswd[30]=”openlab/open123”;
char db330[30]=”db330”;
char db730[30]=”db730”
char rdbdesc[30]=”db730”;
char var_name[30]={};
exec sql connect:userpasswd at:db730 using:rdbdesc;
exec sql connect:userpasswd at:db330;
exec sql at:db730 select first_name into :var_name from s_emp where id=1;
exec sql at:db330 select first_name into :var_name from s_emp where id=1;
exec sql at:db330 commit work release;
exec sql at:db730 commit work release;

// 使用database link
grant create database link to openlab; // 授权创建数据库连接的权限给用户 openlab
create database link db10todb20link
connect to openlab
identified by 'open123'
using 'DB20'; // 建立到数据库的连接
exec sql select first_name into :var_name from s_emp where id=1;
exec sql select first_name into :var_name
from s_emp@db10todb20link set salary=salary+3000 where id=1;
exec sql update s_emp@db10todb20link set salary=salary+3000 where id=1;
exec sql commit;
// 该方法只进行了一次本地连接，事务处理和断开连接都只有本地的
```

## proc 中的错误处理

局部错误处理：`sqlca.sqlcode`，类似于C语言的处理方式。

全局错误处理：

```c
exec sql whenever 条件 动作;
// 条件：sqlerror、notfound、sqlwarning
// 动作：
//     do 函数();    调用一个函数
//     do break;    终止一个循环
//     continue;    忽略问题继续运行
//     stop;        终止程序
//     goto 标签名;  跳转程序到标签位置处 
exec sql whenever sqlerror do processError();
exec sql whenever notfound do processNot();
exec sql whenever notfound do break;
// 当 sql 出现错误时，就向上找相应的 whenever 语句：
//   找到匹配的就进行相应的处理
//   找不到匹配的就采用默认的忽略错误的方式继续运行
```

## proc 中的数据处理

使用单个变量操作单行单列：

```c
exec sql select first_name into :var_name from s_emp where id = 1;
```

使用多个变量操作单行多列：

```c
exec sql select id, first_name, salary into :id, :name, :salary
from s_emp where id = 1;
```

结构体替代多个变量，操作单行多列；结构体数组可以操作多行多列：

```c
struct {
  int id;
  char name[30];
  float salary;
} emp;
```

游标操作多行多列：

```c
// 1. 声明游标
exec sql declare 游标名 cursor for select语句;

// 2. 打开游标
exec sql open 游标名;

// 3. 处理数据
exec sql fetch 游标名 into :结构体变量;

// 4. 关闭游标
exec sql close 游标名;

// 5. 提取游标中所有数据：采用出错机制
exec sql whenever not found do break;

// 6. 滚动游标 scroll cursor，滚动游标可以不按照顺序来提取游标中的数据
fetch last          // 提取最后一条
fetch first         // 提取第一条
fetch prior         // 提取当前行的前一行
fetch next          // 提取当前行的后一行
fetch current       // 提取当前行
fetch absolute n    // 绝对行目
fetch relative n    // 相对当前行隔了几行
                    // n = 1   下一行
                    // n = -1  上一行
                    // n = 0   当前行
```

## 动态 sql

在程序执行的过程中，sql 语句可以根据条件发生改变。

一共有三种动态sql：

```c
// 1.
// 要求：不能是 select 语句，不能有占位符(不能含有宿主变量)
// 实现：把要执行的指令作成字符串
// 语法：
exec sql execute immediate :sqlstr;

// 2.
// 要求：不能是 select 语句、可以有占位符
// 语法：
sprintf(sqlstr, "%s", "insert into s_emp values(:b0, :b1)"); // 带有占位符的字符串要先进行预处理
exec sql prepare s from :sqlstr;
// 执行：
exec sql execute s using :变量1, :变量2;

// 3.
// 要求：只能是 select 语句、可以有占位符
// 使用 PREPARE 命令准备 SQL 语句
EXEC SQL PREPARE statement_name FROM :host_string;
//   statement_name: 标识符，
//   host_string：含SQL语句的字符串
// 定义和使用游标
EXEC SQL DECLARE cursor_name CURSOR FOR statement_name;
EXEC SQL OPEN cursor_name [using host_variable_list];
EXEC SQL FETCH cursor_name INTO host_variable_list;
EXEC SQL CLOSE cursor_name;

char sqlstr[100] = "select id, first_name, salary from s_emp where id > :b0";
exec sql prepare s from :sqlstr;            // 把s关联到一个游标上
exec sql declare empcursor cursor for s;    // 打开游标，传入参数
exec sql open empcursor using :id;
```
