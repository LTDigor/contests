def find_natural(b):
    res = [1]
    for i in range(len(b) - 1):
        if b[i] != 10:
            return res

    res = res + [3, 9]
    return res


n = int(input())
b = list(map(int, input().split()))
print(*find_natural(b), sep='\n')
