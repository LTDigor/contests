import math


def mix(number):
    saved_number = number
    ones = [0] * ones_size
    while number > 0:
        prev_pow = math.floor(math.log2(number))
        for i in range(prev_pow):
            ones[i] += 2 ** (prev_pow - 1)

        ones[prev_pow] += number - 2 ** prev_pow + 1
        number -= 2 ** prev_pow

    summ = saved_number * (saved_number + 1) // 2
    for i in range(ones_size):
        summ += ones[i] * pow(2, i, mod)
        summ %= mod

    return summ


def old_mix(number):
    summ = number * (number + 1) // 2 % mod
    for i in range(1, number + 1):
        for j in range(i + 1, number + 1):
            summ += 2 * (i & j)
    summ %= mod

    return summ


t = int(input())
mod = 10 ** 9 + 7
ones_size = 62

for _ in range(t):
    print(mix(int(input())))
