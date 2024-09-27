#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<pair<string, ll> >w;

string pref = "";

struct Node {
    char go[100];
    ll cnt = 0;
};
const ll N = 2000000 + 1;

Node t[N];

ll sz = 1;

void add_s(const string &s) {
    ll v = 0;

    for (auto ch : s) {
        if (t[v].go[ch] == '') {
            t[v].go[ch] = sz++;
        }
        v = t[v].go[ch];
    }
    (t[v].cnt)++;
}

void dfs(ll v) {
    if (t[v].cnt) {
        w.emplace_back(pref, t[v].cnt);
    }

    for (auto i : t[v].go) {
        pref.push_back(i.first);
        v = i.second;
        dfs(v);
    }
    pref.pop_back();
}
signed main() {
    ios_base::sync_with_stdio(0);

    cin.tie(nullptr);
    string all; cin >> all;

    ll n = all.size();

    all.push_back('$');

    string to_change = "";

    vector<pair<bool, ll> >who;

    for (ll i = 0; i < n; ++i) {
        to_change.push_back(all[i]);

        if (all[i + 1] == '$' || (all[i] == '.' && all[i + 1] != '.') || (all[i] != '.' && all[i + 1] == '.')) {
            if (to_change.size() >= 1) {
                if (to_change[0] != '.') {
                    add_s(to_change);
                    who.emplace_back(true, to_change.size());
                } else {
                    who.emplace_back(false, to_change.size());
                }
            }
            to_change = "";
        }
    }
    dfs(0);

    ll i = 0;
    for (auto [c, cnt] : who) {
        if (!c) {
            for (ll i = 0; i < cnt; ++i) {
                cout << '.';
            }
        } else {
            cout << w[i].first;
            if (--w[i].second == 0) {
                i++;
            }
        }
    }
}
