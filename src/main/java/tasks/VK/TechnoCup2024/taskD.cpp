#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define us unordered_set
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

#define watch(x) cerr << #x << " " << (x) << endl;
#define cerr cerr && debug && cout
const bool debug = 1;

using namespace std;

vvll g;
vector<um<ll, ll>> m;
vll results;
ll k;

void print_map(const unordered_map<long long, long long>& umap) {
    for (const auto& pair : umap) {
        cout << "Key: " << pair.first << ", Value: " << pair.second << endl;
    }
}

void dfs(ll node, ll parent, ll depth) {
    m[node][depth] = 1;

    ll res = 0;
    for (const ll nxt : g[node]) {
        if (nxt == parent) {
            continue;
        }

        dfs(nxt, node, depth + 1);

        if (m[nxt].size() > m[node].size()) {
            m[node].swap(m[nxt]);
        }

        for (auto &[d, freq] : m[nxt]) {
            ll x = k - d + 2 * depth - 1;
            res += freq * m[node][x];
        }

        for (auto [d, freq] : m[nxt]) {
            m[node][d] += freq;
        }
        m[nxt].clear();
    }

    results[node] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n >> k;

    g.resize(n);
    m.resize(n);
    results.resize(n);

    for (ll i = 1; i < n; i++) {
        ll frm, to;
        cin >> frm >> to;
        g[to - 1].push_back(frm - 1);
        g[frm - 1].push_back(to - 1);
    }


    dfs(0, 0, 0);
    ll res = 0;
    fori (n) {
        res += results[i];
    }
    cout << res << endl;
    return 0;
}
