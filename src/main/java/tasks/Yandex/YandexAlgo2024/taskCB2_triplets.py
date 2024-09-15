n, k = map(int, input().split())

zero_remainder = n // k
half_remainder = 0
if k % 2 == 0:
    half_remainder = max(0, n + k // 2) // k

res = zero_remainder ** 3 + half_remainder ** 3
print(res)
