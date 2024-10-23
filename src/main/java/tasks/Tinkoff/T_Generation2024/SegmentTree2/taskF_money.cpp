#pragma GCC optimize ("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

struct Node {
	vll items;
	vll pref;
};

vector<Node> t;
vll arr;
ll n;

void build(ll p, ll l, ll r) {
    if (l + 1 == r) {
        vll items = {arr[l]};
        vll pref = {0,arr[l]};
        t[p] = {items, pref};
        return;
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    build(pl, l, mid);
    build(pr, mid, r);

    const vll &left_items = t[pl].items;
    const vll &right_items = t[pr].items;
    vll items;
    vll pref = {0};

    ll lp = 0, rp = 0;
    while (lp < left_items.size() || rp < right_items.size()) {
        if (lp == left_items.size() || (rp < right_items.size() && left_items[lp] > right_items[rp])) {
            items.push_back(right_items[rp++]);
        } else {
            items.push_back(left_items[lp++]);
        }
        pref.push_back(items[lp + rp - 1] + pref[lp + rp - 1]);
    }
    t[p] = {items, pref};
}

// сумма количества элементов на отрезке <= x
ll get(ll p, ll l, ll r, ll lq, ll rq, ll x) {
    if (l >= rq || r <= lq) {
        return 0;
    }

    if (lq <= l && r <= rq) {
        ll ind = upper_bound(all(t[p].items), x) - t[p].items.begin();
        return t[p].pref[ind];
    }

    ll pl = 2*p + 1;
    ll pr = 2*p + 2;
    ll mid = (r + l) >> 1;

    ll resl = get(pl, l, mid, lq, rq, x);
    ll resr = get(pr, mid, r, lq, rq, x);

    return resl + resr;
}

ll get(ll lq, ll rq) {
    ll x = 1;
    ll nxt = 1;
    do {
        x = nxt;
        nxt = get(0, 0, n, lq, rq, x) + 1;
    } while (x < nxt);
    return x;
}

signed main() {
    ll m;
    cin >> n >> m;

    fori (n) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    t = vector<Node>(4 * n);
    build(0, 0, n);

    while (m--) {
        ll l, r;
        cin >> l >> r;
        cout << get(l - 1, r) << '\n';
    }
	return 0;
}