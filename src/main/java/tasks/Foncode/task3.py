n = int(input())
arr = sorted(list(map(int, input().split())))

l, r = n // 2 - 1, n // 2
res = []
for i in range(n):
    if (n + i) % 2 == 0:
        res.append(arr[l])
        l -= 1
    else:
        res.append(arr[r])
        r += 1

print(*res)
