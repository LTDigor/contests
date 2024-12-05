hor = []
vert = []

n = int(input())
for _ in range():
    x, y = map(int, input().split())
    hor.append(x)
    vert.append(y)

hor.sort()
vert.sort()

res = 0

for i in range(1, n + 1):
    res += abs(hor[i] - i)
    res += abs(vert[i] - i)

print(res)

