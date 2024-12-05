def integral(a, b, c, d, K, M, N):
    h = (M - K) / N  # Шаг разбиения интервала
    res = 0.0

    for i in range(N):
        x = K + i * h  # Вычисляем текущую точку на интервале
        res += (a * x ** 3 + b * x ** 2 + c * x + d) * h  # Прибавляем площадь прямоугольника

    return round(res, 3)


def solution():
    a, b, c, d = map(float, input().split())
    K, M = map(float, input().split())
    N = int(input())
    print(integral(a, b, c, d, K, M, N))


solution()
