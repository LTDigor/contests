import math

def countDivisors(num):
    div_count = 0
    sqrt_num = int(math.sqrt(num))

    for i in range(1, sqrt_num + 1):
        if num % i == 0:
            div_count += 1
            if i != num // i:
                div_count += 1

    return div_count


def findProbability(n, k):
    divisorsVal = [0] * (k + 1)
    for i in range(1, k + 1):
        divisorsVal[i] = countDivisors(i)