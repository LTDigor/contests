import heapq

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    frm, to, w = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append((to, w))
    graph[to].append((frm, w))

start, end = map(int, input().split())
start, end = start - 1, end - 1

visited = [False] * n
heap = [(0, start)]
res = 0
while heap:
    dist, node = heapq.heappop(heap)
    if visited[node]:
        continue
    visited[node] = True
    if node == end:
        res = dist
        break
    for nxt, w in graph[node]:
        if not visited[nxt]:
            heapq.heappush(heap, (max(dist, w), nxt))

print(res)
