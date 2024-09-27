from collections import deque

x, k = input().split()
n = int(input())
available = sorted(map(int, input().split()))

mod = int(k)
digits = [int(digit) for digit in x]

start_reminder = 0
for digit in digits:
    start_reminder = (start_reminder * 10 + digit) % mod

parents = [None] * mod
parents[start_reminder] = (start_reminder, -1)

res = -1
q = deque([start_reminder])

while q:
    reminder = q.popleft()

    if reminder == 0:
        res = reminder
        break

    for nxt_digit in available:
        nxt_reminder = (reminder * 10 + nxt_digit) % mod
        if not parents[nxt_reminder]:
            parents[nxt_reminder] = (reminder, nxt_digit)
            q.append(nxt_reminder)

if res == -1:
    print(-1)
else:
    added_digits = []
    curr = res
    while curr != start_reminder:
        parent, digit = parents[curr]
        added_digits.append(digit)

        curr = parents[curr][0]

    added_digits.reverse()

    res_digits = digits + added_digits
    print(*res_digits, sep='')

