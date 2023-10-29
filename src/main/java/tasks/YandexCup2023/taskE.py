def inverse_modulo(a):
    return pow(a, mod - 2, mod)

mod = 10 ** 9 + 7
n = int(input())
f = []
for _ in range(n):
    f.append(tuple(map(int, input().split())))

remove_inds_relatively = list(map(int, input().split()))
for i in range(n - 1):
    remove_inds_relatively[i] -= 1

func_inds = list(range(n))
remove_inds = []
for ind_to_delete in remove_inds_relatively:
    remove_inds.append(func_inds.pop(ind_to_delete))


last_ind = n * (n - 1) // 2 - sum(remove_inds)
added_inds = remove_inds[::-1]
a_last, b_last = f[last_ind]
last_root = inverse_modulo(a_last) * (mod - b_last) % mod if a_last != 0 else -1

res = [last_root]
for i in range(n - 1):
    a, b = f[added_inds[i]]
    if a == 0 or res[-1] == -1:
        res.append(-1)
    else:
        root = inverse_modulo(a) * (res[-1] - b) % mod
        res.append(root)

res.reverse()
print(*res, sep='\n')
