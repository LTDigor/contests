import math
from collections import defaultdict
from functools import cache

n = int(input())
graph = defaultdict(list)
for _ in range(n - 1):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[to].append(frm)
    graph[frm].append(to)

parents = [0] * n
depths = [0] * n
visited = set()


def dfs(curr, parent, depth):
    parents[curr] = parent
    depths[curr] = depth
    visited.add(curr)

    for nxt in graph[curr]:
        if nxt not in visited:
            dfs(nxt, curr, depth + 1)


dfs(0, 0, 0)

h = int(math.log2(n)) + 2
dp = [[0] * h for _ in range(n)]

for i in range(n):
    dp[i][0] = parents[i]

for j in range(1, h):
    for i in range(n):
        dp[i][j] = dp[dp[i][j - 1]][j - 1]


@cache
def lca(u, v):
    if depths[v] > depths[u]:
        u, v = v, u
    for i in range(h - 1, -1, -1):
        if depths[dp[u][i]] - depths[v] >= 0:
            u = dp[u][i]

    if u == v:
        return v

    for i in range(h - 1, -1, -1):
        if dp[v][i] != dp[u][i]:
            v = dp[v][i]
            u = dp[u][i]
    return parents[v]


q = int(input())
for _ in range(q):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1

    lca_node = lca(frm, to)
    res = 0
    if lca_node == frm:
        for child in graph[frm]:
            if child != parents[frm]:
                lca_child = lca(child, to)
                if lca_child == child:
                    res = child
                    break
    else:
        res = parents[frm]
    res += 1
    print(res)

# 4
# 1 2
# 1 3
# 3 4
# 5
# 1 2
# 1 3
# 2 3
# 4 1
# 4 2

# 5
# 1 2
# 1 3
# 1 4
# 4 5
# 4
# 1 4
# 2 5
# 4 3
# 5 2

