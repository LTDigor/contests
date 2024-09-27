#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll INF = 100001;
    ll NEG_INF = -10001;

    int n;
    cin >> n;

    vector<vector<ll>> graph(n, vector<ll>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j) {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][i] != INF && graph[i][v] != INF) {
                    graph[u][v] = min(graph[u][v], graph[u][i] + graph[i][v]);
                    graph[u][v] = max(graph[u][v], NEG_INF);
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            bool cycle = false;
            for (int t = 0; t < n; t++) {
                if (graph[i][t] != INF && graph[t][j] != INF && graph[t][t] < 0) {
                    cycle = true;
                    break;
                }
            }

            if (cycle) {
                cout << 2 << ' ';
            } else if (graph[i][j] == INF) {
                cout << 0 << ' ';
            } else {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
