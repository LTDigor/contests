import heapq
import math
from collections import deque

n, m = map(int, input().split())

cities = list(map(int, input().split()))
graph = [[] for _ in range(n)]

for _ in range(m):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append((v, w))
    graph[v].append((u, w))

res = math.inf
res_frm, res_to = 0, 0
for start in range(n):
    if cities[start] != 1:
        continue

    dists = [math.inf] * n
    dists[start] = 0

    heap = [(0, start)]
    while heap:
        _, node = heapq.heappop(heap)
        if cities[node] + cities[start] == 3:
            if res > dists[node]:
                res = dists[node]
                res_frm, res_to = start, node
            break

        for nxt, weight in graph[node]:
            nxt_dist = dists[node] + weight
            if dists[nxt] > nxt_dist:
                heapq.heappush(heap, (nxt_dist, nxt))
                dists[nxt] = nxt_dist

if res == math.inf:
    print(-1)
else:
    print(res_frm + 1, res_to + 1, res)
