def construct(mult, substr):
    if len(str(mult)) + 2 + len(substr) > mult * len(substr):
        return mult * substr

    return f'{mult}({substr})'


s = input()

memo = {}  # memo[(start_ind, substr_len)] = (mult, substr)
for substr_len in range(1, len(s) + 1):
    for start_ind in range(len(s) - substr_len + 1):
        if substr_len == 1:
            memo[(start_ind, 1)] = 1, s[start_ind]
            continue

        mult, substr = 1, s[start_ind:start_ind + substr_len]
        for sep_index in range(start_ind, start_ind + substr_len - 1):
            left_len = sep_index - start_ind + 1
            right_len = substr_len - left_len

            left_mult, left_substr = memo[(start_ind, left_len)]
            right_mult, right_substr = memo[(sep_index + 1, right_len)]

            if left_substr == right_substr:
                mult, substr = left_mult + right_mult, left_substr
            else:
                curr_str_len = min(len(str(mult)) + 2 + len(substr), mult * len(substr))
                merged_len = len(construct(left_mult, left_substr)) + len(construct(right_mult, right_substr))
                if curr_str_len > merged_len:
                    mult, substr = 1, construct(left_mult, left_substr) + construct(right_mult, right_substr)

        memo[(start_ind, substr_len)] = (mult, substr)

res = construct(*memo[0, len(s)])
print(res)
