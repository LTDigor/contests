#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <unordered_map>

using namespace std;

int main() {
int nodes, vertexes;
cin >> nodes >> vertexes;

unordered_map<int, vector<int>> graph1;
unordered_map<int, vector<int>> graph2;

for (int i = 0; i < vertexes; i++) {
    int frm, to, mark;
    cin >> frm >> to >> mark;
    frm -= 1;
    to -= 1;

    if (mark == 1) {
        graph1[to].push_back(frm);
    } else {
        graph2[to].push_back(frm);
    }
}

vector<int> dp(nodes, INT_MAX);

vector<bool> visited1(nodes, false);
vector<bool> visited2(nodes, false);

visited2[nodes - 1] = true;
visited1[nodes - 1] = true;
queue<tuple<int, int, int>> q;
q.push(make_tuple(nodes - 1, 2, 0));
q.push(make_tuple(nodes - 1, 1, 0));
while (!q.empty()) {
    auto [node, mark, dist] = q.front();
    q.pop();

    dp[node] = min(dp[node], dist);

    unordered_map<int, vector<int>> &nxt_graph = (mark == 2) ? graph1 : graph2;
    int nxt_mark = (mark == 2) ? 1 : 2;
    vector<bool> &visited = (mark == 2) ? visited1 : visited2;

    for (int nxt : nxt_graph[node]) {
        if (!visited[nxt]) {
            visited[nxt] = true;
            q.push(make_tuple(nxt, nxt_mark, dist + 1));
        }
    }
}

vector<int> res(nodes - 1);
for (int i = 0; i < nodes - 1; i++) {
    res[i] = (dp[i] < INT_MAX) ? dp[i] : -1;
}
for (int val : res) {
    cout << val << " ";
}

return 0;
}