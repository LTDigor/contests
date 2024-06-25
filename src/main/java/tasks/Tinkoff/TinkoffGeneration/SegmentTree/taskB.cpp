#include <iostream>
#include <vector>
using namespace std;

vector<long long> t;

void upd(int p, int l, int r, int ind, long long x) {
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
    t[p] = max(t[2 * p + 1], t[2 * p + 2]);
}

long long get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return -1000000001;
    }
    if (l >= lq && r <= rq) {
        return t[p];
    }
    int mid = l + (r - l) / 2;
    return max(get(2 * p + 1, l, mid, lq, rq), get(2 * p + 2, mid, r, lq, rq));
}

int main() {
    int n, k;
    cin >> n;
    t.resize(4 * n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        upd(0, 0, n, i, a);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int lq, rq;
        cin >> lq >> rq;
        cout << get(0, 0, n, lq - 1, rq) << endl;
    }
    return 0;
}