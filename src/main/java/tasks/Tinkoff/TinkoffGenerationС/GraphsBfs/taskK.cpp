#include <iostream>
#include <vector>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> cities(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cities[i];
    }
    std::vector<std::vector<std::pair<int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        --u;
        --v;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    int res = -1;
    int res_frm = 0, res_to = 0;

    std::vector<int> dists(n, -1);
    for (int start = 0; start < n; ++start) {
        if (cities[start] != 1) {
            continue;
        }

        dists[start] = 0;

        std::set<std::pair<long long, int>> heap;
        heap.insert({0, start});

        while (!heap.empty()) {
            int node = heap.begin()->second;
            heap.erase(heap.begin());

            if (cities[node] + cities[start] == 3) {
                if (res == -1 || res > dists[node]) {
                    res = dists[node];
                    res_frm = start;
                    res_to = node;
                }
                break;
            }
            for (auto [nxt, weight] : graph[node]) {
                int nxt_dist = dists[node] + weight;
                if (dists[nxt] == -1 || dists[nxt] > nxt_dist) {
                    heap.erase({dists[nxt], nxt});
                    dists[nxt] = nxt_dist;
                    heap.insert({dists[nxt], nxt});
                }
            }
        }
    }
    if (res == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << res_frm + 1 << " " << res_to + 1 << " " << res << std::endl;
    }
    return 0;
}

