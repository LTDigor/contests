n = int(input())
costs = [0] * n
for i in range(1, n):
    costs[i] = 20 * i**2 - 4 * i + 1 + costs[i - 1]

print(*costs)
