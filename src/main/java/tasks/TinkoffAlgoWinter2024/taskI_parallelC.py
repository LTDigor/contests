import heapq

events = int(input())

heap = []
stack = []
eaten = set()

for i in range(events):
    s = input()
    if s == '2':
        _, uid = stack.pop()
        eaten.add(uid)
    elif s == '3':
        while heap[0][1] in eaten:
            heapq.heappop(heap)
        min_radius = heap[0][0]
        print(min_radius)
    else:
        radius = int(s.split(' ')[1])
        stack.append((radius, i))
        heapq.heappush(heap, (radius, i))
