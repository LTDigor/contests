n = int(input())
nums = map(int, input().split())

summ = 0
for num in nums:
    summ += num % 2

print('YES' if summ % 2 == 0 else 'NO')
