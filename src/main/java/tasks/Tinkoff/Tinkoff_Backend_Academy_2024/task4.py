from collections import deque

from math import inf

n, m = map(int, input().split())
platform = []
for _ in range(m):
    s, t = map(int, input().split())
    s -= 1
    t -= 1
    platform.append((s, t))

dp = [[inf] * n for _ in range(m)]

platform_len = platform[0][1] - platform[0][0] + 1
for row in range(n - platform_len + 1):
    dp[0][row] = abs(row - platform[0][0])

for col in range(1, m):
    platform_len = platform[col][1] - platform[col][0] + 1
    prev_platform_len = platform[col - 1][1] - platform[col - 1][0] + 1
    for up_edge in range(n - platform_len + 1):
        dp[col][up_edge] = abs(up_edge - platform[col][0])
        dp[col][up_edge] += min(dp[col - 1][max(0, up_edge - prev_platform_len + 1):min(n, up_edge + platform_len)])


print(min(dp[-1]))
