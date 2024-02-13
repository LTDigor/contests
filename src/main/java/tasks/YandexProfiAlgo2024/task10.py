t = int(input())

for _ in range(t):
    s = input()
    res = 0
    curr_len = 1
    for i in range(1, len(s)):
        if s[i] == s[i - 1]:
            curr_len += 1
        else:
            curr_len = 1

        if curr_len % 3 == 0:
            res += 1
    print(res)
