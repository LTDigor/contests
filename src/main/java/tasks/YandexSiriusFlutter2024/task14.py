def contains(square, point):
    square_x, square_y, square_side = square
    return square_x <= point[0] <= square_x + square_side and square_y <= point[1] <= square_y + square_side


def is_intersect(square, child):
    if square[0] > child[0]:
        square, child = child, square

    square_x, square_y, square_side = square
    child_x, child_y, child_side = child

    return not (child_y > square_y + square_side or child_x > square_x + square_side or child_y + child_side < square_y)


n = int(input())

parents = {}
squares = []
for i in range(n):
    x, y, r = map(int, input().split())
    squares.append((x - r - 1, y - r - 1, 2 * r + 1))

x_start, y_start = map(int, input().split())
x_end, y_end = map(int, input().split())

for square in squares:
    parent = square
    for child, old_parent in parents.items():
        if is_intersect(square, child):
            parent = old_parent
            break
    parents[square] = parent

start_parent = (-1, -1, -1)
for child, parent in parents.items():
    if contains(child, (x_start, y_start)):
        start_parent = parent
        break

end_parent = (-2, -2, -2)
for child, parent in parents.items():
    if contains(child, (x_end, y_end)):
        end_parent = parent
        break

print(1 if start_parent == end_parent else 0)

# 3
# 1 1 1
# 4 4 2
# 7 1 1
# 0 0
# 8 0

# 3
# 1 1 1
# 4 4 2
# 7 1 1
# 0 0
# 1 7
