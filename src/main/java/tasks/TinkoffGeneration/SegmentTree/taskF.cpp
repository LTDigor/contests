#include <iostream>
#include <vector>

using namespace std;

vector<int> t;
vector<int> a;

void build(int p, int l, int r) {
    if (l + 1 == r) {
        t[p] = a[l] == 0 ? 1 : 0;
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid, r);

    t[p] = t[2 * p + 1] + t[2 * p + 2];
}

void upd(int p, int l, int r, int ind, int x) {
    if (r - l == 1) {
        t[p] = x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (ind < mid) {
        upd(2 * p + 1, l, mid, ind, x);
    } else {
        upd(2 * p + 2, mid, r, ind, x);
    }

    t[p] = t[2 * p + 1] + t[2 * p + 2];
}

pair<int, int> search(int p, int l, int r, int lq, int rq, int k) {
    if (r <= lq || l >= rq) {
        return {-2, 0};
    }
    if (l >= lq && r <= rq && t[p] < k) {
        return {-2, t[p]};
    }
    if (r - l == 1) {
        return {l, 1};
    }
    int mid = l + (r - l) / 2;

    pair<int, int> left = search(2 * p + 1, l, mid, lq, rq, k);
    if (left.first != -2) {
        return left;
    }
    pair<int, int> right = search(2 * p + 2, mid, r, lq, rq, k - left.second);
    if (right.first != -2) {
        return right;
    }
    return {-2, left.second + right.second};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    cin >> n;

    t.resize(4 * n);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);

    cin >> k;
    for (int i = 0; i < k; i++) {
        char s;
        cin >> s;
        if (s == 'u') {
            int i, x;
            cin >> i >> x;
            upd(0, 0, n, i - 1, x == 0 ? 1 : 0);
        } else {
            int lq, rq, k;
            cin >> lq >> rq >> k;
            cout << search(0, 0, n, lq - 1, rq).first + 1 << ' ';
        }
    }

    return 0;
}