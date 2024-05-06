from collections import deque

n, m, = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
dists = [[-1] * m for _ in range(n)]
dists[0][0] = 0
q = deque([(0, 0)])

res = -1
while q:
    x, y = q.popleft()

    for dx, dy in dirs:
        nxt_x, nxt_y = x, y
        while 0 <= nxt_x + dx < n and 0 <= nxt_y + dy < m and grid[nxt_x + dx][nxt_y + dy] != 1:
            nxt_x, nxt_y = nxt_x + dx, nxt_y + dy
            if grid[nxt_x][nxt_y] == 2:
                res = dists[x][y] + 1
                break
        if res != -1:
            break

        if dists[nxt_x][nxt_y] == -1:
            dists[nxt_x][nxt_y] = dists[x][y] + 1
            q.append((nxt_x, nxt_y))
    if res != -1:
        break

print(res)



