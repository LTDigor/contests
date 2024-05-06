#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 30;
ll counter = 0;

vector<vector<ll>> children;
vector<vector<ll>> binup;
vector<ll> values;
vector<ll> path;
vector<ll> tin;
vector<ll> tout;

void dfs(ll node, ll parent) {
    tin[node] = counter++;
    path[node] = path[parent] + values[node];

    binup[node][0] = parent;
    for (ll pow = 1; pow <= MAX_POW; pow++) {
        binup[node][pow] = binup[binup[node][pow - 1]][pow - 1];
    }

    for (ll nxt : children[node]) {
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

    children.resize(n, vector<ll>());
    binup.resize(n, vector<ll>(MAX_POW, 0));
    values.resize(n);
    path.resize(n);
    tin.resize(n);
    tout.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> values[i];
    }

    for (ll i = 1; i < n; i++) {
        ll frm, to;
        cin >> frm >> to;
        children[to - 1].push_back(frm - 1);
        children[frm - 1].push_back(to - 1);
    }

    dfs(0, 0);

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        ll lca = LCA(frm - 1, to - 1);
        cout << path[frm - 1] + path[to - 1] - 2 * path[lca] + values[lca] << endl;
    }

    return 0;
}