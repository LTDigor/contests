N, X, K = map(int, input().split())
days = sorted(list(map(int, input().split())))

s = set()
t = []
for day in days:
    if day % X in s:
        continue
    t.append(day)
    s.add(day % X)

t_len = len(t)
current = t[0]
res = current
i = 0
while K > 0:
    current = t[i % t_len]
    next_item = t[(i + 1) % t_len]
    if next_item - current < 0:
        i += 1
        continue

    res = current
    diff = min(K, (next_item - current) // X + 1)
    t[i % t_len] += X * diff
    K -= diff
    i += 1
print(res)
# 6 5 10
# 1 2 3 4 5 6

# 5 7 12
# 5 22 17 13 8