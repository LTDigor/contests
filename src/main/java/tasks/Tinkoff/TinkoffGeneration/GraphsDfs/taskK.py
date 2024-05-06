n = int(input())
graph = [[] for _ in range(n)]
parent = [0] * n

for i in range(n):
    key_i = int(input()) - 1
    graph[key_i].append(i)
    parent[i] = key_i

used = [False] * n


def dfs(node):
    if used[node]:
        return
    used[node] = True
    dfs(parent[node])
    for nxt in graph[node]:
        dfs(nxt)


res = 0
for i in range(n):
    if not used[i]:
        res += 1
        dfs(i)

print(res)
