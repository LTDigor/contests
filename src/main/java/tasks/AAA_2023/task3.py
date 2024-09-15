import math

from scipy.integrate import quad


def f(x):
    return 1 - 2 / (math.sin(x) + 2)


def fourier_series_coefficients(func, n):
    a = []
    b = []
    pi = math.pi

    for i in range(n + 1):
        a.append(round(quad(lambda x: func(x) * math.cos(x * i) / pi, -pi, pi)[0], 3))
        if i > 0:
            b.append(round(quad(lambda x: func(x) * math.sin(x * i) / pi, -pi, pi)[0], 3))

    return a, b


def solution():
    n = int(input())
    func = f
    a_coeff, b_coeff = fourier_series_coefficients(func, n)
    print(' '.join(str(v) for v in a_coeff))
    print(' '.join(str(v) for v in b_coeff))


solution()
