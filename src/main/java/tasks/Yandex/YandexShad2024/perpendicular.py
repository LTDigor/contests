def normalize(a, b):
    if a != 0:
        a, b = 1.0, b / a
    else:
        b = 1.0
    return a, b


n = int(input())
lines = {}

for _ in range(n):
    a, b, _ = map(float, input().split())
    a, b = normalize(a, b)
    lines[(a, b)] = lines.get((a, b), 0) + 1

q = int(input())
for _ in range(q):
    a, b, _ = map(float, input().split())
    b, a = normalize(b, a)
    if b == 0:
        a = -a
    res = lines.get((b, -a), 0)
    print(res)


# 3
# 1 -1 0
# 1 -1 1
# -2 1 3
# 4
# -1 1 3
# 1 1 2
# 8 4 7
# 4 8 7

# 3
# 5 0 1
# 0 6 7
# 2 3 4
# 3
# -1 0 12
# 0 -99 3
# -3 2 1
