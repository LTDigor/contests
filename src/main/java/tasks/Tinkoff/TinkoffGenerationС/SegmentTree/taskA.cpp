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
    t[p] = t[2 * p + 1] + t[2 * p + 2];
}

long long get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return 0;
    }
    if (l >= lq && r <= rq) {
        return t[p];
    }
    int mid = l + (r - l) / 2;
    return get(2 * p + 1, l, mid, lq, rq) + get(2 * p + 2, mid, r, lq, rq);
}

int main() {
    int n, k;
    cin >> n >> k;
    t.resize(4 * n);
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
            cout << get(0, 0, n, lq - 1, rq) << endl;
        }
    }
    return 0;
}
