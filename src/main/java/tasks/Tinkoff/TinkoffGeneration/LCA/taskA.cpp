#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> children;
vector<int> tin;
vector<int> tout;
int counter = 0;

void dfs(int node) {
    tin[node] = counter++;
    for (int nxt : children[node]) {
        dfs(nxt);
    }
    tout[node] = counter++;
}

bool la(int a, int b) {
    return tin[a] < tin[b] && tout[a] > tout[b];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    children.resize(n, vector<int>());
    tin.resize(n);
    tout.resize(n);

    int start = 0;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == 0) {
            start = i;
        } else {
            children[parent - 1].push_back(i);
        }
    }

    dfs(start);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << la(a - 1, b - 1) << endl;
    }
}
