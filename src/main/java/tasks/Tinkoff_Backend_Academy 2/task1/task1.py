n = int(input())
costs = [0] * n
volume = [0] * n

volume[0] = 1
for i in range(1, n):
    volume[i] = volume[i - 1] + (2 * i + 1)**2
    costs[i] = (2 * i + 1)**3 - volume[i]

print(*costs)
