class StackMin:
    def __init__(self):
        self.mins = []
        self.stack = []
    def get_min(self):
        return self.mins[-1][1]

    def push(self, x):
        i = len(self.stack)
        self.stack.append(x)
        if i == 0 or self.mins[-1][1] > x:
            self.mins.append((i, x))

    def pop(self):
        i = len(self.stack) - 1
        self.stack.pop()
        if self.mins[-1][0] == i:
            self.mins.pop()


def solve():
    n = int(input())
    st = StackMin()
    for _ in range(n):
        s = input()
        if s[0] == '1':
            x = int(s[2:])
            st.push(x)
        elif s[0] == '2':
            st.pop()
        else:
            print(st.get_min())

solve()
