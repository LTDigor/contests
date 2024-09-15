from functools import cache

@cache
def solve(a, b, c):
    res = 0
    if a >= 5:
        cur = a // 5 + solve(a % 5, b, c)
        res = max(res, cur)

    if b >= 2 and c >= 1:
        val = min(b // 2, c)
        cur = val + solve(a, b - 2 * val, c - val)
        res = max(res, cur)

    if b >= 2 and a >= 2:
        val = min(b // 2, a // 2)
        cur = val + solve(a - 2 * val, b - 2 * val, c)
        res = max(res, cur)

    if a >= 1 and c >= 2:
        val = min(a, c // 2)
        cur = val + solve(a - val, b, c - 2 * val)
        res = max(res, cur)

    if a >= 3 and c >= 1:
        val = min(a // 3, c)
        cur = val + solve(a - 3 * val, b, c - val)
        res = max(res, cur)
    return res


t = int(input())

for _ in range(t):
    a, b, c = map(int, input().split())
    print(solve(a, b, c))
