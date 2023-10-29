v, e, s = map(int, input().split())

if e > (v * (v - 1)) // 2:
    print('No')
else:
    print('Yes')
