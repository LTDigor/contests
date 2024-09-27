n, start = map(int, input().split())
start -= 1

graph = []
for _ in range(n):
    row = list(map(int, input().split()))
    graph.append(row)

used = set()


def dfs(node):
    res = 1
    used.add(node)
    for nxt, has_edge in enumerate(graph[node]):
        if nxt not in used and has_edge == 1:
            res += dfs(nxt)
    return res


print(dfs(start))
