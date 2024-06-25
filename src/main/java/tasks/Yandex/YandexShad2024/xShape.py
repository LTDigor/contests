n, m = map(int, input().split())
grid = [input() for _ in range(n)]

decreased = [[0] * (m + 2) for _ in range(n + 2)]
increased = [[0] * (m + 2) for _ in range(n + 2)]

for r in range(1, n + 1):
    for c in range(1, m + 1):
        if grid[r - 1][c - 1] == '1':
            decreased[r][c] = decreased[r - 1][c - 1] + 1
            increased[r][c] = increased[r - 1][c + 1] + 1

for r in range(n, 0, -1):
    for c in range(1, m):
        if decreased[r][c] > 0 and decreased[r + 1][c + 1] > 0:
            decreased[r][c] = decreased[r + 1][c + 1]
        if increased[r][c] > 0 and increased[r + 1][c - 1] > 0:
            increased[r][c] = increased[r + 1][c - 1]

res = 0
for r in range(1, n + 1):
    for c in range(1, m + 1):
        res = max(res, decreased[r][c] + increased[r][c] - 1)
print(res)
