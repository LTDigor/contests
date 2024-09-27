#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p, s;
vector<ll> mod;

pair<ll, ll> leader(ll v) {
    if (p[v] == v) {
        return {v, mod[v]};
    }

    auto [root, care] = leader(p[v]);
    care += mod[v];
    return {root, care};
}

void unite(ll a, ll b) {
    auto [ra, ca] = leader(a);
    auto [rb, cb] = leader(b);

    if (ra == rb) {
        return;
    }

    if (s[ra] > s[rb])
        swap(ra, rb);
    s[rb] += s[ra];
    p[ra] = rb;
    mod[ra] -= mod[rb];

    mod[rb] += 1;
}

void init(ll n) {
    for (ll i = 0; i < n; i++)
        p[i] = i, s[i] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, q;
    cin >> n >> q;

    p.resize(n);
    s.resize(n);
    mod.resize(n);

    init(n);

    for (ll i = 0; i < q; i++) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll x, y;
            cin >> x >> y;
            x--, y--;

            unite(x, y);
        } else if (op == 2) {
            ll x, y;
            cin >> x >> y;
            x--, y--;

            auto [rootX, careX] = leader(x);
            auto [rootY, careY] = leader(t);
            cout << (rootX == rootY ? "YES" : "NO") << endl;
        } else {
            ll x;
            cin >> x;
            x--;

            auto [root, care] = leader(x);
            cout << care << endl;
        }
    }
    return 0;
}