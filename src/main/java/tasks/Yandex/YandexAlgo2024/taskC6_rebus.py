def check(s1, s2, s3):
    s1 = s1[::-1]
    s2 = s2[::-1]
    s3 = s3[::-1]

    if len(s1) < len(s2):
        s1, s2 = s2, s1

    if len(s3) < (len(s1)) or len(s3) > len(s1) + 1:
        return False

    care = 0
    for i in range(len(s3)):
        cur_num = care

        if i < len(s1):
            cur_num += mapping[s1[i]]

        if i < len(s2):
            cur_num += mapping[s2[i]]

        care = cur_num // 10
        cur_num = cur_num % 10

        if cur_num != mapping[s3[i]]:
            return False

    return care == 0


def dfs(ind, mask):
    if ind == len(letters):
        return check(x, y, z)

    char = letters[ind]
    for num in range(10):
        if (mask >> num) & 1:
            continue
        if (x[0] == char or y[0] == char or z[0] == char) and num == 0:
            continue
        mask = mask ^ (1 << num)
        mapping[char] = num

        res = dfs(ind + 1, mask)
        if res:
            return res

        del mapping[char]
        mask = mask ^ (1 << num)
    return False


x, y, z = input(), input(), input()
letters = list(set(x) | set(y) | set(z))
mapping = {}

dfs(0, 0)

if len(letters) > 10:
    result = False
else:
    result = dfs(0, 0)


def build_res(s):
    res = 0
    for c in s:
        res *= 10
        res += mapping[c]
    return res


if result:
    print(build_res(x))
    print(build_res(y))
    print(build_res(z))
else:
    print("UNSOLVABLE")
