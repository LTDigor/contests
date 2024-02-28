n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to, w = map(int, input().split())
    graph[frm - 1].append((to - 1, -w))

INF = 30_000_000
dp = [INF] * n
dp[0] = 0
changed = False
for i in range(n - 1):
    changed = False
    for frm in range(n):
        for to, w in graph[frm]:
            if dp[frm] != INF and dp[to] > dp[frm] + w:
                dp[to] = max(-INF, dp[frm] + w)
                changed = True
        if not changed:
            break


def dfs(cur):
    if visited[cur]:
        return
    visited[cur] = True
    for nxt, _ in graph[cur]:
        dfs(nxt)


visited = [False] * n
for frm in range(n):
    for to, w in graph[frm]:
        if dp[frm] != INF and dp[to] > dp[frm] + w:
            dp[to] = max(-INF, dp[frm] + w)
            dfs(to)

if dp[-1] == INF:
    print(":(")
elif visited[-1]:
    print(":)")
else:
    print(-dp[-1])

# 6 6
# 1 2 -1
# 2 3 -1
# 3 4 -1
# 4 5 -1
# 5 6 -1
# 1 1 1
#
# 3 4
# 1 3 10000
# 1 2 -10000
# 2 2 1
# 2 3 -10000
