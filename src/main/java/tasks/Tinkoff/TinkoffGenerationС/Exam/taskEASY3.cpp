#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

ll solve(ll x) {
    ll res = 0;
    for (ll n = 1; n * n <= x; n++) {
        ll a = x + 2 - n;
        ll b = n + 1;

        if (a % b == 0) {
            res += 1;
        }
    }

    return res;
}

signed main() {
    ll t; cin >> t;
    while (t--) {
        ll x; cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}