#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

ll n;
vector<vll> t;
vll arr;

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        t[p] = {arr[l]};
        return;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    build(pl, l, mid);
    build(pr, mid, r);

    t[p] = {};
    ll lp = 0, rp = 0;
    while (lp < t[pl].size() || rp < t[pr].size()) {
        if (lp == t[pl].size() || (rp < t[pr].size() && t[pl][lp] > t[pr][rp])) {
            t[p].push_back(t[pr][rp++]);
        } else {
            t[p].push_back(t[pl][lp++]);
        }
    }
}

ll get(ll p, ll l, ll r, ll lq, ll rq, ll mn, ll mx) {
    if (l >= rq || r <= lq) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        ll left_ind = lower_bound(t[p].begin(), t[p].end(), mn) - t[p].begin();
        ll right_ind = upper_bound(t[p].begin(), t[p].end(), mx) - t[p].begin();
        return right_ind - left_ind;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    ll resl = get(pl, l, mid, lq, rq, mn, mx);
    ll resr = get(pr, mid, r, lq, rq, mn, mx);

    return resl + resr;
}

ll get(ll lq, ll rq, ll mn, ll mx) {
    return get(0, 0, n, lq, rq, mn, mx);
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    ll m;
    cin >> m;

    arr.resize(n);
    fori(n) {
        cin >> arr[i];
    }

    t.resize(4 * n);
    build(0, 0, n);

    while (m--) {
        ll x, y, k, l;
        cin >> x >> y >> k >> l;
        cout << get(x - 1, y, k, l) << '\n';
    }

    return 0;
}