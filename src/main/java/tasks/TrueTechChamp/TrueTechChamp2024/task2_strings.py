MOD = 998244353
inv_26 = pow(26, MOD - 2, MOD)

n = int(input())
dp = [[0] * 4 for _ in range(n)]

dp[0][0] = 25
dp[0][1] = 1

div = inv_26
for i in range(1, n):
    dp[i][0] = dp[i - 1][0] * 25
    dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * 25
    dp[i][2] = dp[i - 1][1] + dp[i - 1][2] * 25
    dp[i][3] = dp[i - 1][2] + dp[i - 1][3] * 26

    for j in range(4):
        dp[i][j] %= MOD
    div  = (div * inv_26) % MOD

print((dp[-1][-1] * div) % MOD)