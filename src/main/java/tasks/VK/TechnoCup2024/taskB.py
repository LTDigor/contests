def solve():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    s = sum(min(i, k) for i in a)
    print(s // k)


solve()
