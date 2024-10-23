grid = [input() for _ in range(8)]


def mark_grid(row, col, res):
    c = grid[row][col]
    res[row][col] = c

    if c == 'p':
        if col < 7:
            res[row - 1][col + 1] = grid[row - 1][col + 1]
        res[row - 1][col] = grid[row - 1][col]
        if col > 0:
            res[row - 1][col - 1] = grid[row - 1][col - 1]

    if c == 'P':
        if col < 7:
            res[row + 1][col + 1] = grid[row + 1][col + 1]
        res[row + 1][col] = grid[row + 1][col]
        if col > 0:
            res[row + 1][col - 1] = grid[row + 1][col - 1]

    if c.lower() == 'r' or c.lower() == 'q':
        dirs = [(1, 0), (-1, 0), (0, 1), (0, -1)]
        for dr, dc in dirs:
            for i in range(1, 8):
                nr, nc = row + dr * i, col + dc * i
                if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
                    break
                res[nr][nc] = grid[nr][nc]
                if grid[nr][nc] != '.':
                    break

    if c.lower() == 'b' or c.lower() == 'q':
        dirs = [(1, 1), (1, -1), (-1, 1), (-1, -1)]
        for dr, dc in dirs:
            for i in range(1, 8):
                nr, nc = row + dr * i, col + dc * i
                if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
                    break
                res[nr][nc] = grid[nr][nc]
                if grid[nr][nc] != '.':
                    break

    if c.lower() == 'n':
        dd = [(2, 1), (2, -1), (-2, 1), (-2, -1), (1, 2), (1, -2), (-1, 2), (-1, -2)]
        for dr, dc in dd:
            nr, nc = row + dr, col + dc
            if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
                continue
            res[nr][nc] = grid[nr][nc]

    if c.lower() == 'k':
        for dr in [-1, 0, 1]:
            for dc in [-1, 0, 1]:
                nr, nc = row + dr, col + dc
                if nr < 0 or nr >= 8 or nc < 0 or nc >= 8:
                    continue
                res[nr][nc] = grid[nr][nc]


def solve(is_black):
    res = [['?'] * 8 for _ in range(8)]
    for i in range(8):
        for j in range(8):
            c = grid[i][j]
            if c.isalpha() and c.isupper() == is_black:
                mark_grid(i, j, res)
    return res


white = solve(False)
for line in white:
    print(*line, sep='')

print()

black = solve(True)
for line in black:
    print(*line, sep='')
