n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()

res_ind = 0
res = 1_000_000_000_000
for i in range(n - k + 1):
    d = a[i + k - 1] / a[i] - 1
    if d < res:
        res = d
        res_ind = i

print(res)
for i in range(res_ind, res_ind + k):
    print(a[i], end=' ')
