#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <utility>
#include <algorithm>

int main() {
    int n, m, start_x, start_y, end_x, end_y;
    std::cin >> n >> m >> start_x >> start_y >> end_x >> end_y;
    start_x--; start_y--; end_x--; end_y--;

    std::vector<std::string> grid(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> grid[i];
    }

    const int k = 3;
    std::vector<std::vector<std::pair<int, int>>> parents(n, std::vector<std::pair<int, int>>(m, {-1, -1}));
    std::vector<std::vector<bool>> used(n, std::vector<bool>(m, false));
    std::vector<std::vector<int>> dists(n, std::vector<int>(m, -1));
    dists[start_x][start_y] = 0;

    std::vector<std::deque<std::pair<int, int>>> queues(k);
    queues[0].push_back({start_x, start_y});

    int pointer = 0;
    int total = 1;
    int res = -1;

    while (total > 0) {
        while (queues[pointer % k].empty()) {
            pointer++;
        }
        auto [x, y] = queues[pointer % k].front();
        queues[pointer % k].pop_front();
        total--;

        if (used[x][y]) {
            continue;
        }
        used[x][y] = true;

        for (const auto& dir : std::vector<std::pair<int, int>>{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}) {
            int dx = dir.first, dy = dir.second;
            int new_x = x + dx, new_y = y + dy;
            if (0 <= new_x && new_x < n && 0 <= new_y && new_y < m && grid[new_x][new_y] != '#') {
                int nxt_dist = (grid[new_x][new_y] == '.') ? 1 : 2;
                if (dists[new_x][new_y] == -1 || dists[new_x][new_y] > dists[x][y] + nxt_dist) {
                    dists[new_x][new_y] = dists[x][y] + nxt_dist;
                    parents[new_x][new_y] = {x, y};
                    queues[dists[new_x][new_y] % k].push_back({new_x, new_y});
                    total++;
                }
            }
        }
    }

    std::cout << dists[end_x][end_y] << std::endl;

    std::vector<char> arr;
    int x = end_x, y = end_y;
    while (parents[x][y].first != -1) {
        int parent_x = parents[x][y].first;
        int parent_y = parents[x][y].second;
        char symbol = 'N';
        if (x - parent_x == 1) symbol = 'S';
        else if (y - parent_y == 1) symbol = 'E';
        else if (y - parent_y == -1) symbol = 'W';
        arr.push_back(symbol);
        x = parent_x;
        y = parent_y;
    }

    std::reverse(arr.begin(), arr.end());
    for (char c : arr) {
        std::cout << c;
    }
    std::cout << std::endl;

    return 0;
}
