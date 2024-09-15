#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long min_to_point(int frm, int mid, int to) {
    return abs(mid - frm) + abs(to - mid);
};

signed main() {
    int n;
    cin >> n;
    map<int, int> mn_x = {{0, 0}};
    map<int, int> mx_x = {{0, 0}};

    for (int i = 0; i < n; ++i) {
        int x, t;
        cin >> x >> t;
        if (mn_x.count(t) > 0) {
            mn_x[t] = min(mn_x[t], x);
        } else {
            mn_x[t] = x;
        }

        if (mx_x.count(t) > 0) {
            mx_x[t] = max(mx_x[t], x);
        } else {
            mx_x[t] = x;
        }
    }

    map<int, long long> dp_mn = {{0, 0}};
    map<int, long long> dp_mx = {{0, 0}};

    vector<int> times;
    for (const auto& pair : mn_x) {
        times.push_back(pair.first);
    }
    sort(times.begin(), times.end());

    for (size_t i = 1; i < times.size(); ++i) {
        int prev_t = times[i - 1];
        int t = times[i];

        int frm_min_to_min = dp_mn[prev_t] + min_to_point(mn_x[prev_t], mx_x[t], mn_x[t]);
        int frm_max_to_min = dp_mx[prev_t] + min_to_point(mx_x[prev_t], mx_x[t], mn_x[t]);
        dp_mn[t] = min(frm_min_to_min, frm_max_to_min);

        int frm_min_to_max = dp_mn[prev_t] + min_to_point(mn_x[prev_t], mn_x[t], mx_x[t]);
        int frm_max_to_max = dp_mx[prev_t] + min_to_point(mx_x[prev_t], mn_x[t], mx_x[t]);
        dp_mx[t] = min(frm_min_to_max, frm_max_to_max);
        // cout << prev_t << " " << t << " " << dp_mn[t] << " " << dp_mx[t] << endl;
    }

    int last_time = times.back();
    cout << min(dp_mn[last_time] + abs(mn_x[last_time]), dp_mx[last_time] + mx_x[last_time]) << endl;

    return 0;
}

