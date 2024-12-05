def expected_value(a, b, c, d, N):
    def g(x):
        return a * x ** 3 + b * x ** 2 + c * x + d

    res = 0.0
    step = 1 / N
    x = 0
    for i in range(N):
        mid = (x + x + step) / 2
        res += f(mid) * g(mid) * step
        x += step
    return round(res, 3)


def f(x):
    return 6 * (1 - x * x) ** 2 * x


def solution():
    a, b, c, d = map(float, input().split())
    N = int(input())
    print(expected_value(a, b, c, d, N))


solution()
