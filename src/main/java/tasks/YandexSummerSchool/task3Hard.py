import math

n, m = map(int, input().split())
graph = [[] for _ in range(n)]

for _ in range(m):
    u, v, t = map(int, input().split())
    graph[u - 1].append((v - 1, t))
    graph[v - 1].append((u - 1, t))

k = int(input())
offer = []
for i in range(k):
    u, v, t, c = map(int, input().split())
    offer.append((i, u - 1, v - 1, t, c))

offer.sort(key=lambda x: x[4])

p = int(input())
reqs = []

for _ in range(p):
    u, v, t = map(int, input().split())
    reqs.append((u - 1, v - 1, t))

nxt_offer_id = 0
accepted_offers = []
res = True


def dijkstra(start, end):
    d = [math.inf] * n
    used = [False] * n
    d[start] = 0

    for i in range(n):
        v = -1
        for u in range(n):
            if not used[u] and (v == -1 or d[u] < d[v]):
                v = u
        used[v] = True
        for u, w in graph[v]:
            d[u] = min(d[u], d[v] + w)

    return d[end]


for u, v, t in reqs:

    dist = dijkstra(u, v)

    while dist > t and nxt_offer_id < k:
        ind, nu, nv, nt = offer[nxt_offer_id]
        graph[nu].append((nv, nt))
        graph[nv].append((nu, nt))

        dist = dijkstra(u, v)

        accepted_offers.append(ind + 1)
        nxt_offer_id += 1

    if dist > t:
        res = False
        break

if res:
    print(len(accepted_offers))
    if accepted_offers:
        print(*sorted(accepted_offers))
else:
    print(-1)
