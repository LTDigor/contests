from collections import deque

MX = 1001
dirs = [
    (-1, -1), (-1, 0), (-1, 1),
    (0, -1), (0, 1),
    (1, -1), (1, 0), (1, 1)
]

n, t = map(int, input().split())
pawns = []
for _ in range(n):
    x, y = map(int, input().split())
    pawns.append((x, y, 0))


pawn_dists = [[-1] * MX for _ in range(MX)]

q = deque(pawns)
while q:
    x, y, dist = q.popleft()
    if pawn_dists[x][y] != -1:
        continue
    pawn_dists[x][y] = dist
    for dx, dy in dirs:
        nx = x + dx
        ny = y + dy
        if 0 <= nx < MX and 0 <= ny < MX and pawn_dists[nx][ny] == -1:
            q.append((nx, ny, dist + 1))

for _ in range(t):
    x, y = map(int, input().split())
    print(pawn_dists[x][y])
