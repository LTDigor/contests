#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>

using namespace std;

const ll mx_bit = 30;

struct Node {
    Node *go[2];
    ll cnt = 0;
};


void add_num(Node* root, ll num) {
    Node *cur = root;

    for (ll i = mx_bit; i >= 0; i--) {
        ll bit = (num >> i) & 1;
        if (cur->go[bit] == nullptr) {
            cur->go[bit] = new Node();
        }
        cur = cur->go[bit];
    }

    cur->cnt += 1;
}

ll get_max(Node* root, ll num) {
    Node *cur = root;

    ll res = 0;
    for (ll i = mx_bit; i >= 0; i--) {
        ll bit = (num >> i) & 1;

        ll nxt = bit ^ 1;
        if (cur->go[nxt] == nullptr) {
            nxt = bit;
        } else {
            res += 1 << i;
        }
        cur = cur->go[nxt];
    }

    return res;
}

ll get_min(Node* root, ll num) {
    Node *cur = root;

    Node *last_diff;
    ll last_diff_bit = 0;
    for (ll i = mx_bit; i >= 0; i--) {
        ll bit = (num >> i) & 1;

        ll nxt = bit;
        if (cur->go[bit ^ 1] != nullptr) {
            last_diff = cur->go[bit ^ 1];
            last_diff_bit = i;
        }
        cur = cur->go[nxt];
    }

    if (cur->cnt > 1)
        return 0;

    ll res = 1 << last_diff_bit;
    cur = last_diff;
    for (ll i = last_diff_bit - 1; i >= 0; i--) {
        ll bit = (num >> i) & 1;

        ll nxt = bit;
        if (cur->go[nxt] == nullptr) {
            nxt = bit ^ 1;
            res += 1 << i;
        }

        cur = cur->go[nxt];
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n; cin >> n;
    vll a = vector<ll>(n);
    Node *root = new Node();
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        add_num(root, a[i]);
    }

    for (ll i = 0; i < n; i++) {
        cout << get_min(root, a[i]) << " " << get_max(root, a[i]) << endl;
    }
}
