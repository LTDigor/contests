def add_to_res(res, start, end):
    if end > start + 1:
        res.append(start)
        res.append('...')
        res.append(end)
    elif end == start + 1:
        res.append(start)
        res.append(end)
    else:
        res.append(start)


n = int(input())
books = sorted(list(map(int, input().split())))

res = []
start = end = books[0]
for i in range(1, n):
    if books[i] == books[i - 1]:
        continue
    elif books[i] == books[i - 1] + 1:
        end = books[i]
    else:
        add_to_res(res, start, end)
        start = end = books[i]

add_to_res(res, start, end)
print(*res)
