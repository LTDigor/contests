n = int(input())
a = list(map(int, input().split()))

last_pos = {a[i]: i for i in range(n)}

res = 0
prev_pos = -1
for curr in range(1, a[-1] + 1):
    if curr not in last_pos or last_pos[curr] < prev_pos:
        break
    prev_pos = last_pos[curr]
    res += 1

print(res)
