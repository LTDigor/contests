#include <iostream>
#include <vector>

using namespace std;

vector<int> a;
vector<int> gr;
vector<int> le;

vector<pair<int, int>> build(int p, int l, int r) {
    if (l + 1 == r) {
        return {{a[l], l}};
    }

    int mid = l + (r - l) / 2;
    vector<pair<int, int>>left = build(2 * p + 1, l, mid);
    vector<pair<int, int>> right = build(2 * p + 2, mid, r);

    vector<int> res = vector(left.size + right.size);

    int lp = 0, rp = 0;
    while (lp < left.size() && rp < right.size()) {
        if (lp == left.size() || rp < right.size() && right[rp].first < left[lp].second) {
            gr[right[rp].second] += left.size() - lp;
            le[right[rp].second] += left.size() - lp;
            res.push_back(right[rp++]);
        } else {
            res.push_back(left[lp++]);
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n;

    a.resize(n);
    gr.resize(n);
    le.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);

    long long res;
    for (int i = 0; i < n; i++) {
        res += gr[i] * le[i];
    }

    cout << res << endl;
    return 0;
}