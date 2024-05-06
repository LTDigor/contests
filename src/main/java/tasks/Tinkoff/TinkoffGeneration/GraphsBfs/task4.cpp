#include <iostream>
#include <vector>
#include <set>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> points[i].first >> points[i].second;
    }

    int frm, to;
    std::cin >> frm >> to;
    frm--, to--;

    std::vector<long long> dist(n, 2000000000);
    std::vector<bool> visited(n, false);
    dist[frm] = 0;
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int u = 0; u < n; u++) {
            if (!visited[u] && (v == -1 || dist[u] < dist[v])) {
                v = u;
            }
        }

        visited[v] = true;
        for (int u = 0; u < n; u++) {
            long long w = (points[u].first - points[v].first) * (points[u].first - points[v].first) +
                (points[u].second - points[v].second) * (points[u].second - points[v].second);
            dist[u] = std::min(dist[u], dist[v] + w);
        }
    }
    std::cout << dist[to] << std::endl;
    return 0;
}