
```python
from bs4 import BeautifulSoup
import re


doc = ['<html><head><title>Page title</title></head>',
       '<body><p id="firstpara" align="center">This is paragraph <b>one</b>.</p>',
       '<p id="secondpara" align="blah">This is paragraph2 <b>two</b>.</p></body>',
       '</html>']

# soup = BeautifulSoup(''.join(doc), "lxml")
soup = BeautifulSoup(''.join(doc), "html.parser")

print(soup.prettify())
print(type(soup.contents[0]))  # <class 'bs4.element.Tag'>

# navigate soup的一些方法
print(u"navigate soup的一些方法:")
print(soup.contents[0].name)  # html
print(soup.contents[0].contents[0].name)  # head
head = soup.contents[0].contents[0]
print(head.parent.name)  # html
print(head.next)  # <title>Page title</title>
print(head.nextSibling.name)  # body
# <p id="firstpara" align="center">This is paragraph <b>one</b>.</p>
print(head.nextSibling.contents[0])
# <p id="secondpara" align="blah">This is paragraph <b>two</b>.</p>
print(head.nextSibling.contents[0].nextSibling)
print(len(soup('p')))  # 2

print("获得特定标签或有着特定属性的标签:")
titleTag = soup.html.head.title
print(titleTag.string)  # Page title
titleTagContent = soup.html.head.title.contents
print(titleTagContent)  # ['Page title']

print(soup.findAll('p', {"align":"center"}))
# [<p id="firstpara" align="center">This is paragraph <b>one</b>. </p>]
print(soup.find('p', align="center"))
# <p id="firstpara" align="center">This is paragraph <b>one</b>. </p>
print(soup('p', align="center")[0]['id'])  # firstpara
print(soup.find('p', align=re.compile('^c.*'))['id'])  # firstpara
print(soup.find('p').b.string)  # one
print(soup('p')[1].b.string)  # two
print("修改soup：")
titleTag['id'] = 'theTitle'
titleTag.contents[0].replaceWith("New title")
print(soup.html.head)
# <head><title id="theTitle">New title</title></head>
print(soup.p.extract())
print(soup.prettify())
soup.body.insert(0, "This page used to have ")
soup.body.insert(2, " &lt;p&gt; tags!")
print(soup.body)
```
