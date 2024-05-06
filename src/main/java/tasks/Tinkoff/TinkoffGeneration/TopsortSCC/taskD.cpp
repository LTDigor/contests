#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<ll> > g, gr;
vector<ll> used, topsort, color;

void dfs(ll node) {
    used[node] = 1;
    for (ll nxt : g[node]) {
        if (!used[nxt]) {
            dfs(nxt);
        }
    }

    topsort.push_back(node);
}

void dfs_colors(ll node, ll c) {
    color[node] = c;

    for (ll nxt : gr[node]) {
        if (!color[nxt]) {
            dfs_colors(nxt, c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    used.resize(n);
    g.resize(n);
    gr.resize(n);
    color.resize(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;

        g[frm].push_back(to);
        gr[to].push_back(frm);
    }

    for (ll i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    ll c = 1;
    for (ll i = 0; i < n; i++) {
        ll node = topsort[n - i - 1];
        if (!color[node]) {
            dfs_colors(node, c++);
        }
    }

    cout << c - 1 << endl;
    for (ll curr : color) {
        cout << curr << " ";
    }
    cout << endl;

    return 0;
}