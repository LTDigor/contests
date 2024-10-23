from functools import cache

MX = int(input())

d = {}

def bin_search_left(c, mn, mx):
    l, r = mn, mx
    while l <= r:
        mid = (l + r) // 2
        nc = ask(mid)
        if nc == c:
            l = mid + 1
        else:
            bin_search_left(nc, mid + 1, mx)
            r = mid - 1
    d[c] = l - 1

@cache
def ask(x):
    print('?', x)
    ans = input()
    return ans


c = ask(1)
bin_search_left(c, 1, MX)
res = sorted(d.items(), key=lambda x: x[1])

s = ['!']
for k, v in res:
    s.append(k)
    s.append(v)

print(' '.join(s))
