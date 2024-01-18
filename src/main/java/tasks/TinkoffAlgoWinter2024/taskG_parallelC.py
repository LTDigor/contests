n, k = map(int, input().split())
a = list(map(int, input().split()))

coins = a.copy() + a.copy()
n = 2 * n

res = False
res_coins = []
for mask in range(1, 2 ** n):
    summ = 0
    peeked = []
    for i in range(n):
        if mask >> i & 1:
            summ += coins[i]
            peeked.append(coins[i])
    if summ == k:
        res = True
        res_coins = peeked
        break

if res:
    print('Yes')
    print(len(res_coins))
    print(*res_coins)
else:
    print('No')



