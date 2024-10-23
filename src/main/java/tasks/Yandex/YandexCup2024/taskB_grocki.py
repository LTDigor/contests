t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    desc = 0
    asc = 0

    prev_asc = 0
    prev_desc = 0

    res = 0
    trend = 0
    for i in range(1, n):
        if arr[i] - arr[i - 1] > 0:
            asc += 1
            if trend <= 0:
                prev_desc = desc
                trend = 1
            desc = 0
        elif arr[i] - arr[i - 1] < 0:
            desc += 1
            if trend >= 0:
                prev_asc = asc
                trend = -1
            asc = 0
            res += prev_asc
        else:
            trend = 0
            asc = 0
            prev_asc = 0

            desc = 0
            prev_desc = 0
    print(res)





