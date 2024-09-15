from math import inf

n = int(input())
graph = [[] for _ in range(n)]
for a in range(n):
    s = input()
    for b, mark in enumerate(s):
        if mark == '1':
            graph[a].append(b)


def has_odd_cycles():
    def dfs(node, prev, color):
        colors[node] = color

        for nxt in graph[node]:
            if nxt == prev:
                continue
            if colors[nxt] == -1:
                res = dfs(nxt, node, 1 - color)
                if not res:
                    return False
            elif color == colors[nxt]:
                return False
        return True

    colors = [-1] * n
    for i in range(n):
        if colors[i] == -1:
            doubled = dfs(i, -1, 1)
            if not doubled:
                return True
    return False


def floyd():
    d = [[inf] * n for _ in range(n)]
    for frm in range(n):
        for to in graph[frm]:
            d[frm][to] = 1
    for i in range(n):
        for u in range(n):
            for v in range(n):
                d[u][v] = min(d[u][v], d[u][i] + d[i][v])
    return d


if has_odd_cycles():
    print(-1)
else:
    min_dists = floyd()
    print(max(max(dists) for dists in min_dists) + 1)
