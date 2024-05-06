def next_date(date, period):
    if period == 'WEEK':
        ans = date + timedelta(days=7 - date.weekday())
    elif period == 'MONTH':
        if date.month == 12:
            ans = date.replace(year=date.year + 1, month=1, day=1)
        else:
            ans = date.replace(month=date.month + 1, day=1)
    elif period == 'QUARTER':
        if date.month < 4:
            ans = date.replace(year=date.year, month=4, day=1)
        elif date.month < 7:
            ans = date.replace(year=date.year, month=7, day=1)
        elif date.month < 10:
            ans = date.replace(year=date.year, month=10, day=1)
        else:
            ans = date.replace(year=date.year + 1, month=1, day=1)
    elif period == 'YEAR':
        ans = date.replace(year=date.year + 1, month=1, day=1)
    else:
        if 4 <= date.month <= 9:
            ans = date.replace(year=date.year, month=10, day=1)
        elif date.month < 4:
            ans = date.replace(year=date.year, month=4, day=1)
        else:
            ans = date.replace(year=date.year + 1, month=4, day=1)

    return ans

from datetime import timedelta, datetime

period = input()
start, end = input().split()

start = datetime.strptime(start, '%Y-%m-%d')
end = datetime.strptime(end, '%Y-%m-%d')

res = []
curr = start
while curr <= end:
    nxt = next_date(curr, period)
    res.append((curr, nxt - timedelta(days=1)))
    curr = nxt

res[-1] = (res[-1][0], end)
print(len(res))
for left, right in res:
    print(left.strftime('%Y-%m-%d'), right.strftime('%Y-%m-%d'))

# QUARTER
# 2016-09-20 2022-11-30

# YEAR
# 2016-09-20 2022-11-30

# YEAR
# 2016-09-20 2016-09-30
