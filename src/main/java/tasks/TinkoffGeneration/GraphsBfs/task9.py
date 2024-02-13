from collections import deque

n = int(input())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

deltas = [(-2, -1), (-2, 1), (2, -1), (2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2)]

dists1 = [[-1] * (n + 1) for _ in range(n + 1)]
dists1[x1][y1] = 0
q = deque([(x1, y1)])
while q:
    x, y = q.popleft()

    for delta_x, delta_y in deltas:
        new_x, new_y = x + delta_x, y + delta_y
        if 0 < new_x <= n and 0 < new_y <= n and dists1[new_x][new_y] == -1:
            dists1[new_x][new_y] = dists1[x][y] + 1
            q.append((new_x, new_y))

dists2 = [[-1] * (n + 1) for _ in range(n + 1)]
dists2[x2][y2] = 0
q = deque([(x2, y2)])
res = -1
while q:
    x, y = q.popleft()

    if dists1[x][y] != -1 and dists1[x][y] % 2 == dists2[x][y] % 2:
        if res == -1:
            res = max(dists1[x][y], dists2[x][y])
        else:
            res = min(res, max(dists1[x][y], dists2[x][y]))

    for delta_x, delta_y in deltas:
        new_x, new_y = x + delta_x, y + delta_y
        if 0 < new_x <= n and 0 < new_y <= n and dists2[new_x][new_y] == -1:
            dists2[new_x][new_y] = dists2[x][y] + 1
            q.append((new_x, new_y))

print(res)
