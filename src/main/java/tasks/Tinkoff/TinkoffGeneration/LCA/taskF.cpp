#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 20;
ll counter = 0;

vector<unordered_set<ll>> graph;
vector<vector<ll>> tree;
vector<vector<ll>> binup;
vector<vector<bool>> can_up;
vector<vector<bool>> can_down;
vector<ll> tin;
vector<ll> tout;

void dfs(ll node, ll parent) {
    tin[node] = counter++;

    binup[node][0] = parent;
    can_up[node][0] = graph[node].count(parent) == 1;
    can_down[node][0] = graph[parent].count(node) == 1;
    for (ll pow = 1; pow <= MAX_POW; pow++) {
        binup[node][pow] = binup[binup[node][pow - 1]][pow - 1];
        can_up[node][pow] = can_up[node][pow - 1] && can_up[binup[node][pow - 1]][pow - 1];
        can_down[node][pow] = can_down[node][pow - 1] && can_down[binup[node][pow - 1]][pow - 1];
    }

    for (ll nxt : tree[node]) {
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

ll ans_can_up(ll child, ll ancestor) {
    if (child == ancestor) return true;

    ll res = true;
    for (ll pow = MAX_POW; pow >= 0; pow--) {
        if (!isAncestor(ancestor, binup[child][pow])) {
            res = res && can_up[child][pow];
            child = binup[child][pow];
        }
    }

    return res && can_up[child][0];
}

ll ans_can_down(ll child, ll ancestor) {
    if (child == ancestor) return true;

    ll res = true;
    for (ll pow = MAX_POW; pow >= 0; pow--) {
        if (!isAncestor(ancestor, binup[child][pow])) {
            res = res && can_down[child][pow];
            child = binup[child][pow];
        }
    }

    return res && can_down[child][0];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    graph.resize(n);
    tree.resize(n);
    binup.resize(n, vector<ll>(MAX_POW, 0));
    can_up.resize(n, vector<bool>(MAX_POW));
    can_down.resize(n, vector<bool>(MAX_POW));
    tin.resize(n);
    tout.resize(n);

    for (ll i = 1; i < n; i++) {
        ll frm, to;
        cin >> frm >> to;
        graph[frm - 1].insert(to - 1);

        tree[frm - 1].push_back(to - 1);
        tree[to - 1].push_back(frm - 1);
    }
    graph[0].insert(0);
    dfs(0, 0);

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        ll lca = LCA(frm - 1, to - 1);
        // cout << lca << "!!!\n";
        // cout << ans_can_up(frm - 1, lca) << "!!!\n";
        // cout << ans_can_down(to - 1, lca) << "!!!\n";
        // cout << can_down[to - 1][0] << "!!!\n";
        cout << ((ans_can_up(frm - 1, lca) && ans_can_down(to - 1, lca)) ? "Yes" : "No") << endl;
    }

    return 0;
}