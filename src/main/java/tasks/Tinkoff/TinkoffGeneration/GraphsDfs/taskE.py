n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)

used = [False] * n


def get_component(node, result):
    result.append(node + 1)
    used[node] = True
    for nxt in graph[node]:
        if not used[nxt]:
            get_component(nxt, result)


res = []
for i in range(n):
    if not used[i]:
        component = []
        get_component(i, component)
        component.sort()
        res.append(component)

print(len(res))
for component in res:
    print(len(component))
    print(*component)
