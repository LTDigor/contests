from collections import Counter

s = input()
n = len(s)

c = Counter(s)
res = n * (n - 1) // 2 + 1
for freq in c.values():
    res -= freq * (freq - 1) // 2

print(res)
