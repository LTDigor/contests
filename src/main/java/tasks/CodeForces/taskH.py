symbol_to_fun = {
    '+': lambda x, y: x + y,
    '*': lambda x, y: x * y,
    '-': lambda x, y: x - y,
}

def solve():
    s = input().split()
    st = []
    for c in s:
        if c in '+-*':
            b = st.pop()
            a = st.pop()
            res = symbol_to_fun[c](a, b)
            st.append(res)
        else:
            st.append(int(c))
    print(st[0])

solve()
