import heapq

# inputFile = open('001.in', 'right')
# outputFile = open('001lol.out', 'w')
#
#
# def input():
#     return inputFile.readline()
#
#
# def print(s):
#     outputFile.write(s)
#     outputFile.write('\n')
#
#
# def printL():
#     outputFile.write('\n')


printL = print

N = int(input())
p = list(map(int, input().split()))
T = int(input())

printL()
printL()
printL()

neg_heap_saved = [(-v, i) for i, v in enumerate(p) if v > 0]
heapq.heapify(neg_heap_saved)
for i in range(T):
    if i > 0:
        input()
    neg_heap = neg_heap_saved.copy()
    retest_result = '0'
    while neg_heap and retest_result == '0':
        _, ind = heapq.heappop(neg_heap)

        print(f'retest {ind + 1}')
        printL()
        input()
        retest_result = input().strip()

    print('done')
