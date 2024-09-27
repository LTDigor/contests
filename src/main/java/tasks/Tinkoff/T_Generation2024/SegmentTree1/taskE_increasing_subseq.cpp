#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll MOD = 1000000007;
struct Node {
    ll len, freq;
};

ll n;
vector<Node> t;
vll arr;
ll vals;

void compress(vll& a) {
    vll b = a;
    sort(b.begin(), b.end());

    unordered_map<ll, ll> m;

    for (ll x : b)
        if (!m.count(x))
            m[x] = m.size();

    for (ll &x : a)
        x = m[x];
}

Node pull(Node l, Node r) {
    if (l.len == 0 && r.len == 0) {
        return {0, 1};
    }

    if (l.len == r.len) {
        return {l.len, (l.freq + r.freq) % MOD};
    }

    if (l.len > r.len) {
        return l;
    }

    return r;
}

Node get(ll p, ll l, ll r, ll lq, ll rq) {
    if (l >= rq || r <= lq) {
        return {0, 1};
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

Node get(ll lq, ll rq) {
    return get(0, 0, vals, lq, rq);
}

void upd(ll p, ll l, ll r, ll ind, Node x) {
    if (l + 1 == r) {
        t[p] = x;
        return;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;

    ll mid = (l + r) >> 1;

    if (ind < mid) {
        upd(pl, l, mid, ind, x);
    } else {
        upd(pr, mid, r, ind, x);
    }

    t[p] = pull(t[pl], t[pr]);
}

void upd(ll ind, Node x) {
    upd(0, 0, vals, ind, x);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n);
    fori(n) {
        cin >> arr[i];
    }
    compress(arr);

    vals = *max_element(begin(arr), end(arr)) + 1;
    t.resize(4 * vals);

    ll res = 0;
    fori(n) {
        Node prev_max = get(0, arr[i]);
        Node cur = get(arr[i], arr[i] + 1);

        if (prev_max.len + 1 == cur.len) {
            cur = {cur.len, (cur.freq + prev_max.freq) % MOD};
        } else {
            cur = {prev_max.len + 1, prev_max.freq};
        }
        upd(arr[i], cur);
    }

    cout << get(0, vals + 1).freq << endl;
    return 0;
}