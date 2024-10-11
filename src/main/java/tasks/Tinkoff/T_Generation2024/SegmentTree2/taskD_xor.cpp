#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const ll MAX_LEN = 24;

struct Node {
    vll bits = vll(MAX_LEN, 0);
    ll xorr = 0;
    ll sum = 0;
};

vector<Node> t;
vll arr;

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        t[p].sum = arr[l];
        fori (MAX_LEN) {
            t[p].bits[i] = (arr[l] >> i) & 1;
        }
        return;
    }

    ll mid = (r + l) >> 1;
    build(2*p, l, mid);
    build(2*p + 1, mid, r);

    t[p].sum = t[2*p].sum + t[2*p + 1].sum;
    fori (MAX_LEN) {
        t[p].bits[i] = t[2*p].bits[i] + t[2*p + 1].bits[i];
    }
}

void push(ll p, ll l, ll r) {
    if (t[p].xorr == 0) {
        return;
    }

    ll sz = r - l;
    fori(MAX_LEN) {
        if ((t[p].xorr >> i) & 1 > 0) {
            t[p].sum -= (1 << i) * t[p].bits[i];
            t[p].bits[i] = sz - t[p].bits[i];
            t[p].sum += (1 << i) * t[p].bits[i];
        }
    }

    if (sz > 1) {
        t[2*p].xorr ^= t[p].xorr;
        t[2*p + 1].xorr ^= t[p].xorr;
    }
    t[p].xorr = 0;
}

void upd(ll p, ll l, ll r, ll lq, ll rq, ll xorr) {
    push(p, l, r);
    if (l >= rq || r <= lq) {
        return;
    }

    if (lq <= l && r <= rq) {
        t[p].xorr ^= xorr;
        push(p, l, r);
        return;
    }

    ll mid = (r + l) >> 1;
    upd(2 * p, l, mid, lq, rq, xorr);
    upd(2 * p + 1, mid, r, lq, rq, xorr);

    t[p].sum = t[2*p].sum + t[2*p + 1].sum;
    fori (MAX_LEN) {
        t[p].bits[i] = t[2*p].bits[i] + t[2*p + 1].bits[i];
    }
}


ll get(ll p, ll l, ll r, ll lq, ll rq) {
    push(p, l, r);
    if (l >= rq || r <= lq) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        return t[p].sum;
    }

    ll mid = (r + l) >> 1;
    ll resl = get(2 * p, l, mid, lq, rq);
    ll resr = get(2 * p + 1, mid, r, lq, rq);

    return resl + resr;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    arr = vll(n, 0);
    fori (n) {
        cin >> arr[i];
    }

    t.resize(4 * n);
    build(1, 0, n);

    ll m;
    cin >> m;
    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll l, r;
            cin >> l >> r;
            cout << get(1, 0, n, l - 1, r) << '\n';
        } else {
            ll l, r, v;
            cin >> l >> r >> v;
            upd(1, 0, n, l - 1, r, v);
        }
    }

    return 0;
}
