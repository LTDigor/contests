import bisect


def get_time(v0, a, l):
    if a == 0.0:
        return l / v0
    return (-v0 + (v0 ** 2 + 2 * a * l) ** 0.5) / a


n = int(input())
left_t = []
right_t = []
acceleration = []
for _ in range(n):
    lt, rt, a = map(int, input().split())
    left_t.append(lt)
    right_t.append(rt)
    acceleration.append(a)

dist = []
velocity = []

cur_dist = 0
cur_v = 0
for i in range(n):
    dist.append(cur_dist)
    velocity.append(cur_v)

    dt = right_t[i] - left_t[i]
    cur_dist = cur_dist + cur_v * dt + acceleration[i] * dt ** 2 / 2
    cur_v = cur_v + acceleration[i] * dt

q = int(input())

for _ in range(q):
    d = int(input())
    ind = bisect.bisect_right(dist, d) - 1

    t = left_t[ind] + get_time(velocity[ind], acceleration[ind], d - dist[ind])
    print(int(t))
