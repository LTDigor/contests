rows, cols, colors_num, questions_num = map(int, input().split())

colors = [0] * colors_num
used_rows, used_cols = set(), set()

questions = []
for _ in range(questions_num):
    line_type, number, color = map(int, input().split())
    questions.append((line_type, number, color - 1))


for line_type, number, color in questions[::-1]:
    used, another = used_rows, used_cols
    x, y = rows, cols
    if line_type == 2:
        used, another = another, used
        x, y = y, x

    if number not in used:
        used.add(number)
        colors[color] += y - len(another)

print(*colors)

# 4 6 5 7
# 1 1 1
# 2 2 4
# 1 3 3
# 2 4 2
# 1 1 2
# 1 1 5
# 2 1 3

# 50000000 50000000 3 5
# 1 1 2
# 1 2 3
# 1 3 3
# 1 4 3
# 1 5 3
