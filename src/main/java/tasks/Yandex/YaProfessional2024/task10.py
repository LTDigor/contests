from math import ceil, comb, floor

n = int(input())

dp = [[] for _ in range(n + 1)]
dp[0] = [0] * 26
dp[1] = [1] * 26

for l in range(2, n + 1):
    dp[l] = [0] * 26
    for last in range(26):
        for prev in range(last):
            dp[l][last] += dp[l - 1][prev]

MX_DOTS = ceil(n / 2)

dots_dp = [[[0] * 2 for d in range(MX_DOTS + 1)] for _ in range(n + 1)]

dots_dp[0][0][0] = 1
for l in range(1, n + 1):
    for dots in range(1, ceil(l / 2) + 1):
        dots_dp[l][dots][1] = 1 if dots == 1 else dots_dp[l - 1][dots - 1][0]
        dots_dp[l][dots][0] = dots_dp[l - 1][dots][1] + dots_dp[l - 1][dots][0]

res = 0
for dots in range(1, MX_DOTS + 1):
    l = n - dots
    res += sum(dp[l]) * (dots_dp[n][dots][1] + dots_dp[n][dots][0])

print(res)
