#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

struct Node {
    ll sz;
    ll ans, pf, sf;
};

ll n;
vector<Node> t;
vector<ll> arr;

Node pull(Node l, Node r) {
    Node res = {l.sz + r.sz, max(l.ans, r.ans), l.pf, r.sf};
    res.ans = max(res.ans, l.sf + r.pf);

    if (l.pf == l.sz) {
        res.pf += r.pf;
    }

    if (r.sf == r.sz) {
        res.sf += l.sf;
    }

    return res;
}

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        ll val = arr[l] == 0;
        t[p] = {1, val, val, val};
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    build(pl, l, mid);
    build(pr, mid, r);

    t[p] = pull(t[pl], t[pr]);
}

Node get(ll p, ll l, ll r, ll lq, ll rq) {
    if (lq <= l && r <= rq) {
        return t[p];
    }

    if (lq >= r || rq <= l) {
        return {0, 0, 0, 0};
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    Node resl = get(pl, l, mid, lq, rq);
    Node resr = get(pr, mid, r, lq, rq);

    return pull(resl, resr);
}

ll get(ll lq, ll rq) {
    Node res = get(0, 0, n, lq, rq);
    return res.ans;
}

void upd(ll p, ll l, ll r, ll lq, ll rq, ll x) {
    if (lq >= r || rq <= l) {
        return;
    }

    if (l + 1 == r) {
        arr[l] = x;

        ll val = arr[l] == 0;
        t[p] = {1, val, val, val};
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    upd(pl, l, mid, lq, rq, x);
    upd(pr, mid, r, lq, rq, x);

    t[p] = pull(t[pl], t[pr]);
}

void upd(ll ind, ll x) {
    upd(0, 0, n, ind, ind + 1, x);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n);
    fori(n) {
        cin >> arr[i];
    }

    t.resize(4 * n);
    build(0, 0, n);

    ll k; cin >> k;
    fori(k) {
        string op;
        cin >> op;

        if (op == "UPDATE") {
            ll ind, x;
            cin >> ind >> x;
            upd(ind - 1, x);
        } else {
            ll l, r;
            cin >> l >> r;
            cout << get(l - 1, r) << '\n';
        }
    }
    return 0;
}