#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const ll MOD = 1000000007;
const ll SZ = 5000000;

struct Node {
    ll ans;
    ll l, r;
};

ll W, H;
ll sz = 1;

Node t[SZ];

ll pull(ll l, ll r) {
    return t[l].ans + t[r].ans;
}

ll get(ll p, ll l, ll r, ll lq, ll rq) {
    if (l >= rq || r <= lq) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        return t[p].ans;
    }

    ll mid = (r + l) >> 1;

    if (t[p].l == -1) {
        t[sz] = {0, -1, -1};
        t[p].l = sz++;
    }
    ll res = get(t[p].l, l, mid, lq, rq);

    if (t[p].r == -1) {
        t[sz] = {0, -1, -1};
        t[p].r = sz++;
    }
    res += get(t[p].r, mid, r, lq, rq);

    return res;
}

ll get(ll y) {
    return get(0, 0, 2*H, 0, y);
}

void upd(ll p, ll l, ll r, ll ind, ll x) {
    if (l > ind || r <= ind) {
        return;
    }

    if (l + 1 == r) {
        t[p].ans += x;
        return;
    }

    ll mid = (r + l) >> 1;

    if (t[p].l == -1) {
        t[sz] = {0, -1, -1};
        t[p].l = sz++;
    }
    upd(t[p].l, l, mid, ind, x);

    if (t[p].r == -1) {
        t[sz] = {0, -1, -1};
        t[p].r = sz++;
    }
    upd(t[p].r, mid, r, ind, x);

    t[p].ans = pull(t[p].l, t[p].r);
}

void upd(ll lq, ll rq, ll x) {
    upd(0, 0, 2*H, lq, x);

    if (rq < 2*H) {
        upd(0, 0, 2*H, rq, -x);
    }
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> W >> H >> n;

    t[0] = {0, -1, -1};

    tll points[n];
    fori(n) {
        ld x, y;
        cin >> x >> y;
        points[i] = {round(x*2), round(y*2), i};
    }
    sort(points, points + n, [](const tll &a, const tll &b) {
        return get<0>(a) < get<0>(b);
    });

    ll res[n];
    for (auto [x, y, ind] : points) {
        ll delta = x - get(y);
        res[ind] = delta;

        upd(y - delta, y + delta, 2 * delta);
    }

    for (ll item : res) {
        cout << item << endl;
    }

    return 0;
}