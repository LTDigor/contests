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
    q = deque()
    for i in range(platform_len):
        while q and dp[col - 1][q[-1]] > dp[col - 1][i]:
            q.pop()
        q.append(i)

    for up_edge in range(n - platform_len + 1):
        dp[col][up_edge] = abs(up_edge - platform[col][0])
        dp[col][up_edge] += dp[col - 1][q[0]]

        if up_edge + platform_len < n:
            while q and dp[col - 1][q[-1]] > dp[col - 1][up_edge + platform_len]:
                q.pop()
            q.append(up_edge + platform_len)
        if len(q) > platform_len + prev_platform_len - 1:
            q.popleft()

print(min(dp[-1]))
