#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> binup;
ll MAX_POW = 18;

ll LA(ll city, ll dist) {
    for (ll pow = MAX_POW; pow >= 0; pow--) {
        if (dist >= (1 << pow)) {
            city = binup[city][pow];
            dist -= (1 << pow);
        }
    }

    return city;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    binup.resize(n, vector<ll>(MAX_POW, 0));

    for (ll i = 1; i < n; i++) {
        cin >> binup[i][0];
    }

    for (ll pow = 1; pow <= MAX_POW; pow++) {
        for (ll v = 1; v < n; v++) {
            binup[v][pow] = binup[binup[v][pow - 1]][pow - 1];
        }
    }

    ll a1, a2;
    cin >> a1 >> a2;

    ll x, y, z;
    cin >> x >> y >> z;

    ll u = 0;
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        u = LA((a1 + u) % n, a2);
        res += u;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }

    cout << res << endl;
    return 0;
}
