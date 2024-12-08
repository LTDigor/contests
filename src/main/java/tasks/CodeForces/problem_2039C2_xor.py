from functools import cache


@cache
def gcdex(a, b):
    if a == 0:
        return b, 0, 1

    d, x1, y1 = gcdex(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return d, x, y


@cache
def inv_mod(a, mod):
    _, res, _ = gcdex(a, mod)
    return (res % mod + mod) % mod


@cache
def count_res(x, m):
    if m == 0:
        return 0
    if x == 1:
        return m
    if x == 2:
        return m // 2 + 1

    tmp = x
    pw = 0
    while tmp > 0:
        tmp //= 2
        pw += 1
    N = 2 ** pw

    res = 0
    for y in range(1, min(m, N) + 1):
        xor = x ^ y
        if xor % y == 0 or xor % x == 0:
            res += 1

    while x % 2 == 0:
        x //= 2
        N //= 2
        m //= 2

    remainder = [0] * (N + 1)
    for y in range(1, min(m, N) + 1):
        xor = x ^ y
        remainder[y] = xor % x

    inv_N = inv_mod(N, x)
    for i in range(1, min(m, N) + 1):
        k = ((x - remainder[i]) % x) * inv_N % x
        p = m - (i - 1) - k * N
        q = N * x
        if k == 0:
            p -= q
        if p > 0:
            res += p // q + int((p % q) != 0)

    return res

def solve():
    t = int(input())
    for _ in range(t):
        x, m = map(int, input().split())
        print(count_res(x, m))


solve()
# test()
