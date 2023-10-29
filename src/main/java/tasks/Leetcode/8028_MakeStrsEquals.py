from collections import defaultdict
from heapq import *


class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        n = len(s1)

        diff = [i for i in range(n) if s1[i] != s2[i]]
        diff_len = len(diff)

        if diff_len % 2 == 1:
            return -1

        graph = defaultdict(dict)
        for i in range(diff_len):
            for j in range(i + 1, diff_len):
                if i == j:
                    continue
                graph[i][j] = min(x, diff[j] - diff[i])
                graph[j][i] = min(x, diff[j] - diff[i])

        def prim(start):
            mst = {start: 0}
            visited = {start}
            edges = [(cost, start, to) for to, cost in graph[start].items()]
            heapify(edges)

            while edges:
                cost, frm, to = heappop(edges)
                if to not in visited:
                    visited.add(to)
                    mst[to] = cost
                    for to_next, cost2 in graph[to].items():
                        if to_next not in visited:
                            heappush(edges, (cost2, to, to_next))

            return sum(mst.values())

        return min(prim(i) for i in range(diff_len))


solution = Solution()
print(solution.minOperations("11001011111", "01111000110", 2))
