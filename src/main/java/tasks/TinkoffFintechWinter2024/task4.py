class DSU:
    def __init__(self, n, interests, hungers):
        self.parents = list(range(n))
        self.rank = [0] * n

        self.group_interest = interests.copy()
        self.group_hunger = hungers.copy()

    def get_parent(self, child):
        if self.parents[child] == child:
            return child

        new_parent = self.get_parent(self.parents[child])
        if new_parent != self.parents[child]:
            self.parents[child] = new_parent
            self.group_hunger[new_parent] += self.group_hunger[child]
            self.group_interest[new_parent] += self.group_interest[child]

        return self.parents[child]

    def add(self, u, v):
        u, v = self.get_parent(u), self.get_parent(v)
        if u != v:
            if self.rank[u] < self.rank[v]:
                u, v = v, u

            self.parents[v] = u
            self.group_hunger[u] += self.group_hunger[v]
            self.group_interest[u] += self.group_interest[v]

            if self.rank[u] == self.rank[v]:
                self.rank[u] += 1

    def find_max_interest(self, max_hunger):
        groups = list(set(self.parents))
        n = len(groups)
        dp = [[0] * (max_hunger + 1) for _ in range(n + 1)]

        for group_ind in range(1, n + 1):
            for hunger in range(1, max_hunger + 1):
                parent_ind = groups[group_ind - 1]
                group_hunger = self.group_hunger[parent_ind]
                if group_hunger <= hunger:
                    dp[group_ind][hunger] = max(
                        dp[group_ind - 1][hunger],
                        dp[group_ind - 1][hunger - group_hunger] \
                        + self.group_interest[parent_ind]
                    )
                else:
                    dp[group_ind][hunger] = dp[group_ind - 1][hunger]

        return dp[-1][-1]


n, pairs, max_hunger = map(int, input().split())
interests = list(map(int, input().split()))
hungers = list(map(int, input().split()))

dsu = DSU(n, interests, hungers)

for _ in range(pairs):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    dsu.add(u, v)

print(dsu.find_max_interest(max_hunger))

# 3 1 3
# 2 2 3
# 3 1 2
# 2 3

# 4 2 5
# 1 2 1 2
# 4 1 2 3
# 2 3
# 3 4

# 6 3 6
# 1 2 3 4 4 5
# 1 1 2 2 2 3
# 1 2
# 3 4
# 5 6
