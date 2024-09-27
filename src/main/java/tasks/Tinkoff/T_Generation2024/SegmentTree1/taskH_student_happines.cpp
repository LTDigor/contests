#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll MOD = 1000000007;
struct Node {
    ll sum;
    ll first_added;
    ll step;
    ll addition;
};

ll n;
vector<Node> t;
vll arr;

ll get_sum(Node node, ll sz) {
    ll res = node.sum;
    res += node.addition * sz;
    res += (2 * node.first_added + node.step * (sz - 1)) * sz / 2;
    return res;
}

ll get(ll p, ll l, ll r, ll lq, ll rq) {
    if (l >= rq || r <= lq) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        return get_sum(t[p], r - l);
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    ll resl = get(pl, l, mid, lq, rq);
    ll resr = get(pr, mid, r, lq, rq);

    ll sz = min(rq, r) - max(lq, l);
    ll first_added = t[p].first_added;
    if (l < lq) {
        first_added += t[p].step * (lq - l);
    }
    Node node = {resl + resr, first_added, t[p].step, t[p].addition};
    return get_sum(node, sz);
}

ll get(ll lq, ll rq) {
    return get(0, 0, n, lq, rq);
}

void upd(ll p, ll l, ll r, ll lq, ll rq, Node x) {
    if (l >= rq || r <= lq) {
        return;
    }

    if (lq <= l && r <= rq) {
        t[p].addition += x.addition;
        t[p].first_added += x.first_added + x.step * (l - lq);
        t[p].step += x.step;
        return;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;

    ll mid = (l + r) >> 1;

    upd(pl, l, mid, lq, rq, x);
    upd(pr, mid, r, lq, rq, x);

    t[p].sum = get_sum(t[pl], mid - l) + get_sum(t[pr], r - mid);
}

void upd(ll lq, ll rq, Node x) {
    upd(0, 0, n, lq, rq, x);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    t.resize(4 * n);

    ll m;
    cin >> m;
    fori(m) {
        char op;
        cin >> op;
        if (op == '?') {
            ll l, r;
            cin >> l >> r;
            cout << get(l - 1, r) << '\n';
        } else if (op == 'R') {
            ll ind, q;
            cin >> ind >> q;
            if (q == 0) continue;

            ind -= 1;
            if (ind > 0 && q > 1) {
                ll left_ind = max(0LL, ind - q + 1);
                upd(left_ind, ind, {0, q - (ind - left_ind), 1, 0});
            }

            ll right_ind = min(n, ind + q);
            upd(ind, right_ind, {0, q, -1, 0});

        } else {
            ll l, r, x;
            cin >> l >> r >> x;
            if (x == 0) continue;
            upd(l - 1, r, {0, 0, 0, -x});
        }
    }

    return 0;
}