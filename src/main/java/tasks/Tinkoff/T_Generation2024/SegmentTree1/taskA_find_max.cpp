#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll n;
vector<ll> t;
vector<ll> arr;

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        t[p] = l;
        return;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    build(pl, l, mid);
    build(pr, mid, r);

    if (arr[t[pl]] > arr[t[pr]]) {
        t[p] = t[pl];
    } else {
        t[p] = t[pr];
    }
}

ll get_mx(ll p, ll l, ll r, ll lq, ll rq) {
    if (lq <= l && r <= rq) {
        return t[p];
    }

    if (lq >= r || rq <= l) {
        return -1;
    }

    ll pl = 2 * p + 1;
    ll pr = 2 * p + 2;

    ll mid = (l + r) / 2;

    ll resl = get_mx(pl, l, mid, lq, rq);
    ll resr = get_mx(pr, mid, r, lq, rq);

    if (resl == -1) {
        return resr;
    }

    if (resr == -1) {
        return resl;
    }

    if (arr[resl] > arr[resr]) {
        return resl;
    }

    return resr;
}

ll get_mx(ll lq, ll rq) {
    return get_mx(0, 0, n, lq, rq);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    arr.resize(n, -1);
    fori(n) {
        cin >> arr[i];
    }

    t.resize(4 * n, -1);
    build(0, 0, n);

    ll k; cin >> k;
    fori(k) {
        ll l, r;
        cin >> l >> r;
        l -= 1;

        cout << get_mx(l, r) + 1 << '\n';
    }
    return 0;
}
