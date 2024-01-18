import math
from collections import defaultdict, deque

nodes, vertexes = map(int, input().split())

graph1 = defaultdict(list)
graph2 = defaultdict(list)

for _ in range(vertexes):
    frm, to, mark = map(int, input().split())
    frm -= 1
    to -= 1

    if mark == 1:
        graph1[to].append(frm)
    else:
        graph2[to].append(frm)

dp = [math.inf] * nodes

visited1 = [False] * nodes
visited2 = [False] * nodes

visited2[-1] = True
visited1[-1] = True
q = deque([(nodes - 1, 2, 0), (nodes - 1, 1, 0)])
while q:
    node, mark, dist = q.popleft()

    dp[node] = min(dp[node], dist)

    nxt_graph = graph1 if mark == 2 else graph2
    nxt_mark = 1 if mark == 2 else 2
    visited = visited1 if mark == 2 else visited2

    for nxt in nxt_graph[node]:
        if not visited[nxt]:
            visited[nxt] = True
            q.append((nxt, nxt_mark, dist + 1))

res = [dp[i] if dp[i] < math.inf else -1 for i in range(nodes - 1)]
print(*res)
