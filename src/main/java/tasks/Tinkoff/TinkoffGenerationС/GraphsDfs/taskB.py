n, m = map(int, input().split())
counter = [0] * n
for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    counter[frm] += 1
    counter[to] += 1

print(*counter)
