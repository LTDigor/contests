#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

signed main() {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long double cosMult = x1 * x2 + y1 * y2;
    long double sinMult = x1 * y2 - x2 * y1;

    long double res = abs(atan2(sinMult, cosMult));
    cout << fixed << setprecision(7);
    cout << res << endl;
    return 0;
}