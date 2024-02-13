#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int main() {
    int n;
    std::cin >> n;
    int start_x, start_y;
    std::cin >> start_x >> start_y;
    int end_x, end_y;
    std::cin >> end_x >> end_y;
    std::vector<std::pair<int, int>> deltas = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}};
    std::vector<std::vector<bool>> visited(n + 1, std::vector<bool>(n + 1, false));
    visited[start_x][start_y] = true;
    std::queue<std::pair<std::pair<int, int>, int>> q;
    q.push({{start_x, start_y}, 0});
    int res = -1;
    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        auto [x, y] = front.first;
        int dist = front.second;
        if (x == end_x && y == end_y) {
            res = dist;
            break;
        }
        for (auto [delta_x, delta_y] : deltas) {
            int new_x = x + delta_x;
            int new_y = y + delta_y;
            if (0 < new_x && new_x <= n && 0 < new_y && new_y <= n && !visited[new_x][new_y]) {
                visited[new_x][new_y] = true;
                q.push({{new_x, new_y}, dist + 1});
            }
        }
    }
    std::cout << res << std::endl;
    return 0;
}