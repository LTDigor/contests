#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using ll = long long;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<ll>> graph(n, vector<ll>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                graph[i][j] = 9223372036854775;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                graph[u][v] = min(graph[u][v], graph[u][i] + graph[i][v]);
            }
        }
    }

    ll max_distance = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != 9223372036854775) {
                max_distance = max(max_distance, graph[i][j]);
            }
        }
    }
    cout << max_distance << endl;

    return 0;
}