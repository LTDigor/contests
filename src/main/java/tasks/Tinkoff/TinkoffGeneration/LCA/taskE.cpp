#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 30;
ll MX_COST = 1000000;
ll counter = 0;

vector<vector<ll>> children;
vector<vector<ll>> binup;
vector<vector<ll>> func;
vector<ll> values;
vector<ll> tin;
vector<ll> tout;

void dfs(ll node, ll parent) {
    tin[node] = counter++;

    binup[node][0] = parent;
    func[node][0] = values[node];
    for (ll pow = 1; pow <= MAX_POW; pow++) {
        binup[node][pow] = binup[binup[node][pow - 1]][pow - 1];
        func[node][pow] = min(func[node][pow - 1], func[binup[node][pow - 1]][pow - 1]);
    }

    for (ll nxt : children[node]) {
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

ll find(ll child, ll ancestor) {
    if (child == ancestor) return MX_COST;
    ll res = MX_COST;
    for (ll pow = MAX_POW; pow >= 0; pow--) {
        if (!isAncestor(ancestor, binup[child][pow])) {
            res = min(res, func[child][pow]);
            child = binup[child][pow];
        }
    }

    return min(res, func[child][0]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    children.resize(n, vector<ll>());
    binup.resize(n, vector<ll>(MAX_POW, 0));
    func.resize(n, vector<ll>(MAX_POW, 0));
    values.resize(n);
    tin.resize(n);
    tout.resize(n);

    for (ll i = 1; i < n; i++) {
        ll parent, cost;
        cin >> parent >> cost;
        children[parent - 1].push_back(i);
        values[i] = cost;
    }

    dfs(0, 0);

    ll m;
    cin >> m;
    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        ll lca = LCA(frm - 1, to - 1);
        cout << min(find(frm - 1, lca), find(to - 1, lca)) << endl;
    }

    return 0;
}