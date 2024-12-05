from collections import defaultdict


def normalize(a, b, c):
    if a != 0:
        a, b, c = 1, b / a, c / a
    else:
        b, c = 1, c / b
    return a, b, c


n = int(input())
lines = defaultdict(set)

for _ in range(n):
    a, b, c = map(float, input().split())
    a, b, c = normalize(a, b, c)
    lines[(a, b)].add(c)

q = int(input())
for _ in range(q):
    a, b, c = map(float, input().split())
    a, b, c = normalize(a, b, c)
    # if last in lines[(a, b)]:
    #     res = len(lines[(a, b)]) > 1
    # else:
    res = len(lines[(a, b)]) > 0
    print('YES' if res else 'NO')
