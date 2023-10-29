import bisect
from typing import List


class Solution:
    def findIndices(self, nums: List[int], indexDifference: int, valueDifference: int) -> List[int]:
        max_q, min_q = [], []

        for i in range(len(nums)):
            if not max_q or nums[i] > max_q[-1][0]:
                max_q.append((nums[i], i))

            if not min_q or nums[i] < min_q[-1][0]:
                min_q.append((nums[i], i))

            mx_target = nums[i] + valueDifference
            mx_ind = bisect.bisect_left(max_q, mx_target, key=lambda x: x[0])

            if mx_ind < len(max_q) and i - max_q[mx_ind][1] >= indexDifference:
                return [max_q[mx_ind][1], i]

            mn_target = -(nums[i] - valueDifference)
            mn_ind = bisect.bisect_left(min_q, mn_target, key=lambda x: -x[0])

            if mn_ind < len(min_q) and i - min_q[mn_ind][1] >= indexDifference:
                return [min_q[mn_ind][1], i]

        return [-1, -1]


print(Solution().findIndices([1, 2, 3], 2, 4))
