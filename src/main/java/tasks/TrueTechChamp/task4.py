def countWays(side):
    mod = 998_244_353
    if side == 4:
        return 4

    return formula1(side) % mod


# (N - 1) + 2 * (N - 3 + N - 6 + ...)
def formula1(side):
    return (side - 1) + 2 * count_ariph_sum(side - 4, 3)


def count_ariph_sum(max_item, step):
    items_num = max_item // step + 1
    min_item = max_item - step * (items_num - 1)

    summ = ((max_item + min_item) * items_num) // 2
    return summ


N = int(input())
print(countWays(N))
