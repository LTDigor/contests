#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll n;
vector<ll> t;
vector<ll> arr;

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        t[p] = arr[l];
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    build(pl, l, mid);
    build(pr, mid, r);

    t[p] = t[pl] + t[pr];
}

ll get_val(ll p, ll l, ll r, ll lq, ll rq) {
    if (lq <= l && r <= rq) {
        return t[p];
    }

    if (lq >= r || rq <= l) {
        return 0;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    ll resl = get_val(pl, l, mid, lq, rq);
    ll resr = get_val(pr, mid, r, lq, rq);

    return resl + resr;
}

ll get_val(ll i) {
    return get_val(0, 0, n, 0, i + 1);
}

void upd(ll p, ll l, ll r, ll i, ll x) {
    if (l + 1 == r) {
        t[p] += x;
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    if (i < mid) {
        upd(pl, l, mid, i, x);
    } else {
        upd(pr, mid, r, i, x);
    }
    t[p] = t[pl] + t[pr];
}

void upd(ll lq, ll rq, ll x) {
    upd(0, 0, n, lq, x);

    if (rq < n) {
        upd(0, 0, n, rq, -x);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n);

    ll prev = 0;
    fori(n) {
        cin >> arr[i];
        ll tmp = arr[i];
        if (i > 0) {
            arr[i] = arr[i] - prev;
        }
        prev = tmp;
    }

    t.resize(4 * n);
    build(0, 0, n);

    ll k; cin >> k;
    fori(k) {
        char op; cin >> op;
        if (op == 'a') {
            ll l, r, x;
            cin >> l >> r >> x;
            upd(l - 1, r, x);
        } else {
            ll ind; cin >> ind;
            cout << get_val(ind - 1) << '\n';
        }
    }
    return 0;
}
