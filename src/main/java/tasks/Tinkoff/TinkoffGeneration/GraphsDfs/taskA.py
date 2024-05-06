n, m = map(int, input().split())
graph = [[0] * n for _ in range(n)]

for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm][to] = 1

for row in graph:
    print(*row)
