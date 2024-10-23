def solve(n, k, a, b, c):
    abc = len(a.intersection(b).intersection(c))
    if abc >= k:
        return k

    res = k
    ab = len(a.intersection(b)) - abc
    bc = len(b.intersection(c)) - abc
    if ab < bc:
        ab, bc = bc, ab

    used_in_ab = min(ab, k - abc)
    used_in_a = k - used_in_ab - abc
    res += used_in_a

    used_in_bc = max(0, min(k - abc - used_in_ab, bc))
    used_in_b = k - abc - used_in_bc

    res += used_in_b
    return res

print(
    solve(
        int(input()),
        int(input()),
        set(map(int, input().split())),
        set(map(int, input().split())),
        set(map(int, input().split())),
    )
)