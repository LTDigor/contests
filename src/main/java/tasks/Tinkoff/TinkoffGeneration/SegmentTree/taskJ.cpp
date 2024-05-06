#include <iostream>
#include <vector>

using namespace std;

vector<int> t;
vector<int> a;

void build(int p, int l, int r) {
    if (l + 1 == r) {
        t[p] = a[l] * (l % 2 == 0 ? 1 : -1);
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid, r);

    t[p] = t[2 * p + 1] + t[2 * p + 2];
}

void upd(int p, int l, int r, int ind, int x) {
    if (r - l == 1) {
        t[p] = x * (l % 2 == 0 ? 1 : -1);
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

int get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return 0;
    }
    if (l >= lq && r <= rq) {
        return t[p];
    }
    int mid = l + (r - l) / 2;

    int left = get(2 * p + 1, l, mid, lq, rq);
    int right = get(2 * p + 2, mid, r, lq, rq);

    return left + right;
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
        int s;
        cin >> s;
        if (s == 0) {
            int i, x;
            cin >> i >> x;
            upd(0, 0, n, i - 1, x);
        } else {
            int lq, rq, k;
            cin >> lq >> rq;
            cout << get(0, 0, n, lq - 1, rq) * (lq % 2 == 1 ? 1 : -1) << endl;
        }
    }

    return 0;
}
