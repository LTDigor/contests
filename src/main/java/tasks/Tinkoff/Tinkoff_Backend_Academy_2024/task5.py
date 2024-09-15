n, m = map(int, input().split())

graph = [set() for _ in range(n)]

for i in range(m):
    frm, to = map(int, input().split())
    frm -= 1
    to -= 1

    graph[frm].add(to)


def has_cycles():
    visited = [0] * n

    def dfs(node):
        visited[node] = 1
        for nxt in graph[node]:
            if visited[nxt] == 1:
                return True
            elif visited[nxt] == 2:
                continue
            else:
                if dfs(nxt):
                    return True
        visited[node] = 2
        return False

    for i in range(n):
        if visited[i] == 2:
            continue
        else:
            if dfs(i):
                return True
    return False


def fill_topsort(node):
    used[node] = True
    for nxt in graph[node]:
        if not used[nxt]:
            fill_topsort(nxt)
    topsort.append(node)


if has_cycles():
    print('No')
else:
    used = [False] * n
    topsort = []
    for i in range(n):
        if not used[i]:
            fill_topsort(i)

    res = [x + 1 for x in topsort[::-1]]
    print('Yes')
    print(*res)
