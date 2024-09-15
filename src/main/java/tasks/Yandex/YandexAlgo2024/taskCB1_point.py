s = input()
c = set(s)
res = True
if ('N' in c) != ('S' in c):
    res = False
if ('W' in c) != ('E' in c):
    res = False

print('Yes' if res else 'No')
