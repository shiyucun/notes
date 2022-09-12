
# numpy的判等断言

```python
import numpy as np
import numpy.testing as nt


a = 12.34567
b = 12.34569
c = 12.3456000000000007
d = 12.3456000000000009
e = '12.3456000000000007'
f = '12.3456000000000009'

try:
    nt.assert_equal(a, b)
except AssertionError:
    print(' 1 !=')
else:
    print(' 1 ==')

try:
    nt.assert_equal(c, d)
except AssertionError:
    print(' 2 !=')
else:
    print(' 2 ==')

try:
    nt.assert_string_equal(e, f)
except AssertionError:
    print(' 3 !=')
else:
    print(' 3 ==')

try:
    nt.assert_allclose(a, b, rtol=0, atol=1e-5)
except AssertionError:
    print(' 4 !=')
else:
    print(' 4 ==')

try:
    nt.assert_allclose(a, b, rtol=0, atol=1e-4)
except AssertionError:
    print(' 5 !=')
else:
    print(' 5 ==')

try:
    nt.assert_almost_equal(a, b, decimal=5)
except AssertionError:
    print(' 6 !=')
else:
    print(' 6 ==')

try:
    nt.assert_almost_equal(a, b, decimal=4)
except AssertionError:
    print(' 7 !=')
else:
    print(' 7 ==')

try:
    nt.assert_approx_equal(a, b, significant=7)
except AssertionError:
    print(' 8 !=')
else:
    print(' 8 ==')

try:
    nt.assert_approx_equal(a, b, significant=6)
except AssertionError:
    print(' 9 !=')
else:
    print(' 9 ==')

g = np.array([12.34567, np.nan])
h = np.array([12.34569, np.nan])
i = np.array([12.3456000000000007, np.nan])
j = np.array([12.3456000000000009, np.nan])

try:
    nt.assert_array_equal(g, h)
except AssertionError:
    print('10 !=')
else:
    print('10 ==')

try:
    nt.assert_array_equal(i, j)
except AssertionError:
    print('11 !=')
else:
    print('11 ==')

try:
    nt.assert_almost_equal(g, h, decimal=5)
except AssertionError:
    print('12 !=')
else:
    print('12 ==')

try:
    nt.assert_almost_equal(g, h, decimal=4)
except AssertionError:
    print('13 !=')
else:
    print('13 ==')

k = np.array([1.0])
l = np.array([1.0])
eps = np.finfo(l.dtype).eps
print(eps)
m = l + eps
n = m + eps

try:
    nt.assert_array_almost_equal_nulp(k, l)
except AssertionError:
    print('14 !=')
else:
    print('14 ==')

try:
    nt.assert_array_almost_equal_nulp(k, m)
except AssertionError:
    print('15 !=')
else:
    print('15 ==')

try:
    nt.assert_array_almost_equal_nulp(k, n)
except AssertionError:
    print('16 !=')
else:
    print('16 ==')

try:
    nt.assert_array_max_ulp(k, n, maxulp=2)
except AssertionError:
    print('17 !=')
else:
    print('17 ==')

try:
    nt.assert_array_max_ulp(k, n, maxulp=1)
except AssertionError:
    print('18 !=')
else:
    print('18 ==')

#  1 !=
#  2 ==
#  3 !=
#  4 !=
#  5 ==
#  6 !=
#  7 ==
#  8 !=
#  9 ==
# 10 !=
# 11 ==
# 12 !=
# 13 ==
# 2.22044604925e-16
# 14 ==
# 15 ==
# 16 !=
# 17 ==
# 18 !=
```
