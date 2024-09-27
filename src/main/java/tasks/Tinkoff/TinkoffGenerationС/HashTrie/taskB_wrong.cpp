#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll alphabet_size = 100;

struct Node {
    Node *go[alphabet_size];
    ll terminated;
};

void add_str(Node *root, const vector<char> &s) {
    Node *cur = root;
    for (char c : s) {
        if (!cur->go[c]) {
            cur->go[c] = new Node();
            cur->go[c]->terminated = 0;
        }
        cur = cur->go[c];
    }
    cur->terminated += 1;
}

void dfs(Node *cur, vector<vector<char>> &sorted, vector<char> cared) {
    for (ll i = 0; i < (cur->terminated); i++) {
        sorted.push_back(vector<char>(cared));
    }

    for (char c = 0; c < alphabet_size; c++) {
        if (cur->go[c]) {
            cared.push_back(c);
            dfs(cur->go[c], sorted, cared);
            cared.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;

    vector<vector<char>> strs;

    vector<char> care;
    for (char c : s) {
        if (care.size() == 0 || c == '.' && care[0] == '.' || c != '.' && care[0] != '.') {
            care.push_back(c);
        } else {
            strs.push_back(care);
            care = vector<char>(1, c);
        }
    }

    strs.push_back(care);

    Node *root = new Node();
    root->terminated = 0;
    for (vector<char> str : strs) {
        if (str[0] != '.') {
            add_str(root, str);
        }
    }

    vector<vector<char>> sorted;
    vector<char> empt = vector<char>(0);

    dfs(root, sorted, empt);

    ll cur_ind = 0;
    for (ll i = 0; i < strs.size(); i++) {
        if (strs[i][0] == '.') {
            for (char c : strs[i]) {
                cout << c;
            }
        } else {
            for (char c : sorted[cur_ind]) {
                cout << c;
            }
            cur_ind++;
        }
    }
    cout << endl;
    return 0;
}