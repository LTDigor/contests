#include <bits/stdc++.h>

using namespace std;

vector<vector<pair<int, int>>> p;
vector<vector<int>> s;
vector<vector<int>> mx;

pair<int, int> leader(int r, int c) {
    if (p[r][c] == make_pair(r, c)) {
        return make_pair(r, c);
    }
    p[r][c] = leader(p[r][c].first, p[r][c].second);
    return p[r][c];
}

void unite(int ra1, int ca1, int rb1, int cb1) {
    auto [ra, ca] = leader(ra1, ca1);
    auto [rb, cb] = leader(rb1, cb1);
    if (ra == rb && ca == cb) {
        return;
    }
    if (s[ra][ca] > s[rb][cb]) {
        swap(ra, rb);
        swap(ca, cb);
    }
    s[rb][cb] += s[ra][ca];
    p[ra][ca] = p[rb][cb];
    mx[rb][cb] = max(mx[ra][ca], mx[rb][cb]);
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    int q;
    cin >> q;
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    p = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            p[i][j] = {i, j};
        }
    }
    s = vector<vector<int>>(n, vector<int>(m, 1));
    mx = grid;

    vector<tuple<int, int, int>> to_add;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r -= 1;
        c -= 1;
        to_add.push_back(make_tuple(r, c, grid[r][c]));
        grid[r][c] = 0;
    }
    reverse(to_add.begin(), to_add.end());

    vector<int> res;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (grid[r][c] == 0) {
                continue;
            }
            heap.push(make_tuple(grid[r][c], r, c));
            for (auto [dr, dc] : dirs) {
                int nr = r + dr;
                int nc = c + dc;
                if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] > 0) {
                    unite(nr, nc, r, c);
                }
            }
        }
    }
    int mn, mn_r, mn_c;
    tie(mn, mn_r, mn_c) = heap.top();
    auto [lr, lc] = leader(mn_r, mn_c);
    while (mn != mx[lr][lc]) {
        heap.pop();
        tie(mn, mn_r, mn_c) = heap.top();
        tie(lr, lc) = leader(mn_r, mn_c);
    }
    res.push_back(mn);
    for (auto [r, c, w] : to_add) {
        grid[r][c] = w;
        heap.push(make_tuple(grid[r][c], r, c));
        for (auto [dr, dc] : dirs) {
            int nr = r + dr;
            int nc = c + dc;
            if (0 <= nr && nr < n && 0 <= nc && nc < m && grid[nr][nc] > 0) {
                unite(nr, nc, r, c);
            }
        }
        tie(mn, mn_r, mn_c) = heap.top();
        tie(lr, lc) = leader(mn_r, mn_c);
        while (mn != mx[lr][lc]) {
            heap.pop();
            tie(mn, mn_r, mn_c) = heap.top();
            tie(lr, lc) = leader(mn_r, mn_c);
        }
        res.push_back(mn);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}
