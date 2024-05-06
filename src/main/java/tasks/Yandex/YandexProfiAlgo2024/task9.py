t = int(input())

for _ in range(t):
    L, R = map(int, input().split())

    if L >= 0:
        print(L, R)
    elif L < 0 and R >= 1:
        if L < -R:
            print(L, 1)
        else:
            print(R, -1)
    else:
        print(R, L)
