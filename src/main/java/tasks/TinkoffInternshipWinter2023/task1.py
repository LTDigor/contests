from collections import Counter

t = int(input())

tinkoff_counter = Counter("TINKOFF")
for _ in range(t):
    s = input()
    print("YES" if len(s) == 7 and Counter(s) == tinkoff_counter else "NO")
