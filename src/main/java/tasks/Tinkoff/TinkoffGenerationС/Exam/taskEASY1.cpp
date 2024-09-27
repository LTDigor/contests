#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll MAX_POW = 18;
ll counter = 0;

vector<vector<ll>> children;
vector<vector<ll>> parents;
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

ll find_dist(ll cur) {
    ll res = 1;
    while (cur != 0) {
        res++;
        cur = parents[cur];
        if (res > n) break;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    children.resize(n, vector<ll>());
    parents.resize(n);
    binup.resize(n, vector<ll>(MAX_POW, 0));
    tin.resize(n);
    tout.resize(n);

    parents[0] = 0;
    for (ll i = 1; i < n; i++) {
        ll parent;
        cin >> parent;
        parent -= 1;

        binup[i][0] = parent;
        children[parent].push_back(i);
        parents[i] = parent;
    }

    dfs(0);

    ll q; cin >> q;
    for (ll i = 0; i < q; i++) {
        ll a, b; cin >> a >> b;
        a--, b--;
        
        ll u = LA(a, b);
        ll res = find_dist(u);
        cout << res << endl;
    }
    return 0;
}
