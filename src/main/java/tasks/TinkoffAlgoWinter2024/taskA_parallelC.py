balloons, workers = map(int, input().split())

balloon_time_arr, balloons_to_rest_arr, long_period_arr = [], [], []

for _ in range(workers):
    balloon_time, balloons_to_rest, time_to_rest = map(int, input().split())
    long_period = balloon_time * balloons_to_rest + time_to_rest

    balloon_time_arr.append(balloon_time)
    balloons_to_rest_arr.append(balloons_to_rest)
    long_period_arr.append(long_period)

left, right = 1, 10 ** 9 + 1
while left <= right:
    mid = (left + right) // 2
    will_inflate = 0
    for i in range(workers):
        will_inflate += (mid // long_period_arr[i]) * balloons_to_rest_arr[i]
        will_inflate += min(balloons_to_rest_arr[i], mid % long_period_arr[i] // balloon_time_arr[i])

    if will_inflate >= balloons:
        right = mid - 1
    else:
        left = mid + 1

print(left)
