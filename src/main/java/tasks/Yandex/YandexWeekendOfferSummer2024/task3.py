n = int(input())
root_val = int(input())

INF = 1_000_000_000
NEG_INF = 1

left_children = [-1] * n
right_children = [-1] * n
mx = [INF] * n
mn = [NEG_INF] * n
mx_key = [-1] * n
mn_key = [-1] * n

keys = [-1] * n
keys[0] = root_val

for i in range(1, n):
    key, parent, direction = input().split()
    key = int(key)
    parent = int(parent) - 1
    keys[i] = key
    if direction == 'R':
        right_children[parent] = i
    else:
        left_children[parent] = i


def dfs(node, up_min, up_max):
    left = left_children[node]
    right = right_children[node]
    if left != -1:
        dfs(left, up_min, min(up_max, keys[node] - 1))
        mn_key[node] = mn_key[left]
        mn[node] = max(up_min, mx[left] + 1)
    else:
        mn_key[node] = keys[node]
        mn[node] = up_min

    if right != -1:
        dfs(right, max(up_min, keys[node]), up_max)
        mx_key[node] = mx_key[right]
        mx[node] = min(up_max, mn[right])
    else:
        mx_key[node] = keys[node]
        mx[node] = up_max


dfs(0, NEG_INF, INF)

lq, rq = map(int, input().split())
res = 0
for i in range(n):
    left_c = left_children[i]
    right_c = right_children[i]
    if left_c == -1:
        l = max(mn[i], lq)
    else:
        l = max(mx_key[left_c] + 1, lq)

    if right_c == -1:
        r = min(mx[i], rq)
    else:
        r = min(mn_key[right_c], rq)
    res += max(0, r - l)
print(res)
