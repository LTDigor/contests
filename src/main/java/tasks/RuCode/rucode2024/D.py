def to_ind(c):
    return (ord(c) - ord('A'))


def to_char(ind):
    return chr(ord('A') + ind)


n, k = map(int, input().split())
used = [False] * n
blocked = 0

direct_inputs = (n - 2 * k) // 2
for i in range(direct_inputs):
    ind = used.index(False)
    print(to_char(ind))
    used[ind] = True

    c = input()
    used[to_ind(c)] = True
    blocked += 2


reverse_inputs = k
for i in range(reverse_inputs):
    if used[blocked + 1]:
        ind = used.index(False)
    else:
        ind = blocked + 1
    print(to_char(ind))
    used[ind] = True

    c = input()
    used[to_ind(c)] = True
    blocked += 2

if n % 2 == 1:
    ind = used.index(False)
    print(to_char(ind))