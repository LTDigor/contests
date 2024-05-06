n = int(input())
a = list(map(int, input().split()))

eps = 0.0001
l, r = min(a), max(a)
while True:
    line_level = (l + r) / 2

    square = 0.0
    for i in range(1, n):
        if line_level <= min(a[i], a[i - 1]) or line_level >= max(a[i], a[i - 1]):
            square += (a[i] + a[i - 1]) / 2 - line_level
        else:
            k1 = (a[i - 1] - line_level) / (a[i - 1] - a[i])
            square += (a[i - 1] - a[i]) / 2 * k1**2

            k2 = (a[i] - line_level) / (a[i] - a[i - 1])
            square += (a[i] - a[i - 1]) / 2 * k2**2

    if square > eps:
        l = line_level
    elif square < -eps:
        r = line_level
    else:
        print(line_level)
        break
