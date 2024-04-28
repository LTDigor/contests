#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<set<ll>> g, gr, gc;
vector<ll> topsort, color, used;

void dfs(ll node) {
    used[node] = 1;
    for (ll nxt : g[node]) {
        if (!used[nxt]) {
            dfs(nxt);
        }
    }

    topsort.push_back(node);
}

void dfs_colors(ll node, ll c) {
    color[node] = c;

    for (ll nxt : gr[node]) {
        if (color[nxt] == -1) {
            dfs_colors(nxt, c);
        }
    }
}

void delete_dfs(ll start, ll node) {
    used[node] = 1;
    for (ll nxt : gc[node]) {
        gc[start].erase(nxt);

        if (!used[nxt]) {
            delete_dfs(start, nxt);
        }
    }
}

vector<ll> bfs(ll start, ll c) {
    vector<ll> dists = vector<ll>(c, -1);
    dists[start] = 0;

    queue<pair<ll, ll>> q;
    q.push({start, 0});

    while (!q.empty()) {
        auto [node, d] = q.front();
        q.pop();

        for (ll nxt : gc[node]) {
            if (dists[nxt] == -1) {
                dists[nxt] = d + 1;
                q.push({nxt, d + 1});
            }
        }
    }

    return dists;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    g.resize(n);
    gr.resize(n);
    color.resize(n, -1);
    used.resize(n);

    for (ll i = 0; i < m; i++) {
        ll frm, to;
        cin >> frm >> to;
        frm--, to--;

        g[frm].insert(to);
        gr[to].insert(frm);
    }

    for (ll i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
        }
    }

    ll c = 0;
    vector<pair<ll, ll>> res;
    for (ll i = 0; i < n; i++) {
        ll node = topsort[n - i - 1];
        if (color[node] == -1) {
            dfs_colors(node, c++);

            ll prev = -1;
            ll first = -1;
            for (ll j = 0; j < n; j++) {
                if (color[j] == c - 1) {
                    if (prev == -1) {
                        first = j;
                        prev = j;
                    } else {
                        res.push_back({prev, j});
                        prev = j;
                    }
                }
            }
            if (prev != first) {
                res.push_back({prev, first});
            }
        }
    }

    vector<ll> color_to_node = vector<ll>(c);
    for (ll i = 0; i < n; i++) {
        color_to_node[color[i]] = i;
    }

    gc = vector<set<ll>>(c);
    for (ll frm = 0; frm < n; frm++) {
        for (ll to = 0; to < n; to++) {
            if (color[frm] != color[to] && g[frm].count(to)) {
                gc[color[frm]].insert(color[to]);
            }
        }
    }

    for (ll frm = 0; frm < c; frm++) {
        vector<ll> dists = bfs(frm, c);
        for (ll to = 0; to < c; to++) {
            if (dists[to] > 0) {
                gc[frm].insert(to);
            }
        }
    }


    for (ll u = 0; u < c; u++) {
        for (ll v : gc[u]) {
            used = vector<ll>(n);
            used[u] = 1;
            delete_dfs(u, v);
        }
    }

    for (ll c_from = 0; c_from < c; c_from++) {
        for (ll c_to : gc[c_from]) {
            res.push_back({color_to_node[c_from], color_to_node[c_to]});
        }
    }

    cout << res.size() << endl;
    for (auto [frm, to] : res) {
        cout << frm + 1 << " " << to + 1 << endl;
    }
    cout << endl;

    return 0;
}