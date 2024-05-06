n = int(input())
mul = n // 1000
rem = n % 1000

N = 2002
dp = [13_000_000] * (N + 1)
dp[1] = 0
dp[0] = 0
for i in range(1, N + 1):
    for j in range(i + 1, N + 1):
        dp[j] = min(dp[j], dp[i] + (179 * i + 719 * j) % 1000 - 500)


print(dp[rem] + mul * (dp[rem + 1000] - dp[rem]))

# 3002 -566279
