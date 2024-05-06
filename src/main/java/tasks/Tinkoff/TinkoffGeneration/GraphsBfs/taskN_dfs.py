import functools
import math


@functools.cache
def dfs(node, left_time):
    if node == nodes - 1:
        return math.inf

    res = 0
    for nxt, nxt_weight, nxt_time in graph[node]:
        if not visited[nxt] and left_time - nxt_time >= 0:
            visited[nxt] = True
            res = max(res, min(nxt_weight, dfs(nxt, left_time - nxt_time)))
            visited[nxt] = False

    return res


nodes, vertexes = map(int, input().split())
graph = [[] for _ in range(nodes)]

for _ in range(vertexes):
    frm, to, node_time, weight = map(int, input().split())
    frm, to, weight = frm - 1, to - 1, weight - 3_000_000

    if weight > 0:
        graph[frm].append((to, weight, node_time))
        graph[to].append((frm, weight, node_time))

visited = [False] * nodes
visited[0] = True

res_weight = dfs(0, 1440)

ans = min(10_000_000, res_weight // 100)
print(ans)
