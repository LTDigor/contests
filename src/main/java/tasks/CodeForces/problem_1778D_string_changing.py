MOD = 998244353

memo = {}


def inv(x):
    x %= MOD
    if x in memo:
        return memo[x]
    res = 1
    p = MOD - 2
    while p:
        if p & 1:
            res = res * x % MOD
        x = x * x % MOD
        p >>= 1

    memo[x] = res
    return res


def mul(a, b):
    a %= MOD
    b %= MOD
    return a * b % MOD


def solve():
    n = int(input())
    a = input()
    b = input()

    diff = sum(1 for i in range(n) if a[i] != b[i])

    m = [0] * (n + 1)
    add = [0] * (n + 1)

    m[1] = 1

    for i in range(2, n + 1):
        delimiter = inv(n - i + 1)
        m[i] = (n * delimiter * m[i - 1]) % MOD - ((i - 1) * delimiter * m[i - 2]) % MOD
        m[i] = (m[i] + MOD) % MOD

        add[i] = (n * delimiter * add[i - 1]) % MOD - ((i - 1) * delimiter * add[i - 2]) % MOD
        add[i] = (add[i] - (n * delimiter) % MOD + 5 * MOD) % MOD

    m1 = (add[n - 1] - add[n] + MOD + 1) % MOD
    m1 = m1 * inv((m[n] - m[n - 1] + MOD) % MOD) % MOD

    ans = (m1 * m[diff] + add[diff]) % MOD
    print(ans)


t = int(input())
for _ in range(t):
    solve()
