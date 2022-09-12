# numpy的便捷函数

[TOC]

## 相关性
- 样本<br>
a = [a1 a2 ... an]<br>
b = [b1 b2 ... bn]<br>
- 均值<br>
ave(a) = (a1+a2+...+an)/n<br>
ave(b) = (b1+b2+...+bn)/n<br>
- 离差<br>
dev(a) = [a1 a2 ... an] - ave(a)<br>
dev(b) = [b1 b2 ... bn] - ave(b)<br>
- 方差<br>
var(a) = ave(dev(a)dev(a))<br>
var(b) = ave(dev(b)dev(b))<br>
- 标准差<br>
std(a) = sqrt(var(a))<br>
std(b) = sqrt(var(b))<br>
- 自协方差<br>
cov(a,a) = ave(dev(a)dev(a)) = var(a)<br>
cov(b,b) = ave(dev(b)dev(b)) = var(b)<br>
- 互协方差<br>
cov(a,b) = ave(dev(a)dev(b))<br>
cov(b,a) = ave(dev(b)dev(a))<br>
- 相关矩阵<br>
| cov(a,a)/std(a)std(a)  cov(a,b)/std(a)std(b) |<br>
| cov(b,a)/std(b)std(a)  cov(b,b)/std(b)std(b) |<br>
即：<br>
| 1               coco(a,b) |<br>
| coco(b,a)              1  |<br>

- 相关性系数
coco(a,b) == coco(b, a)，取值[-1, 1]。
相关性系数的大小反映了两个随机信号间相关性的强弱，其绝对值越接近于1，相关性越强，反之越接近于0，相关性越弱。相干性系数的正负则反映了两个随机信号相关性的方向，正值表示正相关，即变化趋势一致，负值表示反相关，即变化趋势相反。<br>
numpy.cov() -> 相关矩阵的分子矩阵<br>
numpy.corrcoef() -> 相关矩阵
- 示例代码：
```
import datetime as dt
import numpy as np
import matplotlib.pyplot as mp
import matplotlib.dates as md


def dmy2ymd(dmy):
    dmy = str(dmy, encoding='utf-8')
    date = dt.datetime.strptime(
        dmy, '%d-%m-%Y').date()
    ymd = date.strftime('%Y-%m-%d')
    return ymd


dates, bhp_closing_prices = np.loadtxt(
    'bhp.csv', delimiter=',',
    usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'), converters={1: dmy2ymd})

_, vale_closing_prices = np.loadtxt(
    'vale.csv', delimiter=',',
    usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'),
    converters={1: dmy2ymd})

bhp_returns = np.diff(bhp_closing_prices) / bhp_closing_prices[:-1]
vale_returns = np.diff(vale_closing_prices) / vale_closing_prices[:-1]

ave_a = np.mean(bhp_returns)
dev_a = bhp_returns - ave_a
var_a = np.mean(dev_a * dev_a)
std_a = np.sqrt(var_a)
ave_b = np.mean(vale_returns)
dev_b = vale_returns - ave_b
var_b = np.mean(dev_b * dev_b)
std_b = np.sqrt(var_b)
cov_aa = var_a
cov_ab = np.mean(dev_a * dev_b)
cov_bb = var_b
cov_ba = np.mean(dev_b * dev_a)

covs = np.array([
    [cov_aa, cov_ab],
    [cov_ba, cov_bb]])
stds = np.array([
    [std_a * std_a, std_a * std_b],
    [std_b * std_a, std_b * std_b]])

corr = covs / stds
print(corr)

corr = np.corrcoef(bhp_returns, vale_returns)
print(corr)

covs = np.cov(bhp_returns, vale_returns)
std_a = np.std(bhp_returns, ddof=1)
std_b = np.std(vale_returns, ddof=1)
stds = np.array([
    [std_a * std_a, std_a * std_b],
    [std_b * std_a, std_b * std_b]])
corr = covs / stds
print(corr)

mp.gcf().set_facecolor(np.ones(3) * 240 / 255)
mp.title('Correlation Of Returns', fontsize=20)
mp.xlabel('Date', fontsize=14)
mp.ylabel('Returns', fontsize=14)
ax = mp.gca()
ax.xaxis.set_major_locator(
    md.WeekdayLocator(byweekday=md.MO))
ax.xaxis.set_minor_locator(md.DayLocator())
ax.xaxis.set_major_formatter(
    md.DateFormatter('%d %b %Y'))
mp.tick_params(labelsize=10)
mp.grid(linestyle=':')
dates = dates.astype(md.datetime.datetime)
mp.plot(dates[:-1], bhp_returns, c='orangered',
        label='BHP')
mp.plot(dates[:-1], vale_returns, c='dodgerblue',
        label='VALE')
mp.legend()
mp.gcf().autofmt_xdate()
mp.show()
```

