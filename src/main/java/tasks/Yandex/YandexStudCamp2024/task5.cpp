#include <bits/stdc++.h>
#include "Network.h"

using namespace std;

//struct Path
//{
//    std::vector<int> path = {};
//    bool isContaminated = false;
//};
//
//struct Edge
//{
//    int id, i, j;
//};
//
//class Network
//{
//    public:
//        Network(const std::vector<Edge> edges);
//        Path getPath(int source, int dest);
//        void printPath(Path path);
//    private:
//        int n;
//        std::vector<Edge> edges;
//        std::vector<std::vector<int>> adj;
//        Path BFS(int source, int dest);
//};

vector<Edge> edges;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Edge e;
        cin >> e.id >> e.i >> e.j;
        edges.push_back(e);
    }

    Network network = Network(edges);

    int res = 0;
    for (Edge e : edges) {
        Path p = network.getPath(e.i, e.j);
        if (p.isContaminated) {
            res = e.id;
            break;
        }
    }

    cout << res << endl;
}
