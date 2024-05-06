t = int(input())

for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))

    if n == 1:
        print("YES")
    else:
        res = True
        ones_counter = 0
        for a in arr:
            ones_counter += int(a == 1)
            if a == 0 or ones_counter > 2:
                res = False
                break
        print("YES" if res else "NO")




