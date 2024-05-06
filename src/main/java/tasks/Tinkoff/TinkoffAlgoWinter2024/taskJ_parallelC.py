n = int(input())
tshirts = list(map(int, input().split()))

m = int(input())
pants = list(map(int, input().split()))

ti, pi = 0, 0

res = abs(tshirts[ti] - pants[pi])
t_res, p_res = tshirts[ti], pants[pi]
while ti < n - 1 or pi < m - 1:
    if ti == n - 1 or pi < m - 1 and tshirts[ti] - pants[pi] > 0:
        pi += 1
    else:
        ti += 1

    diff = tshirts[ti] - pants[pi]
    if res > abs(diff):
        res = abs(diff)
        t_res = tshirts[ti]
        p_res = pants[pi]

print(t_res, p_res)

