import sys
sys.setrecursionlimit(10 ** 5)

n, con = list(map(int, input().split()))
graph = [[] for _ in range(n)]
used = [False] * n

for _ in range(con):
    frm, to = map(int, input().split())
    frm, to = frm - 1, to - 1
    graph[frm].append(to)
    graph[to].append(frm)

def dfs_check(node, component):
    component += 1
    used[node] = True
    for nxt in graph[node]:
        if not used[nxt]:
            component = max(component, dfs_check(nxt, component))
    return component

res = []
ans = 0
for i in range(n):
    if not used[i]:
        component = dfs_check(i, 0)
        sz = component
        ans += sz * (sz - 1) // 2

def gcd(a, b):
    if a < b:
        a, b = b, a
    while b > 0:
        a, b = b, a % b
    return a

total = n * (n - 1) // 2
_gcd = gcd(ans, total)
print(ans // _gcd, total // _gcd)
