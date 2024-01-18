#include <bits/stdc++.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int events;
    std::cin >> events;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> heap;
    std::stack<std::pair<int, int>> stack;
    std::unordered_set<int> eaten;

    for (int i = 0; i < events; i++) {
        int s;
        std::cin >> s;

        if (s == 2) {
            int uid = stack.top().second;
            stack.pop();
            eaten.insert(uid);
        } else if (s == 3) {
            while (eaten.count(heap.top().second) > 0) {
                heap.pop();
            }

            int min_radius = heap.top().first;
            std::cout << min_radius << std::endl;
        } else {
            int radius;
            std::cin >> radius;
            stack.push(std::make_pair(radius, i));
            heap.push(std::make_pair(radius, i));
        }
    }

    return 0;
}

