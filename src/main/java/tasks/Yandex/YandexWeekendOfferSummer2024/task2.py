import bisect

n, m, k = map(int, input().split())
a = sorted(map(int, input().split()))

res = 0
for i in range(n):
    mn = bisect.bisect_left(a, a[i] - m, 0, i)
    mx = bisect.bisect_right(a, k - a[i], 0, i)
    res += max(0, mx - mn)

print(res)
