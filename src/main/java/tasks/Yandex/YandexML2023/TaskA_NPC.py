def checkNPCs(arr, n):
    visited = [-1] * n
    for i in range(n):
        if visited[i] != -1:
            continue
        cur = i
        while arr[cur] != -1:
            if visited[cur] == i:
                return False
            if visited[cur] == -1:
                visited[cur] = i
            cur = arr[cur] - 1

    return True


n = int(input())
arr = list(map(int, input().split()))
print('Yes' if checkNPCs(arr, n) else 'No')
