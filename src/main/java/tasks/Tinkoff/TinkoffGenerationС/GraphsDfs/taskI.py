n = int(input())
path = list(map(int, input().split()))

res = [n]
while res[-1] != 1:
    res.append(path[res[-1] - 2])

res = res[::-1]
print(*res)
