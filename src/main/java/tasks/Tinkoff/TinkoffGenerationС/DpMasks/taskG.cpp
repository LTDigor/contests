#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll INF = 100000000000;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n), c(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        if (k >= a[i] && k <= b[i])
            dp[1 << i][i] = i;
    }

    vector<vector<ll>> dp(1 << n, vector<vector<ll>>(n, -1));
    for (ll mask = 1; mask < (1 << n); mask++) {
        ll mood = k;
        for (ll i = 0; i < n; i++) {
            mood += ((mood & (1 << i)) > 0) * c[i];
        }
        for (ll cur = 0; cur < n; cur++) {
            if (mask & (1 << cur) == 0) continue;
            for (ll nxt = 0; nxt < n; nxt++) {
                if (mask & (1 << nxt) > 0 || mood < a[nxt] || mood > b[nxt]) continue;
                ll nxt_mask = mask | (1 << nxt);
                dp[nxt_mask][nxt] = cur;
            }
        }
    }

    ll res_meetings = 0;
    ll res_end = -1;
    ll res_mask = 0;
    for (ll mask = 1; mask < (1 << n); mask++) {
        ll meetings = 0;
        for (ll i = 0; i < n; i++) {
            meetings += (meetings & (1 << i)) > 0;
        }
        if (meetings <= res_meetings) continue;

        ll end = -1;
        for (ll i = 0; i < n; i++) {
            if (dp[mask][i] != -1) {
                end = i;
                break;
            }
        }

        if (end != -1) {
            res_end = end;
            res_meetings = meetings;
            res_mask = mask;
        }
    }


    vector<ll> res_path;
    ll cur = end;
    ll mask = res_mask;
    while (mask > 0) {
        res_path.push_back(cur);

        ll parent = dp[mask][cur];
        mask ^= 1 << cur;
        cur = parent;
    }

    cout << res_path.size() << endl;
    for (ll i = n - 1; i >= 0; i--) {
            cout << res_path[i] + 1 << " ";
        }
        cout << endl;

    return 0;
}