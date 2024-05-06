#include <iostream>
#include <vector>
#include <string>

bool is_tree(int node, int parent, std::vector<bool>& used, const std::vector<std::vector<int>>& graph) {
    used[node] = true;
    for (int nxt : graph[node]) {
        if (nxt == parent)
    	    continue;
        if (used[nxt] || !is_tree(nxt, node, used, graph))
    		return false;
    }
    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
      int frm, to;
      std::cin >> frm >> to;
      frm--, to--;

      graph[frm].push_back(to);
      graph[to].push_back(frm);
    }
    std::vector<bool> used(n, false);

    bool res = is_tree(0, -1, used, graph);
    for (bool u : used) {
        if (!u) {
    	    res = false;
    	    break;
        }
    }

    std::cout << (res ? "YES" : "NO") << std::endl;
    return 0;
}
