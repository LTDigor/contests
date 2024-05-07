#include <bits/stdc++.h>
#define ll int
#define vll vector<ll>
#define pll pair<ll, ll>
#define vpll vector<pll>

using namespace std;

const string DIR_NAMES[4] = {"SOUTH", "WEST", "NORTH", "EAST"};
const string DIR_NAMES_BACK[4] = {"NORTH", "EAST", "SOUTH", "WEST"};
const vpll DIRS = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

struct hashFunction {
    size_t operator()(const pll &x) const {
        return x.first ^ x.second;
    }
};

unordered_set<pll, hashFunction> used;

void dfs(ll x, ll y) {
    for (ll i = 0; i < 4; i++) {
        ll nx = x + DIRS[i].first;
        ll ny = y + DIRS[i].second;

        if (used.find({nx, ny}) == used.end()) {
            used.insert({nx, ny});
            cout << DIR_NAMES[i] << endl;
            string ans;
            cin >> ans;
            if (ans == "EMPTY") {
                dfs(nx, ny);
                cout << DIR_NAMES_BACK[i] << endl;
                cin >> ans;
            }
        }
    }
}

signed main() {
    used.insert({0, 0});
    dfs(0, 0);
    cout << "DONE" << endl;
}
