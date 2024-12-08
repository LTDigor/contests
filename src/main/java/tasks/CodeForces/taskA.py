closed_to_open = {
    ')': '(',
    '}': '{',
    ']': '[',
}

def check_parenthesis(s):
    stack = []

    for c in s:
        if c in '([{':
            stack.append(c)
        else:
            if stack and stack[-1] == closed_to_open[c]:
                stack.pop()
            else:
                return False
    return len(stack) == 0


def solve():
    s = input()
    res = check_parenthesis(s)
    print('YES' if res else 'NO')


solve()
