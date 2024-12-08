from collections import deque


def solve():
    n = int(input())

    left = deque()
    right = deque()

    def normalize():
        total = len(left) + len(right)
        target_left = total // 2 + total % 2
        # print(total, target_left, left, right)
        while len(left) > target_left:
            item = left.pop()
            right.appendleft(item)

        while len(left) < target_left:
            item = right.popleft()
            left.append(item)

    for _ in range(n):
       s = input()
       if s[0] == '+':
           ind = int(s[2:])
           right.append(ind)
           normalize()
       elif s[0] == '*':
           ind = int(s[2:])
           left.append(ind)
           normalize()
       else:
           ind = left.popleft()
           normalize()
           print(ind)


solve()
