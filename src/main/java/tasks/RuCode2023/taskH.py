adults, children = map(int, input().split())

s = -1
while adults > 0 or children > 0:
    if children > adults:
        children -= 1
    else:
        adults -= 1

    children -= 3
    adults -= 3
    s += 2

print(s)
