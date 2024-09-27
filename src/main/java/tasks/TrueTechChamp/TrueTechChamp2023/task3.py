def add_points(arr):
    if len(arr) <= 1:
        return

    curr_pos = 0
    min_pos = 0
    for i in range(len(arr)):
        if i % 2 == 0:
            curr_pos += len(arr[i])
        else:
            curr_pos -= len(arr[i])
        min_pos = min(min_pos, curr_pos)

    curr_pos = -min_pos
    for i in range(len(arr)):
        if i % 2 == 0:
            points_to_add = curr_pos
            curr_pos += len(arr[i])
        else:
            points_to_add = curr_pos - len(arr[i])
            curr_pos -= len(arr[i])

        arr[i] = '.' * points_to_add + arr[i]


def compare(strings1, strings2):
    n = min(len(strings1), len(strings2))
    for i in range(n):
        if len(strings1[i]) > len(strings2[i]):
            return True
        elif len(strings1[i]) < len(strings2[i]):
            return False

    return False


def bubble_sort(ways):
    n = len(ways)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if compare(ways[j], ways[j + 1]):
                ways[j], ways[j + 1] = ways[j + 1], ways[j]


def get_ways(string):
    res = []

    def fill_res(curr_way, left_str):
        if len(left_str) == 0:
            res.append(curr_way[:])
            return
        if len(left_str) == 1:
            return

        for i in range(1, len(left_str)):
            if len(curr_way) % 2 == 0:
                curr_way.append(left_str[:i + 1])
            else:
                curr_way.append(left_str[:i + 1][::-1])
            fill_res(curr_way, left_str[i + 1:])
            curr_way.pop()

    fill_res([], string)
    res.sort()

    # bubble sort
    bubble_sort(res)

    for one_way in res:
        add_points(one_way)

    return res


s = input()

for way in get_ways(s):
    for row in way:
        print(row)
