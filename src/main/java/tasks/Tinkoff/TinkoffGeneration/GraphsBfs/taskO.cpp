#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    int m;
    cin >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int frm, to;
        cin >> frm >> to;
        frm--, to--;
        graph[frm].push_back(to);
        graph[to].push_back(frm);
    }

    vector<int> dists0(n, -1);
    vector<int> dists1(n, -1);
    dists0[0] = 0;
    dists1[0] = prices[0];

    set<pair<int, int>> heap;
    heap.insert({0, 0});

    while (!heap.empty()) {
        int node = heap.begin()->second;
        heap.erase(heap.begin());

        int nxt_dist0 = min(dists1[node], dists0[node] + prices[node]);
        int nxt_dist1 = min(dists1[node] + prices[node], nxt_dist0 + prices[node]);
        for (int nxt : graph[node]) {
            if (dists0[nxt] == -1 || dists0[nxt] > nxt_dist0) {
                heap.erase({dists0[nxt], nxt});
                dists0[nxt] = nxt_dist0;
                heap.insert({dists0[nxt], nxt});
            }

            if (dists1[nxt] == -1 || dists1[nxt] > nxt_dist1) {
                heap.erase({dists1[nxt], nxt});
                dists1[nxt] = nxt_dist1;
                heap.insert({dists1[nxt], nxt});
            }
        }
    }

    cout << dists0[n - 1] << endl;
    return 0;
}