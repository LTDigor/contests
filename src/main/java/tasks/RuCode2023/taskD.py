n = int(input())
needed_nines = 0
for _ in range(n):
    p = input()
    p_needs = 2
    for i in range(len(p) - 1, -1, -1):
        if p[i] == '0':
            p_needs += 1
        else:
            if p[i] == '9':
                p_needs -= 1
            break
    needed_nines += p_needs


print(needed_nines)
