from collections import deque

n, m = map(int, input().split())
cells = []
for _ in range(n):
    cells.append(input())

dists = {(0, 0): 0}

q = deque([(0, 0)])
res = -1
while q:
    x, y = q.popleft()

    if x == n - 1 and y == m - 1:
        res = dists[(x, y)]
        break
    for delta_x, delta_y in ((-1, 0), (1, 0), (0, -1), (0, 1)):
        new_x, new_y = x + delta_x, y + delta_y
        if 0 <= new_x < n and 0 <= new_y < m \
                and cells[new_x][new_y] != '#' and (new_x, new_y) not in dists:
            dists[(new_x, new_y)] = dists[(x, y)] + 1
            q.append((new_x, new_y))

print(res)
