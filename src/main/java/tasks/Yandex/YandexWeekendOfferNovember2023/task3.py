from collections import defaultdict
from heapq import *

N = int(input())
heap = []
exp = defaultdict(int)
last_updated = defaultdict(int)

crew = set()
crew_exp = 0
prev_time = 0
for _ in range(N):
    name, time = input().split()
    time = int(time)

    crew_exp += len(crew) * (time - prev_time)
    if name in crew:
        crew.remove(name)
        exp[name] += time - last_updated[name]
        crew_exp -= exp[name]
    else:
        crew.add(name)
        heappush(heap, (exp[name], time, name))
        crew_exp += exp[name]

    last_updated[name] = time
    prev_time = time

    while heap[0][2] not in crew:
        heappop(heap)

    max_exp, _, experienced_name = heap[0]
    max_exp += time - last_updated[experienced_name]
    print(experienced_name, crew_exp - 2 * max_exp)

# 9
# Ivan 1
# Anton 1
# Victor 2
# Anton 3
# Ivan 5
# Denis 10
# Victor 11
# Anton 11
# Ivan 12
