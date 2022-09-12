
# numpy的通用函数

- [numpy的通用函数](#numpy的通用函数)
  - [读取csv文件](#读取csv文件)
  - [算术平均值](#算术平均值)
  - [加权平均值](#加权平均值)
  - [最大值和最小值](#最大值和最小值)
  - [极差](#极差)
  - [中位数](#中位数)
  - [统计量](#统计量)
  - [条件选择](#条件选择)
  - [数组处理](#数组处理)
  - [卷积](#卷积)
  - [解线性方程组](#解线性方程组)
  - [ndarray对象的方法](#ndarray对象的方法)

## 读取csv文件

函数：

```python
字段1, 字段2, ... = numpy.loadtxt(
    文件名, delimiter=分隔符, usecols=选择列,
    unpack=是否转换类型, dtype=目标类型, converters=转换器组)
```

csv文件：

csv表格文件列编号从0开始，使用txt打开时表现为每列数据之间使用`,`分隔。

因此读取Excel文件时分隔符使用`,`，如下：

col0 | col1 | col2 | col3 | col4 | col5 | col6 | col7
---|---|---|---|---|---|---|---
AAPL | 28-01-2011 |   | 344.17 | 344.4 | 333.53 | 336.1 | 21144800
AAPL | 31-01-2011 |   | 335.8 | 340.04 | 334.3 | 339.32 | 13473000
AAPL | 01-02-2011 |   | 341.3 | 345.65 | 340.98 | 345.03 | 15236800
AAPL | 02-02-2011 |   | 344.45 | 345.25 | 343.55 | 344.32 | 9242600

使用txt打开的表现形式：

```text
AAPL,28-01-2011, ,344.17,344.4,333.53,336.1,21144800
AAPL,31-01-2011, ,335.8,340.04,334.3,339.32,13473000
AAPL,01-02-2011, ,341.3,345.65,340.98,345.03,15236800
AAPL,02-02-2011, ,344.45,345.25,343.55,344.32,9242600
```

```python
import numpy as np

closing_prices = np.loadtxt(
    'aapl.csv', delimiter=',',
    usecols=(6), unpack=True)

print(type(closing_prices))  # <class 'numpy.ndarray'>

# 三种方式求平均数
mean = closing_prices.sum() / closing_prices.size
print(mean)
mean = np.mean(closing_prices)
print(mean)
mean = closing_prices.mean()
print(mean)
```

## 算术平均值

```text
S = [s1, s2, ..., sn]
m = (s1 + s2 + ... + sn) / n
```

如读取csv文件的示例代码：`closing_prices`是一个数组，使用`np.mean()`函数可以求得数组的平均值。

## 加权平均值

```text
S = [s1, s2, ..., sn]
W = [w1, w2, ..., wn]
a = (s1*w1 + s2*w2 + ... + sn*wn) / (w1 + w2 + ... + wn)
a = average(S, weights=W)
```

```python
import numpy as np

closing_prices, volumes = np.loadtxt(
    'aapl.csv', delimiter=',',
    usecols=(6, 7), unpack=True)

# np.dot()参数为一维时就是对应项相乘，参数为二维时做矩阵乘法
vwap = closing_prices.dot(volumes) / volumes.sum()
print(vwap)

vwap = np.average(closing_prices, weights=volumes)  # 通过average函数求加权平均值
print(vwap)
```

## 最大值和最小值

- `max`/`min`: 在一个数组内求最大/最小值
- `maximum`/`minimum`: 在两个数组之间求对应元素的最大/最小值数组

```python
import numpy as np

highest_prices, lowest_prices = np.loadtxt(
    'aapl.csv', delimiter=',',
    usecols=(4, 5), unpack=True)

max_highest_price, min_lowest_price = highest_prices[0], lowest_prices[0]

for highest_price, lowest_price in zip(highest_prices, lowest_prices):
    if highest_price > max_highest_price:
        max_highest_price = highest_price
    if lowest_price < min_lowest_price:
        min_lowest_price = lowest_price

price_range = max_highest_price - min_lowest_price
print(price_range)

max_highest_price = np.max(highest_prices)
min_lowest_price = np.min(lowest_prices)
price_range = max_highest_price - min_lowest_price
print(price_range)
```

## 极差

极差是指一个数组中最大值与最小值之差。

```python
import numpy as np

highest_prices, lowest_prices = np.loadtxt(
    'aapl.csv', delimiter=',', usecols=(4, 5), unpack=True)

max_highest_price, min_highest_price = highest_prices[0], highest_prices[0]
max_lowest_price, min_lowest_price = lowest_prices[0], lowest_prices[0]

for highest_price, lowest_price in zip(highest_prices, lowest_prices):
    if highest_price > max_highest_price:
        max_highest_price = highest_price
    if highest_price < min_highest_price:
        min_highest_price = highest_price
    if lowest_price > max_lowest_price:
        max_lowest_price = lowest_price
    if lowest_price < min_lowest_price:
        min_lowest_price = lowest_price

high_spread = max_highest_price - min_highest_price
print(high_spread)

low_spread = max_lowest_price - min_lowest_price
print(low_spread)

high_spread = np.ptp(highest_prices)  # 通过ptp函数求极差
print(high_spread)

low_spread = np.ptp(lowest_prices)  # 通过ptp函数求极差
print(low_spread)
```

## 中位数

在有序样本中间位置处的元素就是中位数，偶数个样本时中位数为中间两个样本的平均数。

```python
import numpy as np

closing_prices = np.loadtxt(
    'aapl.csv', delimiter=',', usecols=(6), unpack=True)

sorted_prices = np.msort(closing_prices)
n = sorted_prices.size
median = (sorted_prices[int((n - 1) / 2)] + sorted_prices[int(n / 2)]) / 2
print(median)

median = np.median(closing_prices)  # 使用numpy包中的median函数求中位数
print(median)
```

## 统计量

- 样本：`S = [s1, s2, ..., sn]`
- 均值：`m = (s1 + s2 + ... + sn) / n`
- 离差：`D = [d1, d2, ..., dn], di = si - m`
- 离差方：`Q = [q1, q2, ..., qn], qi = di^2`
- 方差：`V = (q1 + q2 + ... + qn) / n`
  - 反映随机样本的分散程度
- 总体方差：`V = (q1 + q2 + ... + qn) / n`
- 样本方差：`V = (q1 + q2 + ... + qn) / (n - 1)`
- 标准差：`s = sqrt(V)`
  - 反映随机样本的分散程度，经过标准化统一量纲

numpy函数：

- 方差：`numpy.var(S)`
- 标准差：`numpy.std(S)`

```python
import numpy as np

closing_prices = np.loadtxt(
    'aapl.csv', delimiter=',', usecols=(6), unpack=True)

mean = closing_prices.mean()
devs = closing_prices - mean
pvar = (devs ** 2).mean()
pstd = np.sqrt(pvar)
svar = (devs ** 2).sum() / (closing_prices.size - 1)
sstd = np.sqrt(svar)
print(pvar, pstd, svar, sstd)

pvar = np.var(closing_prices)
pstd = np.std(closing_prices)
svar = np.var(closing_prices, ddof=1)
sstd = np.std(closing_prices, ddof=1)
print(pvar, pstd, svar, sstd)
```

## 条件选择

- `numpy.where(条件表达式)`：返回数组中满足给定条件表达式的元素的下标数组
- `numpy.take(数组，下标数组)`：从数组中抽取下标位于下标数组中的元素
- `数组[掩码布尔数组]`：得到满足条件表达式的元素

```python
import numpy as np

a = np.array([10, 40, 20, 60, 50, 30, 70, 90, 80])

b = np.where((a >= 40) & (a <= 60))
print(b)

c = np.take(a, b[0])
print(c)

d = (a >= 40) & (a <= 60)
print(d)

e = a[d]
print(e)

# (array([1, 3, 4], dtype=int64),)
# [40 60 50]
# [False  True False  True  True False False False False]
# [40 60 50]
```

## 数组处理

- `numpy.apply_along_axis(func, axis, arr)`
  - 沿着数组arr的axis轴
  - 将获取到的元素作为参数传给函数func
  - 再将func函数每次调用的返回值组成数组返回

```python
import numpy as np

def print_one(elm):
    print(elm)

def add_ten(elm):
    return elm + 10

a = np.array([
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9]])

np.apply_along_axis(print_one, 0, a)
np.apply_along_axis(print_one, 1, a)
b = np.apply_along_axis(add_ten, 0, a)
print(b)
c = np.apply_along_axis(add_ten, 1, a)
print(c)

# [1 4 7]
# [2 5 8]
# [3 6 9]
# [1 2 3]
# [4 5 6]
# [7 8 9]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
# [[11 12 13]
#  [14 15 16]
#  [17 18 19]]
```

## 卷积

计算举例：

```text
a = [1, 2, 3, 4, 5]
b = [8, 7, 6]

对 a 和 b 求卷积：

0 0 1 2 3 4 5 0 0
6 7 8 0 0 0 0 0 0 -> 6 * 0 + 7 * 0 + 8 * 1 = 8
0 6 7 8 0 0 0 0 0 -> 6 * 0 + 7 * 1 + 8 * 2 = 23
0 0 6 7 8 0 0 0 0 -> 6 * 1 + 7 * 2 + 8 * 3 = 44
0 0 0 6 7 8 0 0 0 -> 6 * 2 + 7 * 3 + 8 * 4 = 65
0 0 0 0 6 7 8 0 0 -> 6 * 3 + 7 * 4 + 8 * 5 = 86
0 0 0 0 0 6 7 8 0 -> 6 * 4 + 7 * 5 + 8 * 0 = 59
0 0 0 0 0 0 6 7 8 -> 6 * 5 + 7 * 0 + 8 * 0 = 30

可以得到以下三种结果：

full: 8 23 44 65 86 59 30
same: 23 44 65 86 59
valid: 44 65 86
```

```python
import numpy as np

a = np.array([1, 2, 3, 4, 5])
b = np.array([8, 7, 6])

c = np.convolve(a, b)
print(c)
d = np.convolve(a, b, 'same')
print(d)
e = np.convolve(a, b, 'valid')
print(e)

# [ 8 23 44 65 86 59 30]
# [23 44 65 86 59]
# [44 65 86]
```

## 解线性方程组

```python
import numpy as np

# 系数矩阵
a = np.array([[4, 2, 6], [3, 2, 7], [1, 3, 9]])
# 结果矩阵
b = np.array([[26], [28], [34]])
# 未知数矩阵
c = np.linalg.lstsq(a, b, rcond=None)[0]
print(c)

# [[1.]
#  [2.]
#  [3.]]
```

## ndarray对象的方法

- `clip`
  - 原数组中：
    - 所有比给定最大值大的元素全部被设定为最大值
    - 所有比最小值小的元素全部被设定为最小值。
- `compress`
  - 根据给定条件筛选数组中的满足条件的元素
- `prod`/`cumprod`
  - 元素累乘

```python
import numpy as np

a = np.arange(1, 6)
print(a)
b = a.clip(min=2)
print(b)
c = a.clip(max=4)
print(c)
d = a.clip(2, 4)
print(d)
e = a.compress(2 <= a)
print(e)
f = a.compress(a <= 4)
print(f)
g = a.compress((2 <= a) & (a <= 4))
print(g)
h = a.prod()
print(h)
i = 10
print('{}! ='.format(i), np.arange(1, i + 1).prod())
j = a.cumprod()
print(j)

# [1 2 3 4 5]
# [2 2 3 4 5]
# [1 2 3 4 4]
# [2 2 3 4 4]
# [2 3 4 5]
# [1 2 3 4]
# [2 3 4]
# 120
# 10! = 3628800
# [  1   2   6  24 120]
```
