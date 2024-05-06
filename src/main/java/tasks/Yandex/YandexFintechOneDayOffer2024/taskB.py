from collections import deque, defaultdict
from sys import stdout

userLimit, serviceLimit, duration = map(int, input().split())

q = deque()
users = defaultdict(lambda : deque())

while (s := input()) != '-1':
    t, user_id = map(int, s.split())

    prev_t = t - duration
    while users[user_id] and users[user_id][0] < prev_t:
        users[user_id].popleft()

    while q and q[0] < prev_t:
        q.popleft()

    if len(users[user_id]) >= userLimit:
        print(429)
        stdout.flush()
    elif len(q) >= serviceLimit:
        print(503)
        stdout.flush()
    else:
        users[user_id].append(t)
        q.append(t)
        print(200)
        stdout.flush()
