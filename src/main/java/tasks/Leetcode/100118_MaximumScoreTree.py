from collections import defaultdict
from typing import List


class Solution:
    def maximumScoreAfterOperations(self, edges: List[List[int]], values: List[int]) -> int:
        tree = defaultdict(list)
        for frm, to in edges:
            tree[frm].append(to)
            tree[to].append(frm)

        def dfs(node, frm):
            to_loose = 0
            for nxt in tree[node]:
                if nxt != frm:
                    to_loose = + dfs(nxt, node)

            if to_loose == 0:
                return values[node]
            return min(to_loose, values[node])

        return sum(values) - dfs(0, -1)


print(Solution().maximumScoreAfterOperations(edges=[[0, 1], [0, 2], [0, 3], [2, 4], [4, 5]], values=[5, 2, 5, 2, 1, 1]))
print(Solution().maximumScoreAfterOperations(edges=[[0,1]], values=[2, 1]))
