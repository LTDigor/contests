n = int(input())
graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

for i in range(n):
    for u in range(n):
        for v in range(n):
            if graph[u][v] == 0 and graph[u][i] != 0 and graph[i][v] != 0:
                graph[u][v] = 1

for row in graph:
    print(*row)
