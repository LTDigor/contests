#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<bool>> dp;
vector<vector<int>> ks;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    dp = vector<vector<ll>>(n, vector<ll>(n));
    ks = vector<vector<ll>>(n, vector<ll>(n));
    ll res = 0;
    for (ll i = 0; i < n; i++) {
        dp[i][i] = 1;
        res++;
    }

    for (ll i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
        } else if (k > 0) {
            dp[i][i + 1] = 1;
            ks[i][i + 1] = 1;
        }
        res += dp[i][i + 1];
    }

    for (ll len = 3; len <= n; len++) {
        for (ll l = 0; l + len <= n; l++) {
            ll r = l + len - 1;
            if (s[l] == s[r]) {
                dp[l][r] = dp[l + 1][r - 1];
                ks[l][r] = ks[l + 1][r - 1];
            } else if (ks[l + 1][r - 1] < k) {
                dp[l][r] = dp[l + 1][r - 1];
                ks[l][r] = ks[l + 1][r - 1] + 1;
            }

            res += dp[l][r];
        }
    }
    cout << res << endl;
    return 0;
}