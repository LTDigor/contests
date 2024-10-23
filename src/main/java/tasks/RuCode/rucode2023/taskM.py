l, r = map(int, input().split())

if (r - l) == 1:
    print(-1)
elif r == l:
    print(r)
else:
    print(r - 1)
