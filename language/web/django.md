
# Django

- [Django](#django)
  - [优缺点](#优缺点)
  - [安装](#安装)
  - [创建django项目并启用服务](#创建django项目并启用服务)
  - [django结构](#django结构)
  - [manage.py和django-admin](#managepy和django-admin)
  - [URL的使用](#url的使用)
  - [django中的应用](#django中的应用)
  - [django模板(Tempate)](#django模板tempate)
  - [模板的语法](#模板的语法)
  - [静态文件的处理](#静态文件的处理)
  - [模型-ORM(Model)](#模型-ormmodel)
  - [模型的数据库操作方法(CRUD)](#模型的数据库操作方法crud)
  - [admin后台管理](#admin后台管理)
  - [django联合查询](#django联合查询)
  - [Model高级应用(自定义查询对象objects)](#model高级应用自定义查询对象objects)
  - [HttpRequest](#httprequest)
  - [使用`a`标记拼接地址栏参数](#使用a标记拼接地址栏参数)
  - [使用forms模块处理form表单](#使用forms模块处理form表单)
  - [内置小部件(widgets)](#内置小部件widgets)
  - [cookies \& session](#cookies--session)
    - [cookies](#cookies)
    - [session](#session)

Django 是一个 Python 语言开发的开源框架，后台管理系统非常强大，采用了 MTV 框架模式。

**参考资料**：

[djangobook2](http://docs.30c.org/djangobook2/)
[djangoproject](https://docs.djangoproject.com/en/1.11/)

## 优缺点

**优点**：

- 开源框架，文档支持完美
- 解决方案众多，内部功能支持较多
- 路由系统完整
- 自助式的后台管理

**缺点**：耦合度偏高

## 安装

查看已安装的django：

1. 执行`python3`
2. 输入`import django`(报错说明未安装)
3. 输入`django.VERSION`(输出`django`版本)

在线安装：

```shell
sudo pip3 install django          # 最新版本
sudo pip3 install django==1.11.8  # 指定版本
```

离线安装：

1. <https://www.djangoproject.com/> 下载`django`安装包
2. `tar -xvf Django-1.11.8.tar.gz`解压
3. `cd Django-1.11.8`进入到文件夹
4. `sudo python3 setup.py install`安装

## 创建django项目并启用服务

在`/usr/local/bin`目录下有两个文件：`django-admin`和`django-admin.py`。

因为在环境变量中已经添加了`django-admin`文件，因此在任何位置处都允许直接使用其来创建项目。

**创建django项目**：

```shell
mkdir django
cd django
django-admin startproject syc
```

**启动服务**：

```shell
cd syc
./manage.py runserver  # 只能在本机访问
./manage.py runserver 0.0.0.0:8000  # 在局域网内可通过任何表示主机的方式访问
```

**使用浏览器访问**：

1. <http://localhost:8000>
2. <http://127.0.0.1:8000>

**注意**：

`Linux 16.04`中默认安装了`Python2`，需要`Python3`运行`Django`时需修改`manage.py`并重新启动服务：

```python
#!/usr/bin/env python  -> #!/usr/bin/env python3
```

## django结构

1. `manage.py`负责执行`django`中各项操作的文件(命令脚本文件)
2. 主文件夹(名称与项目名称相同)
    1. `__init__.py`项目初始化文件，每当服务被启动时执行一次
    2. `urls.py`项目基础`url`(路由)配置文件(执行程序的位置)
    3. `wsgi.py`配置应用服务器
    4. `settings.py`项目主设置文件：语言，时区，应用，模板，...
       - `BASE_DIR`：项目所在的绝对路径
       - `DEBUG`：调试模式(开发过程时置True，上线必须置为False)
       - `ALLOWED_HOSTS`：可访问项目的地址列表，不设置则只有`localhost`和`127.0.0.1`可访问，推荐写`*`
       - `INSTALLED_APPS`：已安装的应用，自己创建应用时需在此注册
       - `MIDDLEWARE`：中间件
       - `ROOT_URLCONF`：指定项目基础路由配置文件
       - `TEMPLATES`：指定模板的相关信息
       - `DATABASES`：指定数据库的相关信息
       - `LANGUAGE_CODE`：指定语言，汉字(zh-hans)
       - `TIME_ZONE`：指定时区，中国上海(Asia/Shanghai)
       - `STATIC_URL`：指定静态文件路径

`settings`加载流程：

1. 先加载`global_settings`
    - 文件位于：`/usr/local/lib/python3.5/dist-package/django/conf`
2. 再加载本项目`settings`

**注意**：当`global_settings`与项目`settings`冲突时，优先使用`settings`。

## manage.py和django-admin

终端中进入到项目文件夹并输入`./manage.py`可以得到：

```text
    [auth]
              changepassword : 修改后台管理用户密码
              createsuperuser : 创建后台管理用户
    [contenttypes]
              remove_stale_contenttypes
    [django]
              check ：检查项目的完整性
              compilemessages ：编译语言文件(国际化)
              createcachetable ：创建缓存表
              dbshell ：进入Django 数据shell交互模式
              diffsettings
              dumpdata ：导出数据
              flush ：清空数据
              inspectdb ：将数据库表导出为Models
              loaddata
              makemessages
              makemigrations ：创建数据库日志文件，记录Models改动
              migrate ：根据日志同步数据库
              sendtestemail
              shell
              showmigrations
              sqlflush
              sqlmigrate
              sqlsequencereset
              squashmigrations
              startapp ：创建一个应用
              startproject
              test
              testserver
    [sessions]
              clearsessions
    [staticfiles]
              collectstatic ：收集所有静态文件到指定文件夹中
              findstatic ：查找静态文件
              runserver ：启动服务器
```

在 linux 终端中直接输入`django-admin`，可以得到：

```text
    check
    compilemessages
    createcachetable
    dbshell
    diffsettings
    dumpdata
    flush
    inspectdb
    loaddata
    makemessages
    makemigrations
    migrate
    runserver
    sendtestemail
    shell
    showmigrations
    sqlflush
    sqlmigrate
    sqlsequencereset
    squashmigrations
    startapp
    startproject
    test
    testserver
```

## URL的使用

`urls.py`默认在主文件夹中，包含所有的地址映射。

当一个请求产生后，会到`urls.py`中进行地址匹配，匹配上之后再找到对应的处理程序(View视图)执行。

**测试**：

首先使用命令`django-admin startproject`创建一个项目。

然后创建`views.py`文件，用于包含所有定义好的视图(处理程序)，如下：

```python
from django.http import HttpResponse

def fun(request):
    return HttpResponse("Hello Django");
```

之后在`urls.py`中追加：

```python
from .views import fun

urlpatterns = [
    url(r'^admin/', admin.site.urls),
    url(r'^fun/$', fun)
]
```

**URL使用过程**：

1. 请求产生后，首先会查询路由列表(`urls.py`的`urlpattern`列表)，得到对应的`URL`函数
2. 查询过程中会与路由列表项依次匹配，能够匹配上多个时只执行第一个，不再向下匹配
3. 然后去执行对应`view`匹配到的函数
4. 最后将结果响应给客户端

**URL函数**：

```python
url(regex, views, kwards=None, name=None)
# regex：正则表达式，用来匹配 request 请求的 URL
# views：URL 处理的视图函数，可以是自己写的，也可以是系统自带的
# kwards：字典，用来向 views 传参
# name：给当前的 URL 起一个名字，通常会配合着模板中的标签 {%url%} 使用
```

**URL向view传参**：

使用正则表达式的子组传参，使用`()`，如下：

```python
urlpatterns = [
    ...
    url(r'^(argument)$', get_arg0),  # 子组字符串 argument，且只匹配该字符串
]

# 在 view.py 中添加以下函数
def get_arg0(request, arg):
    return HttpResponse()
```

注意：

1. 在 url 中，一个子组`()`表示一个参数
2. `view.py`对应的处理函数要根据 url 参数(子组)的个数定义参数
3. 定义的参数要位于 request 之后

指定url函数的第三个参数(字典传参)，如下：

```python
urlpatterns += [
    ...
    url(r'^shownames/$', shownames, {'name':'zsf', 'age':'25'})
]

# 在 view.py 中添加以下函数
def shownames(request, name, age):
    return HttpResponse(name + ":" + age)
```

## django中的应用

应用表示的就是网站中一个独立的模块，包含独立的信息。

例如网易，是一个网站，是一个完整的项目，该网站可能会包含新闻，娱乐，体育，财经等不同的频道。

这些频道在 django 或网站中，可以被称为 "应用"。

在整个项目的主文件夹中不要去处理其他的请求，主文件夹只做主要设置以及应用地址的分发。

**创建应用**：

命令：`./manage.py startapp 应用名称`。

在项目中的体现：会出现一个应用的文件夹，文件夹中会包含应用的配置的文件。

需要在`settings.py`中注册应用：在`INSTALLED_APPS`中追加应用名称即可，如下：

```python
INSTALLED_APPS = [
  'django.contrib.admin',
  ...
  '应用名称',
]
```

**应用的结构组成**：

- `migrations文件夹`：存放数据库日志文件，是一个django与数据库交互的中间文件
- `__init__.py`：初始化应用的`py`文件
- `admin.py`：与后台管理相关的`py`文件
- `apps.py`：应用属性设置文件，不需要改
- `models.py`：Models模型文件
- `tests.py`：测试模块，通常不用
- `views.py`：定义视图的`py`文件

**应用中的URL**：

作用：应用中的url负责匹配当前应用中的视图。

由于应用中默认不带`urls.py` 文件，所以该文件需要手动添加。

添加`urls.py`文件：

```python
from django.conf.urls import url

urlpatterns = [
  ...
  url(r'^music/', include(music_urls)),
]
```

## django模板(Tempate)

模板就是一个网页文件，可以被`view`响应给用户，模板解决了复杂的显示问题。

**模板的设置**：

在主设置文件`settings.py`中，增加对模板的设置：

- `BACKEND`：模板的搜索引擎，无需改动
- `DIRS`：指定模板所存放的位置，DIRS = ['index.temp','music.temp']
  - 如果 DIRS 中不写任何内容时 django 会自动搜索一个叫`tempaltes`的文件夹
  - 因此 DIRS 中可以什么都不写，然后在每个应用中创建一个`templates`文件夹，并将模板保存于此
- `APP_DIRS`：True，首先从 DIRS 指定的文件夹查找模板，否则直接到 templates 查找

设置如下：

```python
TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'DIRS': [],
        'APP_DIRS': True,
        'OPTIONS': {
            'context_processors': [
                'django.template.context_processors.debug',
                'django.template.context_processors.request',
                'django.contrib.auth.context_processors.auth',
                'django.contrib.messages.context_processors.messages',
            ],
        },
    },
]
```

**模板的加载方式**：

方法1：使用`HttpResponse`直接加载字符串。

```python
return HttpResponse("... ...")
```

方法2：使用`loader`获取模板，通过`HttpResponse`进行响应。

```python
from django.template import loader

def xxx(request):
    t = loader.get_template('show.html')
    html = t.render({})
    return HttpResponse(html)
```

方法3：使用`render`直接加载。

```python
return render(request, '模板名称', 参数字典)
# 参数字典：用于传递参数，等于 locals() 时，会将函数内部的 locals 变量传给调用者
```

方法4：路由文件中`url`函数中的`name`参数。

```python
url(regex, views, kwards=None, name=None)
```

name 参数允许为当前的 url 起一个名字。

确保能够 Template、Models、Views 在任何情况下都能找到对应的 url 请求地址。

以上 url 请求地址匹配模式有可能会发生改变。

使用方式：

1. 为 url 函数增加 name 参数，并起名
2. 在模板中有以下两种方式：
    - `{%url 'name'%}`该标签表示的就是`name`所对应的地址匹配模式
    - `{%url 'name' 参数1 参数2 %}`

## 模板的语法

**变量**：

允许将后端的数据传递给模板(html)，html会根据变量的值来显示内容。

允许作为变量传递给模板的类型有数字，字符串，列表，元组，字典(集合)，函数，对象等。

获取变量值的语法：`{{变量名}}`。

**标签**：

允许嵌套与服务器相关的内容到标签中。

每个标签表示的都是独立的功能，由服务器解释执行。

语法：`{% ... %}`。

常用的标签：

```js
{%if 条件%} ... {%endif%}
{%if 条件%} ... {%else%} ... {%endif%}
{%ifequal 值1 值2%} ... {%endifequal%}
{%ifequal 值1 值2%} ... {%else%} ... {%endifequal%}

// 以上
// 可以接收 not、and、or
// 不支持 and 和 or 同时出现
// 空[]、空()、空{}、空字符串、零、None 当做 False 处理


{%for 变量 in 元组|字典%} ... {%endfor%}

forloop.counter      // 记录循环的次数
forloop.counter0     // 同上，但从 0 开始
forloop.revcounter   // 记录未被遍历的项目数
forloop.revcounter0
forloop.first        // 布尔值，标记是否为第一个项目(第一次遍历)
forloop.last         // 布尔值，标记是否为最后一个项目(最后一次遍历)
```

**过滤器**：

在显示数据前，对数据进行改变。

常用过滤器：

```js
{{var | upper}}  // 将 var 变量的值变为大写
{{var | lower}}  // 将 var 变量的值变为小写
```

## 静态文件的处理

静态文件指的是模板中要用到的css、js、image等一些普通文件。

django中通过相对路径和绝对路径获取不到静态文件，可通过特殊的静态文件设置访问静态文件。

在`settings.py`中设置静态文件：

- `STATIC_ROOT`：在部署时，将静态文件收集到的位置
- `STATIC_URL`：指定访问静态文件的路径
- `STATICFILES_DIRS`：指定开发阶段中，所有的静态文件所存放的位置
  - `STATICFILES_DIRS = (BASE_DIR, 'static')`

使用静态文件：

1. 使用文件的最顶层：`{%load static%}`
2. 使用时：`<img src="{%static 'images/food.jpg'%}">`

## 模型-ORM(Model)

模型就是根据数据中的表结构而创建出来的 class。

数据库中的每张表都可以被映射成一个 class，表中的每个字段都可以被映射成一个属性。

表名可以被构建成 class name，表中的字段，可以被构建成 class 中的一个属性(名称一致)。

可以对数据进行CRUD的操作。

C：Create、R：Retrieve、U：Update、D：Delete

**如何创建和使用模型**：

ORM ：Object Relational Mapping，对象关系映射，简称 ORM。

ORM可以提高开发效率，可以自动对实体对象与数据库中的 Table 进行字段与属性的映射。

因此可以省略庞大的数据访问层。

使用ORM可以不用 SQL 编码而直接对数据库进行 CRUD 操作。

第一步：**创建和配置mysql数据库**。

创建一个数据库：

```sql
create database webdb default charset utf8 collate utf8_general_ci;
```

在`settings.py`中配置数据库：

```python
DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',  # 数据库引擎
        'NAME': 'webdb',                       # 数据库名称
        'USER': 'root',                        # 用户名
        'PASSWORD': '123456',                  # 密码
        'HOST': 'localhost',                   # 主机
        'PORT': '3306'                         # 端口号
    }
}
```

第二步：**编写Model**。

每个类必须继承自`models.Model`，定义类如下：

```python
class Publish(models.Model):
    name = models.CharFiled(max_length=30)
    address = models.CharField(max_length=50)
    city = models.CharField(max_length=60)
    country = models.CharField(max_length=50)
    website = models.URLFied()
```

以上每个字段需要指定数据类型。

django支持的数据类型如下：

- BooleanField
- CharField
- DateField
- DateTimeField
- EmailField
- FileField
- ImageField
- TextField
- URLField
- ...

每个字段还可以指定属性。

django支持的属性如下：

- null：判断是否为空，如：
  - name=models.CharField(max_length=20, null=True)
- blank：后台填写的数据是否可以为空白
- choices：作为数据选项
- default：设置默认值
- primary_key：标识主键
- verbose_name：为字段起别名
- db_column ：指定列名
- db_index：指定列的顺序

第三步：**数据库的同步操作**。

`./manage.py makemigrations`

作用：将每个应用下的`models.py`映射生成一个日志文件，存放在`migrations`文件夹中。

`./manage.py migrate`

作用：将每个应用下的`migrations`中的日志文件同步到数据库中。

第四步：**数据的导入导出(数据迁移)及版本切换**。

`./manage.py migrate 应用名称 版本号`

作用：在终端中做版本切换，在django中想恢复到之前的数据库操作可以使用此命令。

`./manage.py inspectdb > 文件名.py`

作用：在终端中通过数据库自动导出`Models`。

`mysqldump -u root -p [-d] 数据库名 > 文件名.sql`

作用：在终端中将数据库导出为sql文件，`[-d]`为可选项：

- 没有`-d`选项导出表结构和数据
- 有`-d`选项只导出表结构

`mysql -u root -p 数据库名 < 文件名.sql`

作用：在终端中将`sql`文件导入数据库(需提前创建数据库)。

## 模型的数据库操作方法(CRUD)

**在视图中增加数据**：

方法1：

```python
Entry.objects.create(属性=值, 属性=值)
```

方法2：

```python
# 创建一个实体对象，并通过save()完成增加操作
obj = Entry(属性=值, 属性=值)
obj.save()
```

方法3：

```python
# 通过字典传参
dic = {"key1":"value1", "key2":"value2" ...}
obj = Entry(**dic)
obj.save()
```

**查询操作**：

在 view 中完成，并将查询结果放在 Template 中显示，所有的查询都要在`Entry.objects`的基础上完成。

`Entry.objects.all()`

作用：查找数据库表的所有记录。

`Entry.objects.values('name')`

作用：查询所有行某一列的值。

`Entry.objects.get(id=1)`

作用：查找一条记录，只能返回一条记录，如果返回多条则报错。

`filter()`

作用：自定义查找条件，可以给多个条件，如果是多条件，则使用`AND`连接。

举例：

```python
# 有Entry的属性作为filter的条件
# select * from author where name='xx'
Author.objects.filter(name='xx')
# select * from author where name='xx' and age=15
Author.objects.filter(name='xx', age=15)

# 使用Field Lookups
# select * from * where id>4
Author.objects.filter(id__gt=4)
# select * from * where id=5
Author.objects.filter(id__exact=5);
# select * from * where name like '%zh%'
Author.objects.filter(name__contains='zh')
# select * from * where id in (1,2,3)
Author.objects.filter(id__in=[1,2,3])

inner_query = Author.objects.filter(name__exact='syc').values('age')
authors = Author.objects.filter(age__gt=inner_query)
```

`exclude()`

作用：对条件取反。

举例：

```python
# select * from author where not(name='zh' and age=28)
Author.objects.exclude(name='zh', age=28)
```

`order_by()`

作用：按指定的字段进行排序，多个字段排序时用`,`分隔，默认升序排序，降序在名称前添加`-`。

用法：`Author.objects.order_by('-name','-age')`

**修改接口**：

修改单个对象，先通过`get`获取到响应的`Model`对象，再修改对象值，最后调对象的save()函数。

举例：

```python
obj=Author.objects.get(id=1)
obj.name = "张三"
obj.age = 29
obj.save()
```

批量修改(修改结果集的值)，调用`update()` 函数：`Entry.objects.all().update(字段='值', ...)`。

**删除接口**：

删除单个对象，获取删除的对象之后调用`delete()`函数。

举例：

```python
obj = Entry.object.get(id=1)
obj.delete()
```

批量删除，得到查询结果集之后调用`delete()`函数：`Entry.objects.all().delete()`。

**`F()`操作和`Q()`操作**：

`F()`操作

作用：获取对象中某列的值，对整列值进行操作。

语法：`F('列名')`

举例：

```python
from django.db.model import F

def do_F(request):
    authors = Author.objects.all();
    authors.update(age = F('age')+10)
    return HttpResponse("...");
```

`Q()`操作

作用：对对象进行复杂操作，自定义关联多个查询条件。

举例：

```python
def doQ(request):
    q = Q()
    q.connector = 'AND' # 指定查询的关联条件
    q.children.append(('id', 2))
    q.children.append(('age', 25))
    authors = Author.objects.filter(q)
    return render(...)
```

**原生的数据库操作**：

查询函数：`raw()`

语法：`Entry.objects.raw(sql语句)`

增删改：

```python
def sql(request):
    with connection.cursor() as cursor:
        sql = 'delete from index_author where id=5'
        cursor.execute(sql)
        return render(...)
```

## admin后台管理

后台登录地址：<http://localhost:8000/admin>

**创建后台管理员(超级用户)**：

`./manage.py createsuperuser`

**`admin.py`**：用于注册需要管理的 Model，只有在此注册的 Model 才能被后台管理。

**注册 Model**：

```python
from .models import *

admin.site.register(Entry)
```

**`models.py`**：

后台数据显示的默认效果可读性不高。

`models.py`中各个class中追加`__str__`函数可以提高后台显示可读性。

如下：

```python
def __str__(self):
    return self.name
```

`models.py`的各个`class`中通过定义内部类可以修改`web`页面中展现的属性值。

`model`类内部类为`Meta`。内部类成员如下：

- `db_table`：指定数据表的名字，与数据库有关
- `ordering`：指定排序字段，值为一个列表，默认升序排序，加'-'表示降序
- `verbose_name`：单数形式，定义在admin中显示的名字
- `verbose_name_plural`：复数形式，可设置
  - verbose_name_plural=verbose_name

举例：

```python
class Meta:
    db_table = 'author'
    ordering = ['-age', 'name']
    verbose_name = '作者'
    verbose_name_plural = verbose_name
```

**高级管理**：

`admin.py`中创建自定义管理类可以实现高级功能。

定义`EntryAdmin`类，继承自`admin.ModelAdmin`，如下：

```python
class EntryAdmin(admin.ModelAdin):
    ...
    admin.site.register(Entry, EntryAdmin)
```

允许增加的属性：

- `list_display`：响应页面展示的字段，取值可以是由属性名称所组成的元组
- `list_display_links`：生成超链接，展示具体信息，取值必须要出现在`list_display`中
- `list_editable`：定义可以直接在外层修改的字段，取值不能出现在`list_display_links`
- `search_fields`：添加允许被搜索的字段
- `list_filter`：右边增加一个过滤器，取值是由属性名组成的元组
- `date_hierarchy`：顶部增加事件选择器，所以取值必须是`DateField`的字符串
- `fields`：指定页面上显示的属性以及显示顺序
- `fieldsets`：对现有的显示属性进行分组，如下：

```python
fieldsets = (
    元组1 - ('分组名称', {'fields':(), 'classes':('collapse')})
    元组2 - ()
)
```

## django联合查询

**一对一查询**：

A表中的一条记录，只能与B表中的一条记录进行匹配；在数据库中B表会存储A表的主键。

语法：`models.OneToOneField(Entry)`。

查询：

```python
class Name:
    ...
    # 在 Name 中添加了对其它表字段的引用
    age = models.OneToOneField(Age)

    # 正向查询：通过 Name 查找 age
    name = Name.objects.get(id=1)
    age = name.Age
    
    # 反向查询：通过 age 找 Name
    age = Age.objects.get(id=9)
    name = age.Name
```

**一对多/多对一查询**：

A表中的一条数据可以与B表中的任意多条记录匹配；数据库中通过外键约束实现一对多效果。

语法：`name = models.ForeignKey(Entry)`。

查询：

```python
class Book(models.Model):
    ...
    author = models.ForeignKey(Author)

    # 正向查询
    book = Book.objects.get(id=1)
    author = book.author
    
    # 反向查询
    author = Author.objects.get(id=9)
    books = author.book_set.all()
```

**多对多查询**：

- A表的一条记录可以与B表的任意多条记录匹配
- B表的一条记录也可以与A表的任意多条记录匹配
- 数据库通过创建中间表的方式来完成该操作

语法：`models.ManyToManyField()` --> 任一个实体类中使用该语句都会创建中间表。

查询：

```python
class Author(models.Model):
    ....
    publish = models.ManyToManyField(Publish)

    # 正向查询 - 在 Author 中查询 Publish
    author = Author.objects.get(id=9)
    pub_list = author.publish.all()  # 通过关联属性.all()
    
    # 反向查询 - 在 Publish 中查询 Author
    pub = Publish.objects.get(id=1)
    au_list = pub.author_set.all()
```

## Model高级应用(自定义查询对象objects)

自定义objects对象取代默认的objects，允许在自定义的objects上增加自定义函数。

目的是为了扩充原有objects的功能。

步骤：

第1步：声明类`EntryManager`，继承自`models.Manager`，并添加自定义函数：

```python
class EntryManager(models.Manager):
    def 函数名(self,自定义参数)
        ...
        return ...
```

第2步：将`EntryManager`与`Entry`相结合：

```python
class Entry(models.Model):
    objects = EntryManager()
```

## HttpRequest

`HttpRequest`是请求对象，封装了请求过程中的信息，如：请求地址，源请求路径，请求参数等。

在`django`中，`HttpRequest`默认被作为每个视图处理函数的参数传递进来。

查看`request`的内容：`print(dir(request))`。

主要内容：

- `request.scheme`：请求的协议
- `request.body`：请求的主体
- `request.path`：请求的路径
- `request.get_host()`：请求的主机地址/域名
- `request.method`：请求的方法
- `request.GET`：向服务器请求数据
- `request.POST`：发送数据到服务器处理
- `request.COOKIES`：cookies的数据
- `request.META`：获取元数据

每个请求一定会有`method`，只有`post`和`put`才会产生请求主体，其余请求方法都没有请求主体。

当发生`GET`请求时，可以通过`request.GET['名称']`的方式来获取请求提交的数据。

`POST`获取数据：

```python
if request.method == 'POST':
    if 'name' in request.POST and request.POST['name']
        value = request.POST['name']
        return HttpResponse(value)
    else:
        return HttpResponse("方式不对!")
```

## 使用`a`标记拼接地址栏参数

- `<a href="/index/anchor/?name=v&age=12">xxx</a>`
  - `?`：表示后面的是要提交的参数
  - `name`：提交的参数名称为 name ，值为 v
  - `&`：表示关联，即后面还有要提交的参数
  - `age`：提交的参数名称为 age ， 值为 12

## 使用forms模块处理form表单

自定义 forms 模块(`forms.py`)是一个与表单关联的 python 文件。

文件内允许根据表单创建 class，一个 class 对应网页上一个表单，class 要继承自`forms.Form`。

使用时，通过`views`找到`forms`，再发送给模板，并自动生成表单。

**操作**：

创建`forms.py`，并创建对应的 class，继承自`forms.Form`。

创建属性，一个属性对应这样一个表单控件：`subject=forms.CharField(label='标题')`。

在 views 中，创建`forms.Form`的对象，并发送给模板。

模板中，可以对`forms.Form`对象进行解析。

注意：需要自己创建`<form>`和提交按钮。

**处理方式**：

```js
{%for field in form%}
    {{field.label}}:{{field}}
{%endfor%}

{{form.as_table}}
    {{form.as_p}}
{{form.as_ul}}
```

在 HTML 中提交的表单也可以传递给`forms.Form`：

```python
form = EntryForm(request.POST)
if request.method == 'POST':
    form = XXXForm(request.POST)
    if form.is_valid():       # 必须要经过验证
        cd=form.cleaned_data  # 封装提交的数据
        print(cd['subject'])
        ...
```

**form 的高级表单处理**：

将 model 和 form 结合到一起使用，通过model类自动生成表单。

在`forms.py`中实现下列操作：

创建 class，`EntryForm(forms.ModelForm)`。

创建内部类 Meta，并定义相关信息：

- `model`：指定关联的 Model 是哪个
- `fields`：指定列表，声明要生成表单控件的属性
  - `__all__`：全部属性都生成表单控件
- `labels`字典，如下：

```json
{
  '属性1':'标签1',
  '属性2':'标签2',
}
```

## 内置小部件(widgets)

widgets 在 django 中对应表单控件元素。

如果自己指定控件的话，需要通过小部件进行关联，并且也允许为控件指定属性。

**常用小部件**：

- `TextInput`：type='text'
- `NumberInput`：type='number'
- `EmailInput`：type='email'
- `URLInput`：type="url"
- `PasswordInput`：type='password'
- `HiddenInput`：type='hidden'
- `CheckboxInput`：type='checkbox'
- `Textarea`：`<textarea></textarea>`
- `Select`：`<select>`

**小部件的使用**：

```python
forms.Form
subject=forms.CharField(
    label='',
    widget=forms.TextInput(
        attrs={
            'class':'form-control',
            'placeholder':'Input your subject',
        }
))

forms.ModelForm
class AuthorForm(forms.ModelForm):
    class Meta:
        model = Author
        fields = "__all__"
        labels = {'name':'姓名',}
        widgets = {'name':forms.TextInput(attrs={'class':'form-control',})}
```

## cookies & session

### cookies

cookies 是一段保存在客户端(浏览器)上的文本，记录一些与用户相关的信息，可长时间保存。

例如：保存登录信息和用户喜好。

django 中设置 cookies：

- 不使用模板

```python
    response = HttpResponse('xxx')
    response.set_cookie(key, value, expires)
        # key: cookie 的名称
        # value: cookie 的值
        # expires: 保存时间 以 s 为单位
```

- 使用模板

```python
    response=render_to_response('xx.html',{})
    response.set_cookie(key, value, expires)
    return response
```

- 重定向

```python
    response = HttpResponseRedirect(地址)
    response.set_cookie(key, value, expires)
    return response
```

django 中获取 cookies：`request.COOKIES`。

### session

session(会话)，是服务器为每个浏览器临时开辟的空间，保存用户的临时信息。

django 中设置 session 值：

```python
request.session['key'] = value
request.session.set_expiry(time)  # 设置过期时间，如果设置为0的话则关闭，浏览器失效
```

django 中获取 session 值：`request.session.get('key')`。

django 中删除 session 值：`del request.session['key']`。

`settings.py` 中可以追加与 session 相关的设置变量，如下：

```text
SESSION_COOKIE_AGE=60*30
SESSION_EXPIRE_AT_BROWSER_CLOSE=True
```
