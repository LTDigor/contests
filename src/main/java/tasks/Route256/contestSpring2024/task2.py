t = int(input())

for _ in range(t):
    s = input()
    filler = s[0]
    if filler != s[-1]:
        print('No')
        continue
    res = True
    for i in range(1, len(s) - 1):
        if s[i] != filler and (s[i - 1] != filler or s[i + 1] != filler):
            res = False
            break
    print('Yes' if res else 'No')
