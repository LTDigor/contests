from collections import defaultdict, deque

n, x_start, y_start, x_end, y_end = map(int, input().split())

graph_x = defaultdict(list)
graph_y = defaultdict(list)

graph_x[x_start].append((x_start, y_start))
graph_y[y_start].append((x_start, y_start))

graph_x[x_end].append((x_end, y_end))
graph_y[y_end].append((x_end, y_end))

for _ in range(n):
    x, y = map(int, input().split())
    graph_x[x].append((x, y))
    graph_y[y].append((x, y))

visited = set()

q = deque()
for x, y in graph_x[x_start] + graph_y[y_start]:
    q.append((0, (x, y)))
    visited.add((x, y))

del graph_x[x_start]
del graph_y[y_start]

res = -1
while q:
    dist, point = q.popleft()

    if point == (x_end, y_end):
        res = dist
        break

    for nxt_point in graph_x[point[0]] + graph_y[point[1]]:
        if nxt_point not in visited:
            visited.add(nxt_point)
            q.append((dist + 1, nxt_point))

    del graph_x[point[0]]
    del graph_y[point[1]]

print(res)
