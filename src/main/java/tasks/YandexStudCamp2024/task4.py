n, k = map(int, input().split())
mx = list(map(int, input().split()))

ids = [0] * k
marks = [['Y'] * n for _ in range(k)]
errors = 0

for i in range(k):
    s = list(input().split())
    ids[i] = s[0]
    for mark_id in range(n):
        mark = s[mark_id + 1]
        if mark == '-':
            continue
        mark = int(mark)
        if mark < 0 or mark > mx[mark_id]:
            marks[i][mark_id] = 'N'
            errors += 1

print(errors)
for i in range(k):
    print(ids[i], *marks[i])

