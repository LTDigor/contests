#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> topsort;

bool check(ll node) {
    visited[node] = true;
    for (ll nxt : graph[node]) {
        if (!visited[nxt]) {
            return false;
        }
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    visited.resize(n, false);
    graph.resize(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;

        graph[frm - 1].push_back(to - 1);
    }

    for (ll i = 0; i < n; i++) {
        ll item;
        cin >> item;
        topsort.push_back(item - 1);
    }

    bool res = true;
    for (ll i = n - 1; i >= 0; i--) {
        res = check(topsort[i]);
        if (!res) {
            break;
        }
    }

    cout << (res ? "YES" : "NO") << endl;

    return 0;
}