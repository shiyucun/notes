
# SCRAPY框架爬虫

- [SCRAPY框架爬虫](#scrapy框架爬虫)
  - [Scrapy的组件及架构图](#scrapy的组件及架构图)
  - [安装](#安装)
  - [使用](#使用)

SCRAPY框架是用Python实现的一个为了爬取网站数据、提取结构性数据而编写的应用框架。

框架本身已经实现了一些重复性的工作。

我们只需要按照框架本身写几个简单的模块或者简单的扩展一些模块就可以你个性化自己的功能。

## Scrapy的组件及架构图

![image](https://doc.scrapy.org/en/latest/_images/scrapy_architecture_02.png)

- Engine(引擎)：
  - 负责Spiders、ItemPipelines、Downloader、Scheduler之间的通讯
  - 负责信号、数据传递等
- Scheduler(调度器)：
  - 负责接收引擎发送过来Requests请求
  - 按照一定的方式对请求进行整理、排列、入队
  - 当引擎需要时交还给引擎
- Downloader(下载器)：
  - 负责下载引擎发送的所有Requests请求
  - 将获取到的Responses交还给Scrapy
  - 由引擎交给Spiders来处理。
- Spiders(爬虫)：
  - 负责处理所有Responses
  - 从中分析提取数据，获取Items字段需要的数据
  - 将需要跟进的URL提交给引擎，再次进入调度器
- Item Pipelines(管道)：
  - 负责处理Spiders中获取到的Items
  - 进行后期处理的地方(详细分析、过滤、存储等)
- Downloader Middleware(下载中间件)：
  - 可以当作是一个可以自定义扩展下载功能的组件
- Spiders Middleware(Spiders中间件)：
  - 可以自定扩展或操作引擎与Spiders中间通信的功能组件

## 安装

```shell
# Ubuntu
sudo apt-get install python-dev python-pip libxml2-dev libxslt1-dev
sudo pip install scrapy
```

## 使用

1. 新建一个新的爬虫项目，一个项目可能包含很多个爬虫，依次执行命令：

```shell
"mkdir ~/Spider"
"cd ~/Spider"
"scrapy startproject tencentSpider"
"cd tencentSpider"
```

查看项目结构：

```shell
tree
.
├── scrapy.cfg
└── tencentSpider
    ├── __init__.py
    ├── items.py
    ├── middlewares.py
    ├── pipelines.py
    ├── settings.py
    └── spiders
        └── __init__.py

2 directories, 7 files
```

2. 明确要抓取的目标，生产一个具体的爬虫，命令`scrapy genspider tencent`

查看项目结构：

```shell
tree
├── scrapy.cfg
├── tecentLog.txt
└── tencentSpider
    ├── __init__.py
    ├── __init__.pyc
    ├── items.py
    ├── middlewares.py
    ├── pipelines.py
    ├── settings.py
    ├── settings.pyc
    └── spiders
        ├── __init__.py
        ├── __init__.pyc
        └── tecent.py
2 directories, 12 files
```

下面需要具体取修改代码逻辑，按照需求实现爬虫逻辑：

- `setttings.py`设置
- `pipelines.py`保存的逻辑
- `tecent.py`抓取页面信息和继续跳转的逻辑
- `items.py`保存item的映射

3. 制作爬虫 (spiders/tencent.py)：制作爬虫开始爬取网页
4. 存储内容 (pipelines.py)：设计管道存储爬取内容
5. 在Scrapy下启动爬虫：命令`scrapy crawl tencent`
