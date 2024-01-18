#include <bits/stdc++.h>

using namespace std;

int getMaxLess(const set<int>& sset, int number, int default_value) {
    auto it = sset.upper_bound(number - 1);
    if ( it != sset.begin()) {
            return *--it;
    }
    return default_value;
}

int getMinGreater(const set<int>& sset, int number, int default_value) {
    auto it = sset.lower_bound(number + 1);
    if (it != sset.end()) {
        return *it;
    }

    return default_value;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<pair<int, int>> arr_sorted;
    for (int i = 0; i < n; i++) {
        arr_sorted.push_back(make_pair(arr[i], i));
    }
    sort(arr_sorted.begin(), arr_sorted.end());

    long long res = 0;
    set<int> ordered_set;
    for (int i = 0; i < n; i++) {
        long long v = arr_sorted[i].first;
        long long ind = arr_sorted[i].second;

        long long left_ind = getMaxLess(ordered_set, ind, -1);
        long long right_ind = getMinGreater(ordered_set, ind, n);

        res += v * (ind - left_ind) * (right_ind - ind);
        ordered_set.insert(ind);
    }

    cout << res << endl;
    return 0;
}