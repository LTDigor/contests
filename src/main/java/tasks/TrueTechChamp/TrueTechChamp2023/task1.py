d = list(map(int, input()))
n = len(d)

eq = 1
for i in range(n - 2, -1, -1):
    if d[i + 1] == d[i]:
        eq += 1
    else:
        break

more = 0
if d[1:] == [0, 1, 2]:
    more = 3
elif d[2:] == [1, 2] or d[2:] == [0, 1]:
    more = 2
elif d[-1] in [0, 1, 2]:
    more = 1

less = 0
if d[2:] == [9, 8, 7]:
    less = 3
elif d[2:] == [9, 8] or d[2:] == [8, 7]:
    less = 2
elif d[-1] in [9, 8, 7]:
    less = 1

res = 1
if eq == 1 and (less == 1 and more == 0 or more == 1 and less == 0):
    res = 2

print(res)
