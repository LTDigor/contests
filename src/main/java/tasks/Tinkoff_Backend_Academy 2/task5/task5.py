import math

n = int(input())

dp = [(-math.inf, -math.inf, 0, 0, 0)] * n
for i in range(n):
    herd = input()
    na, nb, nc = herd.count('a'), herd.count('b'), herd.count('c')

    ugliness = max(na, nb, nc) - min(na, nb, nc)
    power = na + nb + nc
    dp[i] = (-ugliness, power, na, nb, nc)

    for j in range(i):
        _, _, old_na, old_nb, old_nc = dp[j]
        new_na, new_nb, new_nc = na + old_na, nb + old_nb, nc + old_nc

        ugliness = max(new_na, new_nb, new_nc) - min(new_na, new_nb, new_nc)
        power = new_na + new_nb + new_nc
        dp[i] = max(dp[i], (-ugliness, power, new_na, new_nb, new_nc))

max_power = max(dp)[1]
print(dp)
print(max_power)
