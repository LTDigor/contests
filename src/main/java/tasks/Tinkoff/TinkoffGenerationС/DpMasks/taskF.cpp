#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll INF = 100000000000;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n);

    vector<ll> dp(1 << n);

    vector<ll> f(1 << n);
    vector<vector<ll>> fs(1 << n, vector<ll>(n));

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        frm -= 1;
        to -= 1;

        graph[frm].push_back(to);
        ll mask = (1 << frm) | (1 << to);
        fs[mask][frm] = 1;
    }

    for (ll mask = 0; mask < (1 << n); mask++) {
        for (ll i = 0; i < n; i++) {
            if ((mask & (1 << i)) == 0) continue;
            for (ll to : graph[i]) {
                if ((mask & (1 << to)) == 0) continue;
                fs[mask][i] += fs[mask ^ (1 << i)][to];
            }
            f[mask] += fs[mask][i];
        }
    }

    dp[0] = 1;

    for (ll mask = 1; mask < (1 << n); mask++) {
        ll most_significant_bit_number = 1;
        while (most_significant_bit_number < mask)
            most_significant_bit_number <<= 1;
        most_significant_bit_number >>= 1;
        for (ll submask = mask; submask > most_significant_bit_number; submask = (submask - 1) & mask) {
            dp[mask] += f[submask] * dp[mask ^ submask];
        }
    }

    cout << dp[(1 << n) - 1] << endl;
    return 0;
}