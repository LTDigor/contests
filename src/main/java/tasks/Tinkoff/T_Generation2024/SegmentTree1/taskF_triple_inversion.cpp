#include <bits/stdc++.h>
#define ll long long
#define fori(n) for (ll i = 0; i < n; i++)


using namespace std;

vector<ll> a;
vector<ll> gr;
vector<ll> le;

vector<pair<ll, ll>> build(int l, int r) {
    if (l + 1 == r) {
        return {{a[l], l}};
    }

    int mid = l + (r - l) / 2;
    vector<pair<ll, ll>> left = build(l, mid);
    vector<pair<ll, ll>> right = build(mid, r);

    vector<pair<ll, ll>> res;

    // left pointer, right pointer
    unsigned int lp = 0, rp = 0;

    // merge sort solution
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
    fori(n) {
        cin >> a[i];
    }
    build(0, n);

    ll res = 0;
    fori(n) {
        res += gr[i] * le[i];
    }
    cout << res << endl;
    return 0;
}
