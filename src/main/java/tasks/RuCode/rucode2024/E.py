from linecache import cache

n, k = map(int, input().split())

def all_del_n(n):
    ans = []
    for i in range(1, n // 2):
        if n % i == 0:
            ans.append(i)

dels = all_del_n(n)

@cache
def rec(elem, k):
    for cur in dels:
        if cur <= elem:
            rec(elem-cur, k-1)

    if cur > (  elem - cur):
        pass
    if k == 1:
        if  elem - cur == 0:
            return 1

