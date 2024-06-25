n, m = map(int, input().split())
grid = [input() for _ in range(n)]

horizontal = [[0] * (m + 1) for _ in range(n + 1)]
vertical = [[0] * (m + 1) for _ in range(n + 1)]

for r in range(1, n + 1):
    for c in range(1, m + 1):
        if grid[r - 1][c - 1] == '1':
            horizontal[r][c] = horizontal[r][c - 1] + 1

for r in range(1, n + 1):
    for c in range(m - 1, 0, -1):
        if grid[r - 1][c - 1] == '1' and grid[r - 1][c] == '1':
            horizontal[r][c] = horizontal[r][c + 1]

for c in range(1, m + 1):
    for r in range(1, n + 1):
        if grid[r - 1][c - 1] == '1':
            vertical[r][c] = vertical[r - 1][c] + 1


for c in range(1, m + 1):
    for r in range(n - 1, 0, -1):
        if grid[r - 1][c - 1] == '1' and grid[r][c - 1] == '1':
            vertical[r][c] = vertical[r + 1][c]


res = 0
for r in range(1, n + 1):
    for c in range(1, m + 1):
        res = max(res, horizontal[r][c] + vertical[r][c] - 1)
print(res)
