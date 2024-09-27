#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

signed main() {
    ll n; cin >> n;

    ll l = 2, r = n - 1;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll ans;
        cout << "? " << mid << endl;
        cin >> ans;

        if (ans == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << "! " << l - 1 << endl;
    return 0;
}