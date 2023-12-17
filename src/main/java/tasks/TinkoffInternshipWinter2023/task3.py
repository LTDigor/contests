def get_max_remained(array, total):
    for a in array:
        if a <= total:
            total -= a

    return total


n, m = map(int, input().split())
arr = list(map(int, input().split()))

pref = [0] * (n + 1)
for i in range(n):
    pref[i + 1] = pref[i] + arr[i]

highest = sorted([(val, ind) for ind, val in enumerate(arr)], key=lambda x: (-x[0], x[1]))

res = m - pref[-1]
for val, ind in highest:
    if pref[ind] <= m:
        if val + pref[ind] <= m:
            res = max(res, val - 1)
        else:
            res = max(res, m - pref[ind])

print(res)