## 多项式拟合
函数：nump.ployfit()
- 示例代码：
```
import datetime as dt
import numpy as np
import matplotlib.pyplot as mp
import matplotlib.dates as md


def dmy2ymd(dmy):
    dmy = str(dmy, encoding='utf-8')
    date = dt.datetime.strptime(
        dmy, '%d-%m-%Y').date()
    ymd = date.strftime('%Y-%m-%d')
    return ymd


dates, bhp_closing_prices = np.loadtxt(
    'bhp.csv', delimiter=',', usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'), converters={1: dmy2ymd})

_, vale_closing_prices = np.loadtxt(
    'vale.csv', delimiter=',', usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'), converters={1: dmy2ymd})

diff_closing_prices = bhp_closing_prices - vale_closing_prices
days = dates.astype(int)

p = np.polyfit(days, diff_closing_prices, 5)
poly_closing_prices = np.polyval(p, days)
q = np.polyder(p)

roots = np.roots(q)
reals = roots[np.isreal(roots)].real
peeks = [[days[0], np.polyval(p, days[0])]]
for real in reals:
    if days[0] < real and real < days[-1]:
        peeks.append([real, np.polyval(p, real)])
peeks.append([days[-1], np.polyval(p, days[-1])])
peeks.sort()
peeks = np.array(peeks)

mp.gcf().set_facecolor(np.ones(3) * 240 / 255)
mp.title('Polynomial Fitting', fontsize=20)
mp.xlabel('Date', fontsize=14)
mp.ylabel('Returns', fontsize=14)
ax = mp.gca()
ax.xaxis.set_major_locator(
    md.WeekdayLocator(byweekday=md.MO))
ax.xaxis.set_minor_locator(md.DayLocator())
ax.xaxis.set_major_formatter(
    md.DateFormatter('%d %b %Y'))
mp.tick_params(labelsize=10)
mp.grid(linestyle=':')
dates = dates.astype(md.datetime.datetime)
mp.plot(dates, poly_closing_prices, c='dodgerblue',
        linewidth=3, label='Polynomial Fitting')
mp.scatter(dates, diff_closing_prices,
           c='limegreen', alpha=0.5, s=80,
           label='Difference Price')
dates, prices = np.hsplit(peeks, 2)
dates = dates.astype(int).astype('M8[D]').astype(
    md.datetime.datetime)
for i in range(1, dates.size):
    mp.annotate('', xytext=(dates[i - 1], prices[i - 1]),
                xy=(dates[i], prices[i]), size=40,
                arrowprops=dict(arrowstyle='fancy',
                                color='orangered', alpha=0.25))
mp.legend()
mp.gcf().autofmt_xdate()
mp.show()
```

## 符号数组
- sign，返回数组中每个元素的符号，用1/-1/0表示正/负/零。
- piecewise，根据多个条件满足与否，将判断结果映射到一个给定的数组中。
- 示例代码：
```
import datetime as dt
import numpy as np
import matplotlib.pyplot as mp
import matplotlib.dates as md


def dmy2ymd(dmy):
    dmy = str(dmy, encoding='utf-8')
    date = dt.datetime.strptime(
        dmy, '%d-%m-%Y').date()
    ymd = date.strftime('%Y-%m-%d')
    return ymd


dates, closing_prices, volumes = np.loadtxt(
    'bhp.csv', delimiter=',', usecols=(1, 6, 7), unpack=True,
    dtype=np.dtype('M8[D],f8,f8'), converters={1: dmy2ymd})

diff_closing_prices = np.diff(closing_prices)
# sign_closing_prices = np.sign(diff_closing_prices)
sign_closing_prices = np.piecewise(
    diff_closing_prices, [diff_closing_prices < 0, diff_closing_prices == 0,
    diff_closing_prices > 0], [-1, 0, 1])
obvs = volumes[1:] * sign_closing_prices

mp.gcf().set_facecolor(np.ones(3) * 240 / 255)
mp.title('On-Balance Volume', fontsize=20)
mp.xlabel('Date', fontsize=14)
mp.ylabel('OBV', fontsize=14)
ax = mp.gca()
ax.xaxis.set_major_locator(
    md.WeekdayLocator(byweekday=md.MO))
ax.xaxis.set_minor_locator(md.DayLocator())
ax.xaxis.set_major_formatter(
    md.DateFormatter('%d %b %Y'))
mp.tick_params(labelsize=10)
mp.grid(linestyle=':')
dates = dates[1:].astype(md.datetime.datetime)
rise = obvs > 0
fall = obvs < 0
fc = np.zeros(dates.size, dtype='3f4')
ec = np.zeros(dates.size, dtype='3f4')
fc[rise], fc[fall] = (1, 0, 0), (0, 0.5, 0)
ec[rise], ec[fall] = (1, 1, 1), (1, 1, 1)
mp.bar(dates, obvs, 1.0, 0, align='center',
       color=fc, edgecolor=ec, label='OBV')
mp.legend()
mp.gcf().autofmt_xdate()
mp.show()
```

