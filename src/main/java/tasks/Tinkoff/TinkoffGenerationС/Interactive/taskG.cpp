#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

signed main() {
    ll n; cin >> n;
    string s; cin >> s;

    ll num = 0;
    for (ll i = 0; i < n; i++) {
        ll bit = s[n - i - 1] - '0';
        num += bit << i;
    }

    unordered_set<ll> used;
    used.insert(num);

    cout << "Alice" << endl;
    for (ll i = 0; i < (1 << n) - 1; i++) {
        for (ll bit = 0; bit < n; bit++) {
            ll nxt = num ^ (1 << bit);
            if (used.count(nxt) == 0) {
                cout << bit + 1 << endl;
                used.insert(nxt);
                num = nxt;
                break;
            }
        }

        ll ans; cin >> ans;
        if (ans < 1) {
            return 0;
        }
        ans -= 1;
        num = num ^ (1 << ans);
        used.insert(num);
    }

    return 0;
}
