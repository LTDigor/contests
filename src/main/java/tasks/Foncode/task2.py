from collections import Counter

n = int(input())
counter = Counter(input())

res = 300
for item in "SPCEM":
    if item not in counter:
        res = 0
        break
    else:
        res = min(res, counter[item])

print(res * 5)

