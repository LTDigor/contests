#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

signed main() {
    ll n; cin >> n;

    cout << "? 1 1 " << n << " " << n << endl;
    ll total; cin >> total;

    ll l, r;

    l = 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll cur;
        cout << "? 1 1 " << mid << " " << n << endl;
        cin >> cur;

        if (cur > 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ll x_left = l;

    l = 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;

        ll cur;
        cout << "? 1 1 " << n << " " << mid << endl;
        cin >> cur;

        if (cur > 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    ll y_left = l;

    ll w;
    cout << "? " << x_left << " " << 1 << " " <<  x_left << " " << n << endl;
    cin >> w;

    ll h = total / w;


    cout << "! " << x_left << " " << y_left << " " << x_left + h - 1 << " " << y_left + w - 1 << endl;
    return 0;
}
