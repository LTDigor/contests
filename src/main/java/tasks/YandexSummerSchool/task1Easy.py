s = input()
if len(s) >= 8 and any(c.isupper() for c in s) and any(c.isdigit() for c in s) and any(c.islower() for c in s):
    print('YES')
else:
    print('NO')