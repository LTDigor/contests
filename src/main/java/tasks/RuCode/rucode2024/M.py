t = int(input())
d = {
    '?' * 2,
    '?' * 11,
    '?' * 8 + ' ' + '?' + ' ' + '?' * 8 + ' ' + '?' * 7,
    '?' * 7,
    '?' * 17,
    '?' * 8 +  ' ' + '?' * 7,
    '?' * 6,
    '?' * 3 + ' ' + '?' * 4,
    '?' * 5 + ' ' + '?' * 10,
}
for _ in range(t):
    s = input()
    print(1 if s in d else 0)
