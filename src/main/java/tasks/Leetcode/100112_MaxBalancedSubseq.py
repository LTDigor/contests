from typing import List


class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:
        if max(nums) <= 0:
            return max(nums)

        ans = nums[0]
        prev = nums[0] - 1
        for i in range(1, len(nums)):
            if nums[i] - prev > 1:
                ans = max([ans, ans + nums[i], nums[i]])
                prev = max(nums[i] - 1, prev - 1)
            else:
                ans = max(ans, nums[i])
                prev = min(nums[i] - 1, prev - 1)

        return ans


print(Solution().maxBalancedSubsequenceSum([34, 34, 32, 33]))
