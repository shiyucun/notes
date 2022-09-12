
```python
from lxml import etree

xml = """<bookstore>
    <book>
        <title lang="eng">Harry Potter</title>
        <price>29.99</price>
    </book>
    <book>
        <title lang="chi">Learning XML</title>
        <price>39.95</price>
    </book>
    </bookstore>"""

# 得到根节点
root = etree.fromstring(xml)
print(root)

print("选取节点:")
# 选取所有book子元素
element = root.xpath('book')
print(element)
# 选取根节点bookstore
element = root.xpath('/bookstore')
print(element)
# 选取所有book子元素的title子元素
element = root.xpath('book/title')
print(element)
# 以根节点为始祖，选取其后代中的title元素
element = root.xpath('//title')
print(element)
# 以book子元素为始祖，选取后代中的price元素
element = root.xpath('book//price')
print(element)
# 以根节点为始祖，选取其后代中的lang属性值
element = root.xpath('//@lang')
print(element)

print("通配符:")
# 选取 bookstore 所有子元素
element = root.xpath('/bookstore/*')
print(element)
# 选取根节点的所有后代元素
element = root.xpath('//*')
print(element)
# 选取根节点的所有具有属性节点的title元素
element = root.xpath('//title[@*]')
print(element)
# 选取当前节点下所有节点
element = root.xpath('node()')
print(element)  # '\n    ' 是文本节点
# 选取根节点所有后代节点，包括元素、属性、文本。
element = root.xpath('//node()')
print(element)

print("预判:")
# 选取bookstore的第一个book子元素
element = root.xpath('/bookstore/book[1]')
print(element[0].getchildren()[0].attrib)
# 选取bookstore的最后一个book子元素
element = root.xpath('/bookstore/book[last()]')
print(element[0].getchildren()[0].attrib)
# 选取bookstore的倒数第二个book子元素
element = root.xpath('/bookstore/book[last()-1]')
print(element)
# 选取bookstore的前两个book子元素
element = root.xpath('/bookstore/book[position()<3]')
print(element)
# 以根节点为始祖，选取其后代中含有lang属性的title元素
element = root.xpath('//title[@lang]')
print(element)
# 以根节点为始祖，选取其后代中含有lang属性并且值为eng的title元素
element = root.xpath("//title[@lang='eng']")
print(element)
# 选取bookstore子元素book，条件是book的price子元素要大于35
element = root.xpath("/bookstore/book[price>35.00]")
print(element)
# 选取bookstore子元素book的子元素title，条件是book的price子元素要大于35
element = root.xpath("/bookstore/book[price>35.00]/title")
print(element)

print("条件选取:")
# 选取所有book的title元素或者price元素
element = root.xpath('//book/title|//book/price')
print(element)
# 选择所有title或者price元素
element = root.xpath('//title|//price')
print(element)
# 选择book子元素title或者全部的price元素
element = root.xpath('/bookstore/book/title|//price')
print(element)

print("测试步:")
# child::nodename 选取所有属于当前节点的book子元素，等价于'./nodename'
element = root.xpath('child::book')
print(element)
element = root.xpath('./book')
print(element)
# attribute::lang 选取当前节点的 lang 属性，等价于 './@lang'
element = root.xpath('//*[@lang]')[0].xpath('attribute::lang')
print(element)
element = root.xpath('//*[@lang]')[0].xpath('@lang')
print(element)
# child::* 选取当前节点的所有子元素，等价于 './*'
element = root.xpath('child::*')
print(element)
element = root.xpath('./*')
print(element)
# attribute::* 选取当前节点的所有属性，等价于 './@*'
element = root.xpath('//*[@*]')[0].xpath('attribute::*')
print(element)
element = root.xpath('//*[@*]')[0].xpath('@*')
print(element)
# child::text() 选取当前节点的所有文本子节点，等价于 './text()'
element = root.xpath('child::text()')
print(element)
element = root.xpath('./text()')
print(element)
# child::node() 选取当前节点所有子节点，等价于 './node()'
element = root.xpath('child::node()')
print(element)
element = root.xpath('./node()')
print(element)
# descendant::book 选取当前节点所有 book 后代，等价于 './/book'
element = root.xpath('descendant::book')
print(element)
element = root.xpath('.//book')
print(element)
# ancestor::book 选取当前节点所有 book 先辈
element = root.xpath('.//title')[0].xpath('ancestor::book')
print(element)
# ancestor-or-self::book 选取当前节点的所有 book 先辈以及如果当前节点是 book 的话也要选取
element = root.xpath('.//title')[0].xpath('ancestor-or-self::book')
print(element)
element = root.xpath('.//book')[0].xpath('ancestor-or-self::book')
print(element)
element = root.xpath('.//book')[0].xpath('ancestor::book')
print(element)
# child::*/child::price 选取当前节点的所有 price 孙节点，等价于 './*/price'
element = root.xpath('child::*/child::price')
print(element)
element = root.xpath('./*/price')
print(element)
```
