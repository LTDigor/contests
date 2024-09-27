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
    vll zeros(sq);

    ll bucket_ind = 0;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        zeros[bucket_ind] += x == 0;
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

        ll res = 0;
        ll left_bucket_ind = l / sq;
        ll right_bucket_ind = r / sq;

        if (left_bucket_ind == right_bucket_ind) {
            for (ll j = l % sq; j <= r % sq; j++) {
                res += buckets[left_bucket_ind][j] == 0;
            }
        } else {
            for (ll j = left_bucket_ind + 1; j < right_bucket_ind; j++) {
                res += zeros[j];
            }

            for (ll j = l % sq; j < sq; j++) {
                res += buckets[left_bucket_ind][j] == 0;
            }

            for (ll j = 0; j <= r % sq; j++) {
                res += buckets[right_bucket_ind][j] == 0;
            }
        }

        cout << res << " ";
    }

    return 0;
}