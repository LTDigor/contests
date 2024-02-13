#include <iostream>
#include <vector>
#include <set>
#include <algorithm>


using namespace std;
int main() {
    int n, m, start, end;
    cin >> n >> m >> start >> end;
    start--, end--;

    vector<vector<pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int frm, to, weight;
        cin >> frm >> to >> weight;
        frm--, to--;

        graph[frm].push_back({to, weight});
        graph[to].push_back({frm, weight});
    }

    vector<long long> dist(n, -1);
    dist[start] = 0;

    vector<long long> parent(n, -1);

    set<pair<long long, int>> q;
    q.insert({0, start});

    while (!q.empty()) {
        auto node = q.begin()->second;
        q.erase(q.begin());

        if (node == end) break;
        for (auto [nxt, weight] : graph[node]) {
            if (dist[nxt] == -1 || dist[nxt] > dist[node] + weight) {
                q.erase({dist[nxt], nxt});
                dist[nxt] = dist[node] + weight;
                q.insert({dist[nxt], nxt});

                parent[nxt] = node;
            }
        }
    }

    if (dist[end] == -1) {
        cout << -1 << endl;
    } else {
        vector<int> res;
        int current = end;

        res.push_back(current + 1);
        while (current != start) {
            current = parent[current];
            res.push_back(current + 1);
        }

        reverse(res.begin(), res.end());
        cout << dist[end] << " " << res.size() << endl;
        for (auto item : res) {
            cout << item << " ";
        }
    }

    return 0;
}