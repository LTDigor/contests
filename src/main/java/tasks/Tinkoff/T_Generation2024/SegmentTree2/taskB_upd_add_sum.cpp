#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

struct Node {
    ll sum = 0;
    ll updated = -1;
    ll added = 0;
};

vector<Node> t;

void push(ll p, ll l, ll r) {
    ll sz = r - l;

    if (sz > 1) {
        if (t[p].updated != -1) {
            t[2 * p].updated = t[p].updated;
            t[2 * p].added = t[p].added;

            t[2 * p + 1].updated = t[p].updated;
            t[2 * p + 1].added = t[p].added;
        } else {
            t[2 * p].added += t[p].added;
            t[2 * p + 1].added += t[p].added;
        }
    }

    if (t[p].updated != -1) {
        t[p].sum = t[p].updated * sz;
    }
    t[p].sum += t[p].added * sz;

    t[p].updated = -1;
    t[p].added = 0;
}

void upd(ll p, ll l, ll r, ll lq, ll rq, ll updated, ll added) {
    push(p, l, r);
    if (l >= rq || r <= lq) {
        return;
    }

    if (lq <= l && r <= rq) {
        if (updated != -1) {
            t[p].updated = updated;
            t[p].added = 0;
        } else {
            t[p].added += added;
        }
        push(p, l, r);
        return;
    }

    ll mid = (r + l) >> 1;
    upd(2 * p, l, mid, lq, rq, updated, added);
    upd(2 * p + 1, mid, r, lq, rq, updated, added);

    t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;
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

    ll N = pow(2, ceil(log2(n)));
    t.resize(2 * N);

    ll m;
    cin >> m;
    while (m--) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll l, r, v;
            cin >> l >> r >> v;
            upd(1, 0, N, l, r, v, 0);
        } else if (op == 2) {
            ll l, r, v;
            cin >> l >> r >> v;
            upd(1, 0, N, l, r, -1, v);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << get(1, 0, N, l, r) << '\n';
        }
    }

    return 0;
}
