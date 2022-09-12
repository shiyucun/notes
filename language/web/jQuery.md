
# jQuery

- [jQuery](#jquery)
  - [使用 jQuery](#使用-jquery)
  - [DOM 对象和 jQuery 对象相互转换](#dom-对象和-jquery-对象相互转换)
  - [jQuery 选择器](#jquery-选择器)
  - [创建对象](#创建对象)
  - [DOM](#dom)
  - [事件](#事件)
  - [动画](#动画)

jQuery 是一个轻量级的被封装好的 JS 文件库，提供了更为简便的页面元素操作方式。

jQuery 中封装了 JS、CSS、DOM 的操作。

## 使用 jQuery

- 引入 jQuery 的文件：`<script src="jquery-1.11.3.js"></script>`
- jQuery 对象：
  - jQuery对象是由jQuery对页面元素进行封装后的一种体现
  - jQuery中所提供的所有操作只针对jQuery对象
- 工厂函数：
  - 想要获取 jQuery 对象，就要使用工厂函数`$()`
  - 在`$()`中传递一个选择器，则返回一个选择器所对应的 jQuery 对象
- `$()`：
  - `$( function() { 网页加载时要执行的内容} );`
    - 特点：生成DOM树之后就开始执行
  - `window.onload = function(){ ... }`
    - 特点：渲染完成后才开始执行

## DOM 对象和 jQuery 对象相互转换

- DOM 对象：以 DOM 方式获取的节点对象
  - 只能访问 DOM 所提供的标准方法和属性
  - 不能访问jQuery的函数和属性的
- jQuery 对象：由 jQuery 来封装的对象
  - 只能访问 jQuery 所提供的属性和方法
  - 不能访问 DOM 的属性和方法

DOM 对象转换为 jQuery 对象：`var jQuery对象 = $(DOM对象);`

jQuery对象转换为DOM对象：

- `var DOM对象 = jQuery对象.get(0);`
- `var DOM对象 = jQuery对象[0];`

注意：jQuery 对象起名时最好以`$`开头，用来区分于 DOM 对象。

## jQuery 选择器

用于获取页面上的元素(可能是多个)，并返回 jQuery 对象。

语法：`$(选择器)`

- ID选择器：
  - `$("#ID值");`
    - 返回 HTML 页面指定 ID 值的元素
- 类选择器：
  - `$(".className");`
    - 返回 HTML 页面所有 class 为 className 的元素
- 元素选择器：
  - `$("元素名称");`
    - 返回 HTML 页面所有指定元素名称的元素
- 通用选择器/通配符选择器：
  - `$("*");`
    - 返回 HTML 页面所有的元素
- 群组选择器/复合选择器：
  - `$("selector1,selector2,... ");`
    - 返回满足函数内所有选择器的元素
- 层次选择器：
  - `$("selector1 selector2");`
    - 获取 selector1 元素的后代元素 selector2
  - `$("selector1>selector2");`
    - 获取 selector1 元素的子元素 selector2
  - `$("selector1+selector2");`
    - 获取紧紧接在 selector1 后面的元素 selector2
  - `$("selector1~selector2");`
    - 获取 selector1 后面所有的 selector2 的元素
- 过滤选择器：在 jQuery 中，以`:`开始
  - `:first`
    - 获取匹配到的第1个元素
  - `:last`
    - 获取匹配到的最后1个元素
  - `:not(selector)`
    - 获取满足 selector 选择器的元素之外的元素
  - `:odd`
    - 匹配所有索引值为奇数的元素，从0开始计数
  - `:even`
    - 匹配所有索引值为偶数的元素，从0开始计数
  - `:eq(index)`
    - 匹配索引值等于 index 的元素
  - `:gt(index)`
    - 匹配索引值大于 index 的元素
  - `:lt(index)`
    - 匹配索引值小于 index 的元素
- 内容过滤选择器：
  - `:contains("text")`
    - 匹配包含指定文本的元素
  - `:empty`
    - 匹配空元素(不包含任何子元素和文本的)
  - `:has(selector)`
    - 匹配含有选择器所匹配的元素
  - `:parent`
    - 匹配本身是父元素的元素(包含子元素或文本)
- 可见性过滤选择器：
  - `:hidden`
    - 匹配所有不可见元素
  - `:visible`
    - 匹配所有可见的元素
- 状态过滤选择器：主要用在表单元素中
  - `:enabled`
    - 匹配所有可用元素
  - `:disabled`
    - 匹配所有禁用元素
  - `:checked`
    - 匹配所有被选中的元素(radio和checkbox用)
  - `:selected`
    - 匹配所有被选中的元素(select 和 option)
- 属性选择器：允许使用元素所附带的属性及其值来匹配页面元素
  - `[attr]`匹配具有 attr 属性的元素
  - 举例:
    - `$("[id]");` 匹配页面中所有具有 id 属性的元素
    - `[attr=value]`匹配 attr 属性值等于 value 的元素
    - `[attr!=value]`匹配 attr 属性值不等于 value 的元素
    - `[attr^=value]`匹配 attr 属性值是以 value 字符串开始的元素
    - `[attr$=value]`匹配 attr 属性值是以 value 字符串结尾的元素
    - `[attr*=value]`匹配 attr 属性值中包含 value 字符串的元素

## 创建对象

使用 Object 直接创建对象：

```js
var newObj = new Object();
// 添加属性
newObj.property1 = value1;
newObj.property2 = value2;
// 添加方法
newObj.method1 = function() { ... }
newObj.method2 = function(argu){ ... }
```

使用构造器创建对象：

```js
function 对象名(参数1,参数2,... ...){
// 为属性赋值
this.属性1 = 参数1;
this.属性2 = 参数2;
// 创建方法
this.funName = function(){ ... }
}
var obj1 = new 对象名(实参1,实参2);
var obj2 = new 对象名(实参1,实参2);
```

使用 JSON 创建对象：`JSON：JavaScript Object Notation`

JSON 是 JS 对象表现形式，通常会作为数据交换格式(轻量级)。

声明 JSON 时：

- 使用键值对的方式来声明数据
- 所有的属性必须用`""`引起来，值如果是字符串的话也要用`""`引起来
- 属性和值之间使用`:`隔开
- 多对属性和值之间，使用`,`隔开

## DOM

- 基本操作
  - `html()`读取或修改 jQuery 对象中的 HTML 内容
  - `text()`读取或修改 jQuery 对象中的文本内容
  - `val()`读取或修改 jQuery 对象中的 value 属性值(表单控件)
  - `attr()`读取或修改 jQuery 对象的属性值
  - `removeAttr()`删除 jQuery 对象的指定属性
- 样式操作
  - `attr("class","class值")`动态绑定class属性值
  - `addClass("className")`动态的为元素添加一个类选择器
  - `removeClass("className")`动态的移除一个类选择器
  - `removeClass()`移除所有的类选择器
  - `toggleClass("className")`切换样式：
    - 元素如果具备 className 类选择器，则删除
    - 元素如果没有 className 类选择器，则添加
  - `hasClass("className")`判断元素是否具备 className 类选择器
  - `css("属性名","属性值")`动态的为元素设置 css 属性及值
  - `css(JSON对象)`动态的为元素设置一组的 css 属性值
- 遍历节点
  - `children() / children(selector)`
    - 获取某 jQuery 对象的所有子元素或带有指定选择器的子元素(只考虑直接子节点)
  - `next() / next(selector)`
    - 获取某 jQuery 对象的下一个兄弟元素/满足 selector 的下一个兄弟元素
  - `prev() / prev(selector)`
    - 获取某 jQuery 对象的上一个兄弟元素/满足 selector 的上一个兄弟元素
  - `siblings() / siblings(selector)`
    - 获取某 jQuery 对象的其他兄弟元素/满足 selector 的其他兄弟元素
  - `find(selector)`
    - 查找满足 selector 选择器的后代元素
  - `parent()`
    - 查找某 jQuery 对象的父元素
- 创建节点
  - 语法：`$("要创建的内容")`
  - 示例：`$("<div id="d1">这是一个div</div>")`创建一对div元素
- 插入节点
  - 内部插入节点：
    - `append()`
      - 作为最后一个子节点添加，
      - 举例：`$("obj1").append(obj2);`
    - `prepend()`
      - 作为第一个子节点添加
      - 举例：`$("body").prepend($div);`
  - 外部插入节点：
    - `after()`作为下一个兄弟节点添加进来
    - `before()`作为上一个兄弟节点添加进来
- 删除节点
  - `remove()`删除当前的节点
  - `remove(selector)`按选择器删除某个节点
  - `empty()`清空当前节点
- 复制和替换元素
  - 替换元素：
    - `replaceWith(字符串或函数)`
    - `replaceAll(selector)`
    - 举例：
      - `$("p").replaceWith("<b> ... </b>");`
      - `$("<b> ... </b>").replaceAll("p");`
      - 将所有标记`<p></p>`以及其中的内容替换为`<b> ... </b>`
  - 复制元素：
    - `clone()`复制当前元素以及子元素，并返回复制好的 jQuery 对象
    - 举例：`var $newD1 = $("#d1").clone();`
    - `clone(true)`复制元素、子元素以及节点行为(事件)

## 事件

**页面加载后执行**：

```js
$(document).ready(function(){
  // DOM 树加载完成后，则运行该函数
  // 页面初始化内容
});

$().ready(function(){
  // DOM 树加载完成后，则运行该函数
  // 页面初始化内容
});

$(function(){
  // DOM 树加载完成后，则运行该函数
  // 页面初始化内容
});
```

**与其他JS库共存**：

将$的控制权交给其他JS库：`jQuery.noConflict();`

进行封装重新获取`$`的控制权：

方式1：

```js
jQuery(function($) {
  // 允许正常使用 $
});
```

方式2：

```js
(function($){
  // 允许正常使用 $
})(jQuery);
```

**jQuery的事件绑定**：

方式1：`$obj.bind("事件名称", 事件处理函数);`

```js
$obj.bind("click", function(){
  // 事件的操作
  // 允许使用 this 来引用处理事件的 DOM 元素
});
```

方式2：`$obj.事件名称(事件处理函数);`

```js
$obj.click(function(){
  // 事件的操作
});

// $obj.click() 表示要触发 $obj 的 click 事件
```

模拟操作：使用代码的方式触发事件。

语法1：`$obj.trigger("事件名称");`

```js
// 触发 $obj 的 click 事件
$obj.trigger("click");
```

语法2：`$obj.click();`

事件对象：

```js
$obj.bind("click", function(event){ ... });
$obj.click(function(event){ ... });
```

事件冒泡：使用事件对象 stopPropagation() 阻止事件冒泡。

## 动画

基本显示/隐藏语法：

```js
$obj.show();
$obj.show(执行时间)
$obj.hide();
$obj.hide(执行时间)
```

滑动式显示 / 隐藏语法：

```js
$obj.slideDown(执行时间);  //显示
$obj.slideUp(执行时间);    //隐藏
```

淡入淡出式显示 / 隐藏语法：

```js
$obj.fadeIn(执行时间);   //显示
$obj.fadeOut(执行时间);  //隐藏
```

自定义动画语法：

```js
$obj.animate(js对象, 执行时间);
// js 对象：JSON对象，描述动画完成后元素的样式
```
