#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

const int MX = 1001;
vector<pair<int, int>> dirs = {
    {-1, -1}, {-1, 0}, {-1, 1}, 
    {0, -1}, {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<tuple<int, int, int>> pawns;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pawns.emplace_back(x, y, 0);
    }

    vector<vector<int>> pawn_dists(MX, vector<int>(MX, -1));

    deque<tuple<int, int, int>> q(pawns.begin(), pawns.end());
    while (!q.empty()) {
        auto [x, y, dist] = q.front();
        q.pop_front();
        if (pawn_dists[x][y] != -1) {
            continue;
        }
        pawn_dists[x][y] = dist;
        for (const auto& [dx, dy] : dirs) {
            int nx = x + dx;
            int ny = y + dy;
            if (0 <= nx && nx < MX && 0 <= ny && ny < MX && pawn_dists[nx][ny] == -1) {
                q.emplace_back(nx, ny, dist + 1);
            }
        }
    }

    for (int i = 0; i < t; ++i) {
        int x, y;
        cin >> x >> y;
        cout << pawn_dists[x][y] << '\n';
    }

    return 0;
}

