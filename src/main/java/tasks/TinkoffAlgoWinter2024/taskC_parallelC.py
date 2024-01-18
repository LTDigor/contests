import math
from collections import defaultdict

n, k_saved = map(int, input().split())
primes = defaultdict(int)
k = k_saved

for divider in range(2, k_saved + 1):
    while k > 0 and k % divider == 0:
        primes[divider] += 1
        k //= divider

curr = defaultdict(int)
for divider_saved in primes:
    divider = divider_saved
    while n >= divider:
        curr[divider_saved] += n // divider
        divider *= divider_saved

res = math.inf
for divider, freq in primes.items():
    res = min(res, curr[divider] // freq)

print(res)
