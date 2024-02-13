from collections import defaultdict

nodes, vertexes, length = map(int, input().split())

graph = defaultdict(dict)
for _ in range(vertexes):
    node1, bus_number, node2 = map(int, input().split())
    graph[node1][bus_number] = node2
    graph[node2][bus_number] = node1

path = list(map(int, input().split()))

curr_node = 1
for bus_number in path:
    if bus_number not in graph[curr_node]:
        curr_node = 0
        break
    else:
        curr_node = graph[curr_node][bus_number]

print(curr_node)


