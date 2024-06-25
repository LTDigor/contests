#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<bool> visited;
vector<bool> marked;
vector<ll> topsort;

void dfs(ll node) {
    visited[node] = true;
    for (ll nxt : graph[node]) {
        if (!visited[nxt])
            dfs(nxt);
    }

    topsort.push_back(node);
}

void mark(ll node) {
    marked[node] = true;
    for (ll nxt : graph[node]) {
        if (!marked[nxt])
            mark(nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m, s;
    cin >> n >> m >> s;

    visited.resize(n);
    marked.resize(n);
    graph.resize(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;

        graph[frm].push_back(to); // !!!
    }

    for (ll i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    ll res = 0;
    mark(s);
    for (ll i = 0; i < n; i++) {
        ll node = topsort[n - 1 - i];
        if (!marked[node]) {
            mark(node);
            res++;
        }
    }

    cout << res << endl;

    return 0;
}