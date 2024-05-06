from collections import defaultdict
from itertools import accumulate

n, length, target = map(int, input().split())
arr = list(map(int, input().split()))

pref = list(accumulate(arr))
seen = defaultdict(set)
seen[0].add(0)

res = 0
for i in range(n):
    needed_pref = pref[i] - target
    if needed_pref in seen and (i - length) in seen[needed_pref]:
        res = i - length + 1
        break

    seen[pref[i]].add(i + 1)

print(res)
