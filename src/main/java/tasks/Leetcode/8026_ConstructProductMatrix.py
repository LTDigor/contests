from typing import List


class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        def inverse_modulo(a, b):
            if a == 0:
                return b, 0, 1
            gcd, x1, y1 = inverse_modulo(b % a, a)
            x = y1 - (b // a) * x1
            y = x1
            return gcd, x, y

        product = 1
        MOD = 12345
        n, m = len(grid), len(grid[0])
        for i in range(n):
            for j in range(m):
                product *= grid[i][j]

        for i in range(n):
            for j in range(m):
                grid[i][j] = (product // grid[i][j]) % MOD
        return grid


print(Solution().constructProductMatrix([[1, 2], [3, 4]]))
