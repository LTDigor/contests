#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n; cin >> n;

    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll near = mid + 1;

        cout << "? " << mid << endl;
        ll midVal; cin >> midVal;

        cout << "? " << near << endl;
        ll nearVal; cin >> nearVal;

        if (mid % 2 == 0 && midVal == nearVal || mid % 2 != 0 && midVal != nearVal) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << "? " << l << endl;
    ll res; cin >> res;
    cout << "! " << res << endl;
    return 0;
}