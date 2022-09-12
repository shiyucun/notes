
# HTTP和HTTPS

- [HTTP和HTTPS](#http和https)
  - [关于URL](#关于url)
  - [HTTP和HTTPS协议](#http和https协议)
  - [HTTP Request请求的GET和POST方法](#http-request请求的get和post方法)
  - [关于User-Agent](#关于user-agent)
  - [HTTP Response响应的状态码](#http-response响应的状态码)

## 关于URL

URL(Universal Resource Locator)：统一资源定位符。

URL是用于完整地描述Internet上网页和其他资源的地址的一种标识方法。

基本格式：`scheme://host[:port#]/path/…/[?query-string][#anchor]`

- `scheme`：协议(如http、https、ftp)
- `host`：服务器的IP地址或者域名
- `port#`：服务器的端口（如果是走协议默认端口，缺省端口80
- `path`：访问资源的路径
- `query-string`：参数，发送给http服务器的数据
- `anchor`：锚（跳转到网页的指定锚点位置）

如：

- <http://www.baidu.com>
- <http://item.jd.com/11963485.html#product-detail>
- <ftp://192.168.1.118:8081/index>

URL是爬虫的入口，非常重要。

## HTTP和HTTPS协议

HTTP(HyperText Transfer Protocol)是超文本传输协议，用于发布和接收HTML页面。

HTTP协议是一个应用层的协议，无连接(每次连接只处理一个请求)、无状态(每次连接传输均独立)。

HTTPS(Hypertext Transfer Protocol over Secure Socket Layer)协议在HTTP下加入SSL层。

HTTPS=HTTP+SSL(Secure Sockets Layer)用于Web的安全传输，在传输层对网络连接进行加密。

HTTP的端口号为80；HTTPS的端口号为443。

## HTTP Request请求的GET和POST方法

GET：是为了从服务器上获取信息，传输给服务器数据的过程不够安全，数据大小有限制。

POST：向服务器传递数据，传输数据的过程是安全的，大小理论上没有限制。

## 关于User-Agent

User Agent中文名为用户代理，简称UA。

UA是一个特殊字符串头，使得服务器能够识别：

- 客户使用的操作系统及版本
- CPU类型
- 浏览器及版本、浏览器渲染引擎、浏览器语言、浏览器插件
- ...

## HTTP Response响应的状态码

200为成功，300是跳转，400、500意味着有错误：

错误码 | 解决方法
---|---
400(Bad Request) | 检查请求的参数或者路径
401(Unauthorized) | 需要授权的网页，尝试重新登录
403(Forbidden) | 需要登录，尝试重新登录；IP被封，暂停爬取，并增加爬虫等待时间；拨号网络尝试重新联网更改IP
404(Not Found) | 直接丢弃
5XX(服务器错误) | 直接丢弃并技术，连续不成功时，WARNING并停止爬取

说明：

- 服务器返回给爬虫的信息可以用来判断我们爬虫当前是否正常在运行
- 出现异常错误时，一般来说：
  - 如果是500的错误那么爬虫会进入休眠状态，说明服务器已经宕机
  - 如果是400的错误，则需要考虑爬虫的抓取策略的修改，可能是网站更新了，或者是爬虫被禁了
