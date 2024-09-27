from collections import deque

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)

visited = [False] * n
visited[0] = True
q = deque([0])
while q:
    node = q.popleft()
    for nxt in graph[node]:
        if not visited[nxt]:
            visited[nxt] = True
            q.append(nxt)
            print(node + 1, nxt + 1)
