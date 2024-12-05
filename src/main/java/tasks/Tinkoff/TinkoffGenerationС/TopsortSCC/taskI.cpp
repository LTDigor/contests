#include <bits/stdc++.h>
#define ll long long

using namespace std;

vector<vector<ll>> graph, color;
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
        if (!visited[nx][ny] && graph[nx][ny] >= graph[x][y])
            dfs(nx, ny);
    }

    topsort.push_back({x, y});
}

void dfs_colors(ll x, ll y, ll c) {
    color[x][y] = c;
    for (auto [dx, dy] : diff) {
        ll nx = x + dx, ny = y + dy;
        if (nx >= n || nx < 0 || ny >= m || ny < 0) {
            continue;
        }
        if (color[nx][ny] == -1 && graph[nx][ny] >= graph[x][y])
            dfs_colors(nx, ny, c);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    visited.resize(n, vector<bool>(m, false));
    color.resize(n, vector<ll>(m, -1));
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
    reverse(topsort.begin(), topsort.end());

    ll c = 0;
    for (auto [x, y] : topsort) {
        if (color[x][y] == -1) {
            dfs_colors(x, y, c++);
        }
    }

    cout << c << endl;

    return 0;
}