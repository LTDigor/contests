#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int gcd(int x, int y) {
    if (x < y) {
        swap(x, y);
    }
    if (y == 0) {
        return x;
    }
    while (x % y > 0) {
        int tmp = x;
        x = y;
        y = tmp % y;
    }
    return y;
}

void build_gcd(vector<int>& arr, const vector<int>& src, int p, int l, int r) {
    if (l + 1 == r) {
        arr[p] = src[l];
        return;
    }

    int mid = (l + r) / 2;
    int lp = 2 * p + 1;
    int rp = 2 * p + 2;

    build_gcd(arr, src, lp, l, mid);
    build_gcd(arr, src, rp, mid, r);

    arr[p] = gcd(arr[lp], arr[rp]);
}

int get_gcd(const vector<int>& arr, int p, int l, int r, int lq, int rq) {
    if (lq <= l && r <= rq) {
        return arr[p];
    }
    if (rq <= l || r <= lq) {
        return 0;
    }

    int mid = (l + r) / 2;
    int lp = 2 * p + 1;
    int rp = 2 * p + 2;

    int ans_l = get_gcd(arr, lp, l, mid, lq, rq);
    int ans_r = get_gcd(arr, rp, mid, r, lq, rq);

    return gcd(ans_l, ans_r);
}

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> gcd_a(4 * n);
    vector<int> gcd_b(4 * n);

    vector<int> a_diff(n - 1);
    vector<int> b_diff(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        a_diff[i] = abs(a[i] - a[i + 1]);
        b_diff[i] = abs(b[i] - b[i + 1]);
    }

    build_gcd(gcd_a, a_diff, 0, 0, n - 1);
    build_gcd(gcd_b, b_diff, 0, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int x1, x2, y1, y2;
        cin >> x1 >> x2 >> y1 >> y2;
        x1--; x2--; y1--; y2--;

        int res = a[x1] + b[y1];
        if (x2 > x1) {
            int val = get_gcd(gcd_a, 0, 0, n - 1, x1, x2);
            res = gcd(res, val);
        }
        if (y2 > y1) {
            int val = get_gcd(gcd_b, 0, 0, n - 1, y1, y2);
            res = gcd(res, val);
        }

        cout << res << endl;
    }

    return 0;
}

