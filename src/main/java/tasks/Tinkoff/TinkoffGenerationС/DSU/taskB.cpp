#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p;
vector<ll> s;
vector<tuple<int, int, int>> edges;


ll leader(ll v) {
    if (p[v] == v) {
        return v;
    }

    return (p[v] == v) ? v : p[v] = leader(p[v]);
}

void unite(ll a, ll b) {
    a = leader(a), b = leader(b);
    if (a == b)
        return;

    if (s[a] > s[b])
        swap(a, b);

    s[b] += s[a];
    p[a] = b;
}

void init(ll n) {
    for (ll i = 0; i < n; i++) {
        p[i] = i, s[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m, x;
    cin >> n >> m >> x;

    p.resize(n);
    s.resize(n);

    init(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to, w;
        cin >> frm >> to >> w;
        frm--, to--;

        edges.push_back({w, frm, to});
    }
    sort(edges.begin(), edges.end());

    ll res = 0;
    for (auto [w, a, b] : edges) {
        if (w > x) break;

        ll ra = leader(a);
        ll rb = leader(b);
        if (ra != rb && w == x) {
            res += s[ra] * s[rb];
        }

        unite(ra, rb);
    }

    cout << res << endl;
}
