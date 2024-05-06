rows, cols = map(int, input().split())
matrix = []
for _ in range(rows):
    matrix.append(input())

dp = [[0] * (cols + 1) for _ in range(rows + 1)]

for r in range(rows):
    for c in range(cols):
        if matrix[r][c] == '#':
            dp[r + 1][c + 1] = min(dp[r][c], dp[r + 1][c], dp[r][c + 1]) + 1

res = 1
for r in range(6, rows + 1):
    for c in range(6, cols + 1):
        side = res + 1
        if r - 2 * side < 1 or c - 2 * side < 1:
            continue

        minSquareSize = min(
            dp[r][c - side],
            dp[r - side][c],
            dp[r - side][c - side],
            dp[r - 2 * side][c - side],
            dp[r - side][c - 2 * side],
        )

        if minSquareSize >= side:
            res = max(res, side)

print(res)
