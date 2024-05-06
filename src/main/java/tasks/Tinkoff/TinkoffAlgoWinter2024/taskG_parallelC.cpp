#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> coins = a;
    coins.insert(coins.end(), a.begin(), a.end());
    n = 2 * n;

    bool res = false;
    std::vector<int> res_coins;
    for (int mask = 1; mask < (1 << n); mask++) {
        int summ = 0;
        std::vector<int> peeked;
        for (int i = 0; i < n; i++) {
            if (mask >> i & 1) {
                summ += coins[i];
                peeked.push_back(coins[i]);
            }
        }
        if (summ == k) {
            res = true;
            res_coins = peeked;
            break;
        }
    }

    if (res) {
        std::cout << "Yes" << std::endl;
        std::cout << res_coins.size() << std::endl;
        for (int i = 0; i < res_coins.size(); i++) {
            std::cout << res_coins[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}

