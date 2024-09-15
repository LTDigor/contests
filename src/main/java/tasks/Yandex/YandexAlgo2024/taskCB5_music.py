n = int(input())
a = list(map(int, input().split()))

to_del = -1
visited = set()
prev = 0
for i in range(1, n):
    if a[i] < a[i - 1] and a[i - 1] not in visited:
        to_del = a[i - 1]
        break
    elif a[i] != a[i - 1]:
        visited.add(a[i - 1])

if to_del == -1:
    to_del = max(a)

print(*(x for x in a if x != to_del))


