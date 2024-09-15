n = int(input())
mn_x = {0: 0}
mx_x = {0: 0}

for _ in range(n):
    x, t = map(int, input().split())
    mn_x[t] = min(mn_x.get(t, 10 ** 9), x)
    mx_x[t] = max(mx_x.get(t, -10 ** 9), x)

dp_mn = {0: 0}
dp_mx = {0: 0}

times = sorted(mn_x.keys())


def min_to_point(frm, mid, to):
    return abs(mid - frm) + abs(to - mid)


for i in range(1, len(times)):
    prev_t = times[i - 1]
    t = times[i]

    frm_min_to_min = dp_mn[prev_t] + min_to_point(mn_x[prev_t], mx_x[t], mn_x[t])
    frm_max_to_min = dp_mx[prev_t] + min_to_point(mx_x[prev_t], mx_x[t], mn_x[t])
    dp_mn[t] = min(frm_min_to_min, frm_max_to_min)

    frm_min_to_max = dp_mn[prev_t] + min_to_point(mn_x[prev_t], mn_x[t], mx_x[t])
    frm_max_to_max = dp_mx[prev_t] + min_to_point(mx_x[prev_t], mn_x[t], mx_x[t])
    dp_mx[t] = min(frm_min_to_max, frm_max_to_max)


last_time = times[-1]
print(min(dp_mn[last_time] + abs(mn_x[last_time]), dp_mx[last_time] + abs(mx_x[last_time])))
