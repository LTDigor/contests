#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, int, int>>> graph(n);
    for (int i = 0; i < m; ++i) {
        int frm, to, node_time, weight;
        cin >> frm >> to >> node_time >> weight;
        frm -= 1;
        to -= 1;
        weight -= 3000000;
        if (weight > 0) {
            graph[frm].emplace_back(to, weight, node_time);
            graph[to].emplace_back(frm, weight, node_time);
        }
    }

    int left = 0;
    int right = 10000000;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        bool can_reach = false;

        vector<int> dists(n, -1);
        dists[0] = 0;

        set<pair<int, int>> heap;
        heap.insert({0, 0});

        while (!heap.empty()) {
            int node = heap.begin()->second;
            heap.erase(heap.begin());

            if (node == n - 1) {
                can_reach = true;
                break;
            }

            for (auto [nxt, weight, t] : graph[node]) {
                int nxt_dist = dists[node] + t;
                if (mid * 100 <= weight
                && nxt_dist <= 1440
                && (dists[nxt] == -1 || dists[nxt] > nxt_dist)) {
                    heap.erase({dists[nxt], nxt});
                    dists[nxt] = nxt_dist;
                    heap.insert({dists[nxt], nxt});
                }
            }
        }

        if (can_reach) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (--left < 0) {
        left = 0;
    }

    cout << left << endl;
    return 0;
}


