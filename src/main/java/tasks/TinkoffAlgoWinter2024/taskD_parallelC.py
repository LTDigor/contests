def findKthPositive(arr, k):
    left = 0
    right = len(arr)
    while left < right:
        middle = (left + right) // 2
        if arr[middle] - middle - 1 < k:
            left = middle + 1
        else:
            right = middle
    return left + k


n, q = map(int, input().split())
arr = list(map(int, input().split()))
kexes = list(map(int, input().split()))

res = []
for k in kexes:
    res.append(findKthPositive(arr, k - 1))

print(*res)
