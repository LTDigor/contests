n = int(input())

points = []
res = True

for _ in range(n):
    d, c, s = map(int, input().split())
    points.append((d + c, 1))
    points.append((s, -1))
    if s < d + c:
        res = False

points.sort()

can_close = 0
need_close = 0
for i in range(1, 2 * n):
    point, val = points[i]

    segment_len = point - points[i - 1][0]
    can_close += segment_len

    if val == -1 and need_close > 0:
        can_close -= 1
        need_close -= 1

    if val == 1:
        need_close += 1

    if can_close < 0:
        res = False
        break

    closed = min([need_close, can_close, segment_len])
    can_close -= closed
    need_close -= closed

print('YES' if res else 'NO')


# 3
# 1 2 4
# 3 2 8
# 2 3 7

# 4
# 1 1 4
# 1 1 4
# 1 1 4
# 1 1 4

# 4
# 1 2 4
# 1 2 7
# 2 2 4
# 3 1 5
