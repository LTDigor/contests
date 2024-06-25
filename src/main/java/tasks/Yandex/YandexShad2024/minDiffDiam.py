n = int(input())
a = list(map(int, input().split()))
a.sort()

res_ind = 0
res = 1_000_000_000_000
for i in range(n // 2 + 1):
    d_a = a[i + n // 2 - 1] - a[i]
    if i == 0:
        d_b = a[-1] - a[i + n // 2]
    elif i == n // 2:
        d_b = a[n // 2 - 1] - a[0]
    else:
        d_b = a[-1] - a[0]
    if d_a / d_b < res:
        res = d_a / d_b
        res_ind = i

print(res)
for i in range(res_ind, res_ind + n // 2):
    print(a[i], end=' ')
