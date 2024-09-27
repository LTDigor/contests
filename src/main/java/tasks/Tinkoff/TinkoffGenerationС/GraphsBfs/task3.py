from collections import deque

n, m, start = map(int, input().split())
start -= 1

graph = [[] for _ in range(n)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u - 1].append((v - 1, w))
    graph[v - 1].append((u - 1, w))

dists = [-1] * n
dists[start] = 0

q = deque([start])
while q:
    node = q.popleft()

    for nxt, w in graph[node]:
        if dists[nxt] == -1 or dists[nxt] > dists[node] + w:
            dists[nxt] = dists[node] + w
            if w == 0:
                q.appendleft(nxt)
            else:
                q.append(nxt)

print(*dists)
