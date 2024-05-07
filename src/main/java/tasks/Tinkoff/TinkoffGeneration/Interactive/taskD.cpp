#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>

using namespace std;

signed main() {
    ll n; cin >> n;
    ll k; cin >> k;

    ll l = 1, r = n;
    while (l < r) {
        ll mid = (l + r) / 2;
        ll near = mid + 1;

        cout << "? " << mid << endl;
        ll midVal; cin >> midVal;

        cout << "? " << near << endl;
        ll nearVal; cin >> nearVal;

        if (nearVal > midVal) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    ll shift = l;
    bool res = false;
    l = 1, r = shift;
    while (l <= r) {
        ll mid = (l + r) / 2;
        cout << "? " << mid << endl;
        ll midVal; cin >> midVal;

        if (midVal == k) {
            res = true;
            l = mid;
            break;
        } else if (midVal > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (res) {
        cout << "! " << l << endl;
        return 0;
    }

    l = shift + 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        cout << "? " << mid << endl;
        ll midVal; cin >> midVal;

        if (midVal <= k) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << l << endl;
    return 0;
}