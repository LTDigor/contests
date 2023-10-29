def find_ans(angles):
    axis = 0
    for angle in angles:
        axis += 180 - angle
        if axis > 360:
            return (-1,)

    angles_num = len(angles)

    if angles_num == 1:
        mn = 3
    elif 360 - axis >= 180:
        mn = angles_num + 2
    elif 360 - axis > 0:
        mn = angles_num + 1
    else:
        mn = angles_num

    mx = 360 - axis + angles_num

    return mn, mx


k = int(input())
angles = [int(input()) for _ in range(k)]
print(*find_ans(angles))
