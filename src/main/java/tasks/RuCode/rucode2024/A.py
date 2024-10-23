import math

n = int(input())
l = len(str(n))
res = 0
for i in range(l - 1):
    d = 10 ** (i + 1) - 10 ** i
    res += math.ceil(d / 500)

d = n - (10 ** (l - 1) - 1)
res += math.ceil(d / 500)
print(res)