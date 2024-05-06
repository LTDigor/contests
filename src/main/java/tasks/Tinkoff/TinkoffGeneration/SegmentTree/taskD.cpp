#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> t;
vector<int> a;

void build(int p, int l, int r) {
    if (l + 1 == r) {
        t[p] = {a[l], l};
        return;
    }

    int mid = l + (r - l) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid, r);

    t[p] = max(t[2 * p + 1], t[2 * p + 2]);
}

pair<int, int> get(int p, int l, int r, int lq, int rq) {
    if (r <= lq || l >= rq) {
        return {0, -1};
    }
    if (l >= lq && r <= rq) {
        return t[p];
    }
    int mid = l + (r - l) / 2;
    return max(get(2 * p + 1, l, mid, lq, rq), get(2 * p + 2, mid, r, lq, rq));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k;
    scanf("%i", &n);
    t.resize(4 * n);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        scanf("%i", &a[i]);
    }
    build(0, 0, n);

    scanf("%i", &k);
    for (int i = 0; i < k; i++) {
        int lq, rq;
        scanf("%i %i", &lq, &rq);
        printf("%i\n", get(0, 0, n, lq - 1, rq).second + 1);
    }
    return 0;
}