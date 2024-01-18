def find_left_len(nums):
    n = len(nums)
    res = n

    # find seq start
    left = -1
    for i in range(n - 2):
        if nums[i] == nums[i + 1] and nums[i] == nums[i + 2]:
            left = i
            break

    right = left + 1
    while left >= 0 and right < n and nums[left] == nums[right]:
        prev_left = left
        prev_right = right

        while left >= 0 and nums[left] == nums[prev_left]:
            left -= 1

        while right < n and nums[right] == nums[prev_right]:
            right += 1

        to_delete = (right - prev_right) + (prev_left - left)
        if to_delete < 3:
            break
        res -= to_delete

    return res


arr = list(map(int, input().split()))
print(find_left_len(arr))
