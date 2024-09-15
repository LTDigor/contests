from collections import defaultdict

a, b = map(int, input().split())
mod = 998244353
inv_2 = 499122177

divisors = defaultdict(int)

cur_div = 2
while a > 0 and cur_div <= a:
    while a > 0 and a % cur_div == 0:
        a //= cur_div
        divisors[cur_div] += 1
    cur_div += 1

pows = list(divisors.values())
total = b
for p in pows:
    mult = b * p + 1
    total *= mult
    total %= mod

res = (total * inv_2) % mod
print(res)
