def rotate(matrix):
    size = len(matrix)
    for row in range(size // 2):
        for col in range(size // 2 + size % 2):
            tmp = matrix[col][size - 1 - row]
            matrix[col][size - 1 - row] = matrix[row][col]
            matrix[row][col] = matrix[size - 1 - col][row]
            matrix[size - 1 - col][row] = matrix[size - 1 - row][size - 1 - col]
            matrix[size - 1 - row][size - 1 - col] = tmp


def shift_left_up(m):
    size = len(m)
    for _ in range(size - 1):
        if '#' not in m[0]:
            first = m[0]
            for row in range(size - 1):
                m[row] = m[row + 1]
            m[-1] = first
        else:
            break
    for _ in range(size - 1):
        if all(m[row][0] != '#' for row in range(size)):
            for row in range(size):
                m[row] = m[row][1:] + m[row][0:1]
        else:
            break


def solve(m1, m2):
    shift_left_up(m2)
    for i in range(4):
        if i != 0:
            rotate(m1)
        shift_left_up(m1)
        if m1 == m2:
            print('YES')
            return
    print('NO')


n = int(input())
a = [list(input()) for _ in range(n)]
b = [list(input()) for _ in range(n)]

solve(a, b)
