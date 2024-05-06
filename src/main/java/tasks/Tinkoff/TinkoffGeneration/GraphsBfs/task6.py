from collections import deque

start = int(input())
end = int(input())

parent = {start: start}

q = deque([start])
while q:
    number = q.popleft()

    if number == end:
        break

    if number // 1000 < 9:
        candidate = number + 1000
        if candidate not in parent:
            q.append(candidate)
            parent[candidate] = number

    if number % 10 > 1:
        candidate = number - 1
        if candidate not in parent:
            q.append(candidate)
            parent[candidate] = number

    candidate = number // 10 + number % 10 * 1000
    if candidate not in parent:
        q.append(candidate)
        parent[candidate] = number

    candidate = number * 10 % 10000 + number // 1000
    if candidate not in parent:
        q.append(candidate)
        parent[candidate] = number

res = [end]
curr = end
while curr != start:
    res.append(parent[curr])
    curr = parent[curr]
res = res[::-1]

print(len(res))
print(*res, sep='\n')
