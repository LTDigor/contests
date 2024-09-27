#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>

using namespace std;

// start from 0
const ll mx_bit = 18;

struct Node {
    Node *go[2];
    bool swapped = false;
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
}

void fxor(Node *cur, ll bit_num, ll num) {
    if (cur == nullptr) return;

    if ((num >> bit_num) & 1) {
        cur->swapped = !(cur->swapped);
    }

    fxor(cur->go[0], bit_num - 1, num);
    fxor(cur->go[1], bit_num - 1, num);
}

ll mex(Node *cur, ll bit_num) {
    if (bit_num < 0) {
        return -1;
    }

    Node *left_node;
    Node *right_node;
    if (cur->swapped) {
        left_node = cur->go[1];
        right_node = cur->go[0];
    } else {
        left_node = cur->go[0];
        right_node = cur->go[1];
    }

    if (left_node == nullptr) {
        return 0;
    }

    ll left = mex(left_node, bit_num - 1);
    if (left != -1) {
        return left;
    }

    if (right_node == nullptr) {
        return 1 << bit_num;
    }

    ll right = mex(right_node, bit_num - 1);
    if (right != -1) {
        return right + (1 << bit_num);
    }

    return -1;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    ll n; cin >> n;
    ll m; cin >> m;

    Node *root = new Node();

    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        add_num(root, a[i]);
    }

    for (ll i = 0; i < m; i++) {
        ll x = 1; cin >> x;
        fxor(root, mx_bit, x);
        cout << mex(root, mx_bit) << endl;
    }
}