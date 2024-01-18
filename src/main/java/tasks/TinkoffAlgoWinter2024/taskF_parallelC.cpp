#include <bits/stdc++.h>

using namespace std;

long long count_mega_inversions(const vector<int>& arr) {
    if (arr.size() < 3) {
        return 0;
    }
    multiset<int> sl;
    sl.insert(arr[0]);

    long long res = 0;
    for (int mid = 1; mid < arr.size() - 1; mid++) {
        long long left_greater = mid - distance(sl.begin(), sl.lower_bound(arr[mid]));
        long long right_smaller = arr[mid] - 1 - (mid - left_greater);

        res += left_greater * right_smaller;
        sl.insert(arr[mid]);
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long long res = count_mega_inversions(p);
    cout << res << endl;
    return 0;
}

