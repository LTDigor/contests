#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll n;
vector<vvll> t;

void add(ll x, ll y, ll z, ll added) {
    for (ll i = x; i <= n; i += i & -i)
        for (ll j = y; j <= n; j += j & -j)
            for (ll k = z; k <= n; k += k & -k)
                t[i][j][k] += added;
}

ll sum(ll x, ll y, ll z) {
    ll res = 0;
    for (ll i = x; i > 0; i -= i & -i)
        for (ll j = y; j > 0; j -= j & -j)
            for (ll k = z; k > 0; k -= k & -k)
                res += t[i][j][k];
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    t = vector<vvll>(n + 1, vvll(n + 1, vll(n + 1, 0)));

    ll m = 0;
    while (m != 3) {
        cin >> m;
        if (m == 1) {
            ll x, y, z, added;
            cin >> x >> y >> z >> added;
            add(x + 1, y + 1, z + 1, added);
        } else if (m == 2) {
            ll x1, y1, z1;
            ll x2, y2, z2;

            cin >> x1 >> y1 >> z1;
            cin >> x2 >> y2 >> z2;

            ll res = sum(x2 + 1, y2 + 1, z2 + 1);
            res -= sum(x1, y2 + 1, z2 + 1);
            res -= sum(x2 + 1, y1, z2 + 1);
            res -= sum(x2 + 1, y2 + 1, z1);

            res += sum(x1, y1, z2 + 1);
            res += sum(x2 + 1, y1, z1);
            res += sum(x1, y2 + 1, z1);

            res -= sum(x1, y1, z1);
            cout << res << '\n';
        }
    }

    return 0;
}
D