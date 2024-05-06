def dfs(node: int) -> int:
    visited[node] = True
    ans = p[node]
    for nxt in graph[node]:
        if not visited[nxt]:
            ans += dfs(nxt)
    res.append(node)
    return ans


n = int(input())
p = [0] + list(map(int, input().split()))
graph = [[]]
for _ in range(n):
    s = list(map(int, input().split()))
    graph.append(s[1:])

res = []
visited = [False] * (n + 1)

total = dfs(1)

print(total, len(res))
print(*res)
