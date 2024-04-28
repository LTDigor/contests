#include <iostream>
#include <vector>

using namespace std;

vector<pair<bool, bool>> t;
vector<long long> a;
vector<long long> diff;
int n;

void upd(int p, int l, int r, int ind, long long x) {
    if (r - l == 1) {
        diff[l] += x;
        t[p] = {(diff[l] <= 1), (-diff[l] <= 1)};
        return;
    }
    int mid = l + (r - l) / 2;
    if (ind < mid) {
        upd(2 * p + 1, l, mid, ind, x);
    } else {
        upd(2 * p + 2, mid, r, ind, x);
    }

    bool left = t[2 * p + 1].first && t[2 * p + 2].first && (diff[mid] <= 1);
    bool right = t[2 * p + 1].second && t[2 * p + 2].second && (-diff[mid] <= 1);
    t[p] = {left, right};
}

bool check(int p, int l, int r, int lq, int rq, bool dir) {
    if (r <= lq || rq <= l) {
        return true;
    }
    if (lq <= l && r <= rq) {
        return dir ? t[p].first : t[p].second;
    }

    int mid = l + (r - l) / 2;
    bool left = check(2 * p + 1, l, mid, lq, rq, dir);
    bool right = check(2 * p + 2, mid, r, lq, rq, dir);
    return left && right;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int k;
    cin >> n;
    cin >> k;

    t.resize(4 * n);
    a.resize(n);
    diff.resize(n - 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0) {
            upd(0, 0, n - 1, i - 1, a[i] - a[i - 1]);
        }
    }


    for (int i = 0; i < k; i++) {
        int s;
        cin >> s;
        if (s == 2) {
            long long l, r, x;
            cin >> l >> r >> x;
            if (l > 1) {
                upd(0, 0, n - 1, l - 2, x);
            }
            if (r < n) {
                upd(0, 0, n - 1, r - 1, -x);
            }

        } else {
            long long lq, rq;
            cin >> lq >> rq;
            cout << (check(0, 0, n - 1, min(lq, rq) - 1, max(lq, rq) - 1, lq < rq) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
