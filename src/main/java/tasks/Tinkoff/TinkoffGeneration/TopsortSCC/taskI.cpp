#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph;
vector<vector<bool>> visited;
vector<pair<ll, ll>> topsort;
vector<pair<ll, ll>> diff = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
ll n, m;

void dfs(ll x, ll y) {
    visited[x][y] = true;
    for (auto [dx, dy] : diff) {
        ll nx = x + dx, ny = y + dy;
        if (nx >= n || nx < 0 || ny >= m || ny < 0) {
            continue;
        }
        if (!visited[nx][ny] && graph[nx][ny] <= graph[x][y])
            dfs(nx, ny);
    }

    topsort.push_back({x, y});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    visited.resize(n, vector<bool>(m, false));
    graph.resize(n, vector<ll>(m, 0));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            ll h;
            cin >> h;

            graph[i][j] = h;
        }
    }

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            if (!visited[i][j]) {
                dfs(i, j);
            }
        }
    }

    ll res = 0;
    visited = vector<vector<bool>>(n, vector<bool>(m, false));
    for (ll i = 0; i < n; i++) {
        auto [x, y] = topsort[n - 1 - i];
        visited[x][y] = true;
        for (auto [dx, dy] : diff) {
            ll nx = x + dx, ny = y + dy;
            if (nx >= n || nx < 0 || ny >= m || ny < 0) {
                continue;
            }
            if (visited[nx][ny] && graph[nx][ny] <= graph[x][y]) {
                res++;
                break;
            }
        }
    }

    cout << res << endl;

    return 0;
}