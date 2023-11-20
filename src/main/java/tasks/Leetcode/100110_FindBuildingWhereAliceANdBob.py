from typing import List


class Solution:
    def leftmostBuildingQueries(self, heights: List[int], queries: List[List[int]]) -> List[int]:
        n = len(heights)
        preMax = [0] * n
        preMax[-1] = n - 1

        for i in range(n - 2, -1, -1):
            if heights[i] < heights[preMax[i + 1]]:
                preMax[i] = preMax[i + 1]
            else:
                preMax[i] = i

        res = []
        for ai, bi in queries:
            if ai == bi:
                res.append(ai)
                continue
            li, ri = min(ai, bi), max(ai, bi)
            if heights[li] >= heights[ri]:
                if preMax[li] == li:
                    res.append(-1)
                else:
                    l, r = ri + 1, n - 1
                    while l <= r:
                        mid = (l + r) // 2
                        if heights[preMax[mid]] > heights[li]:
                            r = mid - 1
                        else:
                            l = mid + 1
                    if l == n:
                        res.append(-1)
                    else:
                        res.append(preMax[l])
            else:
                res.append(ri)

        return res


# print(Solution().leftmostBuildingQueries([6, 4, 8, 5, 2, 7], [[0, 1], [0, 3], [2, 4], [3, 4], [2, 2]]))
print(Solution().leftmostBuildingQueries([5, 3, 8, 2, 6, 1, 4, 6], [[0, 7], [3, 5], [5, 2], [3, 0], [1, 6]]))
