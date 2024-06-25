#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<long long> t;
vector<long long> sum_even;

void build(int p, int l, int r) {
    if (l + 1 == r) {
        t[p] = a[l];
        sum_even[p] = a[l];
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid, r);

    t[p] = t[2 * p + 1] + t[2 * p + 2];
    sum_even[p] = sum_even[2 * p + 1];
    if ((mid - l) % 2 == 0) {
        sum_even[p] += sum_even[2 * p + 2];
    } else {
        sum_even[p] += t[2 * p + 2] - sum_even[2 * p + 2];
    }
}

void upd(int p, int l, int r, int ind, long long x) {
    if (r - l == 1) {
        t[p] = x;
        sum_even[p] = x;
        return;
    }
    int mid = l + (r - l) / 2;
    if (ind < mid) {
        upd(2 * p + 1, l, mid, ind, x);
    } else {
        upd(2 * p + 2, mid, r, ind, x);
    }
    t[p] = t[2 * p + 1] + t[2 * p + 2];
    sum_even[p] = sum_even[2 * p + 1];
    if ((mid - l) % 2 == 0) {
        sum_even[p] += sum_even[2 * p + 2];
    } else {
        sum_even[p] += t[2 * p + 2] - sum_even[2 * p + 2];
    }
}

long long get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return 0;
    }
    if (l >= lq && r <= rq) {
        if ((lq - l) % 2 != 0) {
            return t[p] + sum_even[p];
        } else {
            return 2 * t[p] - sum_even[p];
        }
    }
    int mid = l + (r - l) / 2;
    return get(2 * p + 1, l, mid, lq, rq) + get(2 * p + 2, mid, r, lq, rq);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k;

    cin >> n;

    t.resize(4 * n);
    sum_even.resize(4 * n);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    build(0, 0, n);

    cin >> k;
    for (int i = 0; i < k; i++) {
        int op;
        cin >> op;
        if (op == 0) {
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