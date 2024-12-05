MX_POW = 11
MX = 2 ** MX_POW
MX_VAL = min(2024, MX)

ask_data = []
for t_pow in range(MX_POW):
    t = 2 ** t_pow
    row = []
    cur = 1
    while cur <= MX_VAL:
        row.append(cur)
        if cur % t == 0:
            cur += t
        cur += 1

    ask_data.append(row)
    row = []
ask_data.reverse()

def ask():
    for row in ask_data:
        print(*row, fli)
    ans = list(map(int, input().split()))
    return ans

t = int(input())
for _ in range(t):
    ans = ask()
    l = 1
    r = MX
    for i in range(MX_POW):
        mid = (l + r) // 2
        if ans[i] == 1:
            r = mid
        else:
            l = mid + 1
    print(l)
