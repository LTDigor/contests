#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> p;
vector<ll> topsort;
vector<ll> res;

void dfs(ll node) {
    visited[node] = true;
    for (ll nxt : graph[node]) {
        if (!visited[nxt])
            dfs(nxt);
    }

    topsort.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;

    visited.resize(n, false);
    graph.resize(n);

    for (ll i = 0; i < n; i++) {
        ll item;
        cin >> item;
        p.push_back(item);
    }

    for (ll i = 0; i < n; i++) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; j++) {
            ll to;
            cin >> to;
            graph[i].push_back(to - 1);
        }
    }

    dfs(0);

    ll total_time = 0;
    for (ll node : topsort) {
        total_time += p[node];
        res.push_back(node);
    }


    cout << total_time << " " << res.size() << endl;
    for (ll item : res) {
        cout << item + 1 << " ";
    }
    cout << endl;

    return 0;
}