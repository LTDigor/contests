import heapq


def main():
    _, m, p = map(int, input().split())
    heap = list(map(int, input().split()))
    heap = [-x for x in heap]
    heapq.heapify(heap)

    res = 0
    for _ in range(m):
        if not heap:
            break
        mx = -heapq.heappop(heap)
        if mx <= p:
            res += mx
        else:
            res += p
            heapq.heappush(heap, -(mx - p))
    print(res)


if __name__ == '__main__':
    main()
