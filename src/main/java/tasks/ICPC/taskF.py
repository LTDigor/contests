a = float(input("? 0\n"))
b = float(input("? 180\n"))
h = float(input("? 90\n"))

s1 = a + b
s2 = (a ** 2 + h ** 2) ** 0.5
s3 = (b ** 2 + h ** 2) ** 0.5

p = 0.5*(s1 + s2 + s3)
R = s1 * s2 * s3 / (4 * (p * (p - s1) * (p - s2) * (p - s3))**0.5)

print("!", round(R))

# 0.828
# 4.828
# 1.236
# -> 3
