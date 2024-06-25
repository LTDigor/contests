#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

signed main() {
    ll n; cin >> n;
    unordered_map<ll, ll> xs, ys;
    map<pll, ll> xys;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;

        xs[x]++;
        ys[x]++;
        xys[{x, y}]++;
    }

    ll res = 0;
    for (auto [p, count] : xys) {
        auto [x, y] = p;
        res += xs[x] + ys[y] - xys[p];
    }
    cout << res << endl;
    return 0;
}