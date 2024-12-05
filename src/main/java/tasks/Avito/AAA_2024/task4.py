import math

import numpy as np
from scipy.integrate import quad

def fourier_series_coefficients(f, N):
    a0 = 1/math.pi * quad(lambda x:  f(x), -math.pi, math.pi) / 2
    res_a = [a0 / 2]
    res_b = []

    for n in range(1, N):
        a = 1/math.pi * quad(lambda x:  f(x) * numpy.cos(n * x), -math.pi, math.pi)
        b = 1/math.pi * quad(lambda x:  f(x) * numpy.sin(n * x), -math.pi, math.pi)

        res_a.append(a)
        res_b.append(b)


def solution():
    n = int(input())
    f = lambda x: numpy.cos(x) / (numpy.exp(x) + 2)
    a_coeff, b_coeff = fourier_series_coefficients(f, n)
    print(' '.join(str(v) for v in a_coeff))
    print(' '.join(str(v) for v in b_coeff))


solution()
