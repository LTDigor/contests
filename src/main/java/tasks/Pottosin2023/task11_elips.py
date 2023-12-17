import math


def bisect(fun, min_val, max_val):
    while min_val <= max_val:
        mid = min_val + (max_val - min_val) // 2
        f_mid, f_mid_right = fun(mid), fun(mid + 1)
        if f_mid_right > 0 and f_mid < 0:
            if f_mid_right < -f_mid:
                return mid + 1
            else:
                return mid
        elif f_mid < 0:
            min_val = mid + 1
        else:
            max_val = mid - 1

    return min_val


def f(x):
    s1 = (x ** 2 / r1 ** 2 - 1)
    s2 = (x ** 2 / r2 ** 2 - 1)
    s3 = (x ** 2 / r3 ** 2 - 1)
    return (s1 ** 0.5 + s2 ** 0.5) ** 2 - 2 * s3


print("? 0")
r1 = float(input())

print("? 90")
r2 = float(input())

print("? 89")
r4 = float(input())

if r4 > r2:
    print("? 135")
    r3 = float(input())
else:
    print("? 45")
    r3 = float(input())

eps = 10 ** (-14)

a = round(bisect(f, min_val=math.ceil(max([r1, r2, r3])), max_val=10_000))
b = round(((1 / r1 ** 2) + (1 / r2 ** 2) - (1 / a ** 2)) ** (-0.5))
d = round(math.degrees(math.asin(b / r1 * ((a ** 2 - r1 ** 2) / (a ** 2 - b ** 2)) ** 0.5)))

if r4 < r2 and d > 0:
    d = 180 - d
print("!", a, b, d)

# 2.268
# 3.46410161513775
# 4.8427
# 2.06192

# 2.0
# 6.0
# 5.9
# 2.683281573

# 2.00027079854
# 5.99270325646
# 6.00
# 5.99270325646
