#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

const ll NEG_INF = 0;

ll sq;
vvll buckets;
vll maximums;
vll addition;

ll find_max(ll l, ll r) {
    ll res = NEG_INF;
    ll left_bucket_ind = l / sq;
    ll right_bucket_ind = r / sq;

    if (left_bucket_ind == right_bucket_ind) {
        for (ll j = l % sq; j <= r % sq; j++) {
            res = max(res, buckets[left_bucket_ind][j] + addition[left_bucket_ind]);
        }
        return res;
    }

    for (ll j = left_bucket_ind + 1; j < right_bucket_ind; j++) {
        res = max(res, maximums[j] + addition[j]);
    }

    for (ll j = l % sq; j < sq; j++) {
        res = max(res, buckets[left_bucket_ind][j] + addition[left_bucket_ind]);
    }

    for (ll j = 0; j <= r % sq; j++) {
        res = max(res, buckets[right_bucket_ind][j] + addition[right_bucket_ind]);
    }


    return res;
}

void add_number(ll l, ll r, ll x) {
    ll left_bucket_ind = l / sq;
    ll right_bucket_ind = r / sq;

    if (left_bucket_ind == right_bucket_ind) {
        for (ll j = l % sq; j <= r % sq; j++) {
            buckets[left_bucket_ind][j] += x;
            maximums[left_bucket_ind] = max(maximums[left_bucket_ind], buckets[left_bucket_ind][j]);
        }
        return;
    }

    for (ll j = left_bucket_ind + 1; j < right_bucket_ind; j++) {
        addition[j] += x;
    }

    for (ll j = l % sq; j < sq; j++) {
        buckets[left_bucket_ind][j] += x;
        maximums[left_bucket_ind] = max(maximums[left_bucket_ind], buckets[left_bucket_ind][j]);
    }

    for (ll j = 0; j <= r % sq; j++) {
        buckets[right_bucket_ind][j] += x;
        maximums[right_bucket_ind] = max(maximums[right_bucket_ind], buckets[right_bucket_ind][j]);
    }

    return;
}


signed main() {
    ll n; cin >> n;

     sq = sqrt(n) + 1;
    buckets = vvll(sq);
    maximums = vll(sq, NEG_INF);
    addition = vll(sq);

    ll bucket_ind = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        maximums[bucket_ind] = max(maximums[bucket_ind], x);
        buckets[bucket_ind].push_back(x);
        if (buckets[bucket_ind].size() == sq) {
            bucket_ind += 1;
        }
    }

    ll k; cin >> k;
    for (ll i = 0; i < k; i++) {
        char op; cin >> op;

        if (op == 'm') {
            ll l, r; cin >> l >> r;
            l -= 1;
            r -= 1;
            cout << find_max(l, r) << " ";
        } else {
            ll l, r; cin >> l >> r;
            l -= 1;
            r -= 1;

            ll x; cin >> x;
            add_number(l, r, x);
        }
    }

    return 0;
}