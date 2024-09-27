#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll INF = 100000000000;

int main() {
    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> dist(1 << n, vector<ll>(n, INF));
    dist[1][0] = 0;
    vector<vector<ll>> dp(1 << n, vector<ll>(n, -1));
    dp[1][0] = 0;

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (ll mask = 1; mask < (1 << n); mask += 2) {
        for (ll i = 0; i < n; i++) {
            if (dp[mask][i] == -1) continue;
            for (ll j = 0; j < n; j++) {
                if ((mask & (1 << j)) > 0 || a[i][j] == 0) continue;
                ll new_mask = mask | (1 << j)
                if (dist[mask][i] + a[i][j] < dist[new_mask][j]) {
                    dp[new_mask][j] = i;
                    dist[new_mask][j] = dist[mask][i] + a[i][j];
                }
            }
        }
    }

    ll res = INF;
    vector<ll> res_path;
    for (ll start = 0; start < n; start++) {
        ll mask = (1 << n) - 1;
        ll path_len = 0;
        ll cur = start;
        vector<ll> path;

        if (dp[mask][cur] == -1) continue;
        while (cur != 0) {
            ll parent = dp[mask][cur];
            path_len += a[parent][cur];
            path.push_back(cur);
            mask ^= (1 << cur);
            cur = parent;
        }
        path.push_back(0);

        if (res > path_len && path.size() == n) {
            res = move(path_len);
            res_path = path;
        }
    }

    if (res == INF) {
        cout << -1 << endl;
        return 0;
    }


    cout << res << endl;
    for (ll i = n - 1; i >= 0; i--) {
        cout << res_path[i] + 1 << " ";
    }
    cout << endl;
    return 0;
}