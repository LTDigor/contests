#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll INF = 100000;
    ll NEG_INF = -10000;

    int n;
    cin >> n;

    vector<vector<ll>> graph(n, vector<ll>(n));
    vector<vector<int>> next(n, vector<int>(n, -1));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (i == j && graph[i][j] > 0) {
                graph[i][j] = 0;
            }

            next[i][j] = j;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][i] != INF && graph[i][v] != INF) {
                    if (graph[u][v] > graph[u][i] + graph[i][v]) {
                        graph[u][v] = graph[u][i] + graph[i][v];
                        next[u][v] = next[u][i];

                        graph[u][v] = max(graph[u][v], NEG_INF);
                        if (u == v && graph[u][u] < 0) {
                            goto endloop;
                        }
                    }
                }
            }
        }
    }
    endloop:
    int startNode = -1;
    for (int i = 0; i < n; ++i) {
        if (graph[i][i] < 0) {
            startNode = i;
            break;
        }
    }

    if (startNode == -1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;

        vector<int> res;
        res.push_back(startNode);
        int curr = next[startNode][startNode];
        while (curr != startNode) {
            res.push_back(curr);
            curr = next[curr][startNode];
        }
        res.push_back(startNode);

        cout << res.size() << endl;
        for (int curr : res) {
            cout << curr + 1 << ' ';
        }
        cout << endl;
    }

    return 0;
}
