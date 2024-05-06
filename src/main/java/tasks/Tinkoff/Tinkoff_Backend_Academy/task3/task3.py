n, m, q = map(int, input().split())

grid = []
for i in range(n):
    grid.append(list(map(int, input().split())))

for i in range(q):
    x, y, k = map(int, input().split())
    x, y = x - 1, y - 1
    res = 0
    for row in range(n):
        if abs(grid[x][y] - grid[row][y]) <= k:
            res += 1
    for col in range(m):
        if abs(grid[x][y] - grid[x][col]) <= k:
            res += 1
    res -= 2  # remove the cell itself
    print(res)
