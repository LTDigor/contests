n = int(input())

coords = set()
steps = [tuple(map(int, input().split())) for _ in range(n)]

res = "Draw"


def gen_cell(pos, center_row, center_col, dir_r, dir_c):
    lst = []
    for i in range(1, pos + 1):
        lst.append((center_row - dir_r * i, center_col - dir_c * i))

    for i in range(5 - pos):
        lst.append((center_row + dir_r * i, center_col + dir_c * i))

    return lst


def check_win(center_row, center_col, figure):
    for dir_r, dir_c in ((1, 0), (0, 1), (1, 1), (-1, 1)):
        for pos in range(5):
            cells = gen_cell(pos, center_row, center_col, dir_r, dir_c)
            if all((x, y, figure) in coords for x, y in cells):
                return True

    return False


for i, (r, c) in enumerate(steps):
    player = i % 2

    coords.add((r, c, player))
    if check_win(r, c, player):
        if i == n - 1:
            res = "First" if i % 2 == 0 else "Second"
        else:
            res = "Inattention"
            break

print(res)
