hours, minutes = map(int, input().split())
res = 0

mx, mn = max(hours, minutes), min(hours, minutes)
mx_str_len = len(str(mx - 1))
res = 0
for time in range(mn):
    if int(str(time)[::-1] + '0' * (mx_str_len - len(str(time)))) < mx:
        res += 1
print(res)
