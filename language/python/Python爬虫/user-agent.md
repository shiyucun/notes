# user-agent

- [user-agent](#user-agent)
  - [HttpHeader之User-Agent](#httpheader之user-agent)
    - [浏览器标识](#浏览器标识)
    - [操作系统标识](#操作系统标识)
    - [加密等级标识](#加密等级标识)
    - [浏览器语言](#浏览器语言)
    - [渲染引擎](#渲染引擎)
    - [版本信息](#版本信息)
  - [浏览器User-Agent的详细信息](#浏览器user-agent的详细信息)
    - [PC端](#pc端)
    - [移动设备端](#移动设备端)
  - [浏览器识别](#浏览器识别)
    - [IE浏览器(以IE9.0为例)](#ie浏览器以ie90为例)
    - [360浏览器](#360浏览器)
    - [搜狗浏览器](#搜狗浏览器)
    - [Chrome](#chrome)
    - [Safari](#safari)
    - [腾讯浏览器](#腾讯浏览器)
    - [Firefox](#firefox)
    - [Theworld](#theworld)
    - [遨游](#遨游)
    - [Opera](#opera)
  - [操作系统定向](#操作系统定向)

## HttpHeader之User-Agent

UserAgent(UA)中文名为用户代理，是Http协议中的一部分，属于头域的组成部分。

UA是特殊的字符串头，会向访问网站提供浏览器类型及版本、操作系统及版本、浏览器内核等信息。

通过UA标识，用户访问的网站可以显示不同的排版从而为用户提供更好的体验或者进行信息统计。

UA可以进行伪装。

### 浏览器标识

出于兼容及推广等目的，很多浏览器的标识相同。

因此浏览器标识并不能说明浏览器的真实版本，真实版本信息在UA字串尾部可以找到。

### 操作系统标识

```text
# FreeBSD
X11;FreeBSD(version no.)i386
X11;FreeBSD(version no.)AMD64

# linux
X11;Linux ppc
X11;Linux ppc64
X11;Linux i686
X11;Linux x86_64

# Mac
Macintosh;PPC Mac OS X
Macintosh;Intel Mac OS X

# Solaris
X11;SunOS i86pc
X11;SunOs sun4u

# Windows
Windows NT 6.1   #对应windows7
Windows NT 6.0   #对应windows Vista
Windows NT 5.2   #对应windows 2003
Windows NT 5.1   对应windows xp
Windows NT 5.0   对应windows 2000
Windows ME
Windows 98
```

### 加密等级标识

- N：表示无安全加密
- I：表示弱安全加密
- U：表示强安全加密

### 浏览器语言

在首选项>常规>语言中指定的语言。

### 渲染引擎

显示浏览器使用的主流渲染引擎有：Gecko、WebKit、KHTML、Presto、Trident、Tasman等。

格式为：渲染引擎/版本信息。

### 版本信息

显示浏览器的真实版本信息。

格式为：浏览器/版本信息。

## 浏览器User-Agent的详细信息

### PC端

```text
safari5.1–MAC
User-Agent:Mozilla/5.0(Macintosh;U;IntelMacOSX10_6_8;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50
safari5.1–Windows
User-Agent:Mozilla/5.0(Windows;U;WindowsNT6.1;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50

IE9.0
User-Agent:Mozilla/5.0(compatible;MSIE9.0;WindowsNT6.1;Trident/5.0;

IE8.0
User-Agent:Mozilla/4.0(compatible;MSIE8.0;WindowsNT6.0;Trident/4.0)

IE7.0
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT6.0)

Firefox4.0.1–MAC
User-Agent:Mozilla/5.0(Macintosh;IntelMacOSX10.6;rv:2.0.1)Gecko/20100101Firefox/4.0.1

Firefox4.0.1–Windows
User-Agent:Mozilla/5.0(WindowsNT6.1;rv:2.0.1)Gecko/20100101Firefox/4.0.1

Opera11.11–MAC
User-Agent:Opera/9.80(Macintosh;IntelMacOSX10.6.8;U;en)Presto/2.8.131Version/11.11

Opera11.11–Windows
User-Agent:Opera/9.80(WindowsNT6.1;U;en)Presto/2.8.131Version/11.11

Chrome17.0–MAC
User-Agent:Mozilla/5.0(Macintosh;IntelMacOSX10_7_0)AppleWebKit/535.11(KHTML,likeGecko)Chrome/17.0.963.56Safari/535.11

傲游（Maxthon）
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Maxthon2.0)

腾讯TT
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;TencentTraveler4.0)

世界之窗（TheWorld）2.x
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1)

世界之窗（TheWorld）3.x
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;TheWorld)

搜狗浏览器1.x
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Trident/4.0;SE2.XMetaSr1.0;SE2.XMetaSr1.0;.NETCLR2.0.50727;SE2.XMetaSr1.0)

GreenBrowser
User-Agent:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1)
```

### 移动设备端

```text
safariiOS4.33–iPhone
User-Agent:Mozilla/5.0(iPhone;U;CPUiPhoneOS4_3_3likeMacOSX;en-us)AppleWebKit/533.17.9(KHTML,likeGecko)Version/5.0.2Mobile/8J2Safari/6533.18.5

safariiOS4.33–iPodTouch
User-Agent:Mozilla/5.0(iPod;U;CPUiPhoneOS4_3_3likeMacOSX;en-us)AppleWebKit/533.17.9(KHTML,likeGecko)Version/5.0.2Mobile/8J2Safari/6533.18.5

safariiOS4.33–iPad
User-Agent:Mozilla/5.0(iPad;U;CPUOS4_3_3likeMacOSX;en-us)AppleWebKit/533.17.9(KHTML,likeGecko)Version/5.0.2Mobile/8J2Safari/6533.18.5

AndroidN1
User-Agent:Mozilla/5.0(Linux;U;Android2.3.7;en-us;NexusOneBuild/FRF91)AppleWebKit/533.1(KHTML,likeGecko)Version/4.0MobileSafari/533.1

AndroidQQ浏览器Forandroid
User-Agent:MQQBrowser/26Mozilla/5.0(Linux;U;Android2.3.7;zh-cn;MB200Build/GRJ22;CyanogenMod-7)AppleWebKit/533.1(KHTML,likeGecko)Version/4.0MobileSafari/533.1

AndroidOperaMobile
User-Agent:Opera/9.80(Android2.3.4;Linux;OperaMobi/build-1107180945;U;en-GB)Presto/2.8.149Version/11.10

AndroidPadMotoXoom
User-Agent:Mozilla/5.0(Linux;U;Android3.0;en-us;XoomBuild/HRI39)AppleWebKit/534.13(KHTML,likeGecko)Version/4.0Safari/534.13

BlackBerry
User-Agent:Mozilla/5.0(BlackBerry;U;BlackBerry9800;en)AppleWebKit/534.1+(KHTML,likeGecko)Version/6.0.0.337MobileSafari/534.1+

WebOSHPTouchpad
User-Agent:Mozilla/5.0(hp-tablet;Linux;hpwOS/3.0.0;U;en-US)AppleWebKit/534.6(KHTML,likeGecko)wOSBrowser/233.70Safari/534.6TouchPad/1.0

WindowsPhoneMango
User-Agent:Mozilla/5.0(compatible;MSIE9.0;WindowsPhoneOS7.5;Trident/5.0;IEMobile/9.0;HTC;Titan)

UC无
User-Agent:UCWEB7.0.2.37/28/999

UC标准
User-Agent:NOKIA5700/UCWEB7.0.2.37/28/999

UCOpenwave
User-Agent:Openwave/UCWEB7.0.2.37/28/999

UCOpera
User-Agent:Mozilla/4.0(compatible;MSIE6.0;)Opera/UCWEB7.0.2.37/28/999
```

## 浏览器识别

### IE浏览器(以IE9.0为例)

```text
UA:Mozilla/5.0(compatible;MSIE9.0;WindowsNT6.1;Trident/5.0;  # PC端
UA:Mozilla/5.0(compatible;MSIE9.0;WindowsPhoneOS7.5;Trident/5.0;IEMobile/9.0;HTC;Titan)  # 移动设备
```

遨游、世界之窗、360浏览器、腾讯浏览器以及搜狗浏览器、Avant、GreenBrowser均采用IE的内核。

因此IE浏览器判断的标准是"MSIE"字段。

MSIE字段后面的数字为版本号。

同时还需要判断不包含"Maxthon"、"Theworld"、"360SE"、"TencentTraveler"、"SE"、"Avant"等字段。

移动设备还需要判断"IEMobile+版本号"。

### 360浏览器

```text
UA:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Trident/4.0;InfoPath.2;.NET4.0C;.NET4.0E;.NETCLR2.0.50727;360SE)  # PC端
# 移动设备暂无
```

360浏览器的判断标准是"360SE"字段，没有版本表示。

### 搜狗浏览器

```text
UA:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Trident/4.0;SE2.XMetaSr1.0;SE2.XMetaSr1.0;.NETCLR2.0.50727;SE2.XMetaSr1.0)  # PC端
# 移动设备暂无
```

搜狗浏览器的判断标准是"SE"、"MetaSr"字段，版本号为SE后面的数字。

### Chrome

```text
UA:Mozilla/5.0(Macintosh;IntelMacOSX10_7_0)AppleWebKit/535.11(KHTML,likeGecko)Chrome/17.0.963.56Safari/535.11  # PC端
UA:Mozilla/5.0(Linux;U;Android2.2.1;zh-cn;HTC_Wildfire_A3333Build/FRG83D)AppleWebKit/533.1(KHTML,likeGecko)Version/4.0MobileSafari/533.1  # 移动设备
```

PC端chrome浏览器的判断标准是chrome字段。

chrome后面的数字为版本号。

移动端的chrome浏览器判断"android"、"linux"、"mobilesafari"等字段，version后面的数字为版本号。

### Safari

```text
UA:Mozilla/5.0(Macintosh;U;IntelMacOSX10_6_8;en-us)AppleWebKit/534.50(KHTML,likeGecko)Version/5.1Safari/534.50  # PC端
UA:Mozilla/5.0(iPhone;U;CPUiPhoneOS4_3_3likeMacOSX;en-us)AppleWebKit/533.17.9(KHTML,likeGecko)Version/5.0.2Mobile/8J2Safari/6533.18.5  # 移动设备
```

Chrome及Nokia’sSeries60browser也使用WebKit内核。

因此Safari浏览器的判断必须是：包含safari字段，同时不包含chrome等信息。

确定后"version/"后面的数字即为版本号。

在以上条件下包含Mobile字段的即为移动设备上的Safari浏览器。

### 腾讯浏览器

```text
UA:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Trident/4.0;TencentTraveler4.0;.NETCLR2.0.50727)  # PC端
UA:MQQBrowser/26Mozilla/5.0(Linux;U;Android2.3.7;zh-cn;MB200Build/GRJ22;CyanogenMod-7)AppleWebKit/533.1(KHTML,likeGecko)Version/4.0MobileSafari/533.1  # 移动设备
```

腾讯浏览器的判断标准是"TencentTraveler"或者"QQBrowser"。

TencentTraveler或QQBrowser后面的数字为版本号。

### Firefox

```text
UA:Mozilla/5.0(WindowsNT6.1;rv:2.0.1)Gecko/20100101Firefox/4.0.1  # PC端
UA:Mozilla/5.0(Android;Linuxarmv7l;rv:5.0)Gecko/Firefox/5.0fennec/5.0  # 移动设备
```

Firefox的判断标准是Firefox字段，firefox后面的数字为版本号。

### Theworld

```text
UA:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;TheWorld)  # PC端
# 移动设备暂无
```

Theworld浏览器的判断标准是"Theworld"字段，没有标示版本号。

需要注意的是：Theworld2.x版本的User-Agent中没有"Theworld"的字段。

### 遨游

```text
UA:Mozilla/4.0(compatible;MSIE7.0;WindowsNT5.1;Maxthon2.0)  # PC端
# 移动设备暂无
```

遨游浏览器的判断标准是"Maxthon"，Maxthon后面的数字为版本号。

### Opera

```text
UA:Opera/9.80(WindowsNT6.1;U;en)Presto/2.8.131Version/11.11  # PC端
UA:Opera/9.80(Android2.3.4;Linux;Operamobi/adr-1107051709;U;zh-cn)Presto/2.8.149Version/11.10  # 移动设备
```

opera浏览器的判断标准是opera字段，opera字段后面的数字为版本号。

## 操作系统定向

操作系统定向依赖于各个浏览器在打开页面时所传输的httpheader信息中的User-Agent。

关于User-Agent的说明，参见User-Agent详细信息中不同操作系统的识别方法。

```text
# PC端
FreeBSD:
X11;FreeBSD(version no.)i386
X11;FreeBSD(version no.)AMD64
Linux:
X11;Linux ppc
X11;Linux ppc64
X11;Linux i686
X11;Linux x86_64
Mac:
Macintosh;PPC Mac OS X
Macintosh;Intel Mac OS X
Solaris:
X11;SunOS i86pc
X11;SunOs sun4u
Windows:
Windows NT 6.1   #对应windows7
Windows NT 6.0   #对应windows Vista
Windows NT 5.2   #对应windows 2003
Windows NT 5.1   #对应windows xp
Windows NT 5.0   #对应windows 2000
Windows ME
Windows 98

# 移动设备端
iOS       iPhone OS 4_3_3  iPhone/iPod
OS 4_3_3         iPad
Android     Android 2.3.7    后面数字为版本号
WebOs       hpwOS/3.0.0
SymbianOS   SymbianOS/9.4
Windows Phone OS   Windows Phone OS 7.5
BlackBerry   BlackBerry
```

[原文](http://blog.csdn.net/u012175089/article/details/61199238)
