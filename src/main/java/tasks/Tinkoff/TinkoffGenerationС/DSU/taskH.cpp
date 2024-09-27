#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> p;
vector<ll> rk;
vector<ll> nxt;

void init_dsu(ll n) {
    for (int i = 0; i < n; i++) {
        p[i] = i;
        rk[i] = 1;
        nxt[i] = i + 1;
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

    ll n, q;
    cin >> n >> q;

    p.resize(n);
    rk.resize(n);
    nxt.resize(n);

    init_dsu(n);

    for (ll i = 0; i < q; i++) {
        ll type, x, y;
        cin >> type >> x >> y;
        x--, y--;
        if (type == 1) {
            merge(x, y);
        } else if (type == 2) {
            ll idx = x;
            while (idx < y) {
                merge(idx , idx + 1);
                ll temp = nxt[idx];
                nxt[idx] = y;
                idx = temp;
            }
        } else {
            cout << (get_root(x) == get_root(y) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}