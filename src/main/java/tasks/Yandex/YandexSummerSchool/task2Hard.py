import heapq

n, k = map(int, input().split())
prices = list(map(int, input().split()))

res = [0] * n
total = 0
heap = []
for day in range(n):
    heapq.heappush(heap, (prices[day], day))
    while heap[0][1] <= day - k:
        heapq.heappop(heap)

    res[heap[0][1]] += 1
    total += heap[0][0]

print(total)
print(*res)

