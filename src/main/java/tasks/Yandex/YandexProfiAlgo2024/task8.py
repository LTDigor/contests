def digit_summ(number):
    res = 0
    while number > 0:
        res += number % 10
        number //= 10
    return res


n = int(input())

k = n
while k % digit_summ(k) != 0:
    k += 1

print(k)
