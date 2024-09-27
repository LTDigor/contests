from collections import deque

n, m, start = map(int, input().split())
start -= 1

graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

dists = [-1] * n
dists[start] = 0

q = deque([start])
while q:
    node = q.popleft()

    for nxt in graph[node]:
        if dists[nxt] == -1:
            dists[nxt] = dists[node] + 1
            q.append(nxt)

print(*dists)
