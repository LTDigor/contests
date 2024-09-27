#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll n;
vector<ll> t;
vector<ll> addition;
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

    t[p] = max(t[pl], t[pr]);
}

ll get_mx(ll p, ll l, ll r, ll lq, ll rq) {
    if (lq <= l && r <= rq) {
        return t[p] + addition[p];
    }

    if (lq >= r || rq <= l) {
        return -1;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    ll resl = get_mx(pl, l, mid, lq, rq);
    ll resr = get_mx(pr, mid, r, lq, rq);

    return max(resl, resr) + addition[p];
}

ll get_mx(ll lq, ll rq) {
    return get_mx(0, 0, n, lq, rq);
}

void upd(ll p, ll l, ll r, ll lq, ll rq, ll x) {
    if (lq <= l && r <= rq) {
        addition[p] += x;
        return;
    }

    if (lq >= r || rq <= l) {
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    upd(pl, l, mid, lq, rq, x);
    upd(pr, mid, r, lq, rq, x);

    t[p] = max(t[pl] + addition[pl], t[pr] + addition[pr]);
}

void upd(ll lq, ll rq, ll x) {
    upd(0, 0, n, lq, rq, x);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n, -1);
    fori(n) {
        cin >> arr[i];
    }

    t.resize(4 * n, 0);
    addition.resize(4 * n, 0);
    build(0, 0, n);

    ll k; cin >> k;
    fori(k) {
        char op;
        cin >> op;

        if (op == 'a') {
            ll l, r, x;
            cin >> l >> r >> x;
            upd(l - 1, r, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << get_mx(l - 1, r) << ' ';
        }
    }
    return 0;
}
