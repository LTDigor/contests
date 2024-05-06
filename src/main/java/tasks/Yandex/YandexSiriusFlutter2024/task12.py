from collections import defaultdict

n = int(input())
prefs = defaultdict(lambda: defaultdict(int))


def add(count, word):
    pref = ""
    for char in word:
        pref = pref + char
        prefs[pref][word] += count


def ask(prefix):
    items = sorted(prefs[prefix].items(), key=lambda x: (-x[1], x[0]))
    return items[0][0]


for i in range(n):
    s = input()
    if s[0] == '+':
        _, count, word = s.split()
        count = int(count)
        add(count, word)
    else:
        _, prefix = s.split()
        res = ask(prefix)
        print(res)

# 8
# + 10 abacaba
# ? a
# + 11 aba
# ? a
# + 1 abacaba
# ? a
# + 1 abacaba
# ? a
