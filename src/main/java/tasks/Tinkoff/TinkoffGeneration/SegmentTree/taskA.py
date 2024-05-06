def upd(p, l, r, ind, x):
    if r - l == 1:
        t[p] = x
        return

    mid = l + (r - l) // 2
    if ind < mid:
        upd(2 * p + 1, l, mid, ind, x)
    else:
        upd(2 * p + 2, mid, r, ind, x)

    t[p] = t[2 * p + 1] + t[2 * p + 2]


def get(p, l, r, lq, rq):
    if r <= lq or l >= rq:
        return 0
    if l >= lq and r <= rq:
        return t[p]

    mid = l + (r - l) // 2
    return get(2 * p + 1, l, mid, lq, rq) + get(2 * p + 2, mid, r, lq, rq)


n, k = map(int, input().split())
t = [0] * (4 * n)

for _ in range(k):
    s = input()
    if s[0] == 'A':
        i, x = map(int, s[2:].split())
        upd(0, 0, n, i - 1, x)
    else:
        lq, rq = map(int, s[2:].split())
        print(get(0, 0, n, lq - 1, rq))
