def check(a, b, c):
    return a + b > c and b + c > a and a + c > b


def solve():
    a, b, c = map(int, input().split())
    d, e, f = map(int, input().split())

    if check(a, b, c) and check(d, e, f):
        print(1)
        if b == e and (a == d and c == f or a == f and c == d):
            print(1)
        else:
            print(0)
    else:
        print(0)


solve()
