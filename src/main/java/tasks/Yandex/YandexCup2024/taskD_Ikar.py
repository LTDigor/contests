from functools import cache

@cache
def ask(x):
    print(x)
    ans = input()
    return ans == 'ok'

def bin_search(l, r):
    R = 10**18
    while l <= r:
        mid = (l + r) // 2
        is_ok = ask(mid)
        if is_ok:
            R = mid
            r = R - 1
        else:
            l = mid + 1
            r = min(2 * l, R)
    return l



ans = ask(1)
if ans:
    print('!', 1)
else:
    print('!', bin_search(2, 4))