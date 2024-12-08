from collections import deque


def find_winner(n, a1, a2):
    counter = 0
    MX = 2 * 10**5
    while len(a1) > 0 and len(a2) > 0 and counter < MX:
        counter += 1
        l1, l2 = a1.pop(), a2.pop()
        if l2 == 0 and l1 == n - 1:
            a2.appendleft(l1)
            a2.appendleft(l2)
        elif l1 == 0 and l2 == n - 1 or l1 > l2:
            a1.appendleft(l1)
            a1.appendleft(l2)
        else:
            a2.appendleft(l1)
            a2.appendleft(l2)
    if counter == MX:
        return -1, "draw"

    if len(a1) == 0:
        return counter, 'second'
    return counter, 'first'


def solve():
    n = int(input())
    a1 = deque(map(int, input().split()))
    a2 = deque(map(int, input().split()))

    a1.reverse()
    a2.reverse()

    c, res = find_winner(n, a1, a2)
    if c == -1:
        print(res)
    else:
        print(res, c)

solve()
