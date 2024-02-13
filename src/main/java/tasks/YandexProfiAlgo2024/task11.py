import copy
import math

numbers = int(input())
prev = [[]]
for i in range(1, numbers + 1):
    curr = copy.deepcopy(prev)
    for variant in curr:
        variant.append({i})

    for variant in prev:
        for set_ind, _set in enumerate(variant):
            if all((i - item) not in _set for item in _set):
                variant_copy = copy.deepcopy(variant)
                variant_copy[set_ind].add(i)
                curr.append(variant_copy)
    print(len(curr))
    prev = curr

# n = int(input())
# bell_digits = [0] * (n + 1)
# bell_digits[0] = 1
#
# for i in range(1, n + 1):
#     for j in range(i):
#         bell_digits[i] += bell_digits[j] * math.comb(i - 1, j)
#
# print(bell_digits)

# 1
# 1
# 3
# 6
# 20
# 67
# 291
# 1099
# 5780
# 26249
# 153238
# 832366
# 5443440
