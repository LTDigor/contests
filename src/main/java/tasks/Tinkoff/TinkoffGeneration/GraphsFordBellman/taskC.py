n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to, w = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append((to, w))

INF = 30000
dp = [INF] * n
dp[0] = 0

for i in range(n - 1):
    for frm in range(n):
        for to, w in graph[frm]:
            if dp[frm] != INF:
                dp[to] = min(dp[to], dp[frm] + w)

print(*dp)
