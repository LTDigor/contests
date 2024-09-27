#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 30;
ll counter = 0;

vector<vector<ll>> graph;
vector<vector<ll>> binup;
vector<ll> tin;
vector<ll> tout;

void dfs(ll node, ll parent) {
    tin[node] = counter++;

    binup[node][0] = parent;
    for (ll pow = 1; pow <= MAX_POW; pow++) {
        binup[node][pow] = binup[binup[node][pow - 1]][pow - 1];
    }

    for (ll nxt : graph[node]) {
        if (nxt != parent)
            dfs(nxt, node);
    }
    tout[node] = counter++;
}

bool isAncestor(ll a, ll b) {
    return tin[a] >= tin[b] && tout[a] <= tout[b];
}

ll LCA(ll a, ll b) {
    if (isAncestor(a, b)) return b;
    if (isAncestor(b, a)) return a;

    for (ll pow = MAX_POW; pow >= 0; pow--) {
        if (!isAncestor(b, binup[a][pow])) {
            a = binup[a][pow];
        }
    }

    return binup[a][0];
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    while (n != 0) {
        graph.clear();
        binup.clear();
        tin.clear();
        tout.clear();

        graph.resize(n);
        binup.resize(n, vector<ll>(MAX_POW, 0));
        tin.resize(n);
        tout.resize(n);

        for (ll i = 1; i < n; i++) {
            ll u, v;
            cin >> u >> v;
            u--, v--;

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, 0);

        ll m;
        cin >> m;
        ll root = 0;
        for (ll i = 0; i < m; i++) {
            char op;
            cin >> op;
            if (op == '?') {
                ll u, v;
                cin >> u >> v;
                u--, v--;

                ll lca = LCA(u, v);
                ll lcaU = LCA(u, root);
                ll lcaV = LCA(v, root);

                if (lcaU == lca) {
                    cout << lcaV + 1 << endl;
                } else if (lcaV == lca) {
                    cout << lcaU + 1 << endl;
                } else {
                    cout << lca + 1 << endl;
                }

            } else {
                ll u;
                cin >> u;
                u--;

                root = u;
            }
        }
        cin >> n;
    }

    return 0;
}