#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>

using namespace std;

const ll mx_bit = 20;

struct Node {
    Node *go[2];
    ll cnt[2];
};


void add_num(Node* root, ll num) {
    Node *cur = root;

    for (ll i = mx_bit; i >= 0; i--) {
        ll bit = (num >> i) & 1;
        if (cur->go[bit] == nullptr) {
            cur->go[bit] = new Node();
        }
        cur->cnt[bit] += 1;
        cur = cur->go[bit];
    }
}

ll mex(Node *root, ll xor_num) {
    Node *cur = root;

    ll res = 0;
    for (ll i = mx_bit; i >= 0; i--) {
        if (cur == nullptr) break;

        ll bit = (xor_num >> i) & 1;
        if (cur->cnt[bit] == (1 << i)) {
            bit = bit ^ 1;
            res += (1 << i);
        }

        cur = cur->go[bit];
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n; cin >> n;
    ll m; cin >> m;

    Node *root = new Node();

    unordered_set<ll> used;
    for (ll i = 0; i < n; i++) {
        ll x; cin >> x;
        if (used.find(x) == used.end()) {
            add_num(root, x);
            used.insert(x);
        }
    }

    ll xor_num = 0;
    for (ll i = 0; i < m; i++) {
        ll x; cin >> x;
        xor_num = xor_num ^ x;
        cout << mex(root, xor_num) << endl;
    }
}
