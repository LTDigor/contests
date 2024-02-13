n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)

used = [0] * n


def has_cycle(node, marker):
    used[node] = 1
    for nxt in graph[node]:
        if used[nxt] == 1 or used[nxt] == 0 and has_cycle(nxt, marker):
            return True

    used[node] = 2
    return False


res = 0
for i in range(n):
    if used[i] == 0 and has_cycle(i, i):
        res = 1
        break
print(res)

# 3 3
# 1 2
# 1 3
# 2 3
