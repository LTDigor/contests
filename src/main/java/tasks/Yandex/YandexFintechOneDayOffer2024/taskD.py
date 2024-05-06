class DSU:
    def __init__(self, size):
        self.parent = list(range(size))
        self.cost = [0] * size

    def join(self, u, v):
        if self.parent[u] == self.parent[v]:
            return

        if u < v:
            u, v = v, u

        self.parent[u] = self.parent[v]
        self.cost[self.parent[v]] += self.cost[self.parent[u]]

    def add(self, u, addition):
        self.cost[self.parent[u]] += addition

    def get(self, u):
        return self.cost[self.parent[u]]


n, m = map(int, input().split())
dsu = DSU(n)

for _ in range(m):
    s = input()
    op = s.split()[0]

    if op == 'trust_join':
        a, b = map(int, [s.split()[1], s.split()[2]])
        a, b = a - 1, b - 1
        dsu.join(a, b)
    elif op == 'trust_add':
        a, x = map(int, [s.split()[1], s.split()[2]])
        a -= 1
        dsu.add(a, x)
    else:
        a = int(s.split()[1])
        a -= 1
        print(dsu.get(a))
