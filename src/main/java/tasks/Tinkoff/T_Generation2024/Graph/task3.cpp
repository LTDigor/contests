//#pragma GCC optimize ("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define vvll vector<vll>
#define um unordered_map
#define us unordered_set
#define all(vec) vec.begin(), vec.end()
#define fori(n) for (ll i = 0; i < n; i++)

using namespace std;

const ll INF = 1e18;

vll topsort;
vector<bool> used;

ll timer = 1;
um<ll, set<pll>> graph;

void dfs(ll node) {
    used[node] = true;
    for (auto [w, nxt] : graph[node]) {
        if (!used[nxt]) {
            dfs(nxt);
        }
    }

    topsort.push_back(node);
}

signed main() {
    ll n, m, s, t;
    cin >> n >> m >> s >> t;
    s--, t--;

    used.resize(n);

    fori (m) {
        ll frm, to, w;
        cin >> frm >> to >> w;
        frm--, to--;

        graph[frm].insert({w, to});
    }


    dfs(s);
    reverse(all(topsort));

    vll dist(n, INF);
    dist[s] = 0;

    fori (topsort.size()) {
        ll node = topsort[i];
        for (auto [w, nxt] : graph[node]) {
            dist[nxt] = min(dist[nxt], dist[node] + w);
        }
    }

    if (dist[t] == INF) {
        cout << "Unreachable" << endl;
    } else {
        cout << dist[t] << endl;
    }
	return 0;
}