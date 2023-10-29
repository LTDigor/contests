import math


def find_cookies(max_hours, cookies):
    if max_hours < len(cookies):
        return 0
    left, right = 1, max(cookies)
    while left <= right:
        cookies_per_hour = (left + right) // 2

        if sum(math.ceil(cookie / cookies_per_hour) for cookie in cookies) <= max_hours:
            right = cookies_per_hour - 1
        else:
            left = cookies_per_hour + 1
    return left


def main():
    N, M = map(int, input().split())
    cookies_arr = []
    for _ in range(N):
        cookies_arr.append(int(input()))
    print(find_cookies(M, cookies_arr))


if __name__ == '__main__':
    main()
