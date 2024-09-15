#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<int> prefix;
vector<int> infix;
unordered_map<int, int> infix_positions;
vector<int> left_children;
vector<int> right_children;

// left included, right excluded
bool check_subtree(int pref_l, int pref_r, int inf_l, int inf_r) {
    // empty
    if (inf_l == inf_r) {
        return true;
    }

    // leaf
    if (inf_l + 1 == inf_r) {
        if (prefix[pref_l] != infix[inf_l]) {
            return false;
        }
        return true;
    }

    int root = prefix[pref_l];
    int root_ind = infix_positions[root];

    // wrong tree
    if (root_ind < inf_l || root_ind >= inf_r) {
        return false;
    }
    int left_tree_size = root_ind - inf_l;
    int right_tree_size = inf_r - inf_l - left_tree_size - 1;

    // Prefix: ROOT_LEFT_RIGHT
    // Infix: LEFT_ROOT_RIGHT
    bool res_left = check_subtree(pref_l + 1, pref_l + 1 + left_tree_size, inf_l, inf_l + left_tree_size);
    bool res_right = check_subtree(pref_l + 1 + left_tree_size, pref_r, inf_l + left_tree_size + 1, inf_r);

    if (res_left && res_right) {
        if (left_tree_size > 0) {
            left_children[root] = prefix[pref_l + 1];
        }
        if (right_tree_size > 0) {
            right_children[root] = prefix[pref_l + 1 + left_tree_size];
        }
        return true;
    } else {
        return false;
    }
}

int main() {
    cin >> n;

    prefix.resize(n);
    infix.resize(n);
    left_children.resize(n, -1);
    right_children.resize(n, -1);

    for (int i = 0; i < n; ++i) {
        cin >> prefix[i];
        prefix[i]--; // Adjusting to 0-based index
    }

    for (int i = 0; i < n; ++i) {
        cin >> infix[i];
        infix[i]--; // Adjusting to 0-based index
    }

    for (int i = 0; i < n; ++i) {
        infix_positions[infix[i]] = i;
    }

    if (prefix[0] != 0 || !check_subtree(0, n, 0, n)) {
        cout << -1 << endl;
    } else {
        for (int i = 0; i < n; ++i) {
            cout << left_children[i] + 1 << " " << right_children[i] + 1 << endl; // Adjusting back to 1-based index
        }
    }

    return 0;
}

