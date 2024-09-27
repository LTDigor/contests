n, m, start = map(int, input().split())
start -= 1

graph = [[] for _ in range(n)]
for _ in range(m):
    u, v = map(int, input().split())
    graph[u - 1].append(v - 1)
    graph[v - 1].append(u - 1)

dists = [-1] * n
dists[start] = 0

layers = [[] for _ in range(n)]
layers[0] = [start]
for i in range(1, n - 1):
    for node in layers[i - 1]:
        for nxt in graph[node]:
            if dists[nxt] == -1:
                layers[i].append(nxt)
                dists[nxt] = i

print(*dists)