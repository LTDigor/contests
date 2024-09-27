#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> t;

void upd(int p, int l, int r, int ind, int x) {
    if (r - l == 1) {
        t[p] = {x, 1};
        return;
    }
    int mid = l + (r - l) / 2;
    if (ind < mid) {
        upd(2 * p + 1, l, mid, ind, x);
    } else {
        upd(2 * p + 2, mid, r, ind, x);
    }

    if (t[2 * p + 1].first == t[2 * p + 2].first) {
        t[p] = {t[2 * p + 1].first, t[2 * p + 1].second + t[2 * p + 2].second};
        return;
    }

    t[p] = max(t[2 * p + 1], t[2 * p + 2]);
}

pair<int, int> get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return {0, 0};
    }
    if (l >= lq && r <= rq) {
        return t[p];
    }
    int mid = l + (r - l) / 2;

    pair<int, int> left = get(2 * p + 1, l, mid, lq, rq);
    pair<int, int> right = get(2 * p + 2, mid, r, lq, rq);

    if (left.first == right.first) {
        return {left.first, left.second + right.second};
    }

    return max(left, right);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n;

    t.resize(4 * n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        upd(0, 0, n, i, x);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        char s;
        cin >> s;
        if (s == 'A') {
            int i, x;
            cin >> i >> x;
            upd(0, 0, n, i - 1, x);
        } else {
            int lq, rq;
            cin >> lq >> rq;
            cout << get(0, 0, n, lq - 1, rq).second << endl;
        }
    }

    return 0;
}