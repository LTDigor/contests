L = int(input())

min_vals = []
max_vals = []
val_names = []
for _ in range(L):
    s = input()
    values = s.replace("inf.readInt (", "").replace(");", "").split(', ')
    mn = int(values[0].strip())
    mx = int(values[1].strip())
    val_name = values[2].strip().strip('"')

    val_names.append(val_name)
    min_vals.append(mn)
    max_vals.append(mx)

meet_mn = [False] * L
meet_mx = [False] * L

T = int(input())
tests = [list(map(int, input().split())) for _ in range(T)]
is_error = False
for test_ind in range(T):
    test = tests[test_ind]
    for i in range(L):
        if test[i] < min_vals[i] or test[i] > max_vals[i]:
            is_error = True
            print('Error')
            print(test_ind + 1, val_names[i])
            break
        elif test[i] == min_vals[i]:
            meet_mn[i] = True
        elif test[i] == max_vals[i]:
            meet_mx[i] = True

    if is_error:
        break

if not is_error:
    min_warning_names = [val_names[i] for i in range(L) if not meet_mn[i]]
    if not min_warning_names:
        print('Min OK')
    else:
        print('Warning: Min', *min_warning_names)

    max_warning_names = [val_names[i] for i in range(L) if not meet_mx[i]]
    if not max_warning_names:
        print('Max OK')
    else:
        print('Warning: Max', *max_warning_names)
