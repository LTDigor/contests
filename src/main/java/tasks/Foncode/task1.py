x = input()
a, b, c = map(int, list(x))

res = 0

res = max(res, a * 100 + b * 10 + c)
res = max(res, a * 100 + c * 10 + b)
res = max(res, b * 100 + a * 10 + c)
res = max(res, c * 100 + b * 10 + a)

print(res)