S = input()
pos = 0
diff = 0

pos_plus_diff = [0]
pos_minus_diff = [0]

for c in S:
    if c == 'R':
        pos += 1
    elif c == 'L':
        pos -= 1
    else:
        diff += 1
    pos_plus_diff.append(pos + diff)
    pos_minus_diff.append(pos - diff)
res = max(pos_plus_diff) - min(pos_plus_diff)
res = max(res, max(pos_minus_diff) - min(pos_minus_diff))
print(res)
