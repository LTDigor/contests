import random

N = 15
arr = list(range(1, N + 1))
random.shuffle(arr)

print(N)
print(*arr, sep='\n')
