n, m, k, s, f = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to, w = map(int, input().split())
    graph[frm - 1].append((to - 1, w))

INF = 300_000_000

k = min(k, n - 1)
dp = [[INF] * n for _ in range(k + 1)]
dp[0][s - 1] = 0

for i in range(k):
    for frm in range(n):
        for to, w in graph[frm]:
            if dp[i][frm] != INF:
                dp[i + 1][to] = min([dp[i + 1][to], dp[i][to], dp[i][frm] + w])

print(-1 if dp[-1][f - 1] == INF else dp[-1][f - 1])
