#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MX_POW = 25;
const int MOD = 1e9 + 7;

void dfs(int n, vector<vector<int>>& graph, vector<vector<vector<int>>>& matrix_pows) {
    matrix_pows[0] = graph;
    for (int p = 1; p <= MX_POW; ++p) {
        vector<vector<int>> cur(n, vector<int>(n, 0));
        vector<vector<int>>& prev = matrix_pows[p - 1];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    cur[i][j] = (cur[i][j] + prev[i][k] * 1LL * prev[k][j]) % MOD;
                }
            }
        }
        matrix_pows[p] = cur;
    }
}

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    vector<vector<vector<int>>> matrix_pows(MX_POW + 1, vector<vector<int>>(n, vector<int>(n, 0)));
    dfs(n, graph, matrix_pows);

    for (int i = 0; i < q; ++i) {
        int u, k;
        cin >> u >> k;
        u--;

        vector<int> res_row(n, 0);
        res_row[u] = 1;

        int p = 0;
        while (k > 0) {
            if (k % 2 == 1) {
                vector<int> cur(n, 0);
                for (int i = 0; i < n; ++i) {
                    for (int j = 0; j < n; ++j) {
                        cur[i] = (cur[i] + res_row[j] * 1LL * matrix_pows[p][j][i]) % MOD;
                    }
                }
                res_row = cur;
            }
            k /= 2;
            p++;
        }

        int res = accumulate(res_row.begin(), res_row.end(), 0LL) % MOD;
        cout << res << endl;
    }

    return 0;
}

