n, k, a, m = map(int, input().split())


def lcg(e):
    return (a * e + 11) % m


def next_coin(seed):
    return (abs(seed % 3 - 1) * 5 + abs(seed % 3) * 2) % 8


seed = 0
counter = 0
coins = 0
sweets = 0
while sweets < n:
    counter += 1
    seed = lcg(seed)
    coins += next_coin(seed)
    if coins >= k * 3:
        sweets += coins // 3
        coins = coins % 3

print(counter)
