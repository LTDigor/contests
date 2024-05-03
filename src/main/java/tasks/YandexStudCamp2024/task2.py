def update(bit, i, x):
    while i < len(bit):
        bit[i] += x
        i += i & (-i)


def get_sum(bit, i):
    res = 0
    while i > 0:
        res += bit[i]
        i -= i & (-i)
    return res


n = int(input())

ops = []
used_priorities = []
for _ in range(n):
    op, priority = map(int, input().split())
    ops.append((op, priority))
    if op == 1:
        used_priorities.append(priority)

used_priorities.sort()
p_to_compressed = {v: i + 1 for i, v in enumerate(used_priorities)}
compressed_to_p = {v: k for k, v in p_to_compressed.items()}

tree = [0] * (len(p_to_compressed) + 1)
total = 0
for op, priority in ops:
    if op == 1:
        priority = p_to_compressed[priority]
        update(tree, priority + 1, 1)
        total += 1
    elif op == 0:
        ind = priority
        l, r = 1, len(p_to_compressed)
        while l <= r:
            mid = (l + r) // 2
            if total - get_sum(tree, mid) + 1 <= ind:
                r = mid - 1
            else:
                l = mid + 1
        priority = compressed_to_p[l - 1]
        print(priority)
    else:
        priority = p_to_compressed[priority]
        update(tree, priority + 1, -1)
        total -= 1
