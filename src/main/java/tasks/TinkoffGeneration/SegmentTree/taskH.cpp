#include <iostream>
#include <vector>

using namespace std;

vector<long long> a;
vector<long long> gr;
vector<long long> le;

vector<pair<long long, long long>> build(int l, int r) {
    if (l + 1 == r) {
        return {{a[l], l}};
    }

    int mid = l + (r - l) / 2;
    vector<pair<long long, long long>> left = build(l, mid);
    vector<pair<long long, long long>> right = build(mid, r);

    vector<pair<long long, long long>> res;

    unsigned int lp = 0, rp = 0;
    int cumm = 1;
    while (lp < left.size() || rp < right.size()) {
        if (lp == left.size() || (rp < right.size() && right[rp].first < left[lp].first)) {
            gr[right[rp].second] += left.size() - lp;
            res.push_back(right[rp++]);
        } else {
            le[left[lp].second] += rp;
            res.push_back(left[lp++]);
        }
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;

    a.resize(n);
    gr.resize(n);
    le.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, n);

    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += gr[i] * le[i];
    }
    cout << res << endl;
    return 0;
}
