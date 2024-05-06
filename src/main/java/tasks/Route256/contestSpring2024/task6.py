t = int(input())
mx_pow = 30

for _ in range(t):
    n, k = map(int, input().split())
    m = int(input())
    a = list(map(int, input().split()))

    freq = [0] * 30
    for item in a:
        freq[item] += 1

    rides = 1
    used_cars = 0
    used_boxes = 0
    while used_boxes < m:
        used_place = 0
        for w in range(mx_pow - 1, -1, -1):
            while freq[w] > 0 and used_place + (1 << w) <= k:
                used_place += 1 << w
                freq[w] -= 1
                used_boxes += 1

        used_cars += 1
        if used_cars > n:
            used_cars = 1
            rides += 1

    print(rides)
