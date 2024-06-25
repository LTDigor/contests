import heapq
from collections import defaultdict

from math import inf


def dijkstra(g, start):
    vertexes = len(g)
    distances = [inf] * vertexes
    distances[start] = 0
    pq = [(0, start)]

    while pq:
        current_dist, current_vertex = heapq.heappop(pq)

        if current_dist > distances[current_vertex]:
            continue

        for neighbor, weight in g[current_vertex].items():
            distance = current_dist + weight

            if distance < distances[neighbor]:
                distances[neighbor] = distance
                heapq.heappush(pq, (distance, neighbor))

    return distances


n, m = map(int, input().split())
graph = [defaultdict(lambda: inf) for _ in range(n)]

for _ in range(m):
    x, y, l = map(int, input().split())
    x -= 1
    y -= 1

    graph[x][y] = min(graph[x][y], l)
    graph[y][x] = min(graph[y][x], l)

dists = dijkstra(graph, 0)

used = set()
res = 0
for frm in range(n):
    for to, w in graph[frm].items():
        if (to, frm) in used:
            continue
        used.add((frm, to))
        graph[frm][to] = inf
        graph[to][frm] = inf

        cur_dists = dijkstra(graph, 0)

        graph[frm][to] = w
        graph[to][frm] = w
        if dists != cur_dists:
            res += 1

print(res)
