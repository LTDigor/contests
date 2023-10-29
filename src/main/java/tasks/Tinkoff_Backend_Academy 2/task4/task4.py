q = int(input())


def compress(number):
    while number > 9:
        number = sum(map(int, str(number)))
    return number


for i in range(q):
    l, r = map(int, input().split())
    num = 1
    for i in range(l, r + 1):
        num *= i

    print(compress(num))
