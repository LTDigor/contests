from collections import deque


def is_main(node):
    visited = [False] * n
    visited[node] = True
    q = deque([(node, 0)])

    while q:
        node, dist = q.popleft()
        if dist > 2:
            return False

        for nxt in graph[node]:
            if not visited[nxt]:
                visited[nxt] = True
                q.append((nxt, dist + 1))
    return True


n, m = map(int, input().split())
graph = [[] for _ in range(n)]
for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)

res = 0
for candidate in range(n):
    if is_main(candidate):
        res = candidate + 1
        break
print(res)
