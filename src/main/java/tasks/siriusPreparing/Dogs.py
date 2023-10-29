import math

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

res = 1
minNegatives = math.inf

for start in range(n):
    negatives = 0
    collarInd = 0
    for i in range(n):
        dogInd = (start + i) % n
        dogR = b[dogInd]

        collarR = a[collarInd]
        collarInd += 1
        if collarR > dogR:
            continue
        elif dogR - collarR <= 100:
            negatives += (dogR - collarR) // 2
        else:
            negatives += 30

    if negatives < minNegatives:
        res = start + 1
        minNegatives = negatives

print(res, minNegatives)
