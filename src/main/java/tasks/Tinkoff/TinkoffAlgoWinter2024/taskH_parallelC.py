from collections import defaultdict

n = int(input())

lines = defaultdict(int)
parallels = defaultdict(int)
summ = 0


def normalize(a, b, c):
    if a == 0:
        b, c = 1, c / b
    else:
        a, b, c = 1, b / a, c / a

    return a, b, c


for _ in range(n):
    s = input()
    t = s[0]

    if t == '1':
        _, a, b, c, q = map(int, s.split())
        a, b, c = normalize(a, b, c)
        lines[(a, b, c)] += q
        summ += q
        parallels[(a, b)] += q
    else:
        _, a, b, c = map(int, s.split())
        a, b, c = normalize(a, b, c)

        if lines[(a, b, c)] != 0:
            print('inf')
        else:
            charge = summ - parallels[(a, b)]
            print(charge)
