n = int(input())

prefix = list(int(x) - 1 for x in input().split())
infix = list(int(x) - 1 for x in input().split())

infix_positions = {x: i for i, x in enumerate(infix)}

left = [-1] * n
right = [-1] * n


# left included, right excluded
def check_subtree(pref_l, pref_r, inf_l, inf_r):
    # empty
    if inf_l == inf_r:
        return True

    # leaf
    if inf_l + 1 == inf_r:
        if prefix[pref_l] != infix[inf_l]:
            return False
        return True

    root = prefix[pref_l]

    # Prefix: ROOT_LEFT_RIGHT
    # Infix: LEFT_ROOT_RIGHT
    left_tree_size = infix_positions[root] - inf_l
    right_tree_size = inf_r - inf_l - left_tree_size - 1

    res_left = check_subtree(pref_l + 1, pref_l + 1 + left_tree_size, inf_l, inf_l + left_tree_size)
    res_right = check_subtree(pref_l + 1 + left_tree_size, pref_r, inf_l + left_tree_size + 1, inf_r)

    if res_left and res_right:
        if left_tree_size > 0:
            left[root] = prefix[pref_l + 1]
        if right_tree_size > 0:
            right[root] = prefix[pref_l + 1 + left_tree_size]
        return True
    else:
        return False


if prefix[0] != 0 or not check_subtree(0, n, 0, n):
    print(-1)
else:
    for i in range(n):
        print(left[i] + 1, right[i] + 1)

