n, k = map(int, input().split())

dp = [[[0] * k for _ in range(n)] for _ in range(2)]
mod = 10 ** 9 + 7

# dp[even][length][remained] = dp[