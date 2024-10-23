def f(x):
    res = 0
    while x > 0:
        x = x >> 1
        res += 1
    return 1 << res

def g(x):
    return f(x) - 1 - x

n = int(input())
a = list(map(int, input().split()))
a.sort()

dp_dir = [0] * n
dp_rev = [0] * n

dp_dir[0] = a[0]
dp_rev[0] = g(a[0])

for i in range(1, n):
    dp_dir[i] = max(dp_rev[i-1] & a[i], dp_dir[i-1] & a[i])
    dp_rev[i] = max(dp_rev[i-1] & g(a[i]), dp_dir[i-1] & g(a[i]))

print(max(dp_rev[-1], dp_dir[-1]))
