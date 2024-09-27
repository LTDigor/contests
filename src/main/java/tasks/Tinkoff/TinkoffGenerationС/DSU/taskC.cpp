#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p;
vector<ll> rk;

void init_dsu(ll n) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        rk[i] = 1;
    }
}

int get_root(int v) {
    if (p[v] == v)
        return v;

    return p[v] = get_root(p[v]);
}

void merge(ll a, ll b) {
    int ra = get_root(a), rb = get_root(b);

    if (ra != rb) {
        if (rk[ra] < rk[rb]) {
            p[ra] = rb;
        } else if (rk[rb] < rk[ra]) {
            p[rb] = ra;
        } else {
            p[ra] = rb;
            rk[rb]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    p.resize(n);
    rk.resize(n);

    init_dsu(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
    }

    vector<tuple<string, ll, ll>> questions;
    for (ll i = 0; i < k; i++) {
        string type;
        ll u, v;
        cin >> type >> u >> v;
        u--, v--;

        questions.push_back({type, u, v});
    }
    reverse(questions.begin(), questions.end());

    vector<string> res;
    for (auto [type, u, v] : questions) {
        if (type == "ask") {
            res.push_back((get_root(u) == get_root(v) ? "YES" : "NO"));
        } else {
            merge(u, v);
        }
    }
    reverse(res.begin(), res.end());

    for (string ans : res) {
        cout << ans << endl;
    }
    return 0;
}