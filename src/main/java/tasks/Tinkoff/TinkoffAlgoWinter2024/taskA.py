import math

# n, platform = map(int, input().split())
n = int(input())
p = 10 ** 9 + 7

res = n * (n + 1) // 2 % p
used = set(range(1, n + 1))
for length in range(1, n // 2 + 1):
    a, b = length, n - length
    lcm = a * b // math.gcd(a, b)
    if lcm not in used:
        res += lcm
        res %= p

print(res)
