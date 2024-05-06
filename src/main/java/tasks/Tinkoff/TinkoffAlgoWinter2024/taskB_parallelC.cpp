#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
int rows, cols;
cin >> rows >> cols;

vector<string> matrix;
for (int i = 0; i < rows; i++) {
    string row;
    cin >> row;
    matrix.push_back(row);
}

vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
        if (matrix[r][c] == '#') {
            dp[r + 1][c + 1] = min({dp[r][c], dp[r + 1][c], dp[r][c + 1]}) + 1;
        }
    }
}

int res = 1;
for (int r = 6; r <= rows; r++) {
    for (int c = 6; c <= cols; c++) {
        int side = res + 1;
        if (r - 2 * side < 1 || c - 2 * side < 1) {
            continue;
        }
        int minSquareSize = min({
            dp[r][c - side],
            dp[r - side][c],
            dp[r - side][c - side],
            dp[r - 2 * side][c - side],
            dp[r - side][c - 2 * side]
        });

        if (minSquareSize >= side) {
            res = max(res, side);
        }
    }
}

cout << res << endl;

return 0;
}