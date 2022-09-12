# numpy基础

- [numpy基础](#numpy基础)
  - [数组对象](#数组对象)
  - [元素索引](#元素索引)
  - [数据类型](#数据类型)
  - [通过dtype指定数组元素的数据类型](#通过dtype指定数组元素的数据类型)
  - [数据类型名编码规则](#数据类型名编码规则)
  - [切片](#切片)
  - [变维](#变维)
  - [组合数组](#组合数组)
  - [分割数组](#分割数组)
  - [ndarray对象的属性](#ndarray对象的属性)
  - [类型转换](#类型转换)

## 数组对象

`numpy.ndarray`是一个表示多维数组的类，其中包括：

- 实际数据
- 描述实际数据的元数据

大部分针对数组对象的操作起始就是对元数据的访问或修改，而并不涉及实际数据，借以提高性能。如下：

- 实际数据：`1 2 3 4 5 6 7 8 9`
- 元数据：`3x3->1x9->9x1`

numpy数组数据元素的类型是一致的。通过牺牲灵活性，换取优越的性能。

numpy数组中的元素可以可以通过下标进行访问，起始编号为`0`，最后一个元素的下标为`n-1`。

`ndarray.dtype`属性表示元素的数据类型。

`ndarray.shape`属性表示数组的维度，以`tuple`的形式表示多维。

```python
import numpy as np

a = np.arange(1, 3)
print(a.shape, a)  # (2,) [1 2]

b = np.array([
    [1, 2, 3],
    [4, 5, 6]])
print(b.shape, b, sep='\n')
# (2, 3)
# [[1 2 3]
#  [4 5 6]]

c = np.array([
    [np.arange(1, 5),
     np.arange(5, 9),
     np.arange(9, 13)],
    [np.arange(13, 17),
     np.arange(17, 21),
     np.arange(21, 25)]])
print(c.shape, c, sep='\n')
# (2, 3, 4)
# [[[ 1  2  3  4]
#   [ 5  6  7  8]
#   [ 9 10 11 12]]

#  [[13 14 15 16]
#   [17 18 19 20]
#   [21 22 23 24]]]

d = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9], dtype=np.int8)
print(d.dtype, type(d[0]), d[0])  # int8 <class 'numpy.int8'> 1

e = d.astype(np.int16)
print(e.dtype, type(e[0]), e[0])  # int16 <class 'numpy.int16'> 1
e[0] = 1000
print(e[0], d[0])  # 1000 1，两个值不相等说明开辟了新的内存空间并进行了内存拷贝
print(e.shape, e, sep='\n')
# (9,)
# [1000    2    3    4    5    6    7    8    9]

f = e.reshape((3, 3))
print(f.shape, f, sep='\n')
# (3, 3)
# [[1000    2    3]
#  [   4    5    6]
#  [   7    8    9]]
f[0][0] = 111
print(f[0][0], e[0])  # 111 111，两个值相等说明reshape后的数组与原数组共享内存空间

g = e.reshape((3, 3)).copy()
print(g.shape, g, sep='\n')
# (3, 3)
# [[111   2   3]
#  [  4   5   6]
#  [  7   8   9]]
g[0][0] = 222
print(g[0][0], e[0])  # 222 111，两个值不相等说明开辟了新的内存空间并进行了内存拷贝

print(e.shape, e, sep='\n')
# (9,)
# [111   2   3   4   5   6   7   8   9]
e.shape = (3, 3)
print(e.shape, e, sep='\n')  # 通过修改shape属性修改数组的形状
# (3, 3)
# [[111   2   3]
#  [  4   5   6]
#  [  7   8   9]]
```

## 元素索引

数组元素可以通过索引的方式进行访问(所有的索引都是从0开始)，如下：

- `数组对象[页索引][行索引][列索引]`
- `数组对象[页索引, 行索引, 列索引]`

```python
import numpy as np

a = np.array([
    [[1, 2],
     [3, 4]],
    [[5, 6],
     [7, 8]]])

print(a)
print(a[0])
print(a[0][0])
print(a[0][0][0])

for i in range(a.shape[0]):
    for j in range(a.shape[1]):
        for k in range(a.shape[2]):
            print(a[i, j, k], end=' ')

# [[[1 2]
#   [3 4]]

#  [[5 6]
#   [7 8]]]
# [[1 2]
#  [3 4]]
# [1 2]
# 1
# 1 2 3 4 5 6 7 8
```

## 数据类型

所有的类型都是类：`type(1) -> <class 'int'>`。

类型也是对象，类型对象也有类型，类型对象的类型是`type`：

- `type(type(1)) -> <class 'type'>`
- `type(type(type(1))) -> <class 'type'>`

数据类型：

- python
  - `bool`
  - `int`
  - `float`
  - `complex`
  - `str`
  - `tuple`
  - `list`
  - `dict`
  - `set`
- numpy
  - `bool_`
  - `int8`
  - `int16`
  - `int32`
  - `int64`
  - `uint8`
  - `uint16`
  - `uint32`
  - `uint64`
  - `float16`
  - `float32`
  - `float64`
  - `complex64`
  - `complex128`
  - `str_`
- 自定义的数据类型
  - `dtype([('name', str_, 40), ('age', uint8)])`

## 通过dtype指定数组元素的数据类型

语法：`数据对象 = np.array([初值表], dtype=元素类型)`。

- numpy类型：`..., dtype=np.int8`
- 泛化类型：`..., dtype=np.integer`
- python类型：`..., dtype=int`
- 类型名字符串：`..., dtype='int8'`
- 类型名编码串：`..., dtype='i1'`
- 变长类型+长度：`..., dtype=(np.str_, 14)`
- 定长类型+维度：`..., dtype=(np.int8, 3)`
- 由逗号分割的多个类型名编码串：`..., dtype='U14,i1'`
- [(名称, 类型, 长度/维度), ...]：`..., dtype=[('name', np.str_, 14), ('age', np.int8)]`
- (源类型, 目标类型)：用目标类型的方式访问源类型的数据

```python
import numpy as np

a = np.array([1234], dtype=np.int16)
print(type(a[0]), a.dtype, a.dtype.str, a.dtype.char, a.dtype.itemsize)
# <class 'numpy.int16'> int16 <i2 h 2
# 以上结果'<'表示小端存储，'>'则表示大端存储

b = np.array([1234], dtype=np.integer)
print(type(b[0]), b.dtype, b.dtype.str, b.dtype.char, b.dtype.itemsize)
# <class 'numpy.int32'> int32 <i4 l 4

c = np.array([1234], dtype=int)
print(type(c[0]), c.dtype, c.dtype.str, c.dtype.char, c.dtype.itemsize)
# <class 'numpy.int32'> int32 <i4 l 4

d = np.array([1234], dtype='int16')
print(type(d[0]), d.dtype, d.dtype.str, d.dtype.char, d.dtype.itemsize)
# <class 'numpy.int16'> int16 <i2 h 2

e = np.array([1234], dtype='>i2')
print(type(e[0]), e.dtype, e.dtype.str, e.dtype.char, e.dtype.itemsize)
# <class 'numpy.int16'> >i2 >i2 h 2

f = np.array(['1234'], dtype=(np.str_, 4))
print(type(f[0]), f.dtype, f.dtype.str, f.dtype.char, f.dtype.itemsize)
# <class 'numpy.str_'> <U4 <U4 U 16

g = np.array([(1, 2), (3, 4)], dtype=(np.int16, 2))
print(type(g[0]), g.dtype, g.dtype.str, g.dtype.char, g.dtype.itemsize, g.shape)
print(g)
# <class 'numpy.ndarray'> int16 <i2 h 2 (2, 2)
# [[1 2]
#  [3 4]]

h = np.array([('abcd', 1234)], dtype='U4,i2')
print(h[0]['f0'], h[0]['f1'])
# abcd 1234

i = np.array([('abcd', 1234)], dtype=[('name', np.str_, 4), ('age', np.int16)])
print(i[0]['name'], i[0]['age'])
# abcd 1234

t = np.dtype(('>u2', [('lo', np.uint8), ('hi', np.uint8)]))
j = np.array([0x1234], dtype=t)
print('{:x} {:x}'.format(j['lo'][0], j['hi'][0]))
# 12 34

k = np.array([0x5678], dtype=t)
print('{:x} {:x}'.format(k['lo'][0], k['hi'][0]))
# 56 78
```

## 数据类型名编码规则

格式：`[A]B[C]`

- A：字节序(>/</=)
- B：类型字符
  - `?` - boolean
  - `b` - byte (有符号单字节整数，等价于int8)
  - `B` - unsigned byte (无符号单字节整数，等价于uint8)
  - `i` - signed integer (有符号整数)
  - `u` - unsigned integer (无符号整数)
  - `f` - floating point (浮点数)
  - `c` - complex-floating point (浮点复数)
  - `m` - timedelta (时间差)
  - `M` - datetime (时刻)
  - `O` - python object (对象)
  - `S` - 单或多字节编码的字符串(ASCII/GBK)
  - `U` - unicode编码的字符串(4个字节/字符)
- C：长度，对于整数或者浮点数指字节数，对于字符串指字符数

## 切片

语法：`数组[第1维起始:终止:步长, 第2维起始:终止:步长[, ...]]`

```python
import numpy as np

a = np.arange(1, 10)
print(a)
print(a[:3])
print(a[3:6])
print(a[6:])
print(a[::-1])
print(a[:-4:-1])
print(a[-4:-7:-1])
print(a[-7::-1])
print(a[:])
print(a[::3])
print(a[1::3])
print(a[2::3])
# [1 2 3 4 5 6 7 8 9]
# [1 2 3]
# [4 5 6]
# [7 8 9]
# [9 8 7 6 5 4 3 2 1]
# [9 8 7]
# [6 5 4]
# [3 2 1]
# [1 2 3 4 5 6 7 8 9]
# [1 4 7]
# [2 5 8]
# [3 6 9]

b = np.arange(1, 25).reshape(2, 3, 4)
print(b)
print(b[:, 0, 0])
print(b[0, :, :])
print(b[0, ...])
print(b[0])
print(b[0, 1, ::2])
print(b[..., 1])
print(b[0, ::-1, ::-1])
print(b[-1, 1:, 2:])
# [[[ 1  2  3  4]
#   [ 5  6  7  8]
#   [ 9 10 11 12]]

#  [[13 14 15 16]
#   [17 18 19 20]
#   [21 22 23 24]]]
# [ 1 13]
# [[ 1  2  3  4]
#  [ 5  6  7  8]
#  [ 9 10 11 12]]
# [[ 1  2  3  4]
#  [ 5  6  7  8]
#  [ 9 10 11 12]]
# [[ 1  2  3  4]
#  [ 5  6  7  8]
#  [ 9 10 11 12]]
# [5 7]
# [[ 2  6 10]
#  [14 18 22]]
# [[12 11 10  9]
#  [ 8  7  6  5]
#  [ 4  3  2  1]]
# [[19 20]
#  [23 24]]
```

## 变维

- 视图变维`reshape`/`ravel`
  - 只创建反映新纬度的元数据，实际数据与原数组共享
- 复制变维`flatten`
  - 创建反映新维度的元数据，同时也复制原数组中的实际数据
- 就地变维`shape`/`resize`
  - 直接修改调用此方法的数组对象中的元数据为新的维度
- 视图转置`transpose`
  - 能够进行转置操作的数组至少是二维数组

```python
import numpy as np

a = np.arange(1, 9)
print(a)

b = a.reshape(2, 4)
print(b)

c = b.reshape(2, 2, 2)
print(c)

d = c.ravel()
print(d)

a += 10
print(a)
print(b)
print(c)
print(d)

e = c.flatten()
print(e)

e -= 10
print(a)
print(b)
print(c)
print(d)
print(e)

a.shape = (2, 2, 2)
print(a)

a.resize(2, 4)
print(a)

f = a.transpose()
print(f)

f -= 10
print(a)
print(f)

g = np.array([[1], [2], [3]])
print(g)

h = g.transpose()
print(h)

i = np.array([1, 2, 3])
print(i)

j = i.transpose()
print(j)

# [1 2 3 4 5 6 7 8]
# [[1 2 3 4]
#  [5 6 7 8]]
# [[[1 2]
#   [3 4]]

#  [[5 6]
#   [7 8]]]
# [1 2 3 4 5 6 7 8]
# [11 12 13 14 15 16 17 18]
# [[11 12 13 14]
#  [15 16 17 18]]
# [[[11 12]
#   [13 14]]

#  [[15 16]
#   [17 18]]]
# [11 12 13 14 15 16 17 18]
# [11 12 13 14 15 16 17 18]
# [11 12 13 14 15 16 17 18]
# [[11 12 13 14]
#  [15 16 17 18]]
# [[[11 12]
#   [13 14]]

#  [[15 16]
#   [17 18]]]
# [11 12 13 14 15 16 17 18]
# [1 2 3 4 5 6 7 8]
# [[[11 12]
#   [13 14]]

#  [[15 16]
#   [17 18]]]
# [[11 12 13 14]
#  [15 16 17 18]]
# [[11 15]
#  [12 16]
#  [13 17]
#  [14 18]]
# [[1 2 3 4]
#  [5 6 7 8]]
# [[1 5]
#  [2 6]
#  [3 7]
#  [4 8]]
# [[1]
#  [2]
#  [3]]
# [[1 2 3]]
# [1 2 3]
# [1 2 3]
```

## 组合数组

- 垂直组合：`v = numpy.vstack((u, d))`
  - 将维度相同的u和d数组按照自上向下的顺序组合
- 水平组合：`h = numpy.hstack((l, r))`
  - 将维度相同的l和r数组按照自左向右的顺序组合
- 深度组合`d = numpy.dstack((l, r))`
- 行组合`r = numpy.row_stack((u, d))`
- 列组合`c = numpy.column_stack((l, r))`

```python
import numpy as np

a = np.arange(11, 20).reshape(3, 3)
print(a)
b = np.arange(21, 30).reshape(3, 3)
print(b)

# c = np.vstack((a, b))等价于如下使用concatenate函数
c = np.concatenate((a, b), axis=0)
print(c)

# d = np.hstack((a, b))等价于如下使用concatenate函数
d = np.concatenate((a, b), axis=1)
print(d)

e = np.dstack((a, b))
print(e)

f = np.arange(1, 7).reshape(2, 3)
print(f)
g = np.arange(7, 10).reshape(1, -1)
print(g)

h = np.vstack((f, g))
print(h)

i = np.arange(1, 4)
print(i)
j = np.arange(4, 7)
print(j)

k = np.vstack((i, j))
print(k)

l = np.row_stack((i, j))
print(l)

m = np.column_stack((i, j))
print(m)

# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
# [[21 22 23]
#  [24 25 26]
#  [27 28 29]]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]
#  [21 22 23]
#  [24 25 26]
#  [27 28 29]]
# [[11 12 13 21 22 23]
#  [14 15 16 24 25 26]
#  [17 18 19 27 28 29]]
# [[[11 21]
#   [12 22]
#   [13 23]]

#  [[14 24]
#   [15 25]
#   [16 26]]

#  [[17 27]
#   [18 28]
#   [19 29]]]
# [[1 2 3]
#  [4 5 6]]
# [[7 8 9]]
# [[1 2 3]
#  [4 5 6]
#  [7 8 9]]
# [1 2 3]
# [4 5 6]
# [[1 2 3]
#  [4 5 6]]
# [[1 2 3]
#  [4 5 6]]
# [[1 4]
#  [2 5]
#  [3 6]]
```

## 分割数组

使用函数`vsplit`/`hsplit`/`dsplit`可以分割数组。

注意，使用上述函数分割数组时，只能进行平均分割。

```python
import numpy as np

a = np.vstack((
    np.arange(11, 20).reshape(3, 3),
    np.arange(21, 30).reshape(3, 3)))
print(a)

#b, c = np.vsplit(a, 2)
b, c = np.split(a, 2, axis=0)
print(b)
print(c)

d = np.hstack((
    np.arange(11, 20).reshape(3, 3),
    np.arange(21, 30).reshape(3, 3)))
print(d)

#e, f = np.hsplit(d, 2)
e, f = np.split(d, 2, axis=1)
print(e)
print(f)

g = np.dstack((
    np.arange(11, 20).reshape(3, 3),
    np.arange(21, 30).reshape(3, 3)))
print(g)

h, i = np.dsplit(g, 2)
print(h.T[0].T)
print(i.T[0].T)

# [[11 12 13]
#  [14 15 16]
#  [17 18 19]
#  [21 22 23]
#  [24 25 26]
#  [27 28 29]]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
# [[21 22 23]
#  [24 25 26]
#  [27 28 29]]
# [[11 12 13 21 22 23]
#  [14 15 16 24 25 26]
#  [17 18 19 27 28 29]]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
# [[21 22 23]
#  [24 25 26]
#  [27 28 29]]
# [[[11 21]
#   [12 22]
#   [13 23]]

#  [[14 24]
#   [15 25]
#   [16 26]]

#  [[17 27]
#   [18 28]
#   [19 29]]]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
# [[21 22 23]
#  [24 25 26]
#  [27 28 29]]
```

## ndarray对象的属性

- dtype：元素的类型
- shape：维度
- ndim：维数
- size：元素数(不一定等于len)
- itemsize：每个元素的字节数
- nbytes：总字节数(= size x itemsize)
- T：转置视图
- real/imag：实部/虚部数组
- flat：扁平迭代器

## 类型转换

```python
import numpy as np

a = np.array([
    (1 + 1j, 2 + 4j, 3 + 7j),
    (4 + 2j, 5 + 5j, 6 + 8j),
    (7 + 3j, 8 + 6j, 9 + 9j)])
print(a.dtype)
print(a.shape)
print(a.ndim)
print(a.size)
print(a.itemsize)
print(a.nbytes)
print(a.T)
print(a.real)
print(a.imag)
# complex128
# (3, 3)
# 2
# 9
# 16
# 144
# [[ 1.+1.j  4.+2.j  7.+3.j]
#  [ 2.+4.j  5.+5.j  8.+6.j]
#  [ 3.+7.j  6.+8.j  9.+9.j]]
# [[ 1.  2.  3.]
#  [ 4.  5.  6.]
#  [ 7.  8.  9.]]
# [[ 1.  4.  7.]
#  [ 2.  5.  8.]
#  [ 3.  6.  9.]]

# 遍历数组元素
for row in a:
    for elm in row:
        print(elm)
# 遍历数组元素
for elm in a.flat:
    print(elm)

b = [1, 2, 3, 4, 5]
print(b)
c = np.array(b)
print(c)
d = c.tolist()
print(d)
e = np.array(b).astype(str).tolist()
print(e)
# [1, 2, 3, 4, 5]
# [1 2 3 4 5]
# [1, 2, 3, 4, 5]
# ['1', '2', '3', '4', '5']
```
