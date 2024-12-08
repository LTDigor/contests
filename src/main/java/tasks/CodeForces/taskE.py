def solve():
    arr = list(map(int, input().split()))
    arr = arr[1:]

    res = 0
    st = []
    for i in range(len(arr)):
        if not st:
            st.append([arr[i], 1])
        elif arr[i] == st[-1][0]:
            st[-1][1] += 1
        else:
            if st[-1][1] >= 3:
                res += st.pop()[1]

            if st and st[-1][0] == arr[i]:
                st[-1][1] += 1
            else:
                st.append([arr[i], 1])

    if st[-1][1] >= 3:
        res += st.pop()[1]
    print(res)

solve()
