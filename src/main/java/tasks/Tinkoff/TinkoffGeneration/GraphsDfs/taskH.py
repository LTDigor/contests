from collections import deque

n, start = map(int, input().split())
start -= 1
graph = [[] for _ in range(n)]

for _ in range(n - 1):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1

    graph[frm].append(to)
    graph[to].append(frm)

dists = [-1] * n
dists[start] = 0
q = deque([(start, 0)])
while q:
    node, dist = q.popleft()

    for nxt in graph[node]:
        if dists[nxt] == -1:
            dists[nxt] = dist + 1
            q.append((nxt, dist + 1))

res = []
mx = max(dists)
for i in range(n):
    if dists[i] == mx:
        res.append(i + 1)

print(*res)

# 3 3
# 1 2
# 1 3
# 2 3
