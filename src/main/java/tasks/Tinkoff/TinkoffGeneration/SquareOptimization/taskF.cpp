#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>

using namespace std;

vll t;
vll additional;
vpll seqs;

void relax(ll p, ll l, ll r) {
    if (r - l == 1) {
        return;
    }

    ll mid = (l + r) / 2;
    ll left = 2 * p + 1;
    ll right = 2 * p + 2;

    t[p] = t[left] + t[right];

    t[p] += additional[left] * (mid - l);
    t[p] += additional[right] * (r - mid);

    t[p] += (mid - l) * seqs[left].first + seqs[left].second * (mid - l) * (mid - l - 1) / 2;
    t[p] += (r - mid) * seqs[right].first + seqs[right].second * (r - mid) * (r - mid - 1) / 2;
}

void push(ll p, ll l, ll r) {
    if (r - l == 1) {
        t[p] += additional[p];
        additional[p] = 0;

        t[p] += seqs[p].first;
        seqs[p] = {0, 0};
        return;
    }

    ll mid = (l + r) / 2;
    ll left = 2 * p + 1;
    ll right = 2 * p + 2;
    additional[left] += additional[p];
    additional[right] += additional[p];
    additional[p] = 0;

    seqs[left].first += seqs[p].first;
    seqs[left].second += seqs[p].second;

    seqs[right].first += seqs[p].first + seqs[p].second * (mid - l);
    seqs[right].second += seqs[p].second;
    seqs[p] = {0, 0};

    relax(p, l, r);
}

void add(ll p, ll l, ll r, ll lq, ll rq, ll x) {
    push(p, l, r);
    if (lq >= r || rq <= l) {
        return;
    }

    if (lq <= l && r <= rq) {
        additional[p] += x;
        return;
    }

    ll mid = (l + r) / 2;
    ll left = 2 * p + 1;
    ll right = 2 * p + 2;

    add(left, l, mid, lq, rq, x);
    add(right, mid, r, lq, rq, x);
    relax(p, l, r);
}

void add_seq(ll p, ll l, ll r, ll lq, ll rq, ll x, ll step) {
    push(p, l, r);
    if (lq >= r || rq <= l) {
        return;
    }

    if (lq <= l && r <= rq) {
        seqs[p].first += x + step * (l - lq);
        seqs[p].second += step;
        return;
    }

    ll mid = (l + r) / 2;
    ll left = 2 * p + 1;
    ll right = 2 * p + 2;

    add_seq(left, l, mid, lq, rq, x, step);
    add_seq(right, mid, r, lq, rq, x, step);
    relax(p, l, r);
}

ll get(ll p, ll l, ll r, ll lq, ll rq) {
    push(p, l, r);
    if (lq >= r || rq <= l) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        return t[p];
    }

    ll mid = (l + r) / 2;
    ll left = 2 * p + 1;
    ll right = 2 * p + 2;

    ll res = get(left, l, mid, lq, rq) + get(right, mid, r, lq, rq);
    return res;
}

signed main() {
    ll n, k;
    cin >> n >> k;

    t.resize(4 * n);
    additional.resize(4 * n);
    seqs.resize(4 * n);

    for (ll i = 0; i < k; i++) {
        char s;
        cin >> s;
        if (s == '?') {
            ll l, r; cin >> l >> r;
            l -= 1;
            cout << get(0, 0, n, l, r) << endl;
        } else if (s == 'C') {
            ll l, r; cin >> l >> r;
            l -= 1;
            ll x; cin >> x;

            add(0, 0, n, l, r, -x);
        } else {
            ll i, x; cin >> i >> x;
            i -= 1;

            add_seq(0, 0, n, i - x + 1, i, 1, 1);
            add_seq(0, 0, n, i, i + x, x, -1);
        }
    }
    return 0;
}