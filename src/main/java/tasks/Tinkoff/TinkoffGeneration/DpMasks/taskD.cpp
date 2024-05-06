#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll INF = 100000000000;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<ll> dp(1 << n);
    vector<ll> f(1 << n);

    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (ll j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) == 0) continue;
                f[mask] += a[i][j];
            }
        }
    }

    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll submask = mask; submask > 0; submask = (submask - 1) & mask) {
            dp[mask] = max(dp[mask], f[submask] + dp[mask ^ submask]);
        }
    }

    ll res = *max_element(dp.begin(), dp.end());
    cout << res << endl;
    return 0;
}