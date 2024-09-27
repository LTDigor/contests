import heapq

n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

q = int(input())

dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
p = [[(r, c) for c in range(m)] for r in range(n)]
s = [[1 for c in range(m)] for r in range(n)]
mx = [[grid[r][c] for c in range(m)] for r in range(n)]

to_add = []
for _ in range(q):
    r, c = map(int, input().split())
    r, c = r - 1, c - 1
    to_add.append((r, c, grid[r][c]))
    grid[r][c] = 0

to_add = to_add[::-1]


def leader(r, c):
    if p[r][c] == (r, c):
        return r, c
    p[r][c] = leader(p[r][c][0], p[r][c][1])
    return p[r][c]


def unite(ra, ca, rb, cb):
    (ra, ca), (rb, cb) = leader(ra, ca), leader(rb, cb)
    if (ra, ca) == (rb, cb):
        return

    if s[ra][ca] > s[rb][cb]:
        (ra, ca), (rb, cb) = (rb, cb), (ra, ca)
    s[rb][cb] += s[ra][ca]
    p[ra][ca] = p[rb][cb]
    mx[rb][cb] = max(mx[ra][ca], mx[rb][cb])


res = []
heap = []

for r in range(n):
    for c in range(m):
        if grid[r][c] == 0:
            continue
        heapq.heappush(heap, (grid[r][c], r, c))
        for dr, dc in dirs:
            nr, nc = r + dr, c + dc
            if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] > 0:
                unite(nr, nc, r, c)

mn, mn_r, mn_c = heap[0]
lr, lc = leader(mn_r, mn_c)
while mn != mx[lr][lc]:
    heapq.heappop(heap)
    mn, mn_r, mn_c = heap[0]
    lr, lc = leader(mn_r, mn_c)

res.append(mn)

for r, c, w in to_add:
    grid[r][c] = w
    heapq.heappush(heap, (grid[r][c], r, c))
    for dr, dc in dirs:
        nr, nc = r + dr, c + dc
        if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] > 0:
            unite(nr, nc, r, c)

    mn, mn_r, mn_c = heap[0]
    lr, lc = leader(mn_r, mn_c)
    while mn != mx[lr][lc]:
        heapq.heappop(heap)
        mn, mn_r, mn_c = heap[0]
        lr, lc = leader(mn_r, mn_c)

    res.append(mn)

res = res[::-1]
print(*res, sep='\n')
