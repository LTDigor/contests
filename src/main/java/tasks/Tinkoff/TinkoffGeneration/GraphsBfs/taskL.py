from collections import deque

n, m, start_x, start_y, end_x, end_y = map(int, input().split())
start_x, start_y, end_x, end_y = start_x - 1, start_y - 1, end_x - 1, end_y - 1
grid = [input() for _ in range(n)]

k = 3

parents = [[(-1, -1)] * m for _ in range(n)]
used = [[False] * m for _ in range(n)]

dists = [[-1] * m for _ in range(n)]
dists[start_x][start_y] = 0

queues = [deque() for _ in range(k)]
queues[0].append((start_x, start_y))

pointer = 0
total = 1
res = -1
while total > 0:
    while not queues[pointer % k]:
        pointer += 1

    x, y = queues[pointer % k].popleft()
    total -= 1

    if used[x][y]:
        continue
    used[x][y] = True

    for dx, dy in (0, 1), (1, 0), (0, -1), (-1, 0):
        new_x, new_y = x + dx, y + dy
        if 0 <= new_x < n and 0 <= new_y < m and grid[new_x][new_y] != '#':
            nxt_dist = 1 if grid[new_x][new_y] == '.' else 2
            if dists[new_x][new_y] == -1 or dists[new_x][new_y] > dists[x][y] + nxt_dist:
                dists[new_x][new_y] = dists[x][y] + nxt_dist
                parents[new_x][new_y] = (x, y)
                queues[dists[new_x][new_y] % k].append((new_x, new_y))
                total += 1

print(dists[end_x][end_y])
x, y = end_x, end_y
arr = []
while parents[x][y] != (-1, -1):
    parent_x, parent_y = parents[x][y]
    symbol = 'N'
    if x - parent_x == 1:
        symbol = 'S'
    elif y - parent_y == 1:
        symbol = 'E'
    elif y - parent_y == -1:
        symbol = 'W'
    arr.append(symbol)
    x, y = parent_x, parent_y

arr.reverse()
print(''.join(arr))

