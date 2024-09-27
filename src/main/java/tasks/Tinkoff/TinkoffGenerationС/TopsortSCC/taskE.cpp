#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<pair<ll, ll>> > g, gr;
vector<ll> used, topsort, dist;
ll INF = 30000000000;

void dfs(ll node) {
    used[node] = 1;
    for (auto [nxt, w] : g[node]) {
        if (!used[nxt]) dfs(nxt);
    }

    topsort.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    ll s, t;
    cin >> s >> t;
    s--, t--;

    used.resize(n);
    g.resize(n);
    gr.resize(n);
    dist.resize(n, INF);

    for (ll i = 0; i < m; i++) {
        ll frm, to, w;
        cin >> frm >> to >> w;
        frm--, to--;

        g[frm].push_back({to, w});
        gr[to].push_back({frm, w});
    }

    dfs(s);

    dist[s] = 0;
    ll tsize = topsort.size();
    for (ll i = 0; i < tsize; i++) {
        ll node = topsort[tsize - i - 1];
        for (auto [prev, w] : gr[node]) {
            if (dist[prev] == INF)
                continue;

            dist[node] = dist[node] == INF ? dist[prev] + w : min(dist[node], dist[prev] + w);
        }
    }

    if (dist[t] == INF) {
        cout << "Unreachable" << endl;
    } else {
        cout << dist[t] << endl;
    }
    return 0;
}
