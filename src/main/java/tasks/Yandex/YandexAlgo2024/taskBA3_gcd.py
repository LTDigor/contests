def gcd(x, y):
    if x < y:
        x, y = y, x
    if y == 0:
        return x
    while x % y > 0:
        x, y = y, x % y
    return y


def build_gcd(arr, src, p, l, r):
    if l + 1 == r:
        arr[p] = src[l]
        return

    mid = (l + r) // 2
    lp = 2 * p + 1
    rp = 2 * p + 2

    build_gcd(arr, src, lp, l, mid)
    build_gcd(arr, src, rp, mid, r)

    arr[p] = gcd(arr[lp], arr[rp])


def get_gcd(arr, p, l, r, lq, rq):
    if lq <= l and r <= rq:
        return arr[p]
    if rq <= l or r <= lq:
        return 0

    mid = (l + r) // 2
    lp = 2 * p + 1
    rp = 2 * p + 2

    ans_l = get_gcd(arr, lp, l, mid, lq, rq)
    ans_r = get_gcd(arr, rp, mid, r, lq, rq)

    return gcd(ans_l, ans_r)


n, q = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

gcd_a = [0] * (4 * n)
gcd_b = [0] * (4 * n)

a_diff = [abs(a[i] - a[i + 1]) for i in range(n - 1)]
b_diff = [abs(b[i] - b[i + 1]) for i in range(n - 1)]

build_gcd(gcd_a, a_diff, 0, 0, n - 1)
build_gcd(gcd_b, b_diff, 0, 0, n - 1)

for _ in range(q):
    x1, x2, y1, y2 = map(int, input().split())
    x1 -= 1
    x2 -= 1
    y1 -= 1
    y2 -= 1

    res = a[x1] + b[y1]
    if x2 > x1:
        val = get_gcd(gcd_a, 0, 0, n - 1, x1, x2)
        res = gcd(res, val)
    if y2 > y1:
        val = get_gcd(gcd_b, 0, 0, n - 1, y1, y2)
        res = gcd(res, val)

    print(res)
