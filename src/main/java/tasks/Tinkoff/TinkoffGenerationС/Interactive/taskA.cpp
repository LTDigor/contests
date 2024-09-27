#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n; cin >> n;

    ll l = 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        cout << mid << endl;
        ll res; cin >> res;
        if (res == 0) {
            break;
        } else if (res == -1) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}