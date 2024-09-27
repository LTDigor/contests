def is_tree(node: int, parent: int, used):
    used[node] = True
    for nxt in graph[node]:
        if nxt == parent:
            continue
        if used[nxt] or not is_tree(nxt, node):
            return False
    return True


n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)

used = [False] * n
res = is_tree(0, -1, used) and all(used)
print('YES' if res else 'NO')
