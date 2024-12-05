from functools import *

n, m, q = map(int, input().split())
graph = [[] for _ in range(n)]
MOD = 10 ** 9 + 7

for _ in range(m):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)


@cache
def dfs(at: int, path_len):
    if path_len == 0:
        return 1
    ans = 0
    for nxt in graph[at]:
        ans += dfs(nxt, path_len - 1)
        ans %= MOD

    return ans


for _ in range(q):
    v, k = map(int, input().split())
    v -= 1
    res = dfs(v, k)
    print(res)

# 4 5 3
# 1 2
# 2 3
# 1 3
# 3 4
# 4 1
# 1 3
# 2 4
# 3 30
