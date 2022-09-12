
# JS

- [JS](#js)
  - [使用 JS](#使用-js)
  - [JS 基础语法](#js-基础语法)
    - [变量](#变量)
    - [常量](#常量)
    - [数据类型](#数据类型)
    - [数据类型转换](#数据类型转换)
    - [运算符](#运算符)
    - [流程控制](#流程控制)
    - [数组](#数组)
    - [字符串](#字符串)
    - [RegExp 对象](#regexp-对象)
    - [Math对象](#math对象)
    - [Date对象](#date对象)
    - [Function 对象](#function-对象)
  - [BOM 和 DOM](#bom-和-dom)
  - [window 对象](#window-对象)
  - [window 对象 document 属性](#window-对象-document-属性)
  - [DOM - 事件，通过用户的行为来激发的操作](#dom---事件通过用户的行为来激发的操作)
  - [event 对象](#event-对象)

## 使用 JS

**使用元素事件执行 JS**：

事件：用户在元素上所激发的一些行为操作。

onclick：当用户点击元素时要激发的操作

语法：`<ANY onclick="JS脚本代码">`

**在网页中嵌入`<script>`**：

语法：`<script> 若干JS脚本代码 </script>`

特点：网页加载时即开始执行脚本。

**将 JS 脚本编写在外部的 js 文件中**：

步骤：

1. 创建一个 js 文件并编写 JS 脚本
2. 在使用 JS 的页面上对 js 文件进行引入

引入语法：

`<script src="JS文件路径"></script>`

常用输出接口：

```js
// 向网页中输出一句话，该语句放在按钮中执行会清空网页内容再显示
document.write("...");

// 向浏览器 F12 console 控制台输出一句话
document.log("...");

// 弹窗显示
document.alert("...");

// 弹出消息对话框(包含确认、取消按钮和输入框)
window.prompt("...");

// 在控制台通过类似文件树样式的交互列表显示指定对象的属性
console.dir("...");
```

## JS 基础语法

### 变量

声明：`var 变量名;`
赋值：`变量名 = 值;`
声明并赋值：`var 变量名=值;`

注意：

- 声明变量时，尽量使用`var`关键字
- 可以省略`var`关键字，但容易出问题
- 声明变量未赋值时，默认值为`undefined`

### 常量

声明：`const 常量名=值;`

注意：通常情况下，常量名采用全大写的形式。

### 数据类型

`number`：数字类型，可表示32位的整数以及64位的浮点数
`string`：字符串类型，由 Unicode 的字符，数字，标点符号组成
`boolean`：布尔类型

注意：使用`typeof()`或`typeof`可以查看指定变量的数据类型。

### 数据类型转换

**隐式转换**：

不同数据在做加法运算时会进行自动转换。

- `数字 + 字符串`：将数字转换为字符串
- `数字 + 布尔值`：将布尔值转换为数字
- `字符串 + 布尔值`：将布尔值转换为字符串
- `布尔值 + 布尔值`：将布尔值转换为数字

**强制转换**：

`toString()`任意类型转换成字符串，并返回转换后的结果。

```js
var num = 18;
var str = num.toString();
```

`parseInt()`数据尽量转换成整数，无法转换时返回`NaN`(Not a Number)。

```js
var r = parseInt("13"); [r: 13]
var r = parseInt("13你好"); [r: 13]
var r = parseInt("你好13"); [r: NaN]
```

`parseFloat()`数据尽量转换成小数。

```js
var r = parseFloat("35.5");
```

`Number()`指定的数据转换成数字，只要包含非法字符，结果就为`NaN`。

```js
var r = Number("235.5"); [r: 235.5]
var r = Number("235你好"); [r: NaN]
```

`isNaN()`验证数据是否为非数字，非数字返回`true`，否则返回`false`。

```js
var r = isNaN("35"); [r: false]
var r = isNaN("385ABC") [r: true]
```

### 运算符

```js
+、-、*、/、%
++、--
>、<、>=、<=
!=     // (不等于)
!==    // (严格不等于)
==     // (等于，先做类型转换再做比较)
===    // (严格等于，等式两侧绝对相等，包括数据类型)
!、&&、||
? :
```

### 流程控制

**条件语句**：

```js
if (条件1) {
  语句块1;
} else if (条件2) {
  语句块2;
} ... else if(条件n){
  语句块n;
} else {
  语句块n+1;
}
```

**分支语句**：

```js
switch (变量) {
  case 值1:
    语句块1;
    break;
  case 值2:
    语句块2;
    break;
  ...
  case 值n:
    语句块n;
    break;
  default:
    语句块n+1;
    break;
}
```

**循环语句**：

```js
for (语句 1; 语句 2; 语句 3) {
  语句块;
}
// 语句 1 在循环（代码块）开始前执行
// 语句 2 定义运行循环（代码块）的条件
// 语句 3 在循环（代码块）已被执行之后执行

for (变量 in 对象) { 
  语句块;
}

while (条件) {
  语句块;
}

do {
  语句块;
} while (条件);
```

### 数组

**创建和使用数组**：

创建空数组：`var 数组名 = [];`。

创建数组并初始化元素：`var 数组名 = [元素1, 元素2, 元素3];`。

创建一个空数组：`var 数组名 = new Array();`。

创建数组并初始化元素：`var 数组名 = new Array(元素1, 元素2, 元素3);`。

数组的使用：获取或设置数组中的元素，一律都使用下标(从0开始)。

获取数组的长度：数组名.length。

关联数组：数组分成索引数组和关联数组。

由数字做下标的数组都是索引数组；由字符串做下标的数据都是关联数组。

关联数组语法：`var names = []; names[字符串] = 值;`。

**常用 API**：

`toString()`：将数组转换为字符串，并返回。

`join(seperator)`：返回使用指定分隔符连接数组元素的字符串。

`concat()`：拼接两个或更多的数组，如：`arr.concat(arr2,arr3,...);`。

注意：`concat`函数返回一个新的数组，不改变原数组。

`reverse()`：实现数组的反转，如：`arr.reverse();`。

注意：`reverse`函数会改变现有数组的结构。

`sort()`：数组元素由小到大排序，默认按照元素 Unicode 编码排序。

注意：`sort`函数直接改变现有数组内容。

**自定义排序函数指定数字数组排序方式**：

使用排序函数，如下：

```js
// 排序规则函数：
//   参数为要比较的数字，返回值用于标识参数大小比较结果
//     返回值小于0则 a < b
//     返回值大于0则 a > b
//     返回值等于0则 a = b

function sortAsc(a, b){
  return a - b;
}

var nums = [38, 125, 6, 79, 2357, 9];

nums.sort(sortAsc);

// 使用匿名函数完成排序，如下：
var nums = [38, 125, 6, 79, 2357, 9];

// 指定降序排序
nums.sort(function(a, b){ return b-a; });
```

**进出栈操作**：

`push()`入栈，向数组的尾部添加新元素，并返回新数组的长度。

```js
var nums = [];
nums.push(325);
```

`pop()`出栈，删除并返回数组尾部的元素。

`unshift()`向数组的头部添加新元素，并返回新数组的长度。

`shift()`删除并返回数组头部的元素。

**二维数组**，如下：

```js
var example = [
  ["abc", "bcd", "cde"],
  ["123", "234", "345"],
  ["456", "567", "678"]
];

console.log(example[1][1]);
```

### 字符串

**声明**：

```js
var str1 = "字符串1";
var str2 = String("字符串2");
var str3 = new String("字符串3");
```

`length`属性：返回当前字符串的字符的个数。

**常用函数**：

`toLowerCase()`返回字符串的完全小写形式。

`toUpperCase()`返回字符串的完全大写形式。

注意：上述两个函数返回新的字符串，不修改原数据。

`charAt(index)`返回指定下标处的字符，如下：

```js
var msg = "Hello World ";
var r = msg.charAt(5);
console.log(r); //空格
```

`charCodeAt(index)`返回指定下标处的字符的 Unicode 码，如下：

```js
var msg = "Hello World ";
var r = msg.charCodeAt(0); // H 的 unicode 码
```

检索字符串：查找子字符串在指定字符串中的位置。

- `indexOf(value,fromIndex)`
  - value: 要查找的子字符串
  - fromIndex: 开始查找的位置，省略时从开始处查找
  - 返回第一次出现子字符串的下标，没查询到子字符串时返回-1

- `lastIndexOf(value,fromIndex)`
  - value: 要查找的子字符串
  - fromIndex: 开始查找的位置，省略时从开始处查找
  - 返回最后一次出现子字符串的下标

截取子字符串：

- `substring(start, end)`
  - 返回从 start 到 end-1 之间的子字符串
  - 省略 end 则截取到末尾

分割字符串：

`split(seperator)`用 seperator 对字符串拆分，返回拆分后的数组

模式匹配：

- `replace(substr/regexp, replacement)`
  - 按照指定的格式匹配字符串，并将满足格式的字符替换为目标值
- `match(substr/regexp)`
  - 按照指定的格式匹配字符串，并将满足格式的字符串返回
- `search(substr/regexp)`
  - 返回第一个匹配的内容的下标，未找到则返回-1
  - search 函数不支持全局匹配，自动忽略修饰符 g
  - 修饰符：
    - i 忽略大小写
    - g 全局匹配
    - m 允许多行匹配

```js
var msg = "123789123";
var result = msg.replace(/123/gim,"456");
```

### RegExp 对象

创建 RegExp 对象：

```js
var regExp = /pattern/flags;
var regExp = new RegExp("pattern","flags");
```

常用方法：

```js
regExp.test(string) // string 符合 regExp 的格式返回 true
regExp.exec(string) // 检索并返回满足格式的子字符串
```

### Math对象

- 属性：`Math.PI`、`Math.E`
- 三角函数：
  - `Math.sin(x)`
  - `Math.cos(x)`
  - `Math.tan(x)`
- 计算函数：
  - `Math.sqrt(x)`开平方
  - `Math.log(x)`对数
  - `Math.pow(x, y)`求x的y次幂
- 数值比较函数：
  - `Math.abs(x)`绝对值
  - `Math.max(x, y, z, ...)`返回指定参数中的最大值
  - `Math.min(x, y, z, ...)`返回指定参数中的最小值
  - `Math.random()`返回 [0,1) 的小数(随机数)
  - `Math.round(x)`将x进行四舍五入到整数

### Date对象

- 创建Date对象：
  - 获取当前系统的日期时间
    - `var now = new Date();`
  - 初始化自定义日期时间
    - `var date = new Date("2017/12/2 17:00:00");`
- 方法：
  - `getTime()`读取时间(毫秒)
  - `setTime(毫秒)`设置时间(毫秒)
  - `getFullYear()`读取当前时间对象的年份
  - `getYear()`返回自1900年，到当前时间对象所经过的年数
  - `getMonth()`返回 0-11 的数字表示1-12月
  - `getDate()`返回当前时间对象的日
  - `getDay()`返回当前时间日期对象的星期0~6
  - `getHours()`、`getMinutes()`、`getSeconds()`获取时分秒
  - `toString()`转换为字符串
  - `toLocaleTimeString()`返回当前的时间字符串(时分秒)
  - `toLocaleDateString()`返回当前的日期字符串(年月日)

### Function 对象

在 JS 中每一个函数都是 Function 对象。

创建：

```js
function 函数名([参数列表]) {
  代码块
}
// 返回值：允许有返回值，使用 return 返回，无返回值返回 undefined
// 参数：在 JS 函数中，所有参数默认封装到一个 arguments 数组中
```

其他创建方式：

- 使用Function对象创建函数：
  - `var funName = new Function(arg1, arg2, ... funBody);`
    - `var add = new Function("x", "y", "return (x+y);");`
- 匿名函数：
  - `var add = function(){...}`
- 全局函数：
  - 全局函数适用于所有的JS操作中
  - 由ES所提供的全局函数，不需要单独声明，可直接使用
    - `parseInt()` / `parseFloat()`
    - `isNaN()` / `Number()`
    - `eval()`执行由字符串来表示的 JS 代码

## BOM 和 DOM

BOM：`Browser Object Model`。

BOM 是指浏览器对象模型。

将浏览器看成一个对象，可以通过该对象灵活的操控浏览器，如：地址栏，历史记录，屏幕相关等。

DOM ：`Document Object Model`。

DOM 是指文档对象模型。

将整个HTML文档看成一个对象，可以通过该对象灵活的操控文档中的任何内容。

## window 对象

表示浏览器的窗口。

JS中所有的全局函数，属性都是 window 对象的成员。

在使用时，可以省略`window.`。

**属性**：

- document 窗口中显示的 HTMl 文档对象，是 DOM 中最顶层的对象
- history 当前窗口所浏览过的历史记录
- location 当前窗口中地址栏对象
- screen 当前屏幕对象
- navigator 浏览器相关信息对象

**属性详解**：

- screen
  - 包含客户端显示器的一些相关信息
  - 属性：`width` `height` `availWidth` `availHeight`
- history
  - 包含当前窗口访问过的URL地址们
  - 属性 & 方法：
    - `length`：访问过的 URL 数量
    - `back()`：后退
    - `forward()`：- 前进
    - `go(num)`： 去往历史记录中的第num个页面
- location
  - 包含当前浏览器地址栏中的信息
  - 属性 & 方法：
    - `href`：当前窗口浏览的地址，href 设置值，即浏览器跳转功能
    - `reload()`：重新载入当前网页，等同于刷新
- navigator
  - 包含浏览器的相关信息
  - 属性：`userAgent`当前计算机中所安装的浏览器信息

**对话框**：

- `window.alert()` `alert()`：警告框
- `window.prompt()` `prompt()`：输入框
- `window.confirm()` `confirm()`：确认框，按`确定`按钮，返回true

**周期性定时器**：

```js
var ret = setInterval(func, time);  // 创建并启动定时器
// func：要周期性执行的操作，可以是一个匿名函数
// time：时间间隔周期，以毫秒为单位
// ret：已启动的定时器对象

clearInterval(timer);  // 停止已启动的定时器对象
// timer：要停止的定时器对象

// 一次性定时器：
var ret = setTimeout(func, time);
// func：等待一定时间后要执行的操作，可以是匿名函数
// time：等待时长，以ms为单位
// ret：已启动的定时器对象

clearTimeout(timer);  // 停止已启动定时器对象
```

## window 对象 document 属性

document 对象是 DOM 中最顶层的对象，封装了所有和 HTML 文档相关的属性和方法。

网页加载时，会自动创建 document 对象，在底层形成一颗节点树(DOM 树),该树的根就是 document。

DOM 中所提供的操作有：查找节点、读取节点信息、修改节点信息、创建新节点、删除节点。

**查找节点**：

```js
var elem = document.getElementById(id); // 通过元素 id 查询
// id：要获取的元素的 id 属性值
// elem：得到的元素对象 - DOM 对象
// DOM对象的属性：
//    innerHTML：获取或设置当前元素的 HTML 文本值
//    innerText：获取或设置当前元素的文本值
//    只用于双标记中，区别在于文本值是否会被浏览器解析。
// 表单控件对象的属性：
//    value：获取文本值
```

**读取节点的信息**：

属性：`nodeType` 节点类型

返回值：

- 1：元素节点，表示页面上的一个元素
- 2：属性节点，表示元素的一个属性
- 3：文本节点，表示元素内的文本
- 8：注释节点，表示网页上的一个注释
- 9：文档节点，表示整个html文档

属性：`nodeName` 节点名称

元素节点或属性节点：返回标签名或属性名

- 文本节点：返回`#text`
- 注释节点：返回`#conment`
- 文档节点：返回`#document`

**设置或获取元素节点的属性**：

- `getAttribute(attrName)`
  - 获取指定属性的值
- `attrName`
  - 要获取的属性的名称，返回`attrName`属性的值
- `setAttribute(attrName, attrValue)`
  - 修改/设置指定属性的值
- `attrName`
  - 要修改/设置的属性名称
- `attrValue`
  - 要修改/设置的属性值
- `removeAttribute(attrName)`
  - 将`attrName`属性从当前节点中移除出去

**元素节点的样式**：

- `elem.setAttribute("class", "属性值");`
  - 设置 class 属性的值
- `elem.className = "class属性值";`
  - 设置 class 属性的值
- `elem.style.css属性名 = 值;`
  - 自定义元素样式
  - 如果 css 属性名有连字符(-)的话，连字符(-)要取消，并且(-)后的字符要首字符变大写
  - 自定义元素样式本质上属于内联方式修改
  - 举例：
    - `elem.style.color="red";`
    - `elem.style.fontSize="18px";`
    - `elem.style.borderRightColor="green";`

**查询节点**：

- 通过 id 查询：
  - 语法：`var elem = document.getElementById(id);`
- 根据层次查询节点：
  - `parentNode`根据当前文档的上下层结构，返回父元素节点
  - `childNodes`根据当前文档的上下层结构，返回多个子节点(子节点数组)
  - 能获取到文本节点、元素节点、注释节点，只需要某一种节点时要使用`nodeType`进行判断
- 通过标签名查询节点：
  - 语法：`document|elem.getElementsByTagName(tagName);`
  - 返回值：包含指定标记的数组
- 通过元素的 name 属性查询节点：
  - 语法：`document|elem.getElementsByName(name);`
  - 返回值：包含指定 name 属性值的元素的数组
- 通过元素的 class 值查询节点
  - 语法：`document|elem.getElementsByClassName(className);`
  - 返回值：包含指定 class 属性值的元素的数组

**增加节点**：

创建元素节点：

```js
var elem = document.createElement("元素名");
```

增加节点：

```js
document.body.appendChild(elem);  // 向 body 的最后一个子元素的位置处增加 elem 元素
parentNode.appendChild(elem);  // 向指定元素的最后一个子元素的位置处增加 elem 元素
parentNode.insertBefore(elem, oldElem);
// 将 elem 元素增加到 parentNode 元素中 oldElem 元素之前
// parentNode：表示页面上的任何一个节点元素
```

**删除节点**：

```js
document.body.removeChild(elem);  // 在 body 中删除 elem 元素节点
parentNode.removeChild(elem);  // 在 parentNode 中删除 elem 元素节点
```

## DOM - 事件，通过用户的行为来激发的操作

**触发事件的行为**：

- 鼠标事件
  - `click`：鼠标单击事件
  - `dbclick`：鼠标双击事件
  - `mouseover`：鼠标滑过事件
  - `mouseout`：鼠标移出事件
  - `mousedown`：鼠标按下事件
  - `mouseup`：鼠标抬起事件
- 键盘事件
  - `keydown`：键盘按下时事件
  - `keypress`：键盘按下时事件
  - `keyup`：键盘抬起时事件
- 状态改变事件
  - `load`：加载时触发的事件
  - `change`：改变时触发的事件
  - `focus`：元素获取焦点时触发的事件
  - `blur`：元素失去焦点时触发的事件
  - `submit`：表单被提交时触发的事件

**绑定事件的方式**：

```js
// 在元素中绑定事件
<ANY on事件名="">

// 在 JS 中动态的为元素绑定事件
<script>
var div = document.getElementById("d1");
div.on事件名 = function() { ... }
</script>
```

**事件行为**：

- `load`：元素在加载完毕时要执行的操作
  - 加载完毕是指完整结构的 DOM 树已形成
- `submit`：表单提交时被触发
  - 需要通过一个返回值，来通知表单是否提交
    - 返回 true：提交表单
    - 返回 false：阻止提交

```js
// 在元素中绑定事件
<body onload="">

// 在 JS 中动态绑定事件
window.onload = function() { ... }
```

## event 对象

任何一个事件在触发后，都会产生一个 event 对象。

event 对象中封装了一些有关当前事件的信息：如鼠标的位置、按下的键盘键位、事件触发元素等。

获取 event 对象：

```js
// html 元素绑定事件
<ANY onclick="btn_click(event)">
<script>
function btn_click(event){
  //event 表示事件对象
}
</script>

// 使用 JS 动态绑定事件
<script>
var myDiv = document.getElementById("d1");
myDiv.onclick=function(event){
  ...
}
</script>
```

事件对象常用属性：

- 事件源对象：当前触发事件的元素
  - 可以通过`event.target`获取事件源
- 针对鼠标事件的属性
  - `offsetX`、`offsetY`
    - 用于获取鼠标在元素上的坐标点，以元素的左上角为`(0, 0)`计算
  - `clientX`、`clientY`
    - 用于获取鼠标在网页上的坐标点，以文档的左上角为`(0, 0)`计算
  - `screenX`、`screenY`
    - 用于获取鼠标在显示器上的坐标点，以显示器的左上角为`(0, 0)`计算
- 键盘事件
  - `keypress -> onkeypress`、`keydown -> onkeydown`、`keyup -> onkeyup`
  - 属性：
    - `event.which`表示按下键位的 ASCII 码
  - 注意：
    - 在`keypress`事件中`which`表示的每个字符的 ASCII 码
    - 在`keydown`事件中`which`表示键盘的键位码，大小写英文一致，数字和一些标点也一致
    - 按键按下触发`keydown`，松开按键触发`keyup`，按键一次按下过程中可以触发多次`keypress`
    - `keypress`主要用来接收字母、数字等 ANSI 字符
    - `keydown`和`keyup`事件可以处理任何不被`keypress`识别的击键
- 事件冒泡
  - 在一个对象上触发某类事件(如`onclick`)时
    - 如果此对象定义了此事件的处理程序，那么此事件就会调用这个处理程序
    - 如果没有定义此事件处理程序或者事件返回 true，那么这个事件会向这个对象的父级对象传播
    - 传播过程是从里到外，直至被处理(父级对象所有同类事件都将被激活)
    - 或者传播到了对象层次的最顶层，即`document`对象(有些浏览器是`window`)。
  - `event.stopPropagation();`阻止事件冒泡
