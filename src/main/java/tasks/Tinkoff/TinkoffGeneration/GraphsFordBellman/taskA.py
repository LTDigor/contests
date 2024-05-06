n = int(input())
graph = []

for _ in range(n):
    graph.append(list(map(int, input().split())))

for i in range(n):
    for u in range(n):
        for v in range(n):
            if graph[u][v] == -1 and graph[u][i] != -1 and graph[i][v] != -1:
                graph[u][v] = graph[u][i] + graph[i][v]

print(max(map(max, graph)))
