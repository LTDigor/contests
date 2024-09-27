#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<ll> visited;
vector<ll> topsort;

bool dfs(ll node) {
    visited[node] = 1;
    for (ll nxt : graph[node]) {
        if (visited[nxt] == 0) {
            if (dfs(nxt) == false)
                return false;
        } else if (visited[nxt] == 1) {
            return false;
        }
    }

    visited[node] = 2;
    topsort.push_back(node);
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    visited.resize(n);
    graph.resize(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;

        graph[frm].push_back(to);
    }

    bool res = true;
    for (ll i = 0; i < n; i++) {
        if (!visited[i]) {
            res = res && dfs(i);
        }
        if (!res) {
            break;
        }
    }

    if (res) {
        for (ll i = 0; i < n; i++) {
            cout << topsort[n - 1 - i] + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}