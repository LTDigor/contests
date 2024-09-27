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
vll start_zeros;
vll max_zeros;
vll end_zeros;

ll find_max_zeros_len(ll l, ll r) {
    ll res = 0;
    ll left_bucket_ind = l / sq;
    ll right_bucket_ind = r / sq;

    if (left_bucket_ind == right_bucket_ind) {
        ll cur = 0;
        for (ll j = l % sq; j <= r % sq; j++) {
            if (buckets[left_bucket_ind][j] == 0) {
                cur += 1;
            } else {
                cur = 0;
            }
            res = max(res, cur);
        }
        return res;
    }

    ll cur = 0;
    for (ll j = l % sq; j < sq; j++) {
        if (buckets[left_bucket_ind][j] == 0) {
            cur += 1;
        } else {
            cur = 0;
        }
        res = max(res, cur);
    }

    for (ll j = left_bucket_ind + 1; j < right_bucket_ind; j++) {
        cur += start_zeros[j];
        res = max(res, cur);

        if (end_zeros[j] < buckets[j].size()) {
            cur = end_zeros[j];
        }
        res = max(res, cur);
        res = max(res, max_zeros[j]);
    }

    for (ll j = 0; j <= r % sq; j++) {
        if (buckets[right_bucket_ind][j] == 0) {
            cur += 1;
        } else {
            cur = 0;
        }
        res = max(res, cur);
    }


    return res;
}

void update_number(ll i, ll x) {
    ll bucket_ind = i / sq;
    ll inner_ind = i % sq;

    buckets[bucket_ind][inner_ind] = x;
    ll zeros_start = 0;
    for (ll i = 0; i < buckets[bucket_ind].size(); i++) {
        if (buckets[bucket_ind][i] == 0) {
            zeros_start += 1;
        } else {
            break;
        }
    }
    start_zeros[bucket_ind] = zeros_start;

    ll zeros_end = 0;
    for (ll i = buckets[bucket_ind].size() - 1; i >= 0; i--) {
        if (buckets[bucket_ind][i] == 0) {
            zeros_end += 1;
        } else {
            break;
        }
    }
    end_zeros[bucket_ind] = zeros_end;

    ll cur = 0;
    max_zeros[bucket_ind] = 0;
    for (ll i = 0; i < buckets[bucket_ind].size(); i++) {
        if (buckets[bucket_ind][i] == 0) {
            cur += 1;
        } else {
            cur = 0;
        }
        max_zeros[bucket_ind] = max(max_zeros[bucket_ind], cur);
    }
    return;
}


signed main() {
    ll n; cin >> n;

    sq = sqrt(n) + 1;
    buckets = vvll(sq);
    start_zeros = vll(sq);
    end_zeros = vll(sq);
    max_zeros = vll(sq);

    ll bucket_ind = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        buckets[bucket_ind].push_back(x);
        if (buckets[bucket_ind].size() == sq) {
            bucket_ind += 1;
        }
    }

    for (ll i = 0; i < sq; i++) {
        if (buckets[i].size() > 0) {
            update_number(sq * i, buckets[i][0]);
        }
    }

    ll k; cin >> k;
    for (ll i = 0; i < k; i++) {
        string op; cin >> op;
        if (op == "QUERY") {
            ll l, r; cin >> l >> r;
            l -= 1;
            r -= 1;
            cout << find_max_zeros_len(l, r) << endl;
        } else {
            ll i, x; cin >> i >> x;
            i -= 1;

            update_number(i, x);
        }
    }

    return 0;
}