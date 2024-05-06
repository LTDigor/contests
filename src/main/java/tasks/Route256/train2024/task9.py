from collections import deque


def solve(n, s):
    stack = []
    for c in s:
        if c == 'Z':
            if not stack:
                print('No')
                return
            else:
                stack.pop()
                


t = input()
for _ in range(t):
    n = int(input())
    s = input()
    solve(n, s)
