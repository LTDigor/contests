def increment(bit, index):
    while index < len(bit):
        bit[index] += 1
        index += index & (-index)


def less_left(bit, index):
    result = 0
    while index > 0:
        result += bit[index]
        index -= index & (-index)
    return result


def count_elements_greater_to_left(arr):
    n = len(arr)
    bit = [0] * (n + 1)
    result = [0] * n

    for i in range(n):
        result[i] = i - less_left(bit, arr[i])
        increment(bit, arr[i])
    return result


def count_mega_inversions(arr):
    if len(arr) < 3:
        return 0

    inversions = count_elements_greater_to_left(arr)

    res = 0
    for mid in range(1, len(arr) - 1):
        left_greater = inversions[mid]
        right_smaller = arr[mid] - 1 - (mid - left_greater)

        res += left_greater * right_smaller

    return res


n = int(input())
p = [int(input()) for _ in range(n)]

res = count_mega_inversions(p)
print(res)
