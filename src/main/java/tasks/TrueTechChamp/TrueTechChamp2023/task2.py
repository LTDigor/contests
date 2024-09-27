import math


def find_fractional(int_part, frac_part):
    p = int(int_part + frac_part)
    q = 10 ** (len(frac_part))

    for candidate_q in range(2, q + 1):
        candidate_p = math.ceil((p * candidate_q) / q)
        cand_str = str(candidate_p / candidate_q)

        if f"{int_part}.{frac_part}" == cand_str[:cand_str.index('.') + 3]:
            return candidate_p, candidate_q

    return p, q


t = int(input())
for _ in range(t):
    s = input().split('.')

    if len(s) == 1:
        print(s[0], 1)
    else:
        print(*find_fractional(s[0], s[1]))
