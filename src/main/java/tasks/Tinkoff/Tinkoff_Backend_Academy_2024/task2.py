def day_to_number(day):
    days_dict = {
        "MON": 1,
        "TUE": 2,
        "WED": 3,
        "THU": 4,
        "FRI": 5,
        "SAT": 6,
        "SUN": 7
    }
    return days_dict.get(day.upper(), "Invalid day")


busy = [0]

for week in range(4):
    s = input().strip()
    if len(s) == 0:
        continue
    days = map(day_to_number, s.split())
    for day in days:
        busy.append(week * 7 + day)

busy.append(29)
busy.sort()

res = (0, 0)
for i in range(1, len(busy)):
    if busy[i] - busy[i - 1] - 1 > res[1] - res[0] + 1:
        res = (busy[i - 1] + 1, busy[i] - 1)
print(res[0], res[1])
