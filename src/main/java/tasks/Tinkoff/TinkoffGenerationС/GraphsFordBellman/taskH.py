n, m = map(int, input().split())
s, f = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to, w = map(int, input().split())
    graph[frm - 1].append((to - 1, 1.0 - w / 100))
    graph[to - 1].append((frm - 1, 1.0 - w / 100))

NEG_INF = -1.0

dp = [NEG_INF] * n
dp[s - 1] = 1.0

for i in range(n - 1):
    for frm in range(n):
        for to, w in graph[frm]:
            if dp[frm] != NEG_INF:
                dp[to] = max([dp[to], dp[frm] * w])

print(round(1.0 - dp[f - 1], 8))
