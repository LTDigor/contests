import math


class FiboMatrix:
    key = 0
    matrix_cur = [[0, 0], [0, 0]]
    matrix_one = [[0, 1], [1, 1]]

    def __init__(self, key=1):
        self.key = key
        self.matrix_cur = [[key, key], [key, 0]]
        self.PowsBuffer = {}
        # Словарь для хранения возведённых в степень матриц

    def MultiplyMatrix(self, M1, M2):
        """Умножение матриц
        Ожидаются матрицы 2x2 в виде списков."""

        a11 = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0]
        a12 = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1]
        a21 = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0]
        a22 = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1]
        return [[a11, a12], [a21, a22]]

    def PowMatrix(self, M: list, p: int):
        """Возведение матрицы в степень.
        Ожидаются матрица 2x2 в виде списка и степень.
        """

        if p == 1:
            return M
        if p in self.PowsBuffer:
            return self.PowsBuffer[p]

        K = self.PowMatrix(M, int(p / 2))
        R = self.MultiplyMatrix(K, K)
        self.PowsBuffer[p] = R
        return R

    def GetNum(self, n):
        if n <= 3:
            return n

        n -= 1

        # Разложение переданного номера номера числа n на степени двойки
        powers = []
        p = 0
        for digit in reversed(bin(n)[2:]):
            if digit == '1':
                powers.append(int(pow(2, p)))
            p += 1

        matrices = [self.PowMatrix(FiboMatrix.matrix_one, p)
                    for p in powers]

        # Возведение матриц в необходимые степени

        while len(matrices) > 1:
            M1 = matrices.pop()
            M2 = matrices.pop()
            R = self.MultiplyMatrix(M1, M2)
            # Перемножение полученных матриц
            matrices.append(R)

        self.matrix_cur = self.MultiplyMatrix(self.matrix_cur, matrices[0])
        # Умножение матрицы с F1 и F2 на матрицу, полученную возведением в степень
        return self.matrix_cur[0][1]


N = int(input())

mod = 998_244_353

right = math.ceil((-1 + (1 + 8 * N) ** 0.5) / 2) + 1
left = N - ((right - 1) * (right - 2)) // 2

a, b, c, d = FiboMatrix().GetNum(left), FiboMatrix().GetNum(right), FiboMatrix().GetNum(right + 1), FiboMatrix().GetNum(right + 2)
print((a + b + c + d) % mod)
