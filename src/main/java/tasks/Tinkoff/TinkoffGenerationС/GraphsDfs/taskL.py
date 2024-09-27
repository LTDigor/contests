def dfs(row, col):
    if row < 0 or row >= n or col < 0 or col >= m:
        return
    if visited[row][col] or matrix[row][col] == '.':
        return

    visited[row][col] = True
    dfs(row + 1, col)
    dfs(row, col + 1)
    dfs(row - 1, col)
    dfs(row, col - 1)


n, m = map(int, input().split())
matrix = []
for _ in range(n):
    matrix.append(input())

res = 0
visited = [[False] * m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if matrix[i][j] == '#' and not visited[i][j]:
            dfs(i, j)
            res += 1
print(res)
