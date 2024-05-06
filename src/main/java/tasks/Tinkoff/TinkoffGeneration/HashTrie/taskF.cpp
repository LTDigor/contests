#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

unordered_map<ll, pll> vals;

struct hashFunction {
  size_t operator()(const pll &x) const {
    return x.first ^ x.second;
  }
};

vpll count_hashes(const vll &arr, ll len) {
    vpll hashes;

    ll prev1 = 0;
    ll prev2 = 0;
    for (ll i = 0; i < len; i++) {
        prev1 = prev1 + vals[arr[i]].first;
        prev2 = prev2 + vals[arr[i]].second;
    }
    hashes.push_back({prev1, prev2});

    for (ll i = 1; i < arr.size() - len + 1; i++) {
        prev1 = prev1 - vals[arr[i - 1]].first + vals[arr[i + len - 1]].first;
        prev2 = prev2 - vals[arr[i - 1]].second + vals[arr[i + len - 1]].second;
        hashes.push_back({prev1, prev2});
    }

    return hashes;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n1; cin >> n1;
    vll a1(n1);
    for (ll i = 0; i < n1; i++) {
        cin >> a1[i];
        vals[a1[i]] = {rand(), rand()};
    }

    ll n2; cin >> n2;
    vll a2 = vll(n2);
    for (ll i = 0; i < n2; i++) {
        cin >> a2[i];
        vals[a2[i]] = {rand(), rand()};
    }

    ll res = 0;
    for (ll k = 1; k <= min(n1, n2); k++) {
        vpll hashes1 = count_hashes(a1, k);
        vpll hashes2 = count_hashes(a2, k);

        unordered_set<pll, hashFunction> hashes1_set(hashes1.begin(), hashes1.end());
        for (pll h2 : hashes2) {
            if (hashes1_set.find(h2) != hashes1_set.end()) {
                res = k;
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}
