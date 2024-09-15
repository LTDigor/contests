s = input()
k = int(input())
cur = []

starts = s.count('*')
questions = s.count('?')
original_len = len(s) - starts - questions
if original_len - starts - questions > k:
    print('Impossible')
else:
    for c in s:
        if c not in ('*', '?'):
            cur.append(c)
            continue

        if original_len > k:
            cur.pop()
            original_len -= 1
        elif original_len < k:
            if c == '*':
                cur.extend([cur[-1]] * (k - original_len))
                original_len = k
    if len(cur) == k:
        print(*cur, sep='')
    else:
        print('Impossible')
