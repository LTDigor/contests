#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

signed main() {
    ll n;
    cin >> n;

    ll res = 0;
    ll startX, startY;
    cin >> startX >> startY;

    ll prevX = startX, prevY = startY;
    for (ll i = 1; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x - prevX > 0) {
            res += abs((y + prevY) * (x - prevX));
        } else {
            res -= abs((y + prevY) * (x - prevX));
        }
        prevX = x;
        prevY = y;
    }

    if (startX - prevX > 0) {
        res += abs((startY + prevY) * (startX - prevX));
    } else {
        res -= abs((startY + prevY) * (startX - prevX));
    }
    res = abs(res);

    if (res % 2 == 0) {
        cout << res / 2 << endl;
    } else {
        cout << res / 2 << ".5" << endl;
    }
    return 0;
}