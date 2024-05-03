#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> w;
vector<vector<ll>> cost;
vector<ll> a;
ll INF = 10000000000000;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    w = vector<vector<ll>>(n, vector<ll>(n, INF));
    cost = vector<vector<ll>>(n, vector<ll>(n, INF));
    for (ll i = 0; i < n; i++) {
        w[i][i] = a[i];
        cost[i][i] = 0;
    }

    for (ll len = 2; len <= n; len++) {
        for (ll l = 0; l + len <= n; l++) {
            ll r = l + len - 1;
            for (ll mid = l; mid < r; mid++) {
                ll nw = w[l][mid] + w[mid + 1][r];
                ll nc = cost[l][mid] + cost[mid + 1][r] + nw;
                if (nc < cost[l][r]) {
                    cost[l][r] = nc;
                    w[l][r] = nw;
                }
            }
        }
    }

    cout << cost[0][n - 1] << endl;
    return 0;
}