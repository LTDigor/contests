#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

const ll NEG_INF = 0;

signed main() {
    ll n; cin >> n;

    ll sq = sqrt(n) + 1;
    vvll buckets(sq);
    vll maximums(sq, NEG_INF);

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
        ll l, r; cin >> l >> r;
        l -= 1;
        r -= 1;

        ll res = NEG_INF;
        ll left_bucket_ind = l / sq;
        ll right_bucket_ind = r / sq;

        if (left_bucket_ind == right_bucket_ind) {
            for (ll j = l % sq; j <= r % sq; j++) {
                res = max(res, buckets[left_bucket_ind][j]);
            }
        } else {
            for (ll j = left_bucket_ind + 1; j < right_bucket_ind; j++) {
                res = max(res, maximums[j]);
            }

            for (ll j = l % sq; j < sq; j++) {
                res = max(res, buckets[left_bucket_ind][j]);
            }

            for (ll j = 0; j <= r % sq; j++) {
                res = max(res, buckets[right_bucket_ind][j]);
            }
        }

        cout << res << " ";
    }

    return 0;
}