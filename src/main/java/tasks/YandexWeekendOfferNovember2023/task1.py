N = int(input())
arr = list(map(int, input().split()))


def pairs_sum(arr, N):
    if N % 2 == 1:
        return -1

    target = arr[0] + arr[-1]
    for i in range(1, N // 2):
        if arr[i] + arr[N - i - 1] != target:
            return -1

    return target


print(pairs_sum(arr, N))
