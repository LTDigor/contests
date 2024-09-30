#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll MOD = 1000000007;
struct Node {
    ll ans;
    ll opened, closed;
};

ll n;
vector<Node> t;
string str;

Node pull(Node l, Node r) {
    Node res = {0, 0, 0};

    res.ans = l.ans + r.ans + min(l.opened - l.ans, r.closed - r.ans);
    res.opened = l.opened + r.opened;
    res.closed = l.closed + r.closed;

    return res;
}

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        ll opened = str[l] == '(';
        t[p] = {0, opened, 1 - opened};
        return;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    build(pl, l, mid);
    build(pr, mid, r);

    t[p] = pull(t[pl], t[pr]);
}

Node get(ll p, ll l, ll r, ll lq, ll rq) {
    if (l >= rq || r <= lq) {
        return {0, 0, 0};
    }

    if (lq <= l && r <= rq) {
        return t[p];
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    Node resl = get(pl, l, mid, lq, rq);
    Node resr = get(pr, mid, r, lq, rq);

    return pull(resl, resr);
}

ll get(ll lq, ll rq) {
    return get(0, 0, n, lq, rq).ans * 2;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> str;
    n = str.length();

    t.resize(4 * n);
    build(0, 0, n);

    ll m;
    cin >> m;
    while (m--) {
        ll l, r;
        cin >> l >> r;
        cout << get(l - 1, r) << '\n';
    }

    return 0;
}