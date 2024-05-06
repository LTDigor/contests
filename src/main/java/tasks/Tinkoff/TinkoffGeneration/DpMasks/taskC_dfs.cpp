#include <bits/stdc++.h>
#define ll int

using namespace std;

ll n;
vector<vector<ll>> a;
vector<vector<ll>> memo;

pair<ll, ll> dfs(ll mask, ll last_node) {
    if (mask == (1 << n) - 1) {
        return {, 0};
    }

    vector<ll> res_path;
    ll res_cost = 1000000;
    for (ll nxt = 0; nxt < n; nxt++) {
        if ((mask & (1 << nxt)) == 0 && a[last_node][nxt] > 0) {
            pair<vector<ll>, ll> p = dfs(mask | (1 << nxt), nxt);
            if (res_cost > p.second + a[last_node][nxt]) {
                res_parent = p.first;
                res_cost = p.second + a[last_node][nxt];
            }
        }
    }
    res_path.push_back(last_node);
    return {res_path, res_cost};
}

int main() {
    cin >> n;
    a = vector<vector<ll>>(n, vector<ll>(n));
    memo = vector<vector<ll>>(1 << n, vector<ll>(n));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    pair<vector<ll>, ll> res = dfs(1, 0);
    if (res.second == 1000000) {
        cout << -1 << endl;
    } else {
        reverse(res.first.begin(), res.first.end());
        cout << res.second << endl;
        for (ll node : res.first) {
            cout << node + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}