n, m, k = map(int, input().split())
INF = 20_000_000

graph = [[INF] * n for _ in range(n)]
flight = [[INF] * n for _ in range(n)]
nxt = [list(range(n)) for _ in range(n)]

for i in range(m):
    frm, to, w = map(int, input().split())
    if graph[frm - 1][to - 1] > -w:
        graph[frm - 1][to - 1] = -w
        flight[frm - 1][to - 1] = i

a = list(map(int, input().split()))

for i in range(n):
    for u in range(n):
        for v in range(n):
            if graph[u][i] < INF and graph[i][v] < INF and graph[u][v] > graph[u][i] + graph[i][v]:
                graph[u][v] = max(-INF, graph[u][i] + graph[i][v])
                nxt[u][v] = nxt[u][i]

res = []
has_cycle = False
for i in range(len(a) - 1):
    frm, to = a[i] - 1, a[i + 1] - 1
    curr = frm
    while curr != to:
        if graph[curr][curr] < 0:
            has_cycle = True
            break
        res.append(flight[curr][nxt[curr][to]] + 1)
        curr = nxt[curr][to]
    if graph[curr][curr] < 0:
        has_cycle = True
    if has_cycle:
        break

if has_cycle:
    print(0)
else:
    print(len(res))
    print(*res)
