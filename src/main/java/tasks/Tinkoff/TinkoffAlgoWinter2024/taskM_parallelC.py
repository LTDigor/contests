from collections import Counter

n, m = map(int, input().split())
old_arr = list(map(int, input().split()))
new_arr = list(map(int, input().split()))

counter_old, counter_new = Counter(old_arr), Counter(new_arr)

res = True
for key, freq in counter_old.items():
    if key not in counter_new or counter_new[key] < freq:
        res = False
        break

print(1303 if res else 179)
