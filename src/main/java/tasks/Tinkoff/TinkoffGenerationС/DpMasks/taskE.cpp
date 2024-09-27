#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> last_deleted;
vector<ll> res;

void dfs(ll l, ll r) {
    if (l > r) return;
    ll mid = last_deleted[l][r];

    dfs(l, mid - 1);
    dfs(mid + 1, r);

    res.push_back(mid);
}

int main() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> dp(n);
    vector<ll> prev(n, -1);
    prev[0] = 0;
    vector<vector<bool>> f(n, vector<bool>(n, false));
    last_deleted = vector<vector<ll>>(n, vector<ll>(n, -1));

    for (ll len = 1; len < n; len++) {
        for (ll l = 1; l + len <= n - 1; l++) {
            ll r = l + len - 1;
            for (ll mid = l; mid <= r; mid++) {
                 f[l][r] = ((a[mid] > a[l - 1] && a[mid] > a[r + 1]) || (a[mid] < a[l - 1] && a[mid] < a[r + 1]));
                 if (mid > l) {
                    f[l][r] = f[l][r] && f[l][mid - 1];
                 }
                 if (mid < r) {
                    f[l][r] = f[l][r] && f[mid + 1][r];
                 }
                 if (f[l][r]) {
                    last_deleted[l][r] = mid;
                    break;
                 }
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < i; j++) {
            if (prev[j] != -1 && ((j + 1 == i) || f[j + 1][i - 1]) && a[j] <= a[i]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
        }
    }

    if (prev[n - 1] == -1) {
        cout << -1 << endl;
        return 0;
    }

    ll cur = n - 1;
    while (cur > 0) {
        if (prev[cur] + 1 < cur) {
            dfs(prev[cur] + 1, cur - 1);
        }
        cur = prev[cur];
    }

    cout << res.size() << endl;
    for (ll ind : res) {
        cout << ind + 1 << endl;
    }
    return 0;
}