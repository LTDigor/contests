from collections import defaultdict

n, needed = map(int, input().split())
costs = list(map(int, input().split()))

buckets = defaultdict(list)
for i, cost in enumerate(costs):
    buckets[cost].append(i)

left = n
right = -1
for cost, indexes in sorted(buckets.items(), key=lambda x: x[0]):
    if needed <= 0:
        break

    if len(indexes) <= needed:
        left = min(left, indexes[0])
        right = max(right, indexes[-1])
        needed -= len(indexes)
    else:
        res_left, res_right = 0, n
        for i in range(len(indexes) - needed + 1):
            window_left = min(left, indexes[i])
            window_right = max(right, indexes[i + needed - 1])
            if window_right - window_left < res_right - res_left:
                res_right = window_right
                res_left = window_left

        left, right = res_left, res_right
        needed = 0

print(right - left + 1)


