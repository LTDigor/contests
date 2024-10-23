INF = 10 ** 18

def lcm(a, b):
    mul = a * b
    if a < b:
        a, b = b, a
    while b > 0:
        a, b = b, a % b
    return mul // a

def solve(a, b, c, n):
    LCM = lcm(a, lcm(b, c))
    if LCM == b:
        return -1

    ab = lcm(a, b)
    bc = lcm(b, c)
    ca = lcm(c, a)

    saved_ab, saved_bc, saved_ca = ab, bc, ca

    numbers = []
    while min(ab, bc, ca) < LCM:
        if ab < bc and ab < ca:
            numbers.append(ab)
            ab += saved_ab
        elif bc < ab and bc < ca:
            numbers.append(bc)
            bc += saved_bc
        else:
            numbers.append(ca)
            ca += saved_ca
    m = len(numbers)
    print(m, numbers)
    res = LCM * ((n - 1) // m) + numbers[(n - 1) % m]
    if res > INF:
        return -1
    return res

a, b, c = map(int, input().split())
n = int(input())

a, b, c = sorted([a, b, c])
print(solve(a, b, c, n))
