#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 18;
ll counter = 0;

vector<vector<ll>> children;
vector<vector<ll>> binup;
vector<ll> tin;
vector<ll> tout;

void dfs(ll node) {
    tin[node] = counter++;

    for (ll pow = 1; pow <= MAX_POW; pow++) {
        binup[node][pow] = binup[binup[node][pow - 1]][pow - 1];
    }

    for (ll nxt : children[node]) {
        dfs(nxt);
    }
    tout[node] = counter++;
}

bool isAncestor(ll a, ll b) {
    return tin[a] >= tin[b] && tout[a] <= tout[b];
}

ll LA(ll a, ll b) {
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

    ll n, m;
    cin >> n >> m;

    children.resize(n, vector<ll>());
    binup.resize(n, vector<ll>(MAX_POW, 0));
    tin.resize(n);
    tout.resize(n);

    for (ll i = 1; i < n; i++) {
        ll parent;
        cin >> parent;

        binup[i][0] = parent;
        children[parent].push_back(i);
    }

    dfs(0);

    ll a1, a2;
    cin >> a1 >> a2;

    ll x, y, z;
    cin >> x >> y >> z;

    ll u = 0;
    ll res = 0;
    for (ll i = 0; i < m; i++) {
        u = LA((a1 + u) % n, a2);
        res += u;
        a1 = (x * a1 + y * a2 + z) % n;
        a2 = (x * a2 + y * a1 + z) % n;
    }

    cout << res << endl;
    return 0;
}