## 矢量化
函数：numpy.vectorize()<br>
例如：<br>
&emsp;&emsp;def fun (a, b, c):<br>
&emsp;&emsp;&emsp;&emsp;return a + b + c<br>
&emsp;&emsp;A = np.array([...])<br>
&emsp;&emsp;B = np.array([...])<br>
&emsp;&emsp;C = np.array([...])<br>
&emsp;&emsp;D = numpy.vectorize(fun)(A, B, C)<br>
- 示例代码：
```
import numpy as np


def add(a, b, c):
    return a + b + c


a, b, c = 1, 10, 100
d = add(a, b, c)
print(d)

A = np.arange(1, 10)
B = A * 10
C = B * 10
D = np.vectorize(add)(A, B, C)
print(D)
```

## 曲线交点
汉宁窗函数numpy.hanning()返回一个余弦函数序列：[...]。将其归一化后作为卷积核可以用于曲线平滑，消除噪声干扰。
利用多项式拟合找到平滑后数据的拟合曲线方程f1(x)和f2(x)，f1(x)-f2(x)=0方程的根即两条曲线的交点。
- 示例代码：
```
import warnings
import datetime as dt
import numpy as np
import matplotlib.pyplot as mp
import matplotlib.dates as md

warnings.filterwarnings('ignore', category=np.RankWarning)


def dmy2ymd(dmy):
    dmy = str(dmy, encoding='utf-8')
    date = dt.datetime.strptime(
        dmy, '%d-%m-%Y').date()
    ymd = date.strftime('%Y-%m-%d')
    return ymd


dates, bhp_closing_prices = np.loadtxt(
    'bhp.csv', delimiter=',', usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'), converters={1: dmy2ymd})

_, vale_closing_prices = np.loadtxt(
    'vale.csv', delimiter=',', usecols=(1, 6), unpack=True,
    dtype=np.dtype('M8[D],f8'), converters={1: dmy2ymd})

bhp_returns = np.diff(bhp_closing_prices) / bhp_closing_prices[:-1]
vale_returns = np.diff(vale_closing_prices) / vale_closing_prices[:-1]

N = 8
weights = np.hanning(N)
weights /= weights.sum()

bhp_smooth_returns = np.convolve(weights, bhp_returns, 'valid')
vale_smooth_returns = np.convolve(weights, vale_returns, 'valid')

days = dates[N - 1:-1].astype(int)
degree = 5

bhp_p = np.polyfit(days, bhp_smooth_returns, degree)
bhp_poly_returns = np.polyval(bhp_p, days)

vale_p = np.polyfit(days, vale_smooth_returns, degree)
vale_poly_returns = np.polyval(vale_p, days)

sub_p = np.polysub(bhp_p, vale_p)
roots = np.roots(sub_p)
reals = roots[np.isreal(roots)].real

inters = []
for real in reals:
    if days[0] < real and real < days[-1]:
        inters.append([real, np.polyval(bhp_p, real)])

inters.sort()
inters = np.array(inters)

mp.gcf().set_facecolor(np.ones(3) * 240 / 255)
mp.title('Smoothing Returns', fontsize=20)
mp.xlabel('Date', fontsize=14)
mp.ylabel('Returns', fontsize=14)
ax = mp.gca()
ax.xaxis.set_major_locator(
    md.WeekdayLocator(byweekday=md.MO))
ax.xaxis.set_minor_locator(md.DayLocator())
ax.xaxis.set_major_formatter(
    md.DateFormatter('%d %b %Y'))
mp.tick_params(labelsize=10)
mp.grid(linestyle=':')
dates = dates.astype(md.datetime.datetime)
mp.plot(dates[:-1], bhp_returns, c='orangered', alpha=0.25, label='BHP')
mp.plot(dates[:-1], vale_returns, c='dodgerblue', alpha=0.25, label='VALE')
mp.plot(dates[N - 1:-1], bhp_smooth_returns,
        c='orangered', alpha=0.75, label='BHP')
mp.plot(dates[N - 1:-1], vale_smooth_returns,
        c='dodgerblue', alpha=0.75, label='VALE')
mp.plot(dates[N - 1:-1], bhp_poly_returns,
        c='orangered', linewidth=3, label='BHP')
mp.plot(dates[N - 1:-1], vale_poly_returns,
        c='dodgerblue', linewidth=3, label='VALE')
dates, returns = np.hsplit(inters, 2)
dates = dates.astype(int).astype('M8[D]').astype(md.datetime.datetime)
mp.scatter(dates, returns, marker='x', c='firebrick', s=120, lw=3, zorder=3)
mp.legend()
mp.gcf().autofmt_xdate()
mp.show()

```
<br><br><br><br>

