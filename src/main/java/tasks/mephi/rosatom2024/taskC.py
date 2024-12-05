s = input()

res = 0
for c in s:
    res += int(c, 16)

while res >= 16:
    s = hex(res)[2:]
    res = 0
    for c in s:
        res += int(c, 16)
print(hex(res)[2:])
