#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int root_val;

const int INF = 1000000000;
const int NEG_INF = -1000000000;

vector<int> left_children;
vector<int> right_children;
vector<int> mx;
vector<int> mn;
vector<int> mx_key;
vector<int> mn_key;
vector<int> keys;

void dfs(int node, int up_min, int up_max) {
    int left = left_children[node];
    int right = right_children[node];
    if (left != -1) {
        dfs(left, up_min, min(up_max, keys[node] - 1));
        mn_key[node] = mn_key[left];
        mn[node] = max(up_min, mx[left] + 1);
    } else {
        mn_key[node] = keys[node];
        mn[node] = up_min;
    }

    if (right != -1) {
        dfs(right, max(up_min, keys[node]), up_max);
        mx_key[node] = mx_key[right];
        mx[node] = min(up_max, mn[right]);
    } else {
        mx_key[node] = keys[node];
        mx[node] = up_max;
    }
}

int main() {
    cin >> n;
    cin >> root_val;

    left_children = vector<int>(n, -1);
    right_children = vector<int>(n, -1);
    mx = vector<int>(n, INF);
    mn = vector<int>(n, NEG_INF);
    mx_key = vector<int> (n, -1);
    mn_key = vector<int>(n, -1);
    keys = vector<int>(n, -1);

    keys[0] = root_val;

    for (int i = 1; i < n; i++) {
        int key, parent;
        char direction;
        cin >> key >> parent >> direction;
        keys[i] = key;
        parent--;
        if (direction == 'R') {
            right_children[parent] = i;
        } else {
            left_children[parent] = i;
        }
    }

    dfs(0, NEG_INF, INF);

    int lq, rq;
    cin >> lq >> rq;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int left_c = left_children[i];
        int right_c = right_children[i];
        int l, r;
        if (left_c == -1) {
            l = max(mn[i], lq);
        } else {
            l = max(mx_key[left_c] + 1, lq);
        }

        if (right_c == -1) {
            r = min(mx[i], rq);
        } else {
            r = min(mn_key[right_c], rq);
        }
        res += max(0, r - l);
    }

    cout << res << endl;
    return 0;
}

